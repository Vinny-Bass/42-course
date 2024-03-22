#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char	*str_buff;
	struct s_list	*next;
}	t_list;

int		ft_list_has_newline(t_list *list)
{
	int i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buff[i] != '\0' && i < BUFFER_SIZE)
		{
			if (list->str_buff[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list *ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void ft_append_chunk(t_list **list, char *buffer)
{
	t_list *new_node;
	t_list *last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buff = buffer;
	new_node->next = NULL;
}

void	ft_create_list(t_list **list, int fd)
{
	int char_read;
	char *buffer;

	while (!ft_list_has_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_append_chunk(list, buffer);
	}
}

int ft_len_to_new_line(t_list *list)
{
	int len;
	int i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buff[i])
		{
			len++;
			if (list->str_buff[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	concat_nodes_into_str(t_list *list, char *str, int max_len)
{
	int i;
	int j;

	if (!list || !str)
		return ;
	j = 0;
	while (list && j <= max_len -1)
	{
		i = 0;
		while (list->str_buff[i] && j <= max_len - 1)
		{
			str[j] = list->str_buff[i];
			if (list->str_buff[i++] == '\n')
			{
				str[j] = '\n';
				str[j + 1] = '\0';
				return ;
			}
			j++;
		}
		list = list->next;
	}
	str[j] = '\0';
}

char *ft_get_full_line(t_list *list)
{
	int str_len;
	char *line;

	str_len = ft_len_to_new_line(list);
	line = malloc(str_len + 1);
	if (!line)
		return (NULL);
	concat_nodes_into_str(list, line, str_len);
	return (line);
}
void ft_clean_and_init(t_list **list, t_list *first_node, char *buffer)
{
	t_list *tmp;

	if (!*list)
		return ;
	while(*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buff);
		free(*list);
		*list = tmp;
	}
	if (first_node->str_buff[0])
		*list = first_node;
	else
	{
		free(buffer);
		free(first_node);
	}
}

void ft_reset_list(t_list **list)
{
	t_list *last_node;
	t_list *first_node;
	char *buffer;
	int j;
	int i;

	buffer = malloc(BUFFER_SIZE + 1);
	first_node = malloc(sizeof(t_list));
	if (!buffer || !first_node)
	{
		free(buffer);
		free(first_node);
		return ;
	}
	last_node = ft_lstlast(*list);
	j = 0;
	i = 0;
	while (last_node->str_buff[i] && last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i] && last_node->str_buff[++i])
		buffer[j++] = last_node->str_buff[i];
	buffer[j] = '\0';
	first_node->str_buff = buffer;
	first_node->next = NULL;
	ft_clean_and_init(list, first_node, buffer);
}

char *get_next_line(int fd)
{
	static t_list *list;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (!list)
		return (NULL);
	line = ft_get_full_line(list);
	ft_reset_list(&list);
	return (line);
}

int main(void)
{
	int fd = open("../test", O_RDONLY);  // Replace "yourfile.txt" with your file's path
	if (fd == -1) {
		perror("Failed to open file");  // Print error message if open failed
		return 1;  // Exit if failed to open the file
	}
	char *line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

int 	ft_isalnum(int);
int 	ft_isalpha(int);
int 	ft_isdigit(int);
int 	ft_isprint(int);
int		ft_isascii(int);
void 	*ft_memchr(const void *str, int c, size_t n);
void 	*ft_memcpy(void *to, const void *from, size_t numBytes);
int		ft_memcmp(const void *str1, const void *str2, size_t n_bytes);
void	*ft_memmove(void *to, const void *from, size_t numBytes);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char * dest, const char * src, size_t);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
int 	ft_toupper(int);
int 	ft_tolower(int);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
int 	ft_atoi(const char *);
void	*ft_calloc(size_t nitems, size_t size);
char 	*ft_strdup(const char *);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
char 	*ft_strtrim(char const *s1, char const *set);
char 	**ft_split(char const *s, char c);
char 	*ft_itoa(int n);
char 	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void 	ft_striteri(char *s, void (*f)(unsigned int,char*));
void 	ft_putchar_fd(char c, int fd);
void 	ft_putstr_fd(char *s, int fd);
void 	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char *s, int fd);
typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;
t_list	*ft_lstnew(void *content);
void 	ft_lstadd_front(t_list **lst, t_list *new);
int 	ft_lstsize(t_list *lst);
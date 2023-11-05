#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int 	ft_isalnum(int);
int 	ft_isalpha(int);
int 	ft_isdigit(int);
int 	ft_isprint(int);
int		ft_isascii(int);
void 	*ft_memchr(const void *str, int c, size_t n);
void 	*ft_memcpy(void *, const void *, size_t);
int		ft_memcmp(const void *, const void *, size_t);
void 	*ft_memmove(void *, const void *, size_t);
void	*ft_memset(void *, int, size_t);
void	ft_bzero(void *, size_t );
char 	*ft_strchr(const char *, int);
size_t	ft_strlcat(char * dest, const char * src, size_t);
size_t	ft_strlcpy(char *, const char *, size_t);
size_t 	ft_strlen(const char *);
int 	ft_strncmp(const char *, const char *, size_t);
char 	*ft_strrchr(const char *, int );
int 	ft_toupper(int);
int 	ft_tolower(int);
char 	*ft_strnstr(const char *,const char *, size_t );
int 	ft_atoi(const char *);
void 	*ft_calloc(size_t, size_t);
char 	*ft_strdup(const char *);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
char 	*ft_strtrim(char const *s1, char const *set);
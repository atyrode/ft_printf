# ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>

# define MAX_ARGS 500

int					ft_atoi(char *str);
int					ft_isdigit(int c);
size_t				ft_strlen(char const *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char                *ft_strchr(char *str, int value);

#endif

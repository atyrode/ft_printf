# ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <locale.h>

# define T_U_C (1 << 18)
# define T_C (1 << 17)
# define T_U_X (1 << 16)
# define T_X (1 << 15)
# define T_U_U (1 << 14)
# define T_U (1 << 13)
# define T_U_O (1 << 12)
# define T_O (1 << 11)
# define T_I (1 << 10)
# define T_U_D (1 << 9)
# define T_D (1 << 8)
# define T_P (1 << 7)
# define T_U_S (1 << 6)
# define PRECISION (1 << 5)
# define SPACE (1 << 4)
# define HASHTAG (1 << 3)
# define ZERO (1 << 2)
# define PLUS (1 << 1)
# define MINUS (1 << 0)


# define MAX_ARGS 500

typedef struct      s_val
{

    int             char_n;

    int             sign;

    char            *char_flag;
    int             int_flag;
    int             precision_flag;
    int             flag;

    char            *argtype;

    int             v_int;
    char            v_char;
    char            *v_str;
    void            *v_ptr;

    char            *buffer;

    int             yes;

}                   t_val;

int					ft_atoi(char *str);
int					ft_isdigit(int c);
size_t				ft_strlen(char const *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char                *ft_strchr(char *str, int value);
int				    ft_strchrn(char *format, char c);
void				ft_putchar(char c);
int 				ft_putstr(char *str);
void				ft_putnbr(int n);
char            	*ft_itoa_base(int value, int base);
int                 ft_search(char c, char *charset);
char                ft_search_val(char c, char *charset);
char			    *ft_strlwr(char *s1);
void	            *ft_memalloc(size_t size);
void	            *ft_memset(void *ptr, int value, size_t num);
char	            *ft_strnew(size_t size);
char		        *ft_itoa(int n);
char	            *ft_strdup(char *str);
char	            *ft_strjoin(char const *s1, char const *s2);

#endif

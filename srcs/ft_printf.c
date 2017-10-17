#include "./../includes/ft_printf.h"

void		ft_printf(char *str, ...)
{
	char	*array[MAX_ARGS + 1];
	va_list	ap;
	int		i;

	i = -1;
	va_start(ap, str);
	if (!(ft_strchr(str, '%')))
	{
		while(str[++i] != '\0')
			write(1, &str[i], 1);
	}
	else
		printf("arg\n");
	va_end(ap);
}

int			main(void)
{
	ft_printf("salut\na tous\n");
	ft_printf("salut = %d\n");
	return (0);
}

#include "./../includes/ft_printf.h"

void		ft_printf(char *format, ...)
{
	va_list	list_pointer;
	int		i;
	int		j;
	int		numargs;
	char	*argtype;
	char	*tmp;
	int		arg1;
	char	arg2;

	i = -1;
	tmp = format;
	numargs = ft_strchrn(format, '%');
	va_start(list_pointer, format);
	if (!(argtype = malloc(sizeof(char *) * MAX_ARGS + 1)))
		return ;
	printf("output = \n");
	if(numargs == 0)
		while(format[++i])
			write(1, &format[i], 1);
	else
	{
		i = -1;
		while (++i < numargs)
		{
			tmp = ft_strchr(tmp, '%');
			argtype[i] = *++tmp;
			printf ("argtype[%d] = [%c]\n", i, argtype[i]);
		}
		j = 0;
		i = -1;
		while (format[++i])
		{
			if (format[i] == '%')
			{
				if (argtype[j] == 'd')
				{
				 	arg1 = va_arg(list_pointer, int );
					ft_putnbr(arg1);
				}
				if (argtype[j] == 'c')
				{
				 	arg2 = va_arg(list_pointer, int );
					ft_putchar(arg2);
				}
				j++;
				i += 2;
			}
			write(1, &format[i], 1);
		}
	}
	printf("\n");
	va_end(list_pointer);
}

int			main(void)
{
	int		i;
	char	j;

	i = 5;
	j = 'o';
	ft_printf("salut\n");
	ft_printf("cela doit imprimer 5 = [%d]\n", i);
	ft_printf("test '5' = %d et test 'o' = %c\n", i, j);
	return (0);
}

//might want to remove ft_strchr.c from the minilib

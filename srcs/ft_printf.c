#include "./../includes/ft_printf.h"

void		printf_type(va_list list_pointer, t_val *val, int j)
{
	if (val->argtype[j] == 'd')
	{
		val->v_int = va_arg(list_pointer, int );
		ft_putnbr(val->v_int);
	}
	if (val->argtype[j] == 'c')
	{
		val->v_char = va_arg(list_pointer, int );
		ft_putchar(val->v_char);
	}
}

void		ft_printf(char *format, ...)
{
	va_list	list_pointer;
	int		i;
	int		j;
	int		numargs;
	char	*tmp;
	t_val	val;

	i = -1;
	tmp = format;
	numargs = ft_strchrn(format, '%');
	va_start(list_pointer, format);
	if (!(val.argtype = malloc(sizeof(char *) * MAX_ARGS + 1)))
		exit(-1);
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
			val.argtype[i] = *++tmp;
			printf (" // argtype[%d] = [%c]\n", i, val.argtype[i]);
		}
		i = -1;
		j = 0;
		while (format[++i])
		{
			if (format[i] == '%')
			{
				printf_type(list_pointer, &val, j++);
				i += 2;
			}
			write(1, &format[i], 1);
		}
	}
	printf("\n");
	va_end(list_pointer);
	free(val.argtype);
}

int			main(void)
{
	int		i;
	char	j;

	i = 5;
	j = 'o';
	ft_printf("salut\n");
	ft_printf("cela doit imprimer 5 = [%d]\n", i);
	ft_printf("test '5' = [%d] et test 'o' = [%c]\n", i, j);
	ft_printf("test '5' = [%d] et test 'o' = [%c] et rebelotte 'o' = [%c]\n", i, j, j);
	ft_printf("test '5' = [%d] et test 'o' = [%c] et rebelotte 'o' = [%c] et encore une fois '5' = [%d]\n", i, j, j, i);
	return (0);
}

//might want to remove ft_strchr.c from the minilib

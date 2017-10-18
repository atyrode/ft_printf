#include "./../includes/ft_printf.h"

void		add_space(t_val *val, int diff)
{
	int 	k;

	k = -1;
	while(++k <= val->int_flag - diff)
		val->buffer = ft_strjoin(val->buffer, " ");
}

int			printf_type(va_list list_pointer, t_val *val, int j)
{
	if (val->argtype[j] == '%')
	{
		(val->yes == 2) ? add_space(val, 1) : 0;
		val->buffer = ft_strjoin(val->buffer, "%");
	}
	else if (val->argtype[j] == 'd' || val->argtype[j] == 'i' || val->argtype[j] == 'D')
	{
		val->v_int = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, ft_strlen(ft_itoa(val->v_int))) : 0;
		val->buffer = ft_strjoin(val->buffer, ft_itoa(val->v_int));
	}
	else if (val->argtype[j] == 'c')
	{
		val->v_char = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, 1) : 0;
		val->buffer = ft_strjoin(val->buffer, &val->v_char);
	}
	else if (val->argtype[j] == 's' || val->argtype[j] == 'S')
	{
		val->v_str = va_arg(list_pointer, char* );
		(val->yes == 2) ? add_space(val, (ft_strlen(val->v_str))) : 0;
		val->buffer = ft_strjoin(val->buffer, val->v_str);
	}
	else if (val->argtype[j] == 'u')
	{
		val->v_int = va_arg(list_pointer, unsigned int );
		(val->yes == 2) ? add_space(val, 0) : 0;
		ft_putnbr(val->v_int);
	}
	else if (val->argtype[j] == 'x' || val->argtype[j] == 'X')
	{
		val->v_int = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, 0) : 0;
		val->char_n += (val->argtype[j] == 'x') ?
		ft_putstr(ft_itoa_base((uintmax_t)(val->v_int), 16, 0)) - 1:
		ft_putstr(ft_itoa_base((uintmax_t)(val->v_int), 16, 1)) - 1;
	}
	/*else if (val->argtype[j] == 'p')
	{
		val->v_ptr = va_arg(list_pointer, void* );
		ft_putstr(ft_itoa_base(val->v_ptr));
	}*/
	return (ft_strlen(val->buffer));
}

int			parse_numbers(char *format, t_val *val)
{
	int		i;

	i = 0 + (val->flag & MINUS);
	while(format[i] != '\0' && ft_isdigit(format[i]))
		i++;
	i -= (val->flag & MINUS);
	val->char_flag = (char *)malloc(sizeof(char) * i + 1);
	i = 0 + (val->flag & MINUS);
	while(format[i] != '\0' && ft_isdigit(format[i]))
	{
		val->char_flag[i - (val->flag & MINUS)] = format[i];
		i++;
	}
	val->int_flag = ft_atoi(val->char_flag) - 1;
	val->char_n += val->int_flag;
	return (i);
}

void		parsing_flags(char *format, t_val *val)
{
	int		i;

	i = 0;
	while(ft_strchr("-+0# ", format[i]))
	{
		format[i] == '-' && !(val->flag & MINUS) ? val->flag += MINUS : 0;
		format[i] == '+' && !(val->flag & PLUS) ? val->flag += PLUS : 0;
		format[i] == '0' && !(val->flag & ZERO) ? val->flag += ZERO : 0;
		format[i] == '#' && !(val->flag & HASHTAG) ? val->flag += HASHTAG : 0;
		format[i] == ' ' && !(val->flag & SPACE) ? val->flag += SPACE : 0;
		if (format[i] == '\0')
			break;
		i++;
	}
}

int		parsing(char *format, t_val *val, va_list list_pointer)
{
	int		i;
	int		i_tmp;
	int		j;

	i = -1;
	j = 0;
	val->flag = 0;
	parsing_flags(format, val);
	while(format[++i] != '\0')
	{
		if (format[i] != '%')
		{
			val->buffer = ft_strjoin(val->buffer, ft_strsub(format, i, 1));
		}
		else
		{
			val->yes = 0;
			i++;
			if (ft_search(format[i], "-0123456789"))
			{
				i_tmp = i;
				i += parse_numbers(format + i, val);
				//printf ("i = %d\n", i);
				if (format[i_tmp] == '-')
					val->yes = 1;
				else
					val->yes = 2;
			}
			val->argtype[j] = format[i];
			val->char_n--;
			printf_type(list_pointer, val, j++);
			(val->yes == 1) ? add_space(val, 0) : 0;
		}
	}
	ft_putstr(val->buffer);
	return (ft_strlen(val->buffer));
}

int			ft_printf(char *format, ...)
{
	va_list	list_pointer;
	int		i;
	t_val	val;

	val.char_n = 0;

	va_start(list_pointer, format);

	if (!(val.argtype = malloc(sizeof(char *) * MAX_ARGS + 1)))
		exit(-1);

	i = parsing(format, &val, list_pointer);

	va_end(list_pointer);
	free(val.argtype);

	return(i);
}

#ifdef MAIN

# define TEST2 "%dsa%5%deed%2% tt %c %10s", 5, 'd', "salut"
# define TEST "%d", 5

int				main(void)
{
	int			ft_len;
	int			len;

	fprintf(stderr, "[");
	ft_len = ft_printf(TEST);
	fprintf(stderr, "]\n\n");
	fprintf(stderr, "[");
	len = fprintf(stderr, TEST);
	fprintf(stderr, "]\n\n");
	printf("\nft_len = %i\n", ft_len);
	printf("\nlen = %i\n", len);
	return (0);
}

#endif

//single % should do something better
//%p is hard
//number flags only works with a single digit for now and no flavor text

//depanner le segfault qui vient du %d et du strjoin/strlen apparement (lldb)

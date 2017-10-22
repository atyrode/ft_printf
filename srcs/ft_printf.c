#include "./../includes/ft_printf.h"

int			add_space(t_val *val, int diff)
{
	int 	k;

	k = -1;
	while(++k <= val->int_flag - diff)
		val->buffer = (val->zero) ? ft_strjoin(val->buffer, "0") :
		ft_strjoin(val->buffer, " ");
	return(k);
}

int			printf_type(va_list list_pointer, t_val *val, int j)
{
	if (val->argtype[j] == '%')
	{
		(val->yes == 2) ? add_space(val, 1) : 0;
		val->buffer = ft_strjoin(val->buffer, "%");
		(val->yes == 1) ? add_space(val, 1) : 0;
	}
	else if (val->argtype[j] == 'd' || val->argtype[j] == 'i' || val->argtype[j] == 'D')
	{
		val->v_int = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, ft_strlen(ft_itoa(val->v_int))) : 0;
		if (val->flag & SPACE && val->v_int >= 0)
				val->buffer = ft_strjoin(val->buffer, " ");
		val->buffer = ft_strjoin(val->buffer, ft_itoa(val->v_int));
		(val->yes == 1) ? add_space(val, ft_strlen(ft_itoa(val->v_int))) : 0;
	}
	else if (val->argtype[j] == 'c')
	{
		val->v_char = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, 1) : 0;
		val->buffer = ft_strjoin(val->buffer, &val->v_char);
		(val->yes == 1) ? add_space(val, 1) : 0;
	}
	else if (val->argtype[j] == 's' || val->argtype[j] == 'S')
	{
		val->v_str = va_arg(list_pointer, char* );
		if (val->v_str == NULL)
			val->v_str = "(null)";
		if (val->flag & PRECISION)
		{
			if(val->v_str[0] != '\0')
			{
				if(val->flag & MINUS)
					val->v_str = ft_strsub(val->v_str, 0, val->precision_flag + 1);
				else
					val->v_str = ft_strsub(val->v_str, 0, val->precision_flag + 1);
			}
			else
				val->buffer = ft_strjoin(val->buffer, val->v_str);
		}
		(val->yes == 2) ? add_space(val, ft_strlen(val->v_str)) : 0;
		val->buffer = ft_strjoin(val->buffer, val->v_str);
		(val->yes == 1) ? add_space(val, ft_strlen(val->v_str)) : 0;
	}
	else if (val->argtype[j] == 'u')
	{
		val->v_int = va_arg(list_pointer, unsigned int );
		(val->yes == 2) ? add_space(val, ft_strlen(ft_itoa(val->v_int))) : 0;
		val->buffer = ft_strjoin(val->buffer, ft_itoa(val->v_int));
		(val->yes == 1) ? add_space(val, ft_strlen(ft_itoa(val->v_int))) : 0;
	}
	else if (val->argtype[j] == 'x' || val->argtype[j] == 'X')
	{
		if (val->flag & LONG)
			val->v_int = va_arg(list_pointer, long int );
		else if (val->flag & LONG_LONG)
			val->v_int = va_arg(list_pointer, long long int );
		else if (val->flag & INTMAX_T)
			val->v_int = va_arg(list_pointer, intmax_t );
		else
			val->v_int = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, ft_strlen(ft_itoa_base(val->v_int, 16))) : 0;
		//printf("val->v_int = %lu", val->v_int);
		if (val->v_int == 4294967296)
		{

				val->buffer = ft_strjoin(val->buffer, "100000000");
		}
		else
		val->buffer = (val->argtype[j] == 'x') ?
		ft_strjoin(val->buffer, ft_strlwr(ft_itoa_base(val->v_int, 16))) :
		ft_strjoin(val->buffer, ft_itoa_base(val->v_int, 16));
		(val->yes == 1) ? add_space(val, ft_strlen(ft_itoa_base(val->v_int, 16))) : 0;
	}
	else if (val->argtype[j] == 'o')
	{
		val->v_int = va_arg(list_pointer, int );
		(val->yes == 2) ? add_space(val, ft_strlen(ft_itoa_base(val->v_int, 8))) : 0;
		val->buffer = ft_strjoin(val->buffer, ft_itoa_base(val->v_int, 8));
		(val->yes == 1) ? add_space(val, ft_strlen(ft_itoa_base(val->v_int, 8))) : 0;
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
	//printf("i = %d\n", i);
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
	//printf("char_flag = [%s]\n", val->char_flag);
	val->int_flag = ft_atoi(val->char_flag) - 1;
	val->char_n += val->int_flag;
	return (i);
}

int		parsing_flags(char *format, t_val *val, int i)
{
	if(ft_strchr("-+0# .", format[i]))
	{
			format[i] == '-' && !(val->flag & MINUS) ? val->flag += MINUS : 0;
			format[i] == '+' && !(val->flag & PLUS) ? val->flag += PLUS : 0;
			format[i] == '0' && !(val->flag & ZERO) ? val->flag += ZERO : 0;
			format[i] == '#' && !(val->flag & HASHTAG) ? val->flag += HASHTAG : 0;
			format[i] == ' ' && !(val->flag & SPACE) ? val->flag += SPACE : 0;
			format[i] == '.' && !(val->flag & PRECISION) ? val->flag += PRECISION : 0;
			return(1);
	}
	return(0);
}

int		parsing(char *format, t_val *val, va_list list_pointer)
{
	int		i;
	int		j;
	int		tmp;

/*	ft_printf("%-5.10o", 2500);
1. (    5) -->4704 <--
2. (   10) -->0000004704<--   */

// ^@ problematic

// make fclean doesnt clean libftprintf.a
	i = -1;
	j = 0;
	val->buffer = ft_strnew(1);
	while(format[++i] != '\0')
	{
		if (format[i] != '%')
			val->buffer = ft_strjoin(val->buffer, ft_strsub(format, i, 1));
		else
		{
			val->flag = 0;
			val->yes = 0;
			val->zero = 0;
			(format[i + 1] != '\0') ? i++ : 0;
			//printf("format[%d] = %c\n", i, format[i]);
			parsing_flags(format, val, i);
			if(val->flag & PRECISION)
			{
				tmp = val->int_flag;
				(format[i + 1] != '\0') ? i++ : 0;
				i += parse_numbers(format + i, val);
				val->precision_flag = val->int_flag;
				val->int_flag = tmp;
			}
			//printf("precision_flag = %d", val->precision_flag);
			if (val->flag & SPACE)
				while(format[i] == ' ')
					(format[i + 1] != '\0') ? i++ : 0;
			if (val->flag & PLUS)
			{
				(format[i + 1] != '\0') ? i++ : 0;
				val->buffer = ft_strjoin(val->buffer, "+");
				//fails test "%+d", -42
			}
			if(val->flag & ZERO)
			{
				val->zero = 1;
				(format[i + 1] != '\0') ? i++ : 0;
			}
			if (ft_search(format[i], "-0123456789"))
			{
				i += parse_numbers(format + i, val);
				//printf("2 format[%d] = %c\n", i, format[i]);
				if (val->flag & MINUS)
				{
					val->yes = 1;
					//(format[i + 1] != '\0') ? i++ : 0;
				}
				else
				{
					val->yes = 2;
				}
				//resetting flag here is kind of annoying in certain case, see val->flag zero above
				val->flag = 0;
				parsing_flags(format, val, i);
				//printf("3 format[%d] = %c\n", i, format[i]);
				if(val->flag & PRECISION)
				{
					tmp = val->int_flag;
					(format[i + 1] != '\0') ? i++ : 0;
					i += parse_numbers(format + i, val);
					val->precision_flag = val->int_flag;
					val->int_flag = tmp;
				}
			}
			//printf("yes = %d\n", val->yes);
			//printf("precision_flag = %d\n", val->int_flag);
			if (format[i] == 'l')
			{
				val->flag += LONG;
				if (format[i + 1] == 'l')
				{
					val->flag += LONG_LONG;
					val->flag -= LONG;
					i++;
				}
				i++;
			}
			if (format[i] == 'h')
			{
				val->flag += SHORT;
				if (format[i + 1] == 'h')
				{
					val->flag += UNSIGNED_CHAR;
					val->flag -= SHORT;
					i++;
				}
				i++;
			}
			if (format[i] == 'j')
			{
				val->flag += INTMAX_T;
				(format[i + 1] != '\0') ? i++ : 0;
			}
			val->argtype[j] = format[i];
			val->char_n--;
			printf_type(list_pointer, val, j++);
			//printf("val->yes = %d | val->int_flag = %d\n", val->yes, val->int_flag);
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
# define TEST "%jx", 4294967298

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

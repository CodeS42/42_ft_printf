#include "../headers/ft_printf.h"

static void	conversions(int i, const char *str, va_list arg, int *count)
{
	if (str[i + 1] == 'c')
		ft_printchar((char)va_arg(arg, int), count);
	else if (str[i + 1] == '%')
		ft_printchar('%', count);
	else if ((str[i + 1] == 'd') || str[i + 1] == 'i')
		ft_putnbr_c(va_arg(arg, int), count);
	else if (str[i + 1] == 'u')
		ft_putnbr_uc(va_arg(arg, unsigned int), count);
	else if (str[i + 1] == 'X' || str[i + 1] == 'x')
		ft_printhexa(va_arg(arg, unsigned int), str[i + 1], count);
	else if (str[i + 1] == 'p')
		ft_printhexa(va_arg(arg, unsigned long long), str[i + 1], count);
	else if (str[i + 1] == 's')
		ft_printstr(va_arg(arg, char *), count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_printchar(str[i], &count);
		if (str[i] == '%')
		{
			conversions(i, str, arg, &count);
			if (str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

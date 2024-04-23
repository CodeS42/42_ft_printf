#include "../headers/ft_printf.h"

void	ft_printchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_printstr(char *s, int *count)
{
	int	j;

	j = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (s[j])
	{
		write(1, &s[j], 1);
		j++;
	}
	*count += j;
}

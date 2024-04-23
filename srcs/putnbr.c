#include "../headers/ft_printf.h"

void	ft_putnbr_c(int nb, int *count)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_printchar('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_c(nbr / 10, count);
	}
	ft_printchar(nbr % 10 + '0', count);
}

void	ft_putnbr_uc(unsigned int nb, int *count)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_printchar('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_uc(nbr / 10, count);
	}
	ft_printchar(nbr % 10 + '0', count);
}

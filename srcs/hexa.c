#include "../headers/ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_putnbr_base_uc(unsigned long long nbr, char *base, int *count)
{
	unsigned int	taillebase;

	taillebase = ft_strlen(base);
	if (ft_valid(base) == 1)
	{
		if (nbr > taillebase - 1)
		{
			ft_putnbr_base_uc((nbr / taillebase), base, count);
			ft_printchar(base[nbr % taillebase], count);
		}
		else if (nbr < taillebase)
			ft_printchar(base[nbr % taillebase], count);
	}
}

void	ft_printhexa(unsigned long long nb, char maj, int *count)
{
	if (maj == 'X')
		ft_putnbr_base_uc(nb, "0123456789ABCDEF", count);
	else if (maj == 'x')
		ft_putnbr_base_uc(nb, "0123456789abcdef", count);
	else if (maj == 'p')
	{
		if (nb == 0)
		{
			write(1, "(nil)", 5);
			*count += 5;
		}
		else
		{
			write(1, "0x", 2);
			*count += 2;
			ft_putnbr_base_uc(nb, "0123456789abcdef", count);
		}
	}
}

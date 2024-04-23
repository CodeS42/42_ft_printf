#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_printhexa(unsigned long long nb, char maj, int *count);
void	ft_printchar(char c, int *count);
void	ft_printstr(char *s, int *count);
void	ft_putnbr_c(int nb, int *count);
void	ft_putnbr_uc(unsigned int nb, int *count);
int		ft_printf(const char *str, ...);

#endif

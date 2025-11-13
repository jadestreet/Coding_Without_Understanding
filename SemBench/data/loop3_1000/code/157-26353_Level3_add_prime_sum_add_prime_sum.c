#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int num)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
	}
}
int		ft_putnum(char *ch)
{
	int num;
	num = 0;
	while (*ch)
	{
		num = num * 10;
		num = num + (*ch - '0');
		ch++;
	}
	return (num);
}
int		ft_is_prime(int n)
{
	int i;
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
void	add_prime_sum(int nbr)
{
	int i;
	int sum;
	i = 2;
	sum = 0;
	while (i <= nbr)
	{
		if (ft_is_prime(i))
		{
			sum = sum + i;
			i++;
		}
		else
			i++;
	}
	ft_putnbr(sum);
}
int		main(int ac, char **av)
{
	if (ac == 2)
	{
		add_prime_sum(ft_putnum(av[1]));
	}
	ft_putchar('\n');
	return (0);
}
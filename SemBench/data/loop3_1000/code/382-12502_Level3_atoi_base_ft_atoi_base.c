#include <unistd.h>
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
int		ft_power_base(char ch, int count, int base)
{
	char	nums[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
						'b', 'c', 'd', 'e', 'f'};
	int		i;
	int		dec;
	int		power;
	i = 0;
	power = 1;
	if (ch >= 'A' && ch <= 'F')
	{
		ch = ch + 32;
	}
	while (i <= 15)
	{
		if (nums[i] == ch)
			dec = i;
		i++;
	}
	while (count > 0)
	{
		power = power * (base);
		count--;
	}
	return (power * dec);
}
int		ft_strlen(const	char *str)
{
	int		i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int		ft_atoi_base(const char *str, int str_base)
{
	int		neg;
	int		len;
	int		dec;
	int		j;
	int		i;
	neg = 0;
	dec = 0;
	i = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	len = ft_strlen(str) - 1;
	j = len;
	while (i <= len)
	{
		dec += (int)ft_power_base(str[i], j, str_base);
		j--;
		i++;
	}
	if (neg)
	{
		ft_putchar('-');
	}
	ft_putnbr(dec);
	return (0);
}
int		main(int ac, const char **av)
{
	int result;
	(void)ac;
	result = ft_atoi_base(av[1], 16);
	ft_putchar('\n');
	return (0);
}
#include "fractol.h"

void	fart_check(char *s)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			write(1, "please call julia with a valid number set\n", 43);
			exit(1);
		}
		if (s[i] == '.')
			flag++;
		i++;
	}
	if (flag > 1)
	{
		write(1, "please call julia with a valid number set\n", 43);
		exit(1);
	}
}

double	fart_loop(char *str, double nmb, int i)
{
	double	flag;

	flag = 10;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			flag = 0.1;
		else if (flag == 10)
		{
			nmb *= 10;
			nmb += str[i] - '0';
		}
		else if (flag != 10)
		{
			nmb += (str[i] - '0') * flag;
			flag *= 0.1;
		}
		i++;
	}
	return (nmb);
}

double	ft_atof(char *str)
{
	double	nmb;
	int		neg;
	int		i;

	fart_check(str);
	i = 0;
	nmb = 0;
	neg = 1;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
	}
	nmb = fart_loop(str, nmb, i);
	return (nmb * neg);
}
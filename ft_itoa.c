#include "push_swap.h"

static int	length(int n)
{
	int	count;
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	i = length(n);
	if (n == -2147483648)
		return ("-2147483648");
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}
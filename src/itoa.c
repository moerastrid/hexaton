#include "../include/hexathon.h"

static int	ft_find(int n, int *min)
{
	int	digitlen;

	digitlen = 0;
	if (n < 0)
	{
		n *= -1;
		*min = 1;
	}
	while (n > 0)
	{
		n /= 10;
		digitlen++;
	}
	return (digitlen);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		min;
	int		digitlen;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	if (n == 0)
		return (strdup("0"));
	min = 0;
	digitlen = ft_find(n, &min);
	s = calloc(digitlen + 1 + min, 1);
	if (s == 0)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	while (digitlen > 0)
	{
		s[digitlen - 1 + min] = (n % 10 + '0');
		n /= 10;
		digitlen--;
	}
	return (s);
}

#include "libft.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	ft_strnstr_comp(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] && i == n)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;

	i = 0;
	if (!*little || big == little || (!*big && !*little))
		return ((char *) big);
	if (ft_strlen(big) < ft_strlen(little) || ft_strlen(little) > len)
		return (0);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
			if (!ft_strnstr_comp(&big[i], &little[0], (len - i)))
				return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*
Error in test 12: 
ft_strnstr(0x55628f243033:
"abcdefgh", "abc", 2): expected: (nil), yours:0x55628f243033
Error in test 21: 
ft_strnstr(0x55628f243046:
"aaxx", "xx", 3): expected: (nil), yours: 0x55628f243048
Error in test 26: 
ft_strnstr(0x7ffce1c3c714:
"abcdef", "abc\375xx", 3): expected: (nil), yours:0x7ffce1c3c714
*/
/*
#include <stdio.h>

int	main(void)
{
	char	*frase;
	char	*str;

	frase = "foo bay bar baz";
	str = "bay";

	printf("%s\n", ft_strnstr(frase, str, 12));
	frase = "abcdefgh";
	str = "abc";
	printf("%s\n", ft_strnstr(frase, str, 2));
	return (0);
}*/

/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i;
	int len;
	char *strcpy;

	i = 0;
	len = 0;
	while(src[len])
		len++;
	strcpy = (char *)malloc(sizeof(strcpy) * (len + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy); 
}

#include <stdio.h>

int	main()
{
	char src[] = "Benan";
	char strcpy[5];

	char *result = ft_strdup(src);
	printf("%s", result);
	return (0);
}
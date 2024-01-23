#include <string.h>

char *ft_strchr(const char *s, int c)
{
	while(*s != '\0')
	{
		if( *s == c)
			return((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);
}

#include <stdio.h>

// Function to find the length of the initial segment of 's' consisting of only characters in 'accept'
size_t ft_strspn(const char *s, const char *accept);

int main() {
    // Example strings
    const char *mainString = "Hello123";
    const char *acceptCharacters = "He";

    // Call the ft_strspn function
    size_t spanLength = ft_strspn(mainString, acceptCharacters);

    // Display the result
    printf("Length of the initial segment of 'mainString' containing only characters from 'acceptCharacters': %zu\n", spanLength);

    return 0;
}

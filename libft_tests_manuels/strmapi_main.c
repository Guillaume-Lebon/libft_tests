#include "strmapi_main.h"

char	ft_print_conv(unsigned int i, char c)
{
	static int count;

	if (++count == 1)
		printf("\n");
	if (c >= 'a' && c <= 'z')
		printf("\ns[%u] : '%c' => '%c'", i, c, c - 32);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c >= 'A' && c <= 'Z')
		printf("\ns[%u] : '%c' => '%c'", i, c, c + 32);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	printf("\ns[%u] : '%c' => '%c'", i, c, c);
	return (c);
}

char	ft_detect_null(char *str)
{
	if (str[0] == 'N'
			&& str[1] == 'U'
			&& str[2] == 'L'
			&& str[3] == 'L'
			&& str[4] == '\0')
		return (1);
	return (0);
}

void	ft_print_explain(void)
{
	printf("## FT_STRMAPI ##\n");
	printf("=> Prototype : char *ft_strmapi(char const *s, char (*f)(unsigned int, char));\n");
	printf("=> Crée avec malloc une nouvelle chaîne de caractères, copie de la chaîne 's' passée au crible de la fonction 'f'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse de la nouvelle chaîne de caractères.\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n\n");
	printf("## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's' : chaîne de caractères à copier. Entrer 'NULL' pour une chaîne nulle.\n");
}

int	main(int argc, char **argv)
{
	int	i;
	char	*str;

	if (argc == 1)
		ft_print_explain();
	if (argc != 2)
		return (0);
	if (ft_detect_null(argv[1]) == 1)
		argv[1] = NULL;
	printf("=> chaîne originelle : %p", argv[1]);
	if (argv[1] != NULL)
		printf(" : '%s\\0'", argv[1]);
	printf("\n");
	printf("\n=> ft_strmapi :");
	printf("\n\n=> nouvelle chaîne : %p", str = ft_strmapi(argv[1], &ft_print_conv));
	if (str != NULL)
	{
		printf(" : '");
		for (i = 0 ; str[i] ; i++)
			printf("%c", str[i]);
		if (str[i] == '\0')
			printf("\\0");
		printf("'");
	}
	printf("\n");
	return (0);
}

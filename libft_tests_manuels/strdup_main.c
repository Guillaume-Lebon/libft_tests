#include "strdup_main.h"

void	ft_print_explain(void)
{
	printf("## FT_STRDUP ##\n");
	printf("=> Prototype : char *strdup(const char *s);\n");
	printf("=> Copie une chaîne de caractères dans un nouvel espace mémoire alloué avec malloc.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse de la nouvelle chaîne.\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's' : chaîne de caractères à copier.\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	size_t	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 2)
		return (0);
	printf("=> chaîne originelle : %p\n - chaîne : '%s\\0'\n - taille : %lu\n\n", argv[1], argv[1], strlen(argv[1]));
	printf("=> ft_strdup : %p", (str = ft_strdup(argv[1])));
	if (str != NULL)
	{
		printf("\n - chaîne : '");
		for (i = 0 ; str[i] ; i++)
			printf("%c", str[i]);
		if (str[i] == '\0')
			printf("\\0");
		printf("'\n - taille : %lu\n\n", i);
	}
	free(str);
	printf("=> strdup : %p", (str = strdup(argv[1])));
	if (str != NULL)
	{
		printf("\n - chaîne : '");
		for (i = 0 ; str[i] ; i++)
			printf("%c", str[i]);
		if (str[i] == '\0')
			printf("\\0");
		printf("'\n - taille : %lu\n", i);
	}
	free(str);
	return (0);
}

#include "strjoin_main.h"

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
	printf("## FT_STRJOIN ##\n");
	printf("=> Prototype : char *ft_strjoin(char const *s1, char const *s2);\n");
	printf("=> Crée avec malloc une nouvelle chaîne de caractères fruit de la concaténation de 's1' et de 's2'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse de la nouvelle chaîne de caractères.\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n\n");
	printf("## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's1' : 1 ère chaîne de caractères. Entrer 'NULL' pour une chaîne nulle.\n");
	printf("=> Paramètre 2 : 's2' : 2 ème chaîne de caractères. Entrer 'NULL' pour une chaîne nulle.\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	if (ft_detect_null(argv[1]) == 1)
		argv[1] = NULL;
	if (ft_detect_null(argv[2]) == 1)
		argv[2] = NULL;
	printf("=> s1 : %p", argv[1]);
	if (argv[1] != NULL)
	{
		printf(" : '");
		for (i = 0 ; argv[1][i] ; i++)
			printf("%c", argv[1][i]);
		if (argv[1][i] == '\0')
			printf("\\0");
		printf("'");
	}
	printf("\n=> s2 : %p", argv[2]);
	if (argv[2] != NULL)
	{
		printf(" : '");
		for (i = 0 ; argv[2][i] ; i++)
			printf("%c", argv[2][i]);
		if (argv[2][i] == '\0')
			printf("\\0");
		printf("'");
	}
	printf("\n\n=> chaîne finale : %p", str = ft_strjoin(argv[1], argv[2]));
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

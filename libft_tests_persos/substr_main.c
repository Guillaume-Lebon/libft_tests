#include "substr_main.h"

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
	printf("## FT_SUBSTR ##\n");
	printf("=> Prototype : char *ft_substr(char const *s, unsigned int start, size_t len);\n");
	printf("=> Crée avec malloc une nouvelle chaîne de caractères à partir de la chaîne 's'.\n");
	printf("=> La nouvelle chaîne est une copie de 's' à partir de l'indice 'start' et de taille maximale 'len'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse de la nouvelle chaîne de caractères.\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n\n");
	printf("## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's' : chaîne de caractères à copier.\n");
	printf("=> Paramètre 2 : 'start' : numéro du caractère de 's' à partir duquel copier.\n");
	printf("=> Paramètre 3 : 'len' : taille maximale de la copie.\n");
}

int	main(int argc, char **argv)
{
	unsigned int	start;
	unsigned int	len;
	int		i;
	char		*str;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	start = atoi(argv[2]);
	len = atoi(argv[3]);
	if (ft_detect_null(argv[1]) == 1)
		argv[1] = NULL;
	if (argv[1] != NULL)
	{
		printf("=> s : '%s\\0'\n\n", argv[1]);
		for (i = 0 ; argv[1][i] ; i++)
			printf("s[%d] : '%c'\n", i, argv[1][i]);
		printf("s[%d] : '\\0'\n\n", i);
	}
	else
		printf("=> s : %p\n\n", argv[1]);
	printf("=> start : %u\n", start);
	printf("=> len : %u\n\n", len);
	printf("=> ft_substr : %p\n", str = ft_substr(argv[1], start, len));
	if (str != NULL)
	{
		printf(" - str : '");
		for (i = 0 ; str[i] ; i++)
			printf("%c", str[i]);
		if (str[i] == '\0')
			printf("\\0");
		printf("'\n - taille : %lu + 1 '\\0'\n", strlen(str));
	}
	return (0);
}

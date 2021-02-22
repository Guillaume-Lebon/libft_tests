#include "split_main.h"

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
	printf("## FT_SPLIT ##\n");
	printf("=> Prototype : char **ft_split(char const *s, char c);\n");
	printf("=> Découpe la chaîne de caractères 's' en fonction du caractère 'c'.\n");
	printf("=> Crée un tableau dont chaque ligne est un morceau de 's' ainsi découpée.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse du tableau de chaîne(s) de caractère(s).\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n\n");
	printf("## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's' : chaîne de caractères à découper. Entrer 'NULL' pour une chaîne nulle.\n");
	printf("=> Paramètre 2 : 'c' : caractère de découpage.\n");
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	**tab;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	if (ft_detect_null(argv[1]) == 1)
		argv[1] = NULL;
	printf("=> s : %p", argv[1]);
	if (argv[1] != NULL)
		printf(" : '%s\\0'", argv[1]);
	printf("\n=> c : '%c'\n\n=> ft_split : %p", argv[2][0], tab = ft_split(argv[1], argv[2][0]));
	if (tab != NULL)
	{
		for (i = 0 ; tab[i] != NULL ; i++)
		{
			printf("\ntab[%d] : %p : '", i, tab[i]);
			for (j = 0 ; tab[i][j] ; j++)
				printf("%c", tab[i][j]);
			if (tab[i][j] == '\0')
				printf("\\0");
			printf("'");
		}
		printf("\ntab[%d] : %p", i, tab[i]);
	}
	printf("\n");
	return (0);
}

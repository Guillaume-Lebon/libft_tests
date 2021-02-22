#include "strrchr_main.h"

void	ft_print_explain(void)
{
	printf("## FT_STRRCHR ##\n");
	printf("=> Prototype : char *strrchr(const char *s, int c);\n");
	printf("=> Recherche dans la chaîne de caractères 's' la dernière occurence du caractère 'c'.\n");
	printf("=> Valeurs retournées.\n");
	printf(" - Si 'c' est trouvé dans 's' : retourne l'adresse de 'c' dans 's'.\n");
	printf(" - Si 'c' n'est pas trouvé dans 's' : retourne 'NULL'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's' : chaîne de caractères à analyser.\n");
	printf("=> Paramètre 2 : 'c' : caractère ou valeur à rechercher dans 's'.\n");
	printf("=> Paramètre 3 : 'c' si le paramètre 2 est un caractère. 'v' s'il s'agit d'une valeur numérique.\n");
}

int	main(int argc, char **argv)
{
	int c;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	for (c = 0 ; argv[1][c] ; c++)
		printf("s[%d] = %c / %p\n", c, argv[1][c], &(argv[1][c]));
	printf("s[%d] = %c / %p\n\n", c, argv[1][c], &(argv[1][c]));
	c = 0;
	if (argv[3][0] == 'c')
		c = argv[2][0];
	else if (argv[3][0] == 'v')
		c = atoi(argv[2]);
	printf("=> ft_strrchr : %p\n", ft_strrchr(argv[1], c));
	printf("=>    strrchr : %p\n", strrchr(argv[1], c));
	return (0);
}

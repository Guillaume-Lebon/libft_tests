#include "strnstr_main.h"

void	ft_print_explain(void)
{
	printf("## FT_STRNSTR ##\n");
	printf("=> Prototype : char *strnstr(const char *big, const char *little, size_t len);\n");
	printf("=> Recherche la première occurence de la chaîne de caractères 'little' dans la chaîne de caractères 'big'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - Si 'little' est vide : retourne 'big'.\n");
	printf(" - Si 'little' est dans 'big' : retourne l'adresse de la première occurence de 'little' dans 'big'.\n");
	printf(" - Si 'little' n'est pas dans 'big' : retourne 'NULL'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'big' : chaîne de caractères dans laquelle rechercher 'little'.\n");
	printf("=> Paramètre 2 : 'little' : chaîne de caractères à rechercher dans 'big'.\n");
	printf("=> Paramètre 3 : 'n' : nombre de caractères de 'big' à analyser.\n");
}

int	main(int argc, char **argv)
{
	size_t	n;
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	printf("=> big : %p : '%s'\n\n", argv[1], argv[1]);
	for (i = 0 ; argv[1][i] ; i++)
		printf("big[%d] : %c : %p\n", i, argv[1][i], &(argv[1][i]));
	printf("\n=> little : %p : '%s'\n", argv[2], argv[2]);
	n = atoi(argv[3]);
	printf("\n=> ft_strnstr : %p\n", ft_strnstr(argv[1], argv[2], n));
	printf("=>    strnstr : %p\n", strnstr(argv[1], argv[2], n));
	return (0);
}

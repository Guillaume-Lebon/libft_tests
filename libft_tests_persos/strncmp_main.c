#include "strncmp_main.h"

void	ft_print_explain(void)
{
	printf("## FT_STRNCMP ##\n");
	printf("=> Prototype : int strncmp(const char *s1, const char *s2, size_t n);\n");
	printf("=> Compare les 'n' premiers caractères des chaînes de caractères 's1' et 's2'.\n");
	printf("=> Valeurs retournées.\n");
	printf(" - Si 's1' > 's2' : retourne un entier positif non nul.\n");
	printf(" - Si 's1' == 's2' : retourne zéro.\n");
	printf(" - Si 's1' < 's2' : retourne un entier négatif non nul.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's1' : chaîne de caractères à comparer à 's2'.\n");
	printf("=> Paramètre 2 : 's2' : chaîne de caractères à comparer à 's1'.\n");
	printf("=> Paramètre 3 : 'n' : nombre de caractères à comparer.\n");
}

int	main(int argc, char **argv)
{
	size_t n;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	n = atoi(argv[3]);
	printf("=> s1 : '%s\\0'\n", argv[1]);
	printf("=> s2 : '%s\\0'\n", argv[2]);
	printf("=>  n : %lu\n\n", n);
	printf("=> ft_strncmp : %d\n", ft_strncmp(argv[1], argv[2], n));
	printf("=>    strncmp : %d\n", strncmp(argv[1], argv[2], n));
	return (0);
}

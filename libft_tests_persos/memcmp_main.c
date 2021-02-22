#include "memcmp_main.h"

void	ft_print_explain(void)
{
	printf("## FT_MEMCMP ##\n");
	printf("=> Prototype : int memcmp(const void *s1, const void *s2, size_t n);\n");
	printf("=> Compare les 'n' premiers bytes des zones mémoire 's1' et 's2'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - Si 's1' > 's2' : retourne un entier positif non nul.\n");
	printf(" - Si 's1' == 's2' : retourne zéro.\n");
	printf(" - Si 's1' < 's2' : retourne un entier négatif non nul.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 's1' : chaîne de caractères à comparer avec 's2'.\n");
	printf("- Paramètre 2 : 's2' : chaîne de caractères à comparer avec 's1'.\n");
	printf("- Paramètre 3 : 'n' : nombre de bytes à comparer.\n");
}

int	main(int argc, char **argv)
{
	char	s1[100];
	char	s2[100];
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	strcpy(s1, argv[1]);
	strcpy(s2, argv[2]);
	printf("=> s1 : '");
	for (i = 0 ; i < 100 ; i++)
		printf("%c", s1[i]);
	printf("'\n");
	printf("=> s2 : '");
	for (i = 0 ; i < 100 ; i++)
		printf("%c", s2[i]);
	printf("'\n\n");
	printf("=> ft_memcmp : %d\n", ft_memcmp(s1, s2, atoi(argv[3])));
	printf("=>    memcmp : %d\n", memcmp(s1, s2, atoi(argv[3])));
	return (0);
}

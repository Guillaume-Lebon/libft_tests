#include "memchr_main.h"

void	ft_print_explain(void)
{
	printf("## FT_MEMCHR ##\n");
	printf("=> Prototype : void *memchr(const void *s, int c, size_t n);\n");
	printf("=> Scanne 'n' bytes de la zone mémoire 's' à la recherche du caractère 'c'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - Si 'c' est trouvé dans 's' : retourne l'adresse de 'c' dans 's'.\n");
	printf(" - Si 'c' n'est pas trouvé dans 's' : retourne 'NULL'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 's' : chaîne de caractères à scanner.\n");
	printf("- Paramètre 2 : 'c' : caractère à rechercher dans 's'.\n");
	printf("- Paramètre 3 : 'n' : nombre de caractères de 's' à scanner.\n");
}

int	main(int argc, char **argv)
{
	int	i;
	size_t	n;
	int	size;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	n = atoi(argv[3]);
	size = 0;
	for (i = 0 ; argv[1][i] ; i++)
		++size;
	for (i = 0 ; argv[2][i] ; i++)
		++size;
	size += 2;
	for (i = 0 ; i < size ; i++)
	{
		if (argv[1][i] == '\0')
			printf("s[%d] : '\\0' : %p\n", i, &(argv[1][i]));
		else
			printf("s[%d] : '%c' : %p\n", i, argv[1][i], &(argv[1][i]));
	}
	printf("\n=> ft_memchr : %p\n", ft_memchr(argv[1], argv[2][0], n));
	printf("=>    memchr : %p\n", memchr(argv[1], argv[2][0], n));
	return (0);
}

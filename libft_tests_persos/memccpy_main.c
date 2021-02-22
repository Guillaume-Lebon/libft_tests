#include "memccpy_main.h"

void	ft_supp_end(char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	s[i] = '.';
}

void	ft_print_explain(void)
{
	printf("## FT_MEMCCPY ##\n");
	printf("=> Prototype : void *memccpy(void *dest, const void *src, int c, size_t n);\n");
	printf("=> Copie la zone mémoire 'src' dans la zone mémoire 'dest'.\n");
	printf("=> Copie 'n' bytes, ou jusqu'à trouver le caractère 'c' dans 'src'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - Si 'c' est trouvé dans 'src' : retourne l'adresse dans 'dest' du caractère suivant.\n");
	printf(" - Si 'c' n'est pas trouvé dans 'src' : retourne 'NULL'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 'src' : chaîne de caractères à copier.\n");
	printf("- Paramètre 2 : 'dest' : chaîne de caractères dans laquelle copier 'src'.\n");
	printf("- Paramètre 3 : 'c' : caractère de 'src' jusqu'auquel copier 'src' dans 'dest'.\n");
	printf("- Paramètre 4 : 'n' : nombre de caractères de 'src' à copier dans 'dest'.\n");
}

int	main(int argc, char **argv)
{
	char	src[100];
	char	dest1[100];
	char	dest2[100];
	char	*car;
	size_t	n;
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 5)
		return (0);
	n = atoi(argv[4]);
	memset(src, '.', 100);
	memset(dest1, '.', 100);
	memset(dest2, '.', 100);
	strcpy(src, argv[1]);
	strcpy(dest1, argv[2]);
	strcpy(dest2, argv[2]);
	ft_supp_end(src);
	ft_supp_end(dest1);
	ft_supp_end(dest2);
	printf("## AVANT ##\n");
	printf("=>   src : %p : '", src);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", src[i]);
	printf("'\n");
	printf("=> dest1 : %p : '", dest1);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", dest1[i]);
	printf("'\n");
	printf("=> dest2 : %p : '", dest2);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", dest2[i]);
	printf("'\n\n");
	printf("## APRES ##\n");
	printf("=> ft_memccpy : car + 1 : %p : dest1 : '", (car = ft_memccpy(dest1, src, argv[3][0], n)));
	for (i = 0 ; i < 100 ; i++)
		printf("%c", dest1[i]);
	printf("'\n");
	printf("=>    memccpy : car + 1 : %p : dest2 : '", (car = memccpy(dest2, src, argv[3][0], n)));
	for (i = 0 ; i < 100 ; i++)
		printf("%c", dest2[i]);
	printf("'\n");
	if (car != NULL)
	{
		printf("\n=> dest1 :\n");
		for (i = 0 ; i < 100 ; i++)
			printf("'%c' : %p\n", dest1[i], &(dest1[i]));
		printf("\n");
	}
	if (car != NULL)
	{
		printf("\n=> dest2 :\n");
		for (i = 0 ; i < 100 ; i++)
			printf("'%c' : %p\n", dest2[i], &(dest2[i]));
	}
	return (0);
}

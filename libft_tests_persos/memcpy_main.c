#include "memcpy_main.h"

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
	printf("## FT_MEMCPY ##\n");
	printf("=> Prototype : void *memcpy(void *dest, const void *src, size_t n);\n");
	printf("=> Copie 'n' bytes de la zone mémoire 'src' dans la zone mémoire 'dest'.\n");
	printf("=> Valeur retournée :\n");
	printf(" - Adresse de 'dest'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 'src' : chaîne de caractères à copier.\n");
	printf("- Paramètre 2 : 'dest' : chaîne de caractères dans laquelle copier 'src'.\n");
	printf("- Paramètre 3 : 'n' : nombre de caractères de 'src' à copier dans 'dest'.\n");
}

int	main(int argc, char **argv)
{
	char	src[100];
	char	dest1[100];
	char	dest2[100];
	size_t	n;
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	n = atoi(argv[3]);
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
	printf("=> ft_memcpy : dest1 : %p : '", ft_memcpy(dest1, src, n));
	for (i = 0 ; i < 100 ; i++)
		printf("%c", dest1[i]);
	printf("'\n");
	printf("=>    memcpy : dest2 : %p : '", memcpy(dest2, src, n));
	for (i = 0 ; i < 100 ; i++)
		printf("%c", dest2[i]);
	printf("'\n");
	return (0);
}

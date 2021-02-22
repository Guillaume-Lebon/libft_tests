#include "memset_main.h"

void	ft_print_explain(void)
{
	printf("## FT_MEMSET ##\n");
	printf("=> Prototype : void *memset(void *s, int c, size_t n);\n");
	printf("=> Remplit 'n' bytes de la zone mémoire 's' avec le caractère 'c'.\n");
	printf("=> Valeur retournée :\n");
	printf(" - Adresse de 's'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 's' : chaîne de caractères à remplir.\n");
	printf("- Paramètre 2 : 'c' : caractère avec lequel remplir 's'.\n");
	printf("- Paramètre 3 : 'n' : nombre de copies de 'c' dans 's'.\n");
}

void	ft_supp_end(char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	s[i] = '.';
}

int	main(int argc, char **argv)
{
	char	s1[100];
	char	s2[100];
	int	i;
	size_t	n;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	memset(s1, '.', 100);
	memset(s2, '.', 100);
	strcpy(s1, argv[1]);
	strcpy(s2, argv[1]);
	ft_supp_end(s1);
	ft_supp_end(s2);
	n = atoi(argv[3]);
	printf("## AVANT ##\n");
	printf("=> s1 : %p : '", s1);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", s1[i]);
	printf("'\n");
	printf("=> s2 : %p : '", s2);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", s2[i]);
	printf("'\n\n");
	printf("## APRES ##\n");
	printf("=> ft_memset : s1 : %p : '", ft_memset(s1, argv[2][0], n));
	for(i = 0 ; i < 100 ; i++)
		printf("%c", s1[i]);
	printf("'\n");
	printf("=>    memset : s2 : %p : '", memset(s2, argv[2][0], n));
	for(i = 0 ; i < 100; i++)
		printf("%c", s2[i]);
	printf("'\n");
	return (0);
}

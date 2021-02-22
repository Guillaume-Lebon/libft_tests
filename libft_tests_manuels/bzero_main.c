#include "bzero_main.h"

void	ft_print_explain(void)
{
	printf("## FT_BZERO ##\n");
	printf("=> Prototype : void bzero(void *s, size_t n);\n");
	printf("=> Remplit 'n' bytes de la zone mémoire 's' avec des '\\0'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 's' : chaîne de caractères à remplir.\n");
	printf("- Paramètre 2 : 'n' : nombre de '\\0' à copier dans 's'.\n");
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
	size_t	n;
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	memset(s1, '.', 100);
	memset(s2, '.', 100);
	strcpy(s1, argv[1]);
	strcpy(s2, argv[1]);
	ft_supp_end(s1);
	ft_supp_end(s2);
	n = atoi(argv[2]);
	printf(">>> AVANT >>>\n=> s1 : '");
	for(i = 0 ; i < 100 ; i++)
		printf("%c", s1[i]);
	printf("'\n");
	printf("=> s2 : '");
	for(i = 0 ; i < 100 ; i++)
		printf("%c", s2[i]);
	printf("'\n\n");
	ft_bzero(s1, n);
	bzero(s2, n);
	printf(">>> APRES >>>\n=> ft_bzero : s1 : '");
	for(i = 0 ; i < 100 ; i++)
	{
		if (s1[i] == 0)
			printf("0");
		else
			printf("%c", s1[i]);
	}
	printf("'\n");
	printf("=>    bzero : s2 : '");
	for(i = 0 ; i < 100 ; i++)
	{
		if (s2[i] == 0)
			printf("0");
		else
			printf("%c", s2[i]);
	}
	printf("'\n");
	return (0);
}

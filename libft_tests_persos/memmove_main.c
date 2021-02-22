#include "memmove_main.h"

void	ft_print_explain(void)
{
	printf("## FT_MEMMOVE ##\n");
	printf("=> Prototype : void *memmove(void *dest, const void *src, size_t n);\n");
	printf("=> Copie 'n' bytes de la zone mémoire 'src' dans la zone mémoire 'dest'.\n");
	printf("=> Les 2 zones mémoire peuvent se chevaucher.\n");
	printf("=> Valeur retournée :\n");
	printf(" - Adresse de 'dest'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 'src' : 1 ère chaîne de caractères.\n");
	printf("- Paramètre 2 : 'dest' : numéro du caractère de 'src' où commence 'dest'.\n");
	printf("- Paramètre 3 : 'n' : nombre de caractères de 'src' à copier dans 'dest'.\n");
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
	size_t		n;
	unsigned int	i;
	unsigned int	j;
	char		src1[100];
	char		src2[100];
	char		*dest1;
	char		*dest2;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	n = atoi(argv[3]);
	j = atoi(argv[2]);
	if (j == 0)
		return (0);
	memset(src1, '.', 100);
	memset(src2, '.', 100);
	strcpy(src1, argv[1]);
	strcpy(src2, argv[1]);
	ft_supp_end(src1);
	ft_supp_end(src2);
	dest1 = &(src1[j - 1]);
	dest2 = &(src2[j - 1]);
	printf("## AVANT ##\n");
	printf("=>  src1 : %p : '", src1);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", src1[i]);
	printf("'\n");
	printf("=> dest1 : %p : ", dest1);
	for (i = 0 ; i < j - 1 ; i++)
		printf(" ");
	printf("'");
	for (i = 0 ; i < 50 ; i++)
		printf("%c", dest1[i]);
	printf("'\n\n");
	printf("=>  src2 : %p : '", src2);
	for (i = 0 ; i < 100 ; i++)
		printf("%c", src2[i]);
	printf("'\n");
	printf("=> dest2 : %p : ", dest2);
	for (i = 0 ; i < j - 1 ; i++)
		printf(" ");
	printf("'");
	for (i = 0 ; i < 50 ; i++)
		printf("%c", dest2[i]);
	printf("'\n\n## APRES ##\n");
	printf("=> ft_memmove : dest1 : %p : '", ft_memmove(dest1, src1, n));
	for (i = 0 ; i < 50 ; i++)
		printf("%c", dest1[i]);
	printf("'\n");
	printf("=>    memmove : dest2 : %p : '", memmove(dest2, src2, n));
	for (i = 0 ; i < 50 ; i++)
		printf("%c", dest2[i]);
	printf("'\n");
	return (0);
}

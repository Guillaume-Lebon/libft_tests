#include "itoa_main.h"

void	ft_print_explain(void)
{
	printf("## FT_ITOA ##\n");
	printf("=> Prototype : char *ft_itoa(int n);\n");
	printf("=> Convertit un int en chaîne de caractères.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse de la chaîne de caractère(s) représentant l'int.\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n\n");
	printf("## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'n' : valeur à convertir en chaîne de caractère(s).\n\n");
	printf("## VALEURS LIMITES ##\n");
	printf("=> INT_MAX : %d\n", INT_MAX);
	printf("=> INT_MIN : %d\n", INT_MIN);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	char	*str;

	if (argc == 1)
		ft_print_explain();
	if (argc != 2)
		return (0);
	n = atoi(argv[1]);
	printf("=> nombre à convertir : %d\n\n", n);
	printf("=> ft_itoa : %p", str = ft_itoa(n));
	if (str != NULL)
	{
		printf(" : '");
		for (i = 0 ; str[i] ; i++)
			printf("%c", str[i]);
		if (str[i] == '\0')
			printf("\\0");
		printf("'");
	}
	printf("\n");
	return (0);
}

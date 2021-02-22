#include "atoi_main.h"

void	ft_print_explain(void)
{
	printf("## FT_ATOI ##\n");
	printf("=> Prototype : int atoi(const char *nptr);\n");
	printf("=> Convertit la chaîne de caractères 'nptr' en valeur numérique de type 'int'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - La chaîne de caractères convertie en 'int'.\n");
	printf(" - Zéro s'il n'y a rien à convertir.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'nptr' : chaîne de caractères à convertir en 'int'.\n");
	printf("=> Paramètre 2 : '1' rajoute les espaces '\\t' '\\v' '\\n' '\\f' '\\r' et ' ' au paramètre 1.\n");
	printf("\n## VALEURS LIMITES ##\n");
	printf("=> INT_MAX : %d\n", INT_MAX);
	printf("=> INT_MIN : %d\n", INT_MIN);
}

int	main(int argc, char **argv)
{
	char	str[50];
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	memset(str, '.', 50);
	if (argv[2][0] == '1')
	{
		str[0] = '\t';
		str[1] = '\v';
		str[2] = '\n';
		str[3] = '\f';
		str[4] = '\r';
		str[5] = ' ';
		strcpy(str + 6, argv[1]);
	}
	else
		strcpy(str, argv[1]);
	printf("=> nptr : '");
	for (i = 0 ; str[i] ; i++)
	{
		if (str[i] == '\t')
			printf("\\t");
		else if (str[i] == '\v')
			printf("\\v");
		else if (str[i] == '\n')
			printf("\\n");
		else if (str[i] == '\f')
			printf("\\f");
		else if (str[i] == '\r')
			printf("\\r");
		else
			printf("%c", str[i]);
	}
	printf("'\n\n");
	printf("=> ft_atoi : %d\n", ft_atoi(str));
	printf("=>    atoi : %d\n", atoi(str));
	return (0);
}

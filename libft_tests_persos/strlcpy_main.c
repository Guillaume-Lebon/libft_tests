#include "strlcpy_main.h"

void	ft_print_explain(void)
{
	printf("## FT_STRLCPY ##\n");
	printf("=> Prototype : size_t strlcpy(char *dst, const char *src, size_t size);\n");
	printf("=> Copie 'size - 1' caractères de la chaîne 'src' dans la chaîne 'dest' + '\\0' de fin.\n");
	printf("=> Valeur retournée :\n");
	printf(" - Taille de 'src'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'src' : chaîne de caractères à copier.\n");
	printf("=> Paramètre 2 : 'dest' : chaîne de caractères dans laquelle copier 'src'.\n");
	printf("=> Paramètre 3 : 'size' : nombre de caractères de 'src' (comprenant le '\\0' de fin) à copier dans 'dest'.\n");
}

int	main(int argc, char **argv)
{
	char	dest1[100];
	char	dest2[100];
	size_t	n;
	int	i;

	if (argc == 1)
		ft_print_explain();
	if (argc != 4)
		return (0);
	memset(dest1, '.', 100);
	memset(dest2, '.', 100);
	strcpy(dest1, argv[2]);
	strcpy(dest2, argv[2]);
	n = atoi(argv[3]);
	printf("## AVANT ##\n");
	printf("=>   src : %p : '%s\\0'\n", argv[1], argv[1]);
	printf("=> dest1 : %p : '", dest1);
	for (i = 0 ; i < 100 ; i++)
	{
		if (dest1[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest1[i]);
	}
	printf("'\n");
	printf("=> dest2 : %p : '", dest2);
	for (i = 0 ; i < 100 ; i++)
	{
		if (dest2[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest2[i]);
	}
	printf("'\n\n");
	printf("## APRES ##\n");
	printf("=> ft_strlcpy : %lu : dest1 : %p : '", ft_strlcpy(dest1, argv[1], n), dest1);
	for (i = 0 ; i < 100 ; i++)
	{
		if (dest1[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest1[i]);
	}
	printf("'\n");
	printf("=>    strlcpy : %lu : dest2 : %p : '", strlcpy(dest2, argv[1], n), dest2);
	for (i = 0 ; i < 100 ; i++)
	{
		if (dest2[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest2[i]);
	}
	printf("'\n");
	return (0);
}

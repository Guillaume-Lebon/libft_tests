#include "strtrim_main.h"

char	ft_detect_null(char *str)
{
	if (str[0] == 'N'
			&& str[1] == 'U'
			&& str[2] == 'L'
			&& str[3] == 'L'
			&& str[4] == '\0')
		return (1);
	return (0);
}

void	ft_print_explain(void)
{
	printf("## FT_STRTRIM ##\n");
	printf("=> Prototype : char *ft_strtrim(char const *s1, char const *set);\n");
	printf("=> Crée avec malloc une nouvelle chaîne de caractères, copie de la chaîne 's1' dont le début et la fin ont été trimmés en fonction des caractères contenus dans 'set'.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse de la nouvelle chaîne de caractères.\n");
	printf(" - 'NULL' en cas d'erreur de malloc.\n\n");
	printf("## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's1' : chaîne de caractères à trimmer. Entrer 'NULL' pour une chaîne nulle.\n");
	printf("=> Paramètre 2 : 'set' : caractères à supprimer au début et à la fin de 's1'. Entrer 'NULL' pour une chaîne nulle.\n");
}

int	main(int argc, char **argv)
{
	int	i;
	char	*str;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	if (ft_detect_null(argv[1]) == 1)
		argv[1] = NULL;
	if (ft_detect_null(argv[2]) == 1)
		argv[2] = NULL;
	printf("=> chaîne : %p", argv[1]);
	if (argv[1] != NULL)
		printf(" : '%s\\0'", argv[1]);
	printf("\n=>    set : %p", argv[2]);
	if (argv[2] != NULL)
		printf(" : '%s\\0'", argv[2]);
	printf("\n\n=> ft_strtrim : %p", str = ft_strtrim(argv[1], argv[2]));
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

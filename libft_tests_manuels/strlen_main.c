#include "strlen_main.h"

void	ft_print_explain(void)
{
	printf("## FT_STRLEN ##\n");
	printf("=> Prototype : size_t strlen(const char *s);\n");
	printf("=> Compte le nombre de caractères contenus dans la chaîne de caractères 's'.\n");
	printf("=> Valeur retournée :\n");
	printf(" - Nombre de caractères.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("- Paramètre 1 : 's' : chaîne de caractères à mesurer.\n");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_print_explain();
	if (argc != 2)
		return (0);
	printf("=> s : '%s'\n\n", argv[1]);
	printf("=> ft_strlen : %lu\n", ft_strlen(argv[1]));
	printf("=>    strlen : %lu\n", strlen(argv[1]));
	return (0);
}

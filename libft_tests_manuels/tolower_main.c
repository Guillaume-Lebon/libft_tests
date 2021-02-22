#include "tolower_main.h"

char	ft_detect_all(char *str)
{
	if (str[0] == 'A'
			&& str[1] == 'L'
			&& str[2] == 'L'
			&& str[3] == '\0')
		return (1);
	return (0);
}

void	ft_print_explain(void)
{
	printf("## FT_TOLOWER ##\n");
	printf("=> Prototype : int tolower(int c);\n");
	printf("=> Convertit la valeur 'c' en minuscule si 'c' correspond, sur la table ASCII, à un caractère alphabétique majuscule.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - Si 'c' correspond à un caractère alphabétique majuscule : retourne sa valeur minuscule.\n");
	printf(" - Si 'c' ne correspond pas à un caractère alphabétique majuscule : retourne 'c'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'c' : caractère ou valeur à analyser. Entrer uniquement 'ALL' teste toutes les valeurs entre -1 et +255.\n");
	printf("=> Paramètre 2 : 'c' si le paramètre 1 est un caractère. 'v' s'il s'agit d'une valeur numérique.\n");
}

int	main(int argc, char **argv)
{
	int c;
	int i;

	if (argc == 1)
		ft_print_explain();
	if (!((argc == 2 && ft_detect_all(argv[1]) == 1) || argc == 3))
		return (0);
	if (argc == 3)
	{
		c = 0;
		if (argv[2][0] == 'c')
			c = argv[1][0];
		else if (argv[2][0] == 'v')
			c = atoi(argv[1]);
		if (argv[2][0] == 'c')
			printf(" ► Caractère : %c\n", c);
		else if (argv[2][0] == 'v')
			printf(" ► Valeur : %d\n", c);
		printf("=> ft_tolower : %d\n", ft_tolower(c));
		printf("=>    tolower : %d\n", tolower(c));
	}
	if (argc == 2 && ft_detect_all(argv[1]) == 1)
	{
		for (i = -1 ; i <= 255 ; i++)
		{
			printf(" ► Valeur : %d\n", i);
			printf("=> ft_tolower : %d\n", ft_tolower(i));
			printf("=>    tolower : %d\n", tolower(i));
			if (tolower(i) != ft_tolower(i))
				printf("=> ERREUR !!!\n");
			if (i != 255)
				printf("\n");
		}
	}
	return (0);
}
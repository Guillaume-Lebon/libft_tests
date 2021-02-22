#include "calloc_main.h"

void	ft_print_explain(void)
{
	printf("## FT_CALLOC ##\n");
	printf("=> Prototype : void *calloc(size_t nmemb, size_t size);\n");
	printf("=> Alloue un espace mémoire pour 'nmemb' elements ayant chacun une taille de 'size'.\n");
	printf("=> Initialise chaque byte de l'espace mémoire alloué en lui attribuant la valeur zéro.\n");
	printf("=> Valeurs retournées :\n");
	printf(" - L'adresse du premier byte de l'espace mémoire alloué.\n");
	printf(" - 'NULL' ou une adresse unique que l'on peut free() s'il n'y a rien à allouer ('nmemb' == 0 || 'size' == 0) ou en cas d'erreur de malloc.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'nmemb' : nombre d'éléments.\n");
	printf("=> Paramètre 2 : 'size' : taille de chaque élément.\n");
}

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*add;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	k = i;
	k *= j;
	printf("=> Nombre d'éléments : %lu\n=> Taille de chaque élément : %lu\n=> Espace total à allouer : %lu\n\n", i, j, k);
	printf("=> ft_calloc : %p\n", (add = (char *)ft_calloc(i, j)));
	if (add != NULL)
	{
		for (l = 0 ; l < k ; l++)
			printf("add[%lu] : %p / %d\n", l, (add + l), add[l]);
	}
	free(add);
	printf("\n=>    calloc : %p\n", (add = (char *)calloc(i, j)));
	if (add != NULL)
	{
		for (l = 0 ; l < k ; l++)
			printf("add[%lu] : %p / %d\n", l, (add + l), add[l]);
	}
	free(add);
	return (0);
}

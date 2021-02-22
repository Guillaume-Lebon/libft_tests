#include "putnbr_fd_main.h"

void	ft_print_explain(void)
{
	printf("## FT_PUTNBR_FD ##\n");
	printf("=> Prototype : void ft_putnbr_fd(int n, int fd);\n");
	printf("=> Ecrit avec 'write' l'int 'n' dans le fichier correspondant au file descriptor 'fd'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'n' : nombre à écrire dans le fichier.\n");
	printf("\n## VALEURS LIMITES ##\n");
	printf("=> INT_MAX = %d\n", INT_MAX);
	printf("=> INT_MIN = %d\n", INT_MIN);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	nbr;
	char	c;

	if (argc == 1)
		ft_print_explain();
	if (argc != 2)
		return (0);
	nbr = atoi(argv[1]);
	printf("=> nombre à écrire dans le fichier : %d\n", nbr);
	fd = open("putnbr_fd.txt", O_WRONLY);
	ft_putnbr_fd(nbr, fd);
	close(fd);
	fd = open("putnbr_fd.txt", O_RDONLY);
	printf("=> contenu du fichier : ");
	if (fd > 0)
	{
		printf("'");
		while (read(fd, &c, 1) > 0)
		{
			if (c == '\n')
				printf("\\n");
			else if (c == '\0')
				printf("\\0");
			else
				printf("%c", c);
		}
		printf("'\n");
	}
	close(fd);
	return (0);
}

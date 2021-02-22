#include "putchar_fd_main.h"

void	ft_print_explain(void)
{
	printf("## FT_PUTCHAR_FD ##\n");
	printf("=> Prototype : void ft_putchar_fd(char c, int fd);\n");
	printf("=> Ecrit avec 'write' le caractère 'c' dans le ficher correspondant au file descriptor 'fd'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 'c' : caractère ou valeur ascii à écrire dans le fichier.\n");
	printf("=> Paramètre 2 : 'c' si le paramètre 1 est un caractère, 'v' s'il s'agit d'une valeur ascii.\n");
}

int	main(int argc, char **argv)
{
	int	fd;
	char	c;

	if (argc == 1)
		ft_print_explain();
	if (argc != 3)
		return (0);
	if (argv[2][0] == 'c')
		c = argv[1][0];
	if (argv[2][0] == 'v')
		c = atoi(argv[1]);
	printf("=> caractère à écrire : '%c' (valeur ascii : %d)\n", c, c);
	fd = open("putchar_fd.txt", O_RDWR);
	ft_putchar_fd(c, fd);
	printf("=> contenu du fichier : ");
	close(fd);
	fd = open("putchar_fd.txt", O_RDWR);
	while (fd > 0 && read(fd, &c, 1) > 0)
		printf("'%c' (valeur ascii : %d)\n", c, c);
	close(fd);
	return (0);
}

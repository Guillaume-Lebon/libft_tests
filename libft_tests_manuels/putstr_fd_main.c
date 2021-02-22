#include "putstr_fd_main.h"

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
	printf("## FT_PUTSTR_FD ##\n");
	printf("=> Prototype : void ft_putstr_fd(char *s, int fd);\n");
	printf("=> Ecrit avec 'write' la chaîne de caractères 's' dans le fichier correspondant au file descriptor 'fd'.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1 : 's' : chaîne de caractères à écrire dans le fichier. Entrer 'NULL' pour une chaîne nulle.\n");
}

int	main(int argc, char **argv)
{
	int	fd;
	char	c;

	if (argc == 1)
		ft_print_explain();
	if (argc != 2)
		return (0);
	if (ft_detect_null(argv[1]) == 1)
		argv[1] = NULL;
	printf("=> chaîne de caractères à écrire : %p", argv[1]);
	if (argv[1] != NULL)
		printf(" : '%s\\0'", argv[1]);
	fd = open("putstr_fd.txt", O_WRONLY);
	ft_putstr_fd(argv[1], fd);
	printf("\n=> contenu du fichier : ");
	close(fd);
	fd = open("putstr_fd.txt", O_RDONLY);
	if (fd > 0)
	{
		printf("'");
		while (read(fd, &c, 1) > 0)
		{
			if (c == '\0')
				printf("\\0");
			else if (c == '\n')
				printf("\\n");
			else
				printf("%c", c);
		}
		printf("'\n");
	}
	close(fd);
	return (0);
}

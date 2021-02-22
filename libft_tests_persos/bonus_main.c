#include "bonus_main.h"

char	ft_detect_null(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == 'N'
			&& str[1] == 'U'
			&& str[2] == 'L'
			&& str[3] == 'L'
			&& str[4] == '\0')
		return (1);
	return (0);
}

char	ft_detect_vide(char *str)
{
	if (str == NULL || (str[0] == 'V'
			&& str[1] == 'I'
			&& str[2] == 'D'
			&& str[3] == 'E'
			&& str[4] == '\0'))
		return (1);
	return (0);
}

void	ft_print_elem(t_list *elem, int i)
{
	if (elem == NULL)
		printf("\n\n=> élément n°0 : %p", elem);
	else
		printf("\n\n=> élément n°%d : %p", i, elem);
	if (elem != NULL)
	{
		printf("\n - content : %p", elem->content);
		if (elem->content != NULL)
			printf(" : '%s'", (char *)(elem->content));
		printf("\n - next : %p", elem->next);
	}
}

void	ft_print_list(t_list **first)
{
	int	i;
	t_list	*actual;

	i = 0;
	actual = *first;
	ft_print_elem(actual, ++i);
	while (actual != NULL && actual->next != NULL)
	{
		actual = actual->next;
		ft_print_elem(actual, ++i);
	}
}

void	ft_free_list_b2(t_list **first)
{
	t_list *to_free;

	while ((*first) != NULL && (*first)->next != NULL)
	{
		to_free = *first;
		*first = (*first)->next;
		free(to_free);
	}
	free(*first);
	*first = NULL;
}

void	ft_free_list_b(t_list **first)
{
	t_list *to_free;

	while ((*first) != NULL && (*first)->next != NULL)
	{
		to_free = *first;
		*first = (*first)->next;
		free(to_free->content);
		free(to_free);
	}
	if (*first != NULL)
		free((*first)->content);
	free(*first);
	*first = NULL;
}

void	ft_copy_param(char **str, char *content)
{
	int i;

	if (content == NULL)
		*str = NULL;
	if (content == NULL)
		return ;
	i = 0;
	while (content[i])
		++i;
	*str = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (*str != NULL && content[++i])
		(*str)[i] = content[i];
	(*str)[i] = '\0';
}

t_list	*ft_create_elem_b(void *content)
{
	t_list	*new;
	char	*str;

	ft_copy_param(&str, content);
	new = malloc(sizeof(t_list *));
	if (new == NULL)
		return (NULL);
	new->content = str;
	new->next = NULL;
	return (new);
}

void	ft_create_list(t_list **first, int argc, char **argv)
{
	int	i;
	t_list	*actual;
	t_list	*new;

	i = 0;
	while (++i < argc)
	{
		if (ft_detect_vide(argv[i]) == 1)
			argv[i] = NULL;
		if (ft_detect_null(argv[i]) == 1)
			new = NULL;
		else
			new = ft_create_elem_b(argv[i]);
		if (*first == NULL)
			*first = new;
		else
		{
			actual = *first;
			while (actual->next != NULL)
				actual = actual->next;
			actual->next = new;
		}
	}
}

void	*ft_min_maj2(void *content)
{
	char	*str;
	int	i;

	str = (char *)content;
	i = -1;
	printf("\n\n=> fonction 'f' appliquée.");
	printf("\n - contenu avant fonction 'f' : %p : '%s'", str, str);
	while (str != NULL && str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	printf("\n - contenu après fonction 'f' : %p : '%s'", str, str);
	return((void *)str);
}

void	ft_min_maj(void *content)
{
	char	*str;
	int	i;

	str = (char *)content;
	i = -1;
	printf("\n\n=> fonction 'f' appliquée.");
	printf("\n - contenu avant fonction 'f' : %p : '%s'", str, str);
	while (str != NULL && str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	printf("\n - contenu après fonction 'f' : %p : '%s'", str, str);
}

void	ft_supp_cont(void *content)
{
	char *str;

	str = (char *)content;
	printf("\n\n=> fonction 'del' appliquée.");
	printf("\n - contenu écrasé : %p : '%s'", str, str);
}

void	ft_test_map(t_list **first, t_list **first2, int argc, char **argv)
{
	int ind;

	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("---------------------------------------------------------## FT_LSTMAP ##\n");
	printf("t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));");
	ft_create_list(first, argc, argv);
	printf("\n\n ► LISTE ORIGINELLE");
	ft_print_list(first);
	ind = 0;
	if (argv[argc - 1] != NULL)
		ind = atoi(argv[argc - 1]);
	if (argv[argc - 1] != NULL && ind == 3)
	{
		printf("\n\n\n ► FT_LSTMAP avec lst == NULL && f == NULL && del == NULL");
		*first2 = ft_lstmap(NULL, NULL, NULL);
		ft_print_list(first2);
		ft_free_list_b2(first2);
	}
	if (argv[argc - 1] != NULL && (ind == 3 || ind == 1))
	{
		printf("\n\n\n ► FT_LSTMAP avec lst == NULL && f != NULL && del != NULL");
		*first2 = ft_lstmap(NULL, &ft_min_maj2, &ft_supp_cont);
		ft_print_list(first2);
		ft_free_list_b2(first2);
	}
	if (argv[argc - 1] != NULL && (ind == 3 || ind == 2))
	{
		printf("\n\n\n ► FT_LSTMAP avec lst != NULL && f == NULL && del == NULL");
		*first2 = ft_lstmap(*first, NULL, NULL);
		ft_print_list(first2);
		ft_free_list_b2(first2);
	}
	if (*first != NULL)
		printf("\n\n\n ► FT_LSTMAP avec lst != NULL && f != NULL && del != NULL");
	else if (*first == NULL)
		printf("\n\n\n ► FT_LSTMAP avec lst == NULL && f != NULL && del != NULL");
	*first2 = ft_lstmap(*first, &ft_min_maj2, &ft_supp_cont);
	ft_print_list(first2);
	ft_free_list_b2(first2);
	ft_free_list_b(first);
	printf("\n");
}

void	ft_test_iter(t_list **first, int argc, char **argv)
{
	int ind;

	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("--------------------------------------------------------## FT_LSTITER ##\n");
	printf("------------------------void ft_lstiter(t_list *lst, void (*f)(void *));");
	ft_create_list(first, argc, argv);
	printf("\n\n ► LISTE ORIGINELLE");
	ft_print_list(first);
	ind = 0;
	if (argv[argc - 1] != NULL)
		ind = atoi(argv[argc - 1]);
	if (argv[argc - 1] != NULL && ind == 3)
	{
		printf("\n\n\n ► FT_LSTITER avec lst == NULL && f == NULL");
		ft_lstiter(NULL, NULL);
	}
	if (argv[argc - 1] != NULL && (ind == 3 || ind == 1))
	{
		printf("\n\n\n ► FT_LSTITER avec lst == NULL && f != NULL");
		ft_lstiter(NULL, &ft_min_maj);
	}
	if (argv[argc - 1] != NULL && (ind == 3 || ind == 2))
	{
		printf("\n\n\n ► APRES FT_LSTITER avec lst != NULL && f == NULL");
		ft_lstiter(*first, NULL);
		ft_print_list(first);
	}
	if (*first != NULL)
		printf("\n\n\n ► FT_LSTITER avec lst != NULL && f != NULL");
	else if (*first == NULL)
		printf("\n\n\n ► FT_LSTITER avec lst == NULL && f != NULL");
	ft_lstiter(*first, &ft_min_maj);
	ft_print_list(first);
	ft_free_list_b(first);
	is_first = 0;
	printf("\n");
}

int	ft_count(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (ft_detect_null(argv[i]) == 0)
			++j;
	}
	return (j);
}

void	ft_test_clear(t_list **first, t_list **first2, t_list **null, int argc, char **argv)
{
	t_list	*next_to_supp;
	t_list	*next_to_supp2;
	t_list	*save_first;
	t_list	*save_first2;
	int	nb;
	int	ind;

	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("-------------------------------------------------------## FT_LSTCLEAR ##\n");
	printf("--------------------void ft_lstclear(t_list **lst, void (*del)(void *));");
	nb = 0;
	if (argc >= 3 && argv[argc - 2] != NULL)
		nb = atoi(argv[argc - 2]);
	if (nb == 0 || nb > ft_count(argc, argv))
	{
		is_first = 0;
		printf("\n");
		return ;
	}
	ind = 0;
	if (argv[argc - 1] != NULL)
		ind = atoi(argv[argc - 1]);
	if (ind == 3 || ind == 2)
	{
		printf("\n\n ► LISTES ORIGINELLES");
		ft_create_list(first, argc, argv);
		printf("\n\n -> liste 1 :");
		ft_print_list(first);
		printf("\n\n -> liste 2 :");
	}
	else
		printf("\n\n ► LISTE ORIGINELLE");
	ft_create_list(first2, argc, argv);
	ft_print_list(first2);
	if (nb == 1)
		save_first = NULL;
	if (nb == 1)
		save_first2 = NULL;
	if (nb != 1)
		save_first = *first;
	if (nb != 1)
		save_first2 = *first2;
	next_to_supp = NULL;
	next_to_supp2 = NULL;
	while (*first2 != NULL && (*first2)->next != NULL && nb > 1)
	{
		if (nb == 2)
			next_to_supp = *first;
		if (nb == 2)
			next_to_supp2 = *first2;
		if (*first != NULL)
			*first = (*first)->next;
		*first2 = (*first2)->next;
		--nb;
	}
	if (nb == 1)
	{
		if (argv[argc - 1] != NULL && ind == 3)
		{
			printf("\n\n\n ► FT_LSTCLEAR avec *lst == NULL && del == NULL");
			ft_lstclear(null, NULL);
		}
		if (argv[argc - 1] != NULL && (ind == 3 || ind == 1))
		{
			printf("\n\n\n ► FT_LSTCLEAR avec *lst == NULL && del != NULL");
			ft_lstclear(null, &ft_supp_cont);
		}
		if (argv[argc - 1] != NULL && (ind == 3 || ind == 2))
		{
			printf("\n\n\n ► APRES FT_LSTCLEAR avec *lst != NULL && del == NULL");
			ft_lstclear(first, NULL);
			printf("\n\n=> valeur du pointeur : %p", *first);
			*first = save_first;
			if (next_to_supp != NULL)
				next_to_supp->next = NULL;
			printf("\n\n -> liste 1 :");
			ft_print_list(first);
		}
		if (*first2 != NULL)
			printf("\n\n\n ► APRES FT_LSTCLEAR avec *lst != NULL && del != NULL");
		else if (*first2 == NULL)
			printf("\n\n\n ► APRES FT_LSTCLEAR avec *lst == NULL && del != NULL");
		ft_lstclear(first2, &ft_supp_cont);
		printf("\n\n=> valeur du pointeur : %p", *first2);
		*first2 = save_first2;
		if (next_to_supp2 != NULL)
			next_to_supp2->next = NULL;
		if (ind == 3 || ind == 2)
			printf("\n\n -> liste 2 :");
		ft_print_list(first2);
	}
	*first = save_first;
	ft_free_list_b(first);
	ft_free_list_b(first2);
	is_first = 0;
	printf("\n");
}

void	ft_test_delone(int argc, char **argv)
{
	t_list	*elem;
	t_list	*elem2;
	int	ind;

	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("------------------------------------------------------## FT_LSTDELONE ##\n");
	printf("--------------------void ft_lstdelone(t_list *lst, void (*del)(void *));");
	elem = NULL;
	elem2 = NULL;
	ind = 0;
	if (argv[argc - 1] != NULL)
		ind = atoi(argv[argc - 1]);
	if (ind == 3 || ind == 2)
	{
		printf("\n\n ► ELEMENTS ORIGINELS");
		if (argc > 1 && ft_detect_vide(argv[argc - 1]) == 1)
			elem = ft_create_elem_b(NULL);
		else if (argc > 1 && ft_detect_null(argv[argc - 1]) == 1)
			elem = NULL;
		else if (argc > 1)
			elem = ft_create_elem_b(argv[argc - 1]);
		ft_print_elem(elem, ft_count(argc, argv));
	}
	else
		printf("\n\n ► ELEMENT ORIGINEL");
	if (argc > 1 && ft_detect_vide(argv[argc - 1]) == 1)
		elem2 = ft_create_elem_b(NULL);
	else if (argc > 1 && ft_detect_null(argv[argc - 1]) == 1)
		elem2 = NULL;
	else if (argc > 1)
		elem2 = ft_create_elem_b(argv[argc - 1]);
	ft_print_elem(elem2, ft_count(argc, argv));
	if (argv[argc - 1] != NULL && ind == 3)
	{
		printf("\n\n\n ► FT_LSTDELONE avec lst == NULL && del == NULL");
		ft_lstdelone(NULL, NULL);
	}
	if (argv[argc - 1] != NULL && (ind == 3 || ind == 1))
	{
		printf("\n\n\n ► FT_LSTDELONE avec lst == NULL && del != NULL");
		ft_lstdelone(NULL, &ft_supp_cont);
	}
	if (argv[argc - 1] != NULL && (ind == 3 || ind == 2))
	{
		printf("\n\n\n ► FT_LSTDELONE avec lst != NULL && del == NULL");
		ft_lstdelone(elem, NULL);
		ft_print_elem(elem, ft_count(argc, argv));
	}
	if (elem2 != NULL)
		printf("\n\n\n ► FT_LSTDELONE avec lst != NULL && del != NULL");
	else if (elem2 == NULL)
		printf("\n\n\n ► FT_LSTDELONE avec lst == NULL && del != NULL");
	ft_lstdelone(elem2, &ft_supp_cont);
	ft_print_elem(elem2, ft_count(argc, argv));
	is_first = 0;
	printf("\n");
}

void	ft_test_add_back(t_list **first, int argc, char **argv)
{
	int	i;
	t_list	*new;

	i = 0;
	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("----------------------------------------------------## FT_LSTADD_BACK ##\n");
	printf("------------------------void ft_lstadd_back(t_list **alst, t_list *new);");
	while (++i < argc)
	{
		if (ft_detect_vide(argv[i]) == 1)
			argv[i] = NULL;
		if (ft_detect_null(argv[i]) == 1)
			new = NULL;
		else
			new = ft_create_elem_b(argv[i]);
		ft_lstadd_back(first, new);
	}
	ft_print_list(first);
	ft_free_list_b(first);
	is_first = 0;
	printf("\n");
}

void	ft_test_last(t_list **first, int argc, char **argv)
{
	t_list *elem;

	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("--------------------------------------------------------## FT_LSTLAST ##\n");
	printf("----------------------------------------t_list *ft_lstlast(t_list *lst);");
	ft_create_list(first, argc, argv);
	ft_print_list(first);
	printf("\n\n\n ► DERNIER ELEMENT\n\n=> dernier élément : %p", elem = ft_lstlast(*first));
	if (elem != NULL)
	{
		printf("\n - content : %p", elem->content);
		if (elem->content != NULL)
			printf(" : '%s'", (char *)(elem->content));
		printf("\n - next : %p", elem->next);
	}
	ft_free_list_b(first);
	is_first = 0;
	printf("\n");
}

void	ft_test_size(t_list **first, int argc, char **argv)
{
	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("--------------------------------------------------------## FT_LSTSIZE ##\n");
	printf("--------------------------------------------int ft_lstsize(t_list *lst);");
	ft_create_list(first, argc, argv);
	ft_print_list(first);
	printf("\n\n\n ► TAILLE DE LISTE\n\n=> taille : %d", ft_lstsize(*first));
	ft_free_list_b(first);
	is_first = 0;
	printf("\n");
}

void	ft_test_add_front(t_list **first, int argc, char **argv)
{
	int	i;
	t_list	*new;

	i = 0;
	if (is_first == 0)
		printf("\n------------------------------------------------------------------------\n");
	printf("---------------------------------------------------## FT_LSTADD_FRONT ##\n");
	printf("-----------------------void ft_lstadd_front(t_list **alst, t_list *new);");
	while (++i < argc)
	{
		if (ft_detect_vide(argv[i]) == 1)
			argv[i] = NULL;
		if (ft_detect_null(argv[i]) == 1)
			new = NULL;
		else
			new = ft_create_elem_b(argv[i]);
		ft_lstadd_front(first, new);
	}
	ft_print_list(first);
	ft_free_list_b(first);
	is_first = 0;
	printf("\n");
}

void	ft_test_new(int argc, char **argv)
{
	int	i;
	int	j;
	t_list	*elem;

	i = 0;
	j = 0;
	printf("---------------------------------------------------------## FT_LSTNEW ##\n");
	printf("---------------------------------------t_list *ft_lstnew(void *content);");
	if (argc == 1)
		ft_print_elem(NULL, i);
	while (++i < argc)
	{
		if (ft_detect_vide(argv[i]) == 1)
			argv[i] = NULL;
		if (ft_detect_null(argv[i]) == 1)
			elem = NULL;
		else
			elem = ft_lstnew(argv[i]);
		if (elem != NULL)
			++j;
		ft_print_elem(elem, j);
		free(elem);
	}
	is_first = 0;
	printf("\n");
}

void	ft_print_explain(void)
{
	printf("## PARTIE BONUS : FONCTION(S) DE MANIPULATION(S) DE LISTE(S) ##\n");
	printf("=> Crée(nt) et/ou manipule(nt) une ou plusieurs liste(s) à partir du(des) paramètre(s) entré(s) en ligne de commande.\n");
	printf("\n## EN LIGNE DE COMMANDE ##\n");
	printf("=> Paramètre 1, paramètre 2, etc. : contenu de chaque maillon de(s) liste(s).\n");
	printf("=> Entrer 'NULL' envoie un maillon mis à NULL.\n");
	printf("=> Entrer 'VIDE' envoie un maillon vide, dont le contenu est mis à NULL.\n");
	printf("=> L'avant-dernier paramètre peut spécifier le numéro du maillon à partir duquel s'applique la fonction 'ft_lstclear'.\n");
	printf(" - Si rien n'est précisé, ce numéro est mis à zéro et la fonction 'ft_lstclear' ne s'applique pas.\n");
	printf("=> Le dernier paramètre peut spécifier certaines modalités de tests des fonctions 'ft_lstdelone', 'ft_lstclear', 'ft_lstiter' et 'ft_lstmap'.\n");
	printf(" - '1' envoie des pointeurs sur liste(s) 'lst' et/ou '*lst' mis à NULL.\n");
	printf(" - '2' envoie des pointeurs sur fonction(s) 'f' et/ou 'del' mis à NULL.\n");
	printf(" - '3' équivaut à faire '1' et '2'.\n");
	printf(" - Si rien n'est précisé, aucun pointeur NULL n'est envoyé.\n");
}

int	main(int argc, char **argv)
{
	t_list *first;
	t_list *first2;
	t_list *null;

	is_first = 1;
	first = NULL;
	first2 = NULL;
	null = NULL;
	if (argc == 1)
		ft_print_explain();
	if (argc == 1)
		return (0);
	if (NEW == 1)
		ft_test_new(argc, argv);
	if (ADDFRONT == 1)
		ft_test_add_front(&first, argc, argv);
	if (SIZE == 1)
		ft_test_size(&first, argc, argv);
	if (LAST == 1)
		ft_test_last(&first, argc, argv);
	if (ADDBACK == 1)
		ft_test_add_back(&first, argc, argv);
	if (DELONE == 1)
		ft_test_delone(argc, argv);
	if (CLEAR == 1)
		ft_test_clear(&first, &first2, &null, argc, argv);
	if (ITER == 1)
		ft_test_iter(&first, argc, argv);
	if (MAP == 1)
		ft_test_map(&first, &first2, argc, argv);
	return (0);
}

// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/parameterized.h>
#include <mimick.h>

#include "utils/utils.h"
#include <string.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

static void dummy_del(void *ptr)
{
	(void)ptr;
}

TestSuite(ft_lstmap, .timeout = TIMEOUT);

// do not put 4 in that array
static int data[] = { 1, 2, 3, 6, 9, 42 };

ParameterizedTestParameters(ft_lstmap, simple)
{
	return cr_make_param_array(int, data, sizeof(data) / sizeof
	(*data));
}

mmk_mock_define(malloc_mock_supervisor, void *, size_t);

static void *my_ft(void *ptr)
{
	return ptr;
}

ParameterizedTest(int *c, ft_lstmap, simple)
{
	size_t size, i;
	t_list *ret_ft, *list, *current;
	int malloc_supervisor_res = true;
	static char malloc_warned = false;
	static void *real_malloc = NULL;

	set_real_function((void **)&real_malloc, "malloc");
	i = 0;
	size = *c - 1;
	list = alloca(*c * sizeof(*list));
	while (i <= size)
	{
		list[i].content = (void *)(unsigned long long)size - i + 1;
		list[i].next = (i == 0 ? NULL : &(list[i - 1]));
		i++;
	}

	mmk_mock("malloc@self", malloc_mock_supervisor);
	mmk_when(malloc(mmk_any(size_t)), .then_call = real_malloc);
	ret_ft = ft_lstmap(&list[size], my_ft, dummy_del);
	malloc_supervisor_res = mmk_verify(malloc(mmk_eq(size_t, sizeof(*list))), .times = *c);
	malloc_supervisor_res &= mmk_verify(malloc(mmk_ne(size_t, sizeof(*list))), .never = 1);
	mmk_reset(malloc);

	i = 0;
	current = &ret_ft[0];
	while (i <= size)
	{
		if (current == NULL)
			break;
		ret_ft = current->next;
		cr_expect(current->content == (void *)(unsigned long long) i + 1,
			"Wrong return value at position %lu got %p expected %p.", i,
			current-> content, i + 1);
		free(current);
		current = ret_ft;
		i++;
	}

	if (malloc_supervisor_res == 0 && malloc_warned == false)
	{
		cr_log_warn(
			"(%s:%s) Unexpected malloc usage (either calling it too many, or "
			"too few times, or allocating too much or not enough memory).",
			criterion_current_suite->name, criterion_current_test->name);
		malloc_warned = true;
	}

	cr_assert(i == size + 1, "Invalid list returned got length %d expected %d",
		i, size + 1);
}

ParameterizedTestParameters(ft_lstmap, malloc_fail)
{
	return cr_make_param_array(int, data, sizeof(data) / sizeof(*data));
}

static void *my_ft_malloc_off(void *ptr)
{
	(void)ptr;
	return malloc(4);
}

static void my_del_malloc_off(void *ptr)
{
	cr_expect(ptr != NULL, "Trying to del(NULL)");
	free(ptr);
}

static void validate_split_malloc_fail(int c, int target);

ParameterizedTest(int *c, ft_lstmap, malloc_fail)
{
	for (int target = 0; target < *c * 2; target++)
		validate_split_malloc_fail(*c, target);
}

static int g_target;
static int g_times_malloc_called;

mmk_mock_define(malloc_mock_fail, void *, size_t);

static void *malloc_fail_target(size_t n)
{
	static void *(*real_malloc)(size_t) = NULL;

	set_real_function((void **)&real_malloc, "malloc");
	if (g_times_malloc_called >= g_target)
		return (NULL);
	g_times_malloc_called++;
	return (real_malloc(n));
}

static void validate_split_malloc_fail(int c, int target)
{
	t_list *list, *ret_ft;
	size_t size, i;
	int malloc_supervisor_res;
	static char malloc_warned = false;

	g_target = target;
	g_times_malloc_called = 0;

	i = 0;
	size = c - 1;
	list = alloca(c * sizeof(*list));
	while (i <= size)
	{
		list[i].content = (void *)(unsigned long long)size - i + 1;
		list[i].next = (i == 0 ? NULL : &(list[i - 1]));
		i++;
	}

	mmk_mock("malloc@self", malloc_mock_fail);
	mmk_when(malloc(mmk_any(size_t)), .then_call = (void *)malloc_fail_target);
	ret_ft = ft_lstmap(&list[size], my_ft_malloc_off, my_del_malloc_off);
	malloc_supervisor_res =	mmk_verify(malloc(mmk_any(size_t)), .times =
		target + 1);
	mmk_reset(malloc);

	cr_assert(ret_ft == NULL, "[malloc off]Returns %p but NULL expected.",
		ret_ft);

	if (malloc_supervisor_res == 0 && malloc_warned == false)
	{
		cr_log_warn(
			"(%s:%s) Unexpected malloc usage (either calling it too many, or "
			"too few times, or allocating too much or not enough memory).",
			criterion_current_suite->name, criterion_current_test->name);
		malloc_warned = true;
	}
}

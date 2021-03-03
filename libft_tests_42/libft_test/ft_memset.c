// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <string.h>
#include "utils/utils.h"
#include "rand/utils.h"
#include "rand/numbers.h"
#include "rand/byte_array.h"
#include "forbid/forbid.c"
static void validate_memset(void *ptr0, void *ptr1, int c, size_t n, int f);
void *ft_memset(void *s, int c, size_t n);

TestSuite(ft_memset, .timeout=TIMEOUT);

Test(ft_memset, normal)
{
	char buf0[10] = "..........";
	char buf1[10] = "..........";

	validate_memset(buf0, buf1, '@', 10, false);
}

Test(ft_memset, 0)
{
	char buf0[0] = "";
	char buf1[0] = "";

	validate_memset(buf0, buf1, '@', 0, false);
}

Test(ft_memset, randomised)
{
	void *ptr0, *ptr1;
	int i, n, c;

	for (i = 0; i < RAND_ITERATIONS; i++)
	{
		n = (int)rand_number_max(500);
		ft_byte_array(n, &ptr0, &ptr1);
		c = rand_number_max(255);

		validate_memset(ptr0, ptr1, c, n, true);
	}
}

static void validate_memset(void *ptr0, void *ptr1, int c, size_t n, int f)
{
	int cmp;
	void *ret;

	memset(ptr0, c, n);
	forbid();
	ret = ft_memset(ptr1, c, n);
	allow();
	cmp = memcmp(ptr0, ptr1, n);

	if (f == true)
	{
		ft_free(ptr0);
		ft_free(ptr1);
	}

	cr_assert(ret == ptr1, "Wrong return value got %p expected %p.", ret, ptr1);
	cr_assert(
		cmp == 0, "Function did not operate as expected. (memcmp = %d)", cmp);
}

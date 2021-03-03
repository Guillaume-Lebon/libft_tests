// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <string.h>
#include "rand/strings.h"
#include "rand/utils.h"
#include "utils/utils.h"
#include "rand/byte_array.h"
#include "rand/numbers.h"
#include <stdlib.h>
#include "forbid/forbid.c"

void *ft_memcpy(void *dest, const void *src, size_t n);
static void validate_memcpy(void *src, size_t n, int f);

TestSuite(ft_memcpy, .timeout=TIMEOUT);

Test(ft_memcpy, normal)
{
	char src[10] = "01234567@@";

	validate_memcpy(src, 10, false);
}

Test(ft_memcpy, 0)
{
	char src[10] = "aabbccddee";

	validate_memcpy(src, 0, false);
}

Test(ft_memcpy, 0null)
{
	void *ret;

	ret = ft_memcpy((void *)42, NULL, 0);
	cr_assert(ret == (void *)42, "Wrong return value got %p expected %p.",
		ret, 42);
}

Test(ft_memcpy, null12)
{
	ft_memcpy(NULL, NULL, 10);
}

Test(ft_memcpy, same_ptr)
{
	char buf[42];
	void *ret;

	ret = ft_memcpy(buf, buf, 42);
	cr_assert(ret == buf, "Wrong return value got %p expected %p.",
		ret, buf);
}

Test(ft_memcpy, len0)
{
	void *ret;

	ret = ft_memcpy((void *)42, (void *)4242, 0);
	cr_assert(ret == (void *)42, "Wrong return value got %p expected %p.",
		ret, 42);
}

Test(ft_memcpy, randomised)
{
	int i, n;
	void *src;

	for (i = 0; i < RAND_ITERATIONS; i++)
	{
		n = rand_number_max(500);
		ft_byte_array(n, &src, NULL);

		validate_memcpy(src, n, true);
	}
}

static void validate_memcpy(void *src, size_t n, int f)
{
	void *dest0, *dest1;
	void *ret;
	int cmp;

	ft_byte_array(n, &dest0, &dest1);
	memcpy(dest0, src, n);
	forbid();
	ret = ft_memcpy(dest1, src, n);
	allow();
	cmp = memcmp(dest0, dest1, n);

	if (f == true)
		ft_free(src);
	ft_free(dest0);
	ft_free(dest1);

	cr_assert(
		ret == dest1, "Wrong return value got %p expected %p.", ret, dest1);
	cr_assert(
		cmp == 0, "Function did not operate as expected. (memcmp = %d)", cmp);
}


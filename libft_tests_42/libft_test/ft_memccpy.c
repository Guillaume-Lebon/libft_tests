// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <criterion/new/assert.h>

#define EURO_SYMBOL ((unsigned char)128)

#include <string.h>
#include "rand/numbers.h"
#include "rand/byte_array.h"
#include "utils/utils.h"
#include "rand/utils.h"
#include "forbid/forbid.c"
static void validate_memccpy(void *src, int c, size_t n, int f);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);

TestSuite(ft_memccpy, .timeout=TIMEOUT);

ParameterizedTestParameters(ft_memccpy, simple)
{
	static int data[] = { ']', '5', '7', '1' };

	return cr_make_param_array(int, data, sizeof(data) / sizeof(int));
}

ParameterizedTest(int *c, ft_memccpy, simple)
{
	char buf[] = "1234567@@@";

	validate_memccpy(buf, *c, sizeof(buf), false);
}

Test(ft_memccpy, 0)
{
	char buf[0];

	validate_memccpy(buf, '@', 0, false);
}

Test(ft_memccpy, 0null)
{
	void *ret;

	ret = ft_memccpy((void *)42, NULL, '@', 0);
	cr_assert(ret == NULL, "Wrong return value got %p expected %p.",
		ret, NULL);
}

Test(ft_memccpy, extended_ascii)
{
	char buf[11] = "1234.6789";

	buf[4] = EURO_SYMBOL;

	validate_memccpy(buf, EURO_SYMBOL, 11, false);
}

Test(ft_memccpy, randomised)
{
	void *ptr0;
	int i, len, c;

	for (i = 0; i < RAND_ITERATIONS; i++)
	{
		len = (int)rand_number_max(500);
		c = (int)rand_number_max(255);
		ft_byte_array(len, &ptr0, NULL);

		validate_memccpy(ptr0, c, len, true);
	}
}

static void validate_memccpy(void *src, int c, size_t n, int f)
{
	void *ret0, *ret1;
	void *dest0, *dest1;
	int cmp;

	ft_byte_array(n, &dest0, &dest1);

	ret0 = memccpy(dest0, src, c, n);
	forbid();
	ret1 = ft_memccpy(dest1, src, c, n);
	allow();
	cmp = memcmp(dest1, dest0, n);

	if (f == true)
		ft_free(src);
	ft_free(dest0);
	ft_free(dest1);

	if (ret0 == NULL)
		cr_assert(
			ret1 == NULL, "Expected return value %p expected %p.", ret1, ret0);
	else
		cr_assert(ret1 - dest1
				  == ret0 - dest0, "return value got %p expected %p.", ret1,
			ret0 - dest0 + dest1);

	cr_assert(cmp == 0, "Function did not operate as expected.");
}

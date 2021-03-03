// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <string.h>
#include "rand/utils.h"
#include "rand/numbers.h"
#include "utils/utils.h"
#include "rand/byte_array.h"
#include "forbid/forbid.c"

#define EURO_SYMBOL ((unsigned char)128)

void *ft_memchr(const void *s, int c, size_t n);
static void validate_memchr(void *src, int c, size_t n, int f);

TestSuite(ft_memchr, .timeout=TIMEOUT);

Test(ft_memchr, found)
{
	char buf[10] = "0123456789";

	validate_memchr(buf, '5', 10, false);
}

Test(ft_memchr, not_found)
{
	unsigned char buf[10] = "0123456789";

	validate_memchr(buf, '@', 10, false);
}

Test(ft_memchr, extended_ascii)
{
	char buf[10] = "0123456789";

	buf[4] = EURO_SYMBOL;
	validate_memchr(buf, EURO_SYMBOL, 10, false);
}

Test(ft_memchr, char_overflow)
{
	char buf[10] = "0123.56789";

	buf[4] = 0b01010101;
	validate_memchr(buf, 0b101010101, 10, false);
}

Test(ft_memchr, randomised)
{
	int i, c, n;
	void *str;

	for (i = 0; i < RAND_ITERATIONS; i++)
	{
		n = (int)rand_number_max(500);
		c = (int)rand_number_max(255);
		ft_byte_array(n, &str, NULL);

		validate_memchr(str, c, n, true);
	}
}

static void validate_memchr(void *src, int c, size_t n, int f)
{
	void *ret0, *ret1;

	ret0 = memchr(src, c, n);
	forbid();
	ret1 = ft_memchr(src, c, n);
	allow();

	if (f == true)
		ft_free(src);

	cr_assert(
		ret0 == ret1, "Wrong return value got %p expected %p.", ret1, ret0);
}

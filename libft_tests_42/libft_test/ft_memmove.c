// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "rand/numbers.h"
#include "rand/byte_array.h"
#include "rand/utils.h"
#include "utils/utils.h"
#include <string.h>
#include "forbid/forbid.c"

void *ft_memmove(void *dest, const void *src, size_t n);
static void validate_memmove(
	void *src0, void *src1, int s, int d, int l, size_t n, int f);

#define BYTE_N(ptr, n) (((char*)ptr)[n])

TestSuite(ft_memmove, .timeout=TIMEOUT);

Test(ft_memmove, overlap)
{
	char buf0[16] = "abcdeFGHIJ.....@";
	char buf1[16] = "abcdeFGHIJ.....@";

	validate_memmove(buf0, buf1, 5, 0, 10, 16, false);
}

Test(ft_memmove, preceed)
{
	char buf0[16] = ".....FGHIJ12345@";
	char buf1[16] = ".....FGHIJ12345@";

	validate_memmove(buf0, buf1, 0, 5, 10, 16, false);
}

Test(ft_memmove, 0null)
{
	void *ret;

	ret = ft_memmove((void *)42, NULL, 0);
	cr_assert(ret == (void *)42, "Wrong return value got %p expected %p.",
		ret, 42);
}

Test(ft_memmove, null12)
{
	ft_memmove(NULL, NULL, 16);
}

Test(ft_memmove, same_ptr)
{
	char buf[42];
	void *ret;

	ret = ft_memmove(buf, buf, 42);
	cr_assert(ret == buf, "Wrong return value got %p expected %p.",
		ret, buf);
}

Test(ft_memmove, len0)
{
	void *ret;

	ret = ft_memmove((void *)42, (void *)4242, 0);
	cr_assert(ret == (void *)42, "Wrong return value got %p expected %p.",
		ret, 42);
}

Test(ft_memmove, randomised)
{
	void *ptr0, *ptr1;
	int i, n;
	int s, d, l;

	for (i = 0; i < RAND_ITERATIONS; i++)
	{
		n = (int)rand_number_between(3, 500);
		ft_byte_array(n, &ptr0, &ptr1);
		s = (int)rand_number_max(n - 2);
		d = (int)rand_number_max(n - 2);
		l = (int)rand_number_max(n - (d > s ? d : s) - 1);
		validate_memmove(ptr1, ptr0, s, d, l, n, true);
	}
}

/*
 * Tests the function memmove against ft_memmove
 * The move occurs inside the memory area src0 for memomve and src1 for
 * ft_memove
 * s represent the index of the move source
 * d represents the index of the move destination
 * l represents how many bytes are moved from &src[s] to &src[d]
 */
static void validate_memmove(
	void *src0, void *src1, int s, int d, int l, size_t n, int f)
{
	void *ret1;
	int cmp;

	memmove(&BYTE_N(src0, d), &BYTE_N(src0, s), l);
	forbid();
	ret1 = ft_memmove(&BYTE_N(src1, d), &BYTE_N(src1, s), l);
	allow();

	cmp = memcmp(src0, src1, n);

	if (f == true)
	{
		ft_free(src0);
		ft_free(src1);
	}

	cr_assert(ret1
			  == &BYTE_N(src1, d), "Wrong return value got %p expected %p.", &BYTE_N(src1, d), ret1);
	cr_assert(
		cmp == 0, "Function did not operate as expected. (memcmp = %d)", cmp);
}

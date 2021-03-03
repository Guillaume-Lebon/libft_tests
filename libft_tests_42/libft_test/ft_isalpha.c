// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <string.h>
#include <ctype.h>
#include "utils/utils.h"
#include "forbid/forbid.c"

int ft_isalpha(int c);

TestSuite(ft_isalpha, .timeout=TIMEOUT);

Test(ft_isalpha, all_characters)
{
	int c;
	int ret0, ret1;

	for (c = 0; c < 256; c++)
	{
		ret0 = isalpha(c);
		forbid();
		ret1 = ft_isalpha(c);
		allow();

		cr_assert(int_to_bool(ret0) == int_to_bool(ret1), "Wrong return value"
														  " for character %d got %d"
														  " expected %d.", c, ret1, ret0);
	}
}

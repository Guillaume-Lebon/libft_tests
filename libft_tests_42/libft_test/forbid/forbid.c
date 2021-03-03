// SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <unistd.h>
#include <mimick.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>

#define forbid() forbid_free();forbid_malloc();forbid_write();

#define allow() allow_free();allow_malloc();allow_write();

#define _forbid_remove_warning \
(void)_forbidden_write;\
(void)_forbidden_malloc;\
/*(void)_forbidden_free*/\

//TODO get free() to work
/*static void _forbidden_free(void *ptr)
{
	cr_fatal("[%s] Forbidden function 'free(%p)' called !",
		criterion_current_suite->name, ptr);
}*/

//mmk_mock_define (_free_forbid, void *, void *);

#define forbid_free()/*\
	_forbid_remove_warning\
	mmk_mock("free@self", _free_forbid);\
	mmk_when(free(mmk_any(void *)), .then_call = (void *)_forbidden_free);*/

#define allow_free()/*\
	mmk_verify(free(mmk_any(void *)), .never=1);\
	mmk_reset(free);*/

static void *_forbidden_malloc(size_t n)
{
	cr_fatal("[%s] Forbidden function 'malloc(%lu)' called !",
		criterion_current_suite->name, n);
	return (NULL);
}

mmk_mock_define (_malloc_forbid, void *, size_t);

#define forbid_malloc()\
	_forbid_remove_warning\
	mmk_mock("malloc@self", _malloc_forbid);\
	mmk_when(malloc(mmk_any(size_t)), .then_call = (void *)_forbidden_malloc);

#define allow_malloc()\
	mmk_verify(malloc(mmk_any(size_t)), .never=1);\
	mmk_reset(malloc);

static ssize_t _forbidden_write(int fd, const void *buf, size_t n)
{
	cr_fatal("[%s] Forbidden function 'write(%d, %p, %lu)' called !",
		criterion_current_suite->name, fd, buf, n);
	return 0;
}

mmk_mock_define (_write_forbid, ssize_t, int, const void *, size_t);

#define forbid_write()\
	_forbid_remove_warning\
	mmk_mock("write@self", _write_forbid);\
	mmk_when(write(mmk_any(int), mmk_any(const void *), mmk_any(size_t)),\
		.then_call = (void *)\
		_forbidden_write);

#define allow_write()\
	mmk_verify(write(mmk_any(int), mmk_any(const void *), mmk_any(size_t)),\
		.never=1);\
	mmk_reset(write);

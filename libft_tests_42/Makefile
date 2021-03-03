# SPDX-FileCopyrightText: 2020 The at42 Libft Unit Tests Contributors (see CONTRIBUTORS.md)
#
# SPDX-License-Identifier: GPL-3.0-or-later

TEST_BIN = test.bin

TEST_SRC_PATH = libft_test
TEST_SRC_BASENAME = $(patsubst $(TEST_SRC_PATH)/%,%,$(wildcard $(TEST_SRC_PATH)/*.c))

LIBFT_SRC_PATH = libft
LIBFT_SRC = $(filter-out %_bonus.c,$(wildcard $(LIBFT_SRC_PATH)/*.c))
LIBFT_SRC_BASENAME = $(patsubst $(LIBFT_SRC_PATH)/%,%,$(LIBFT_SRC))

COMMON_SRC = $(filter $(LIBFT_SRC_BASENAME),$(TEST_SRC_BASENAME))

TEST_SRC = $(COMMON_SRC:%=$(TEST_SRC_PATH)/%)
TEST_SRC += $(wildcard $(TEST_SRC_PATH)/rand/*.c)
TEST_SRC += $(wildcard $(TEST_SRC_PATH)/utils/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_CC = gcc
TEST_CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_CC = clang
LIBFT_CFLAGS = $(TEST_CFLAGS) -Werror

BONUS_SRC = $(wildcard $(LIBFT_SRC_PATH)/*_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Inspired by Auto Dependency Generation (by Paul D. Smith)
# see http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#advanced
DEP_FILES = $(TEST_SRC:%.c=%.d) $(LIBFT_SRC:%.c=%.d) $(BONUS_SRC:%.c=%.d)
DEP_FLAGS = -MT $@ -MMD -MP -MF $*.Td
POSTCOMPILE = mv -f $*.Td $*.d && touch $@

LIB = criterion # our testing framework
LIB += dl # dynamicaly load libraries functions to bypass mock in tests
LIB += bsd # <bsd/strings.h> : strlcat for linux
LIBS = $(LIB:%=-l%)

MIMICK = /usr/lib/libmimick.a

RM = rm -rf
GREP = grep
NORM = .norminette/norminette.rb
AR = ar rcs
NM = nm
PRINTF = printf
TPUT = tput

SEARCH_FORBIDDEN_FN = $(NM) $@
SEARCH_FORBIDDEN_FN += | cut -c 18-
SEARCH_FORBIDDEN_FN += | $(GREP) "^T \|^U "
SEARCH_FORBIDDEN_FN += | $(GREP) -v "^U \(__asan\|__ubsan\|malloc$$\|write$$\|free$$\)"
SEARCH_FORBIDDEN_FN += | $(GREP) -v "$(patsubst %\|,%,$(subst \| ^U,\|^U,$(LIBFT_SRC_BASENAME:%.c=^U %\$\|)))"

NB_STATIC = $(SEARCH_FORBIDDEN_FN) | $(GREP) "^T " | wc -l
DETECT_MANY_NON_STATIC = N=$$($(NB_STATIC)); [ $$N == 1 ] || (printf "$(ERROR)Error$(NORMAL): %d static functions are in $(FILE)$*.c$(NORMAL)\n" "$$N" && $(RM) $@ && exit 1)

CURRENT_FN = $(*:$(LIBFT_SRC_PATH)/%=%)
REMOVE_CURRENT_FN = $(GREP) -v "^T $(CURRENT_FN)$$"

NORM_TMP_FILE = /tmp/at42.norm.txt

NORMAL = $(shell $(TPUT) sgr0)

BLACK = $(shell $(TPUT) setaf 0)
RED = $(shell $(TPUT) setaf 1)
GREEN = $(shell $(TPUT) setaf 2)
YELLOW = $(shell $(TPUT) setaf 3)
BLUE = $(shell $(TPUT) setaf 4)
MAGENTA = $(shell $(TPUT) setaf 5)
CYAN = $(shell $(TPUT) setaf 6)
WHITE = $(shell $(TPUT) setaf 7)

BRIGHT = $(shell $(TPUT) bold)
BLINK = $(shell $(TPUT) blink)
REVERSE = $(shell $(TPUT) smso)
UNDERLINE = $(shell $(TPUT) smul)

INVISIBLE = $(shell $(TPUT) civis)
VISIBLE = $(shell $(TPUT) cnorm)

MOVE_UP = $(shell $(TPUT) cuu1)
MOVE_DOWN = $(shell $(TPUT) cud1)
CLEAR_LINE = $(shell $(TPUT) el)
REPLACE_LINE = \r$(CLEAR_LINE)

VALID = $(BRIGHT)$(GREEN)

FILE = $(UNDERLINE)
FILE_TO_CLEAN = $(UNDERLINE)$(YELLOW)
CMD = $(BRIGHT)
ERROR = $(REVERSE)$(RED)

define compile
	@$(PRINTF) "$(INVISIBLE)$(REPLACE_LINE)$(CMD)Compiling$(NORMAL) $(FILE)$*.c$(NORMAL)\n"
	@$(CC) $(CFLAGS) $(DEP_FLAGS) -c -o $@ $< || ($(PRINTF) "$(VISIBLE)" && exit 1)
	@$(POSTCOMPILE)
	@$(PRINTF) "$(MOVE_UP)$(VISIBLE)"
endef

COL30 = \r$(shell $(TPUT) cuf 30)
DOTS = $(PRINTF) "$(COL30)...\n"
DONE = $(PRINTF) "$(COL30)$(VALID)done$(NORMAL)\n"

.PHONY: all
all: norm comp_init $(TEST_BIN) bonus_init $(BONUS_OBJ) bonus_done

$(TEST_BIN): $(TEST_OBJ) $(LIBFT_OBJ) $(MIMICK) | comp_done
	@$(PRINTF) "$(INVISIBLE)$(REPLACE_LINE)$(CMD)Compiling$(NORMAL) $(FILE)$@$(NORMAL)"
	@$(DOTS)
	@$(CC) $(TEST_CFLAGS) $(LIBS) -o $@ $^ || ($(PRINTF) "$(VISIBLE)" && exit 1)
	@$(PRINTF) "$(MOVE_UP)$(VISIBLE)"
	@$(DONE)

.PHONY: comp_init
comp_init:
	@$(PRINTF) "$(CMD)Compiling$(NORMAL) all files"
	@$(DOTS)

.PHONY: bonus_init
bonus_init:
	@$(PRINTF) "$(CMD)Compiling$(NORMAL) all bonus files"
	@$(DOTS)

.PHONY: bonus_done
bonus_done:
	@$(PRINTF) "$(REPLACE_LINE)"
	@$(PRINTF) "$(CMD)Compiling$(NORMAL) all bonus files"
	@$(DONE)

define done
.PHONY: $(1)_done
$(1)_done:
	@$(PRINTF) "$(REPLACE_LINE)$(MOVE_UP)"
	@$(DONE)
endef

$(eval $(call done,comp))

%.o: %.c

$(TEST_OBJ): CC=$(TEST_CC)
$(TEST_OBJ): CFLAGS=$(TEST_CFLAGS)
$(TEST_OBJ): %.o: %.c %.d Makefile
	$(call compile)

define detect_forbidden_fn
	DETECTED_FN=$$($(SEARCH_FORBIDDEN_FN) | $(2)); \
	if [ $$(echo "$$DETECTED_FN" | tr -d '\n' | wc --chars) != 0 ]; then \
		touch "$*.c"; \
		$(PRINTF) "\r\n"; \
		$(PRINTF) "$(CMD)$(1)$(NORMAL) in $(FILE)$*.c$(NORMAL):"; \
		echo "$$DETECTED_FN" | cut -c 2- | tr -d '\n' | sed 's/ /$(NORMAL) $(REVERSE)/'; \
		$(PRINTF) "$(NORMAL)\n"; \
		exit $(3); \
	fi
endef
QUIT = 1
CONTINUE = 0

$(LIBFT_OBJ): CC=$(LIBFT_CC)
$(LIBFT_OBJ): CFLAGS=$(LIBFT_CFLAGS)
$(LIBFT_OBJ): %.o: %.c %.d Makefile
	$(call compile)
	@$(call detect_forbidden_fn,Forbidden functions,$(REMOVE_CURRENT_FN),$(CONTINUE))

$(BONUS_OBJ): CC=$(LIBFT_CC)
$(BONUS_OBJ): CFLAGS=$(LIBFT_CFLAGS)
$(BONUS_OBJ): %.o: %.c %.d Makefile
	$(call compile)
	@$(DETECT_MANY_NON_STATIC)
	@$(call detect_forbidden_fn,External functions,$(GREP) -v "^T ",$(CONTINUE))

.PHONY: clean
clean:
	@$(PRINTF) "$(CMD)Cleaning$(NORMAL) $(FILE_TO_CLEAN).o$(NORMAL), $(FILE_TO_CLEAN).d$(NORMAL) and $(FILE_TO_CLEAN).Td$(NORMAL)"
	@$(DONE)
	@$(RM) $(TEST_OBJ) $(SRC_OBJ) $(BONUS_OBJ) $(DEP_FILES) $(DEP_FILES:%.d=%.Td)

.PHONY: tclean
tclean:
	@$(PRINTF) "$(CMD)Cleaning$(NORMAL) $(FILE_TO_CLEAN)$(TEST_BIN)$(NORMAL)"
	@$(DONE)
	@$(RM) $(TEST_BIN)

.PHONY: fclean
fclean: clean tclean

.PHONY: re
re: fclean all

.PHONY: test
test: all
	@$(PRINTF) "$(CMD)Launching$(NORMAL) tests\n"
	@./$(TEST_BIN)

##########
# Norme
##########
NORM_RULES = $(LIBFT_SRC:%=norm_%) $(BONUS_SRC:%=norm_%) norm_$(LIBFT_SRC_PATH)/libft.h

.PHONY: norm
norm: norm_init $(NORM_RULES) norm_done

$(eval $(call done,norm))

.PHONY: norm_init
norm_init:
	@$(PRINTF) "$(CMD)Checking$(NORMAL) norm for all files"
	@$(DOTS)

.PHONY: $(NORM_RULES)
$(NORM_RULES): norm_%:
	@$(PRINTF) "$(INVISIBLE)$(REPLACE_LINE)$(CMD)Checking$(NORMAL) norm for $(FILE)$*$(NORMAL)\n"
	@! $(NORM) "$*" | $(GREP) "^Error\|^Warning" --color -B 1 || ($(PRINTF) "$(VISIBLE)" && exit 1)
	@$(PRINTF) "$(MOVE_UP)$(VISIBLE)"

.PHONY: rose
rose: NORMAL:= $(shell $(TPUT) sgr0) $(MAGENTA)
rose: BLACK:= $(MAGENTA)
rose: RED:= $(MAGENTA)
rose: GREEN:= $(MAGENTA)
rose: YELLOW:= $(MAGENTA)
rose: BLUE:= $(MAGENTA)
rose: CYAN:= $(MAGENTA)
rose: WHITE:= $(MAGENTA)
rose: all
	@$(PRINTF) "$(shell $(TPUT) sgr0)"

.PHONY: unrose
unrose:
	@$(PRINTF) "$(NORMAL)"

$(DEP_FILES):

-include $(DEP_FILES)

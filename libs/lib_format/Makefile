##
## EPITECH PROJECT, 2024
## libformat
## File description:
## Makefile for libformat
##

###############################
# General build configuration #
###############################

LIBNAME = format
NAME = lib$(LIBNAME).a
SRCDIR = src

# General sources
SRC = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(SRC:.c=.o)

# General build settings
CFLAGS += -Wall -Wextra -Wno-unused-parameter -fno-builtin
CPPFLAGS += -Iinclude

LOADFLAGS = -l$(LIBNAME) '-L$(shell dirname $(NAME))'

###############################
# Testing build configuration #
###############################

TEST_PREFIX =
TEST_BINARY = ./tests/module_tests
#TEST_ARGS =
#TEST_ARGS = --verbose -j1

# Testing sources
TEST_SRC = $(shell find tests -name '*.c' 2>/dev/null)
TEST_OBJ = $(TEST_SRC:.c=.o)

TEST_CVF = $(SRC:.c=.gcno) $(SRC:.c=.gcda)
TEST_CVF += $(TEST_SRC:.c=.gcno) $(TEST_SRC:.c=.gcda)

TEST_CPPFLAGS = -Itests
TEST_CFLAGS = $(DEBUG_CFLAGS) -lcriterion --coverage

###################################
# Debug/extra build configuration #
###################################

# Debugging and testing environment settings
#DEBUG_PREFIX = valgrind --leak-check=full --track-origins=yes
DEBUG_BINARY = ./$(LIBNAME).debug.out

# Debug sources
DEBUG_SRC = $(shell find debug -name '*.c' 2>/dev/null)
DEBUG_OBJ = $(DEBUG_SRC:.c=.o)

DEBUG_CFLAGS = -g3 -O0
DEBUG_CPPFLAGS = -DOMG_DEBUG

##########################
# Makefile Extra Modules #
##########################

MAKE += --no-print-directory
LN ?= ln

get_cpr = 50
# Conditional for terminal support (color=auto)
ifeq ($(shell sh -c "tty >/dev/null && echo ok"), ok)
    LOG_INFO_STR = '\x1b[0%sm%s\x1b[0m\n'
    LOG_STEP_STR = '[%3d%%] '$(LOG_INFO_STR)
    log_info = printf $(LOG_INFO_STR) $(1) $(2)
    log_step = printf $(LOG_STEP_STR) $(1) $(2) $(3)
else
    LOG_INFO_STR = '%s\n'
    LOG_STEP_STR = '[%3d%%] '$(LOG_INFO_STR)
    log_info = printf $(LOG_INFO_STR) $(2)
    log_step = printf $(LOG_STEP_STR) $(1) $(3)
endif

######################################
# General (common) compilation rules #
######################################

# Default recipe
all: $(NAME)
	@$(call log_step,100,"0",'Built target $(NAME)')

# Logging replacement for C compilation
%.o : %.c
	@$(call log_step,$(call get_cpr,"$<"),"0;32","Building C object $@")
	@$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

# Logging replacement for C++ compilation (disabled)
%.o : %.cpp
	@$(call log_step,$(call get_cpr,"$<"),"0;32","Building CXX object $@")
	@$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

# Main compilation target
$(NAME): $(OBJ)
	@$(call log_step,100,"1;32","Building target $(NAME)")
	@$(AR) -rcs $(NAME) $(OBJ)

# Object file cleanup
clean:
	@$(call log_step,0,"0;33","Removing $(OBJ)")
	@$(RM) $(OBJ)

# Binary and object file cleanup
fclean: clean
	@$(call log_step,0,"1;33","Cleaning target $(NAME)")
	@$(RM) $(NAME)

# Forced recompilation
re: fclean
	@$(MAKE) all
	@$(call log_step,100,"0;36",'Rebuilt target $(NAME)')

######################################
# Testing (common) compilation rules #
######################################

# Test object compilation flags
$(TEST_OBJ): CFLAGS += $(TEST_CFLAGS) $(LOADFLAGS)
$(TEST_OBJ): CPPFLAGS += $(TEST_CPPFLAGS)

# Unit test build launcher (rebuilds library)
unit_tests: CFLAGS += $(TEST_CFLAGS)
unit_tests:
	@$(call log_info,"1;35","Building library")
	@CFLAGS="$(CFLAGS)" $(MAKE) all
	@$(call log_info,"1;35","Building test source")
	@$(MAKE) unit_build

# Unit test build system (requires a built library)
unit_build: CFLAGS += $(TEST_CFLAGS)
unit_build: $(TEST_OBJ)
	@$(call log_step,100,"1;32","Building test binary")
	@$(CC) $(CFLAGS) $(TEST_OBJ) $(LOADFLAGS) -o $(TEST_BINARY)
	@$(call log_step,100,"0",'Built tests for target $(NAME)')

# Test cleanup routine
tests_clean:
	@$(call log_step,0,"0;33","Removing $(TEST_OBJ)")
	@$(RM) $(TEST_OBJ)

# Test coverage file cleanup routine
tests_covr_clean:
	@$(call log_step,0,"0;33","Removing $(TEST_CVF)")
	@$(RM) $(TEST_CVF)

# Test binary cleanup routine
tests_fclean: tests_clean tests_covr_clean
	@$(call log_step,100,"1;33","Cleaning test binary for $(NAME)")
	@$(RM) $(TEST_BINARY)

TEST_COMMAND = $(TEST_PREFIX) $(TEST_BINARY) $(TEST_ARGS)

# Automatic test running recipe
tests_run: unit_tests
	@$(call log_info,"1;35","Running testing binary at $(TEST_BINARY)")
	@$(call log_info,"0;90","Executed in shell: '$(TEST_COMMAND)'")
	-@$(TEST_COMMAND)

# Forced recompilation and test rerun recipe
tests_retry:
	@$(call log_info,"1;35","Cleaning old compiled tests")
	@$(MAKE) fclean tests_fclean
	@$(MAKE) tests_run

# MISC : Full cleanup routine
clean_all: fclean tests_fclean im_fclean

###########################################
# Custom (app-specific) compilation rules #
###########################################

# Debug flag compilation
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: CPPFLAGS += $(DEBUG_CPPFLAGS)
debug: $(NAME)
	@$(call log_step,100,"0;35",'Built debug target $(NAME)')

docs:
	@$(call log_info,"1;35","Generating docs for $(NAME) using $(DOCGEN)")
	@$(DOCGEN) $(DOCGEN_FLAGS)
	@$(call log_step,100,"0;35",'Generated docs for $(NAME)')

docs_clean:
	@$(call log_step,100,"0;33","Removing docs: $(DOCGEN_OUTPUT)")
	@$(RM) -r $(DOCGEN_OUTPUT)

######################################
# Immediate test and debugging tools #
######################################

$(DEBUG_OBJ): CFLAGS += $(DEBUG_CFLAGS) $(LOADFLAGS)
$(DEBUG_OBJ): CPPFLAGS += $(DEBUG_CPPFLAGS)


im_test:
	@$(call log_info,"1;35","Building library in debug mode")
	@CFLAGS="$(CFLAGS)" $(MAKE) debug
	@$(call log_info,"1;35","Building debug exe source")
	@$(MAKE) im_build

im_build: CFLAGS += $(DEBUG_CFLAGS)
im_build: $(DEBUG_OBJ)
	@$(call log_step,100,"1;32","Building debug binary")
	@$(CC) $(CFLAGS) $(DEBUG_OBJ) $(LOADFLAGS) -o $(DEBUG_BINARY)
	@$(call log_step,100,"0",'Built debug tool for target $(NAME)')

DEBUG_COMMAND = $(DEBUG_PREFIX) $(DEBUG_BINARY)

im_run: im_test
	@$(call log_info,"1;35","Running debug binary at $(DEBUG_BINARY)")
	@$(call log_info,"0;90","Executed in shell: '$(DEBUG_COMMAND)'")
	-@$(DEBUG_COMMAND)

# Debug cleanup routine
im_clean:
	@$(call log_step,0,"0;33","Removing $(DEBUG_OBJ)")
	@$(RM) $(DEBUG_OBJ)

# Debug binary cleanup routine
im_fclean: im_clean
	@$(call log_step,100,"1;33","Cleaning debug binary $(DEBUG_BINARY)")
	@$(RM) $(DEBUG_BINARY)

# Phony recipes
.PHONY: all clean fclean re \
	unit_tests unit_build tests_clean tests_covr_clean \
	tests_fclean tests_run tests_retry clean_all \
	im_test im_build im_clean im_fclean im_run

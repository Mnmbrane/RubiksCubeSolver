CXX						= gcc
STANDARD_FLAGS			= -std=c++11
WARN_AS_ERRORS_FLAGS	= -pedantic-errors\
								-Wall\
								-Wextra\
								-Werror\
								-Wconversion
DEBUG_FLAGS          = -g3
OPT_FLAGS            = -O0
NO_LINKER_FLAGS      = -c
CPPFLAGS             = $(OPT_FLAGS) $(NO_LINKER_FLAGS) $(STANDARD_FLAGS) \
                       $(WARN_AS_ERRORS_FLAGS)

VPATH = src
# Source files, headers, etc.:
ROOT = $(CURDIR)
INCLUDES = -I$(ROOT)/include -I$(ROOT)/third_party

SRCS = ./src/RCSIO.cpp

OBJS = RCSIO.o

LIB_DIR = ./lib
MAIN = libRubiksCubeSolver.a # static library

.PHONY: all
all: $(MAIN)
	mv $(MAIN) $(LIB_DIR)/$(MAIN)

$(MAIN): $(OBJS)
	ar -r $(MAIN) $(OBJS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

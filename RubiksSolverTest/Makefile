CXX						= gcc
STANDARD_FLAGS			= -std=c++11
WARN_AS_ERRORS_FLAGS	= -pedantic-errors\
								-Wall\
								-Wextra\
								-Werror\
								-Wconversion
DEBUG_FLAGS          = -ggdb
CPPFLAGS             = $(STANDARD_FLAGS) $(WARN_AS_ERRORS_FLAGS)

VPATH = ./

INCLUDES=-Iinclude -Ithird_party

SRCS = Source.cpp

OBJS = Source.o

LIB_DIR = -L./lib

LIBS =	-lRubiksCubeSolver \
			-lgtest \
			-lgtest_main \
			-lstdc++ \
			-lpthread

.PHONY: all
all: $(OBJS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(DEBUG_FLAGS) $(INCLUDES) $< -o $@ $(LIB_DIR) $(LIBS)


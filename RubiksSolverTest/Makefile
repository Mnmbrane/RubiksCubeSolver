include ../MakeInclude

DEBUG_FLAGS          = -ggdb
CPPFLAGS             = $(STANDARD_FLAGS) $(WARN_AS_ERRORS_FLAGS) $(DEBUG_FLAGS)

VPATH = ./

INCLUDES=	-I./../$(PROJECT)/include \
				-I./../$(PROJECT)/include/CubeTypes \
				-I./../$(PROJECT)/third_party \
				-Iinclude

SRCS = TestDriver.cpp

OBJS = TestDriver.o

LIB_DIR =	-L./lib \
				-L./../$(PROJECT)/lib

LIBS =	-lRubiksCubeSolver \
			-lgtest \
			-lgtest_main \
			-lstdc++ \
			-lpthread

.PHONY: all
all: $(OBJS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDES) $< -o $@ $(LIB_DIR) $(LIBS)

.PHONY: clean
clean:
	rm -rf *.o
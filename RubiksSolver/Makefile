include ../MakeInclude
OPT_FLAGS            = -O0
NO_LINKER_FLAGS      = -c
CPPFLAGS             = $(OPT_FLAGS) $(NO_LINKER_FLAGS) $(STANDARD_FLAGS) \
                       $(WARN_AS_ERRORS_FLAGS) $(DEBUG_FLAGS)

VPATH =	src \
			src/CubeTypes

# Source files, headers, etc.:
INCLUDES =	-Iinclude \
				-Iinclude/CubeTypes \
				-Ithird_party

SRCS =	./src/RCSIO.cpp \
			./src/CubeTypes/CubeFace.cpp \
			./src/CubeTypes/Cube.cpp

OBJS =	RCSIO.o \
			CubeFace.o \
			Cube.o

LIB_DIR = ./lib
MAIN = libRubiksCubeSolver.a # static library

.PHONY: all
all: $(MAIN)
	mv $(MAIN) $(LIB_DIR)/$(MAIN)
	rm -rf *.o

$(MAIN): $(OBJS)
	ar -r $(MAIN) $(OBJS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(LIB_DIR)/*.a *.o

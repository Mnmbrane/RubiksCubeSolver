include ../MakeInclude
OPT_FLAGS            = -O0
NO_LINKER_FLAGS      = -c
CPPFLAGS             = $(OPT_FLAGS) $(NO_LINKER_FLAGS) $(STANDARD_FLAGS) \
                       $(WARN_AS_ERRORS_FLAGS) $(DEBUG_FLAGS)

VPATH =	src \
			src/CubeTypes \
			Algorithm/3x3

# Source files, headers, etc.:
INCLUDES =	-Iinclude \
				-Iinclude/CubeTypes \
				-Ithird_party \
				-IAlgorithms/include

SRCS =	CubeManager.cpp \
			RCSIO.cpp \
			CubeFace.cpp \
			Cube.cpp

OBJS := $(SRCS:%.cpp=%.o)

BIN_DIR := bin
LIB_DIR := lib

LIB = libRubiksCubeSolver.a # static library

.PHONY: all
all: $(LIB_DIR)/$(LIB)

$(LIB_DIR)/$(LIB): $(OBJS)
	mkdir -p '$(@D)'
	ar -r $(LIB_DIR)/$(LIB) $(OBJS)

%.o: %.cpp
	mkdir -p '$(@D)'
	$(CXX) $(CPPFLAGS) $(INCLUDES)  -c $< -o $@


.PHONY: clean
clean:
	rm -rf *.a *.o

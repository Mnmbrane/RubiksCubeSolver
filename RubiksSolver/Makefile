EXE = source
CXX=g++

SRC_DIR = src
OBJ_DIR = obj

SRC = Rotate.cpp
OBJ = Rotate.o

CPPFLAGS += -Iinclude
CFLAGS += -Wall
LDFLAGS += -Llib
LDLIBS += -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ): $(SRC_DIR)/$(SRC)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
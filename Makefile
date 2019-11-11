ROOT = $(CURDIR)
PROJECT = $(ROOT)/RubiksSolver
TEST_PROJECT = $(ROOT)/RubiksSolverTest
.PHONY: all
all:
	(cd $(PROJECT); mkdir lib; make all; rm -rf *.o)
	(cd $(TEST_PROJECT); mkdir lib; cp $(PROJECT)/lib/* $(TEST_PROJECT)/lib; make all)

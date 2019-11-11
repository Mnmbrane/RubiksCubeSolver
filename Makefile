ROOT = $(CURDIR)
PROJECT = $(ROOT)/RubiksSolver
TEST_PROJECT = $(ROOT)/RubiksSolverTest

.PHONY: all
all:
	(cd $(PROJECT); mkdir lib; make all)
	(cd $(TEST_PROJECT); mkdir lib; cp $(PROJECT)/lib/* $(TEST_PROJECT)/lib; make all)

.PHONY: clean
clean:
	rm -rf $(PROJECT)/lib
	rm -rf $(TEST_PROJECT)/lib
	rm -rf $(PROJECT)/*.o
	rm -rf $(TEST_PROJECT)/*.o
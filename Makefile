ROOT = $(CURDIR)
PROJECT = $(ROOT)/RubiksSolver
TEST_PROJECT = $(ROOT)/RubiksSolverTest

.PHONY: all
all:
	(cd $(PROJECT); make all)
	(cd $(TEST_PROJECT); cp $(PROJECT)/lib/* $(TEST_PROJECT)/lib; make all)

.PHONY: clean
clean:
	rm -rf $(PROJECT)/*.o
	rm -rf $(TEST_PROJECT)/*.o
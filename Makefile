include MakeInclude

.PHONY: all
all:
	(cd $(PROJECT); make all )
	(cd $(TEST_PROJECT); make all)

.PHONY: clean
clean:
	(cd $(PROJECT); make clean)
	(cd $(TEST_PROJECT); make clean)
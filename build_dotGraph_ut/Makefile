
export MAKEFILE_ABS_PATH=$(abspath $(lastword $(MAKEFILE_LIST)))
export MAKEFILE_DIR=$(shell dirname $(MAKEFILE_ABS_PATH))
export PROJECT_ROOT_DIR=$(shell dirname $(MAKEFILE_DIR))
export SRC_DIR=$(PROJECT_ROOT_DIR)/src
export TESTS_DIR=$(PROJECT_ROOT_DIR)/tests
export ARTIFACTS_DIR=$(MAKEFILE_DIR)/artifacts

all: clex

clex: artifacts
	@echo "-------------------------------------------"
	@echo "Building executable:"
	gcc -o $(ARTIFACTS_DIR)/testDotGraph -g $(ARTIFACTS_DIR)/testDotGraph.o $(ARTIFACTS_DIR)/dotGraph.o

artifacts: source
	@echo "-------------------------------------------"
	echo "Creating ARTIFACTS_DIR = $(ARTIFACTS_DIR)"
	rm -rf $(ARTIFACTS_DIR)
	mkdir $(ARTIFACTS_DIR)

	@echo "Compiling: "
	gcc -o $(ARTIFACTS_DIR)/dotGraph.o -c -g $(SRC_DIR)/dotGraph.c

	@echo "-------------------------------------------"
	@echo "Compiling: "
	gcc -o $(ARTIFACTS_DIR)/testDotGraph.o -c -g $(TESTS_DIR)/testDotGraph.c


source:
	@echo "-------------------------------------------"
	@echo "SRC_DIR = $(SRC_DIR)"
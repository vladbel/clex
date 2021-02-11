
export MAKEFILE_ABS_PATH=$(abspath $(lastword $(MAKEFILE_LIST)))
export MAKEFILE_DIR=$(shell dirname $(MAKEFILE_ABS_PATH))
export PROJECT_ROOT_DIR=$(shell dirname $(MAKEFILE_DIR))
export SRC_DIR=$(PROJECT_ROOT_DIR)/src
export ARTIFACTS_DIR=$(MAKEFILE_DIR)/artifacts
export COMPONENT_DIR=$(SRC_DIR)/task

all: clex

clex: artifacts
	@echo "-------------------------------------------"
	@echo "Building executable:"
	gcc -o $(ARTIFACTS_DIR)/testTask -g $(ARTIFACTS_DIR)/*.o

artifacts: component
	@echo "-------------------------------------------"
	@echo "4 - Compiling test: "
	gcc -c -g $(SRC_DIR)/task/test/testTask.c -o $(ARTIFACTS_DIR)/testTask.o

component: clean
	@echo "-------------------------------------------"
	@echo "2 - Compiling component: "
	cd $(COMPONENT_DIR) && $(MAKE)

clean: source
	@echo "-------------------------------------------"
	@echo "1 - Clean artifacts"	
	rm -rf $(ARTIFACTS_DIR)
	mkdir $(ARTIFACTS_DIR)

source:
	@echo "-------------------------------------------"
	@echo "SRC_DIR = $(SRC_DIR)"
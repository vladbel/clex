
export MAKEFILE_ABS_PATH=$(abspath $(lastword $(MAKEFILE_LIST)))
export MAKEFILE_DIR=$(shell dirname $(MAKEFILE_ABS_PATH))
export PROJECT_ROOT_DIR=$(shell dirname $(MAKEFILE_DIR))
export SRC_DIR=$(PROJECT_ROOT_DIR)/src
export ARTIFACTS_DIR=$(MAKEFILE_DIR)/artifacts

all: clex

clex: artifacts
	@echo "-------------------------------------------"
	@echo "Building executable:"
	gcc -o $(ARTIFACTS_DIR)/clex -g $(ARTIFACTS_DIR)/main.o $(ARTIFACTS_DIR)/app.o

artifacts: source
	@echo "-------------------------------------------"
	echo "Creating ARTIFACTS_DIR = $(ARTIFACTS_DIR)"
	rm -rf $(ARTIFACTS_DIR)
	mkdir $(ARTIFACTS_DIR)

	@echo "-------------------------------------------"
	@echo "Compiling: "
	gcc -o $(ARTIFACTS_DIR)/main.o -c -g $(SRC_DIR)/main.c
	@echo "Compiling: "
	gcc -o $(ARTIFACTS_DIR)/app.o -c -g $(SRC_DIR)/app.c

source:
	@echo "-------------------------------------------"
	@echo "SRC_DIR = $(SRC_DIR)"
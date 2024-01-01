# Project based on Qt lib on Qt Creator
# On Ubumtu some lib need to install
# sudo apt install build-essential mesa-common-dev cmake clang qtcreator 
# qt6-base-dev qml-qt6 qt6-wayland
# Some commands must be used
# sudo update-alternatives --install /usr/bin/qmake qmake /usr/bin/qmake6 100
# sudo update-alternatives --config qmake
# 
# May some of this not need
# 
# 

CC = gcc
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV = --coverage
TARGET = S21_MLP
TESTS = tests.out
OS = $(shell uname -s)
GT_FLAGS = -DTESTS_OBJ_PATH='"$(shell pwd)/src/tests/obj"' -lgtest_main -lgtest -lm -lstdc++ -pthread -lm -g
PRO_FILE = src/view/mlp_qt_view/mlp_qt_view.pro

#  Project files and directories
BUILD_DIR = build
FOLDERS = src/controller/*.h src/model/*.h src/model/*.cc src/tests/*.cc src/ogl/*.h src/ogl/*.cc

ifeq ($(OS), Darwin)
    LIBS := -lcheck
	APPLICATION = $(TARGET).app
	OPEN = open $(APPLICATION)
else
    LIBS := -lgtest -lstdc++ -lcheck_pic -lrt -lpthread -lsubTESTS -lm -g
	APPLICATION = $(TARGET)
	OPEN = ./$(APPLICATION)
endif

all: install

install:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake CONFIG+=qtquickcompiler ../$(PRO_FILE) && make
	make open

uninstall: clean

clean:
	rm -r ./$(BUILD_DIR)

dvi:
	open dvi.html

dist:
	rm -rf Archive_3dviewer1.0/
	mkdir -p Archive_3dviewer1.0/
	mv ./3dviewer/$(APPLICATION) Archive_3dviewer1.0/src/
	tar cvzf Archive_3dviewer1.0.tgz Archive_3dviewer1.0/
	rm -rf Archive_3dviewer1.0/

tests:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(MACRO) $(GT_FLAGS) src/model/*.cc src/tests/*.cc -o $(BUILD_DIR)/$(TESTS)
	./$(BUILD_DIR)/$(TESTS)

open:
	cd $(BUILD_DIR) && $(OPEN)

t:
	./$(BUILD_DIR)/$(TESTS)

valgrind: tests
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TESTS)

v: install
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(APPLICATION)

clang:
	clang-format -style=file:./materials/linters/.clang-format -n $(FOLDERS)
	clang-format -style=file:./materials/linters/.clang-format -i $(FOLDERS)
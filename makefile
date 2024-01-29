all: compile

compile:
	clang++  -g -o main tests/main.cpp src/*.cpp 
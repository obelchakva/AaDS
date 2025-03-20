CXX := g++
CFLAGS := -Wall -Wextra -O2 -std=c++17
LIBS := -lgtest -lpthread

all: ascii85_main unit_tests

ascii85_main: ascii85_encoder.cpp main.cpp
	$(CXX) $(CFLAGS) -o $@ $^

unit_tests: unit_tests.cpp
	$(CXX) $(CFLAGS) $(LIBS) -o $@ $^

.PHONY: clean test run_tests

clean:
	rm -f ascii85_main unit_tests *.o

test: unit_tests
	./unit_tests

run_tests: test
	python3 random_tests.py

# Определяем компилятор
CXX := g++

# Устанавливаем флаги компиляции
CFLAGS := -Wall -Wextra -O2 -std=c++17

# Определяем флаги линковки
LIBS := -lgtest -lpthread

# Цель all: создает обе цели ascii85_main и unit_tests
all: ascii85_main unit_tests

# Цель ascii85_main: собирает исполняемый файл ascii85_main
ascii85_main: ascii85_encoder.cpp main.cpp
	$(CXX) $(CFLAGS) -o $@ $^

# Цель unit_tests: собирает исполняемый файл unit_tests
unit_tests: unit_tests.cpp ascii85_encoder.cpp
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBS)

# Цель clean: очищает все сгенерированные файлы
.PHONY: clean
clean:
	rm -f ascii85_main unit_tests *.o

# Цель test: запускает unit_tests
.PHONY: test
test: unit_tests
	./unit_tests

# Цель run_tests: запускает python тесты
.PHONY: run_tests
run_tests: test
	python3 random_tests.py

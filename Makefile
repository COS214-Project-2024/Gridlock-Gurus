# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = 
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = main

# Code Coverage Flags
COVFLAGS = --coverage
COV_OUTPUT = coverage_report

# Targets
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) *.gcno *.gcda $(COV_OUTPUT) *.gcov

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

coverage: CXXFLAGS += $(COVFLAGS)
coverage: LDFLAGS += $(COVFLAGS)
coverage: clean all
	./$(TARGET)
	gcov $(SRC)
	mkdir -p $(COV_OUTPUT)
	mv *.gcov $(COV_OUTPUT)

# Phony targets
.PHONY: all run clean memcheck coverage


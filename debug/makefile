CXX = g++
EXEC = BasicWind
DEBUG = $(EXEC)_DEBUG

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

DEBUG_ARGS = -Wall -Wextra -Werror -ggdb

all : $(EXEC)

debug : $(DEBUG)

*.o : *.cpp
	$(CXX) -o $@ -c $< 

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ 

$(DEBUG) : $(OBJ)
	$(CXX) -o $@ $^  $(DEBUG_ARGS)

clean :
	rm *.o

mrproper : clean
	rm $(EXEC)

run :
	./$(EXEC)

run_debug :
	./$(DEBUG)

gdb_debug :
	gdb $(DEBUG)
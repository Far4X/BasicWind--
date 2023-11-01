#Problème : mettre le makefile plus bas dans l'arbo pour pouvoir compiler également les classes
#Useless. Utiliser le compilateur fourni avec l'ide


CXX = g++
EXEC = BasicWind
DEBUG = $(EXEC)_DEBUG

FOLDER = debug

SRC = $(wildcard $(FOLDER)/*.cpp) 
OBJ = $(SRC:.cpp=.o)

DEBUG_ARGS = -Wall -Wextra -Werror -ggdb

all : $(EXEC)

debug : $(DEBUG)

*.o : *.cpp
	$(CXX) -c $<  -ld2d1 -o $@  

$(EXEC) : $(OBJ)
	$(CXX) $^ -ld2d1 -o $@ 

$(DEBUG) : $(OBJ)
	$(CXX) -o $@ $^  $(DEBUG_ARGS) 
clean :
	rm *.o
#Commande linux : modif

mrproper : clean
	rm $(EXEC)

run :
	./$(EXEC)

run_debug :
	./$(DEBUG)

gdb_debug :
	gdb $(DEBUG)
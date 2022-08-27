#Environment settings

CC = g++
CFLAGS = -g -Wall

#Variables

MAIN   = main
AGR    = argument_proccessing
FILE_W = file_work
ONEGIN = onegin
SORT   = sort

#Body

all : $(MAIN)

$(MAIN)     : $(MAIN).o $(ONEGIN).o $(FILE_W).o $(SORT).o 
	$(CC) $(CFLAGS) $^ -o $@   

$(MAIN).o   : $(MAIN).cpp
	$(CC) $(CFLAGS) $< -c 
	  
$(ONEGIN).o : $(ONEGIN).cpp $(FILE_W).cpp 
	$(CC) $(CFLAGS) $< -c 

$(FILE_W).o : $(FILE_W).cpp 
	$(CC) $(CFLAGS) $< -c

$(SORT).o   : $(SORT).cpp
	$(CC) $(CFLAGS) $< -c 

clean:
	rm -rf *.o *.save $(MAIN)
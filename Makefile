#------------------------------------------------------------------------------
# Makefile for War
#------------------------------------------------------------------------------

CLIENT1        = main
#ADT1           = Card
SOURCE1        = $(CLIENT1).cpp
OBJECT1        = $(CLIENT1).o
#ADT1_SOURCE    = $(ADT1).cpp
#ADT1_OBJECT    = $(ADT1).o
#ADT1_HEADER    = $(ADT1).h
COMPILE        = g++ -Wall -std=c++11
LINK           = g++ -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full --track-origins=yes

$(CLIENT1) : $(OBJECT1)
	$(LINK) $(CLIENT1) $(OBJECT1)

$(OBJECT1) : $(SOURCE1)
	$(COMPILE) -c $(SOURCE1)

clean :
	$(REMOVE) $(CLIENT1) $(OBJECT1)

memcheck : $(CLIENT1)
	$(MEMCHECK) $(CLIENT1)





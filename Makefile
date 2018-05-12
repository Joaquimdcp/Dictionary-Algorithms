#------------------------------------------------------------------------------

SOURCE=main.cpp hash.o bst.o dichotomic_quim.o
MYPROGRAM=main

CC=g++ -std=c++11

#------------------------------------------------------------------------------



all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)

	$(CC) -o $(MYPROGRAM) $(SOURCE)

clean:

	rm -f $(MYPROGRAM)
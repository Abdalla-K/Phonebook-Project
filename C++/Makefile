output: Phonebook.o Contact.o main.o
	g++ Phonebook.o Contact.o main.o -o output -g -Wall -Wextra

Phonebook.o: Phonebook.cpp Phonebook.h
	g++ -c Phonebook.cpp -g -Wall -Wextra

Contact.o: Contact.cpp Contact.h
	g++ -c Contact.cpp -g -Wall -Wextra

main.o: main.cpp Phonebook.h Contact.h
	g++ -c main.cpp -g -Wall -Wextra

.PHONY: clean
clean:
	rm -f *.o output
autocomplete-big-list: main.o city.o
	clang++ -pedantic -o autocomplete-big-list main.o city.o

main.o: main.cpp
	clang++ -pedantic -c main.cpp

city.o: city.cpp
	clang++ -pedantic -c city.cpp

clean:
	rm -f *.o autocomplete-big-list


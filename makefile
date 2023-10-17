# Workshop Makefile

workshop: main.o
	g++ -o CombatSystem main.o

main.o: main.cpp CombatSystem.cpp
	g++ -c main.cpp

run:
	./main
	
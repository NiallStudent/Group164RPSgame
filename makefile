game: main.cpp CombatSystem.cpp	
	g++ main.cpp CombatSystem.cpp -o main
	./main

test:
	g++ UnitTest.cpp -o UnitTest
	./UnitTest
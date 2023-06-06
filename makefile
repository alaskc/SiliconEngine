all:
	g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system -o md.exe -std=c++17 -Wpedantic
	./md.exe
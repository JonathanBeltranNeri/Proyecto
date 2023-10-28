bin/Tetris 	: src/Tetris.cpp include/*.hpp 
	c++ src/Tetris.cpp -I include -o bin/Tetris -lcurses


	
run : bin/Tetris
	./bin/Tetris
	
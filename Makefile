all:
	@g++ -std=c++11 -o bin/life src/grid.cpp src/cell.cpp src/controller.cpp

clean: 
	@rm bin/*
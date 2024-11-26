all: clock clockExcept main.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp clock clockExcept -o main
clock: clock.h clock.cpp clockExcept
	g++ -pedantic-errors -fdiagnostics-color=always -g -c clock.cpp -o clock
clockExcept: clockExcept.h clockExcept.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g -c clockExcept.cpp -o clockExcept
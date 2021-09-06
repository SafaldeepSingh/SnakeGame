#pragma once
#include "Coordinate.h";
#include "ConsoleWriter.h";
using namespace utility;
class Apple
{
private:
	Coordinate coord;
	ConsoleWriter writer;

public:
	Apple();
	Coordinate getCoord();

	void draw(Coordinate coord);
	void erase();
};


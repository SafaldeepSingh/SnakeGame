#pragma once
#include "Coordinate.h";
#include "ConsoleWriter.h";
using utility::Coordinate;
using utility::ConsoleWriter;
class Map
{
private:
	Coordinate topLeft, BottomRight;
	ConsoleWriter writer;
public:
	Map();
	Map(Coordinate topLeft, Coordinate BottomRight);
private:
	void draw();
};


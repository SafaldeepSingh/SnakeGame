#include "Apple.h";

Apple::Apple()
	: coord(Coordinate(-1,-1))
{
}

Coordinate Apple::getCoord()
{
	return coord;
}

void Apple::draw(Coordinate coord)
{
	this->coord = coord;
	writer.setCharacterAtPosition(coord,'X');
}

void Apple::erase()
{
	writer.setCharacterAtPosition(coord, ' ');
}


#include "Map.h"

Map::Map():Map(Coordinate(0,0), Coordinate(40, 40)) 
{
}
Map::Map(Coordinate topLeft, Coordinate BottomRight)
	:topLeft(topLeft),BottomRight(BottomRight),writer()
{
	draw();
}

void Map::draw()
{
	writer.drawRectangle(topLeft, BottomRight);
}
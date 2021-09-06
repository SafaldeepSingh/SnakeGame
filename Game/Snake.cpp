#include "Snake.h";

Snake::Snake(deque<Coordinate> bodyCoords, double speed, short direction)
	:bodyCoords(bodyCoords),direction(direction),speed(speed),length(bodyCoords.size()),writer()
	,lastErased(Coordinate(-1, -1))
{
	draw();
}

deque<Coordinate> Snake::getSnakeBodyCoords() {
	return bodyCoords;
}
short Snake::getDirection() { return direction; }
void Snake::setDirection(short direction) { this->direction = direction; }


void Snake::grow() {
	bodyCoords.push_back(lastErased);
}
void Snake::move() {
	Coordinate last = bodyCoords.back();
	lastErased = last;
	if (direction == 0) {
		bodyCoords.pop_back();
		bodyCoords.push_front(Coordinate(bodyCoords[0].X, bodyCoords[0].Y-1));
	}
	else if (direction == 1) {
			bodyCoords.pop_back();
			bodyCoords.push_front(Coordinate(bodyCoords[0].X, bodyCoords[0].Y + 1));
	}
	else if (direction == 2) {
			bodyCoords.pop_back();
			bodyCoords.push_front(Coordinate(bodyCoords[0].X-1, bodyCoords[0].Y));
	}
	else if (direction == 3) {
			bodyCoords.pop_back();
			bodyCoords.push_front(Coordinate(bodyCoords[0].X+1, bodyCoords[0].Y));
	}
	writer.setCharacterAtPosition(last.X, last.Y, ' ');
	draw();
}

void Snake::draw() {
	for (int i = 0; i < bodyCoords.size(); i++) {
		writer.setCharacterAtPosition(bodyCoords[i].X, bodyCoords[i].Y, 'O');
	}
}


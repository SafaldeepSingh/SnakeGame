#pragma once
#include "Coordinate.h";
#include "Strings.h"
#include "Console.h";
#include "ConsoleWriter.h";
#include "Time.hh"
using utility::Time;
using utility::Strings;
using utility::Console;
using utility::Coordinate;
using utility::ConsoleWriter;
class Player
{
private:
	int score;
	int	snakeInitialLength;
	Time time;
	Coordinate topLeft;
	Coordinate bottomRight;
	ConsoleWriter writer;
public: 
	Player(Coordinate topLeft, Coordinate bottomRight, int snakeInitialLength);

	int getScore();
	void increaseScore();
	void drawScore();

};


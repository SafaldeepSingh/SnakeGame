#pragma once
#include "ConsoleReader.h";
#include "ConsoleWriter.h";
#include "Map.h";
#include "Snake.h";
#include "Apple.h";
#include "Player.h";

#include "Coordinate.h";
#include <vector>
#include <deque>
using namespace utility;
using namespace std;
class Game
{
private:
	const Coordinate TOPLEFT= Coordinate(0,0);
	const Coordinate BOTTOMRIGHT= Coordinate(50,30);
	const int snakeInitialLength = 10;
	Map map;
	Snake snake;
	Apple apple;
	Player player;
	ConsoleWriter writer;
	ConsoleReader reader;
public:
	Game();
	~Game();
	void start();
	bool isGameOver();
private:
	void update();
	Coordinate getAppleCoord();
	void displayGameOver();
	deque<Coordinate> getInitSnakeCoords();
	bool didSnakeHitWall();
	bool didSnakeHitItself();
	bool didSnakeEatApple();
	bool isValidMove();
};


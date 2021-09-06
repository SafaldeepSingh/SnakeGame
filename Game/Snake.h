#pragma once
#include<vector>
#include<deque>
#include<string>
#include"Coordinate.h";
#include"ConsoleWriter.h";
using utility::Coordinate;	
using utility::ConsoleWriter;	
using namespace std;
class Snake
{
private:
	deque<Coordinate> bodyCoords;
	int length;
	double speed;
	short direction;//0 for UP 1 for DOWN 2 for LEFT 3 for RIGHT
	ConsoleWriter writer;
	Coordinate lastErased;
public: 
	Snake(deque<Coordinate> bodyCoords, double speed, short direction);

	deque<Coordinate> getSnakeBodyCoords();
	void setDirection(short direction);
	short getDirection();

	void grow();
	void move();
private: 
	void draw();
};


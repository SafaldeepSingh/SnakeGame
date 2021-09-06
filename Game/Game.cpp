#include "Game.h";

Game::Game() 
	:map(TOPLEFT,BOTTOMRIGHT)
	,snake(getInitSnakeCoords(),0,2)
	,apple()
	,player(TOPLEFT, BOTTOMRIGHT, snakeInitialLength)
	,writer(),reader()
{}
Game::~Game() {
	writer.clear();
}
void Game::start() {
	//Initialize Game Objects
	writer.setWindowSize(BOTTOMRIGHT.X - TOPLEFT.X + 1, BOTTOMRIGHT.Y - TOPLEFT.Y + 3);
	writer.setCursorVisible(false);
	//draw apple
	apple.draw(getAppleCoord());

	while (!reader.isEscapePressed()) {
		update();
		// check snake hit the wall?
		// 	check snake hit itself?
		if (didSnakeHitWall() == 1 || didSnakeHitItself()==1) {
			// 	   Game Over
			displayGameOver();
			break;
		}
		// use sleep() 20 or 30 milisecond
		Sleep(100);
	}
}


void Game::update() {
	// update game status
	// draw the new game state
	player.drawScore();
	// check user input
	// update snake direction
	if (snake.getDirection() == 0 || snake.getDirection() == 1)
	{
		if (reader.isLeftArrowPressed()) snake.setDirection(2);
		else if (reader.isRightArrowPressed()) snake.setDirection(3);
	}
	else if (snake.getDirection() == 2 || snake.getDirection() == 3)
	{
		if (reader.isUpArrowPressed()) snake.setDirection(0);
		else if (reader.isDownArrowPressed()) snake.setDirection(1);
	}

	// Move the snake
	//if(isValidMove())
		snake.move();

	// Check snake eat apple?
	if (didSnakeEatApple() == 1) {
		// increase score, snake length
		snake.grow();
		player.increaseScore();
		// 	Place apple new place
		apple.erase();
		apple.draw(getAppleCoord());
	}

}
void Game::displayGameOver() 
{
	Coordinate lastCord = writer.getCursorPosition();
	writer.setCursorPosition(10,5);
	Console::writeLine("GAME OVER.!! Want to Play again?(Y/N)" );
	writer.setCursorPosition(20, 6);
//	writer.setCursorPosition(lastCord);
}
Coordinate Game::getAppleCoord()
{
	bool onSnake;
	Coordinate coord = Coordinate(-1,-1);
	do {
		int x = rand() % (BOTTOMRIGHT.X - TOPLEFT.X - 1) + 1;
		int y = rand() % (BOTTOMRIGHT.Y - TOPLEFT.Y - 1) + 1;
		coord = Coordinate(x, y);
		onSnake= false;
		deque<Coordinate> snakeCoords = snake.getSnakeBodyCoords();
		for (int i = 0; i < snakeCoords.size(); i++) {
			if (coord == snakeCoords[i])
			{
				onSnake = true;
				break;
			}
		}
	} while (onSnake);
	return coord;
}
deque<Coordinate> Game::getInitSnakeCoords() {
	int x = (BOTTOMRIGHT.X - TOPLEFT.X-snakeInitialLength) / 2;
	int y = (BOTTOMRIGHT.Y - TOPLEFT.Y) / 2;
	deque<Coordinate> coords;
	for (int i = 0; i < 10; i++) {
		coords.push_back(Coordinate(x+i,y));
	}
	return coords;
}

bool Game::didSnakeHitWall() {
	bool hits = false;
	deque<Coordinate> coords = snake.getSnakeBodyCoords();
	for (int i = 0; i < coords.size(); i++) 
	{
		if(coords[i].X==TOPLEFT.X || coords[i].X == BOTTOMRIGHT.X || coords[i].Y == TOPLEFT.Y || coords[i].Y == BOTTOMRIGHT.Y)
		{
			return true;
		}
	}
}
bool Game::didSnakeHitItself() {
	bool hits = false;
	deque<Coordinate> coords = snake.getSnakeBodyCoords();
	for (int i = 0; i < coords.size(); i++) {
		for (int j = 0; j < coords.size(); j++) {
			if (i == j)	continue;
			if (coords[i] == coords[j])
				return true;
		}
	}
}

bool Game::didSnakeEatApple() {
	bool eats = false;
	deque<Coordinate> coords = snake.getSnakeBodyCoords();
	for (int i = 0; i < coords.size(); i++)
	{
		if (coords[i]==apple.getCoord())
		{
			return true;
		}
	}
}

bool Game::isValidMove()
{
	int direction = snake.getDirection();
	int x = snake.getSnakeBodyCoords()[0].X;
	int y = snake.getSnakeBodyCoords()[0].Y;
	bool notValid = (y - 1 == TOPLEFT.Y && direction == 0)
		|| (y + 1 == BOTTOMRIGHT.Y && direction == 1)
		|| (x - 1 == TOPLEFT.X && direction == 2)
		|| (x + 1 == BOTTOMRIGHT.X && direction == 3);
	return !notValid;
}
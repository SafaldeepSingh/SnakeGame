#include "Player.h"

Player::Player(Coordinate topLeft, Coordinate bottomRight,int snakeInitialLength) 
	:score(0), snakeInitialLength(snakeInitialLength), time(Time::getNow()),
	topLeft(topLeft),bottomRight(bottomRight),writer()
{
	drawScore();
}
int Player::getScore()
{
	return score;
}
void Player::increaseScore() 
{
	score++;
}
void Player::drawScore()
{
	int hours = time.getHoursUntil(Time::getNow());
	int minutes = time.getMinutesUntil(Time::getNow());
	int seconds = time.getSecondsUntil(Time::getNow());
	writer.setCursorPosition((bottomRight.X-topLeft.X-46)/2, (bottomRight.Y + 1));//46

	Console::writeLine("SCORE: " + Strings::integerToString(score,4) +
		"    LENGTH: " + Strings::integerToString((score + snakeInitialLength),4) +
		"    TIME: "+ Strings::integerToString(hours,2)
		+":"+Strings::integerToString(minutes,2)+":" 
		+ Strings::integerToString(seconds,2));
}

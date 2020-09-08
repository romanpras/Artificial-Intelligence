#include "Bullet.h"
#include "GLUT.H"
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Bullet::Bullet()
{
	this->isMoving = false;
}

Bullet::Bullet(double x, double y)
{
	double len;
	this->x = x;
	this->y = y;
	this->power = 30;
	isMoving = false;
}

Bullet::Bullet(double x, double y, double dirx, double diry)
{
	this->x = x;
	this->y = y;
	this->dirx = dirx;
	this->diry = diry;
	this->isMoving = false;

}

Bullet::~Bullet()
{
}

void Bullet::showMe()
{

	glColor3d(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(x - 0.01, y);
	glVertex2d(x, y + 0.01);
	glVertex2d(x + 0.01, y);
	glVertex2d(x, y - 0.01);
	glEnd();
}

void Bullet::SetIsMoving(bool move)
{
	isMoving = move;
}

bool Bullet::GetIsMoving()
{
	return isMoving;
}

void Bullet::move(Node(&maze)[MSZ][MSZ])
{
	int i, j;
	i = MSZ * (y + 1) / 2;
	j = MSZ * (x + 1) / 2;

	if (maze[i][j].GetValue() == SPACE)
	{
		if(this->power>0)
			this->power -= 0.1;
		x += 0.001 * dirx;
		y += 0.001 * diry;
		this->showMe();
	}
}
bool Bullet::simulateMove(Node(&maze)[MSZ][MSZ])
{
	int i, j;
	i = MSZ * (y + 1) / 2;
	j = MSZ * (x + 1) / 2;
	if (maze[i][j].GetValue() == SPACE)
	{
		if(this->power>0)
			this->power -= 0.1;
		if (this->power <= 0)
			return false;
		x += 0.01 * dirx;
		y += 0.01 * diry;
		return true;
	}
	else
	{
		return false;
	}
}
double Bullet::getX()
{
	return x;
}

void Bullet::setX(double x)
{
	this->x = x;
}

void Bullet::setY(double y)
{
	this->y = y;
}

double Bullet::getY()
{
	return y;
}

double Bullet::getPower()
{
	return this->power;
}

void Bullet::setPower(double power)
{
	this->power = power;
}

void Bullet::SetDir(double angle)
{
	dirx = cos(angle);
	diry = sin(angle);
}

void Bullet::SimulateMotion(Node(&maze)[MSZ][MSZ])
{
	int i, j;
	i = MSZ * (y + 1) / 2;
	j = MSZ * (x + 1) / 2;

	while (maze[i][j].GetValue() == SPACE && maze[i][j].getSpecialSpot() == INSIDE_ROOM)
	{
		this->power -= 0.1;
		if (this->power <= 0)
			break;
		double num = maze[i][j].getDangerLevel() + this->power;
		maze[i][j].setDangerLevel(num, i, j);
		x += 0.01 * dirx;
		y += 0.01 * diry;
		i = MSZ * (y + 1) / 2;
		j = MSZ * (x + 1) / 2;
	}
}

int Bullet::getBelongsToTeam()
{
	return this->belongsToTeam;
}

void Bullet::setBelongsToTeam(int teamNum)
{
	this->belongsToTeam = teamNum;
}


int Bullet::calcRow()
{
	int i;
	i = MSZ * (y + 1) / 2;
	return i;
}

int Bullet::calcCol()
{
	int i;
	i = MSZ * (x + 1) / 2;
	return i;
}
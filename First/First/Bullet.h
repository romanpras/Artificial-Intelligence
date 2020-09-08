#pragma once
#include "Node.h"

const double delta = 0.0001;

class Bullet
{
public:
	Bullet();
	Bullet(double x, double y);
	Bullet(double x, double y, double dirx, double diry);
	~Bullet();
	void showMe();
	void SetIsMoving(bool move);
	bool GetIsMoving();
	void move(Node(&maze)[MSZ][MSZ]);
	bool simulateMove(Node(&maze)[MSZ][MSZ]);
	double getX();
	void setX(double x);
	void setY(double y);
	double getY();
	double getPower();
	void setPower(double power);
	void SetDir(double angle);
	void SimulateMotion(Node(&maze)[MSZ][MSZ]);
	int getBelongsToTeam();
	void setBelongsToTeam(int teamNum);
	int calcRow();
	int calcCol();

private:
	double power;
	double x, y;
	double dirx, diry;
	bool isMoving;
	int belongsToTeam;
};


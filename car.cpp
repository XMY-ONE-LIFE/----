#pragma
#include "car.h"
#include "config.h"


Car::Car(double Rw)
{
	length = 100.0;
	width = 60.0;

	p0.x = Swidth / 2 + Rw / 2;
	p0.y = Sheight - length;

	p1 = p0;

	cout << "car loc: " << p0.x << ", " << p0.y << endl;
	cout << "car target loc: " << p1.x << ", " << p1.y << endl;

}

CarObs::CarObs(double Rw)
{
	length = 100.0;
	width = 60.0;

	p0.x = Swidth / 2 + Rw / 2;
	p0.y = Sheight / 2 - length * 4;

	p1 = p0;

	cout << "carObs loc: " << p0.x << ", " << p0.y << endl;
}

void Car::showCar(Point p)//绘制车辆
{
	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLACK);

	double leftPos = p.x - width / 2;
	double rightPos = p.x + width / 2;
	double topPos = p.y - length / 2;
	double bottomPos = p.y + length / 2;

	rectangle(leftPos, topPos, rightPos, bottomPos);
}

void CarObs::showCar(Point p)//绘制障碍车辆

{
	setlinestyle(PS_SOLID, 3);
	setlinecolor(RED);

	double leftPos = p.x - width / 2;
	double rightPos = p.x + width / 2;
	double topPos = p.y - length / 2;
	double bottomPos = p.y + length / 2;

	rectangle(leftPos, topPos, rightPos, bottomPos);
}
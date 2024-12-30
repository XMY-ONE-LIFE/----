#pragma once



#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "point.h"
#include "car.h"
using namespace std;




class Road//道路
{
public:
	Road();
	~Road();
	void showRoad(Point p);//绘制道路

public:
	double RWidth = 100.0;
	CarBase* car = new Car(RWidth);//多态：父类指针指向子类对象
	CarBase* carObs = new CarObs(RWidth);//多态：父类指针指向子类对象
};
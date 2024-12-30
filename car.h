#pragma once



#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "point.h"
using namespace std;


class CarBase//车辆基类
{
public:virtual void showCar(Point p) = 0;//绘制车辆，纯虚函数

public:
	double length;//长度
	double width;//宽度

	Point p0;//起始位置
	Point p1;//终点位置
};

class Car :public CarBase//车辆
{
public:
	Car(double Rw);
	void showCar(Point p);//绘制车辆
};


class CarObs :public CarBase//障碍车辆
{
public:
	CarObs(double Rw);
	void showCar(Point p);//绘制障碍车辆
};
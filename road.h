#pragma once



#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "point.h"
#include "car.h"
using namespace std;




class Road//��·
{
public:
	Road();
	~Road();
	void showRoad(Point p);//���Ƶ�·

public:
	double RWidth = 100.0;
	CarBase* car = new Car(RWidth);//��̬������ָ��ָ���������
	CarBase* carObs = new CarObs(RWidth);//��̬������ָ��ָ���������
};
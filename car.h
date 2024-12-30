#pragma once



#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "point.h"
using namespace std;


class CarBase//��������
{
public:virtual void showCar(Point p) = 0;//���Ƴ��������麯��

public:
	double length;//����
	double width;//���

	Point p0;//��ʼλ��
	Point p1;//�յ�λ��
};

class Car :public CarBase//����
{
public:
	Car(double Rw);
	void showCar(Point p);//���Ƴ���
};


class CarObs :public CarBase//�ϰ�����
{
public:
	CarObs(double Rw);
	void showCar(Point p);//�����ϰ�����
};
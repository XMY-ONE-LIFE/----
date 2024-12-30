#pragma once

#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "road.h"
#include "math_liner_algebra.h"
#include "config.h"
using namespace std;

enum ahead
{
	state1,
	state2
};

class Polynomial//����ʽ�������
{
public:
	Polynomial();
	void ahead();//ֱ��
	void showAheadTrack();//����ֱ�й滮�߹켣
	void calMat();//�������
	void showTrack();//���ƶ���ʽ�滮�߹켣
	void carMove();//���������ƶ�
	void showResult();//��ʾ�ٶ�����ٶȹ���ʱ�������
	void delay(int time); //��ʱ��������λms
	void process();//��������

public:
	Road road;

	double t0 = 0.0;
	double t1 = 3.0;
	double x0 = road.car->p0.x;
	double y0 = road.car->p0.y;
	double x1 = road.car->p1.x;
	double y1 = road.car->p1.y;
	double vx0 = 0.0;
	double vy0 = -120.0;
	double vx1 = 0.0;
	double vy1 = -120.0;
	double ax0 = 0.0;
	double ay0 = 0.0;


	double ax1 = 0.0;
	double ay1 = 0.0;

	Mat X;
	Mat Y;
	Mat T;
	Mat A;
	Mat B;

	double disS = road.car->length * 4;//���򻻵�����
	double safeDis = 400.0;//����ȫ����
	int disAhead = safeDis / 50;//ֱ�й滮�ߵļ��
	double speed = 5.0;//ֱ���ٶ�
	double delta_t = 0.05;//ʱ����

	vector<Point> trackPoint;//�洢�켣��
	int state = state1;
};
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

class Polynomial//多项式求解曲线
{
public:
	Polynomial();
	void ahead();//直行
	void showAheadTrack();//绘制直行规划线轨迹
	void calMat();//计算矩阵
	void showTrack();//绘制多项式规划线轨迹
	void carMove();//车辆换道移动
	void showResult();//显示速度与加速度关于时间的曲线
	void delay(int time); //延时函数，单位ms
	void process();//整个过程

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

	double disS = road.car->length * 4;//纵向换道距离
	double safeDis = 400.0;//纵向安全距离
	int disAhead = safeDis / 50;//直行规划线的间隔
	double speed = 5.0;//直行速度
	double delta_t = 0.05;//时间间隔

	vector<Point> trackPoint;//存储轨迹点
	int state = state1;
};
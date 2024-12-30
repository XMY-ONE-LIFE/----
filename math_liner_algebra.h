#pragma once



#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "config.h"
using namespace std;


class Mat//矩阵
{
public:
#if 0
	Mat();//存在有参构造时，要手写默认构造，才能创建不带参对象
	Mat(int mm, int nn);//手动创建矩阵时用
	void createMat();//手动创建矩阵
#endif

	void createMatT(double t0, double t1);//创建矩阵T
	void createVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6);//创建向量
	void PrintMat();//打印矩阵

	void augMat(Mat a, Mat b);//求矩阵 a 和向量 b 的增广矩阵
	bool solve(Mat a, Mat b); //求线性方程组的解(ax=b ,求 x)，a 为方阵 ，b 为列向量

public:
	int m;
	int	n; //行数和列数
	double mat[N][N] = { 0 };  //矩阵元素初始化
};
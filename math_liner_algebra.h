#pragma once



#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "config.h"
using namespace std;


class Mat//����
{
public:
#if 0
	Mat();//�����вι���ʱ��Ҫ��дĬ�Ϲ��죬���ܴ��������ζ���
	Mat(int mm, int nn);//�ֶ���������ʱ��
	void createMat();//�ֶ���������
#endif

	void createMatT(double t0, double t1);//��������T
	void createVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6);//��������
	void PrintMat();//��ӡ����

	void augMat(Mat a, Mat b);//����� a ������ b ���������
	bool solve(Mat a, Mat b); //�����Է�����Ľ�(ax=b ,�� x)��a Ϊ���� ��b Ϊ������

public:
	int m;
	int	n; //����������
	double mat[N][N] = { 0 };  //����Ԫ�س�ʼ��
};
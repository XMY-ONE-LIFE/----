#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "config.h"
#include "curve_interpolation_algorithm.h"


int main()
{
	//testMatrix();//���Խⷽ����
	initgraph(Swidth, Sheight, EW_SHOWCONSOLE);//ͼ�δ���
	setbkcolor(WHITE);//���ñ�����ɫ
	cleardevice();

	Polynomial p;
	p.process();

	system("pause");
	closegraph();
	p.showResult();

	system("pause");
	closegraph();
	return 0;
}
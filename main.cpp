#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include "config.h"
#include "curve_interpolation_algorithm.h"


int main()
{
	//testMatrix();//测试解方程组
	initgraph(Swidth, Sheight, EW_SHOWCONSOLE);//图形窗口
	setbkcolor(WHITE);//设置背景颜色
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
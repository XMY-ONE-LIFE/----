#pragma
#include "road.h"
#include "config.h"



Road::Road()
{
	showRoad(car->p0);
	//system("pause");

}

Road::~Road()
{
	if (car != nullptr)
	{
		delete car;
		car = nullptr;
	}

	if (carObs != nullptr)
	{
		delete car;
		carObs = nullptr;
	}



}

void Road::showRoad(Point p)//绘制道路
{
	setlinecolor(BLACK);

	//绘制道路中心
	setlinestyle(PS_DASH, 3);
	line(Swidth / 2, 0, Swidth / 2, Sheight);

	//绘制左右边界
	setlinestyle(PS_SOLID, 3);

	line(Swidth / 2 - RWidth, 0, Swidth / 2 - RWidth, Sheight);
	line(Swidth / 2 + RWidth, 0, Swidth / 2 + RWidth, Sheight);

	car->showCar(p);
	carObs->showCar(carObs->p0);
}
/*
#if 0
Mat::Mat()//存在有参构造时，要手写默认构造，才能创建不带参对象
{

}

Mat::Mat(int mm, int nn)//手动创建矩阵时用
{
	m = mm;
	n = nn;
}

void Mat::createMat()//手动创建矩阵
{
	cout << "请输入矩阵元素：" << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> mat[i][j];//手动输入
		}
	}
}
#endif
*/
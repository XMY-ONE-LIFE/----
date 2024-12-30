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

void Road::showRoad(Point p)//���Ƶ�·
{
	setlinecolor(BLACK);

	//���Ƶ�·����
	setlinestyle(PS_DASH, 3);
	line(Swidth / 2, 0, Swidth / 2, Sheight);

	//�������ұ߽�
	setlinestyle(PS_SOLID, 3);

	line(Swidth / 2 - RWidth, 0, Swidth / 2 - RWidth, Sheight);
	line(Swidth / 2 + RWidth, 0, Swidth / 2 + RWidth, Sheight);

	car->showCar(p);
	carObs->showCar(carObs->p0);
}
/*
#if 0
Mat::Mat()//�����вι���ʱ��Ҫ��дĬ�Ϲ��죬���ܴ��������ζ���
{

}

Mat::Mat(int mm, int nn)//�ֶ���������ʱ��
{
	m = mm;
	n = nn;
}

void Mat::createMat()//�ֶ���������
{
	cout << "���������Ԫ�أ�" << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> mat[i][j];//�ֶ�����
		}
	}
}
#endif
*/
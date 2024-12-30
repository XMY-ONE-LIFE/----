#pragma
#include "curve_interpolation_algorithm.h"
#include "config.h"

Polynomial::Polynomial()
{
	//���ֻ�Ǿ�̬չʾ���ߣ���������������
	//������н������л��������ھ���Ҫ������ʱ���ټ������
	showAheadTrack();
	system("pause");
}

void Polynomial::ahead()//ֱ��
{
	while (true)
	{
		BeginBatchDraw();
		cleardevice();
		setlinecolor(BLACK);

		road.car->p0.y -= speed;
		road.car->p1.y -= speed;
		road.showRoad(road.car->p0);
		showAheadTrack();

		EndBatchDraw();		if (road.car->p0.y - road.carObs->p0.y <= safeDis && state == state1
			|| road.car->p0.y <= -50.0 && state == state2)
		{
			break;
		}

		delay(deltaTIME);
	}
}

void Polynomial::showAheadTrack()//����ֱ�й滮�߹켣
{
	setfillcolor(BLUE);
	Point pt = road.car->p0;
	for (int i = 0; i < 50; i++)
	{
		pt.y -= disAhead;
		solidcircle(pt.x, pt.y, 3);
	}
}

void Polynomial::calMat()//�������
{
	x0 = road.car->p0.x;
	y0 = road.car->p0.y;

	road.car->p1.x = Swidth / 2 - road.RWidth / 2;
	road.car->p1.y = road.car->p0.y - disS;

	x1 = road.car->p1.x;
	y1 = road.car->p1.y;

	cout << x0 << ", " << y0 << ", " << x1 << ", " << y1 << endl;
	//system("pause");

	X.createVector(x0, vx0, ax0, x1, vx1, ax1);
	Y.createVector(y0, vy0, ay0, y1, vy1, ay1);
	T.createMatT(t0, t1);
	cout << endl;
	cout << "X������" << endl;
	X.PrintMat();
	cout << "Y������" << endl;

	Y.PrintMat();
	cout << "T����" << endl;
	T.PrintMat();

	if (A.solve(T, X))
	{
		cout << "��õ�A�������£�" << endl;
		A.PrintMat();
	}

	if (B.solve(T, Y))
	{
		cout << "��õ�B�������£�" << endl;
		B.PrintMat();
	}
}

void Polynomial::showTrack()//���ƶ���ʽ�켣
{
	calMat();//�������

	setfillcolor(BLUE);
	for (double t = t0; t <= t1; t += delta_t)
	{
		double x_tmp = A.mat[1][1] * pow(t, 5) + A.mat[2][1] * pow(t, 4) + A.mat[3][1] * pow(t, 3) + A.mat[4][1] * pow(t, 2) + A.mat[5][1] * pow(t, 1) + A.mat[6][1];
		double y_tmp = B.mat[1][1] * pow(t, 5) + B.mat[2][1] * pow(t, 4) + B.mat[3][1] * pow(t, 3) + B.mat[4][1] * pow(t, 2) + B.mat[5][1] * pow(t, 1) + B.mat[6][1];


		solidcircle(x_tmp, y_tmp, 3);
		//putpixel(x_tmp, y_tmp, BLACK);
		//cout << "(" << x_tmp << ", " << y_tmp << ")" << endl;

		Point ptmp;
		ptmp.x = x_tmp;
		ptmp.y = y_tmp;
		//road.car->showCar(ptmp);
		trackPoint.push_back(ptmp);
	}
}

void Polynomial::carMove()//���������ƶ�
{
	showTrack();//��ʾ��ζ���ʽ����

	for (auto it = trackPoint.begin(); it != trackPoint.end(); it++)
	{
		BeginBatchDraw();
		cleardevice();
		setfillcolor(BLUE);
		for (auto ii = it; ii != trackPoint.end(); ii++)
		{
			solidcircle(ii->x, ii->y, 3);
		}


		road.showRoad(*it);
		road.car->p0.x = it->x;
		road.car->p0.y = it->y;//ʵʱ����p0λ��

		EndBatchDraw();
		delay(deltaTIME);
	}

	state = state2;
	//system("pause");
}

void Polynomial::showResult()//��ʾ�ٶ�����ٶȹ���ʱ�������
{
	initgraph(Swidth * 2, Sheight / 2, EW_SHOWCONSOLE);//ͼ�δ���
	setbkcolor(WHITE);//���ñ�����ɫ
	setfillcolor(RED);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	cleardevice();
	setorigin(Swidth / 2 - 100, Sheight / 4);

	line(0, 0, Swidth - 40, 0);
	line(0, -200, 0, 200);

	for (double t = t0; t <= t1; t += delta_t)
	{
		double vx_tmp = 5 * A.mat[1][1] * pow(t, 4) + 4 * A.mat[2][1] * pow(t, 3) + 3 * A.mat[3][1] * pow(t, 2) + 2 * A.mat[4][1] * pow(t, 1) + A.mat[5][1];
		double vy_tmp = 5 * B.mat[1][1] * pow(t, 4) + 4 * B.mat[2][1] * pow(t, 3) + 3 * B.mat[3][1] * pow(t, 2) + 2 * B.mat[4][1] * pow(t, 1) + B.mat[5][1];

		solidcircle(t * 150, vx_tmp, 3);
		solidcircle(t * 150, vy_tmp, 3);
		//putpixel(t * 50, vx_tmp, BLACK);
		//putpixel(t * 50, vy_tmp, BLACK);
		//cout << "(" << vx_tmp << ", " << vy_tmp << ")" << endl;
	}
	system("pause");


	cleardevice();
	line(0, 0, Swidth - 40, 0);
	line(0, -200, 0, 200);

	for (double t = t0; t <= t1; t += delta_t)
	{
		double ax_tmp = 20 * A.mat[1][1] * pow(t, 3) + 12 * A.mat[2][1] * pow(t, 2) + 6 * A.mat[3][1] * pow(t, 1) + 2 * A.mat[4][1];
		double ay_tmp = 20 * B.mat[1][1] * pow(t, 3) + 12 * B.mat[2][1] * pow(t, 2) + 6 * B.mat[3][1] * pow(t, 1) + 2 * B.mat[4][1];

		solidcircle(t * 150, ax_tmp * 2, 3);

		solidcircle(t * 150, ay_tmp * 2, 3);
		//putpixel(t * 50, ax_tmp, BLACK);
		//putpixel(t * 50, ay_tmp, BLACK);
		//cout << "(" << ax_tmp << ", " << ay_tmp << ")" << endl;
	}
}

void Polynomial::delay(int time) //��ʱ��������λms
{
	clock_t  now = clock();
	while (clock() - now < time)
	{



	}
}

void Polynomial::process()//��������
{
	ahead();
	carMove();
	ahead();
}


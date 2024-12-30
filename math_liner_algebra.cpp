#pragma
#include "math_liner_algebra.h"
#include "config.h"


void Mat::createMatT(double t0, double t1)//��������T
{
	m = n = 6;

	for (int j = 1; j <= n; j++)
	{
		mat[1][j] = pow(t0, n - j);
		mat[2][j] = (n - j) * pow(t0, n - j - 1);
		mat[3][j] = (n - j) * (n - j - 1) * pow(t0, n - j - 2);
		if (n - j - 1 < 0)
		{
			mat[2][j] = 0.0;
		}

		if (n - j - 2 < 0)
		{
			mat[3][j] = 0.0;
		}
	}

	for (int j = 1; j <= n; j++)
	{
		mat[4][j] = pow(t1, n - j);
		mat[5][j] = (n - j) * pow(t1, n - j - 1);
		mat[6][j] = (n - j) * (n - j - 1) * pow(t1, n - j - 2);

		if (n - j - 1 < 0)
		{
			mat[5][j] = 0.0;
		}

		if (n - j - 2 < 0)
		{
			mat[6][j] = 0.0;
		}
	}
}

void Mat::createVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6)//��������
{
	m = 6;
	n = 1;

	mat[1][1] = tmp1;
	mat[2][1] = tmp2;
	mat[3][1] = tmp3;
	mat[4][1] = tmp4;
	mat[5][1] = tmp5;
	mat[6][1] = tmp6;
}

void Mat::PrintMat()//��ӡ����
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Mat::augMat(Mat a, Mat b)//����� a ������ b ���������
{
	m = a.m;
	n = a.n + 1;//����+1
	for (int i = 1; i <= a.m; i++)
	{
		for (int j = 1; j <= a.n; j++) {
			mat[i][j] = a.mat[i][j];
		}
		mat[i][n] = b.mat[i][1];//ÿ�е����һ�У���ֵΪ����b����һ�е�Ԫ��
	}
}

bool Mat::solve(Mat a, Mat b) //�����Է�����Ľ�(ax=b ,�� x)��a Ϊ���� ��b Ϊ������ //���� a Ϊ�����ҷ�������Ψһ��ʱ���� true
{
	if (a.n != a.m)//ֻ����Ƿ���ʱ������
	{
		cout << "ϵ�������Ƿ���" << endl;		return false;
	}

	m = a.n;
	n = 1; //�������бض��� a.n�� a.m ��������,�� a.n * 1 ��������

	Mat aa;
	aa.augMat(a, b); //���������
	cout << "��������ǣ�" << endl;
	aa.PrintMat();

	//������뽫�������Ϊ�����Ǿ��󣬲��ж�����������Ƿ�Ϊ n
	for (int i = 1; i <= aa.m; i++)
	{
		//Ѱ�ҵ� i �в�Ϊ���Ԫ��
		int k;
		for (k = i; k <= aa.m; k++)
		{
			if (fabs(aa.mat[k][i]) > 1e-10) //�����������ʱ����Ϊ���Ԫ�ز�Ϊ0
			{
				break;
			}
		}

		if (k <= aa.m)//˵���� i ���в�Ϊ0��Ԫ��
		{
			//������ i �к͵� k ������Ԫ��
			for (int j = i; j <= aa.n; j++)//�ӵ� i ��Ԫ�ؽ������ɣ���Ϊǰ���Ԫ�ض�Ϊ0
			{
				aa.mat[0][j] = aa.mat[i][j]; aa.mat[i][j] = aa.mat[k][j]; aa.mat[k][j] = aa.mat[0][j];//ʹ��aa.mat[0][j]��Ϊ�м��������Ԫ��
			}
			double c;//����
			for (int j = i + 1; j <= aa.m; j++)
			{
				c = -aa.mat[j][i] / aa.mat[i][i];
				for (k = i; k <= aa.n; k++)
				{
					aa.mat[j][k] += c * aa.mat[i][k];//�� i �� a ���ӵ��� j ��
				}
			}
		}
		else //û���ҵ���˵��ϵ�������Ȳ�Ϊ n ��˵������������Ч���̵ĸ���С�� n
		{
			cout << "ϵ���������죬���Է������޽����������" << endl;
			return false;
		}
	}
	//���¶������
	for (int i = a.m; i >= 1; i--)
	{
		mat[i][1] = aa.mat[i][aa.n];
		for (int j = a.m; j > i; j--)
		{
			mat[i][1] -= mat[j][1] * aa.mat[i][j];
		}
		mat[i][1] /= aa.mat[i][i];
	}
	return true;
}
/*
#if 0
void testMatrix()//���Խⷽ����
{
	Mat a(3, 3);
	Mat b(3, 1);
	cout << "������ " << a.m << "*" << a.n << " �ľ���" << endl;
	a.createMat();
	cout << endl;
	cout << "������ " << b.m << "*" << b.n << " ����������" << endl;
	b.createMat();
	cout << endl;

	a.PrintMat();
	b.PrintMat();
		system("pause");
	cout << endl;

	Mat x;
	if (x.solve(a, b))//�����Է�����Ľ�����
	{
		cout << "����������£�" << endl;
		x.PrintMat();
	}
}
#endif
*/

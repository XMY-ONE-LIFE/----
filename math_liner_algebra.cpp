#pragma
#include "math_liner_algebra.h"
#include "config.h"


void Mat::createMatT(double t0, double t1)//创建矩阵T
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

void Mat::createVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6)//创建向量
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

void Mat::PrintMat()//打印矩阵
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

void Mat::augMat(Mat a, Mat b)//求矩阵 a 和向量 b 的增广矩阵
{
	m = a.m;
	n = a.n + 1;//列数+1
	for (int i = 1; i <= a.m; i++)
	{
		for (int j = 1; j <= a.n; j++) {
			mat[i][j] = a.mat[i][j];
		}
		mat[i][n] = b.mat[i][1];//每行的最后一列，赋值为向量b在这一行的元素
	}
}

bool Mat::solve(Mat a, Mat b) //求线性方程组的解(ax=b ,求 x)，a 为方阵 ，b 为列向量 //矩阵 a 为方阵并且方程组有唯一解时返回 true
{
	if (a.n != a.m)//只求解是方阵时的情形
	{
		cout << "系数矩阵不是方阵" << endl;		return false;
	}

	m = a.n;
	n = 1; //解向量中必定有 a.n（ a.m ）个分量,是 a.n * 1 的列向量

	Mat aa;
	aa.augMat(a, b); //求增广矩阵
	cout << "增广矩阵是：" << endl;
	aa.PrintMat();

	//下面代码将增广矩阵化为上三角矩阵，并判断增广矩阵秩是否为 n
	for (int i = 1; i <= aa.m; i++)
	{
		//寻找第 i 列不为零的元素
		int k;
		for (k = i; k <= aa.m; k++)
		{
			if (fabs(aa.mat[k][i]) > 1e-10) //满足这个条件时，认为这个元素不为0
			{
				break;
			}
		}

		if (k <= aa.m)//说明第 i 列有不为0的元素
		{
			//交换第 i 行和第 k 行所有元素
			for (int j = i; j <= aa.n; j++)//从第 i 个元素交换即可，因为前面的元素都为0
			{
				aa.mat[0][j] = aa.mat[i][j]; aa.mat[i][j] = aa.mat[k][j]; aa.mat[k][j] = aa.mat[0][j];//使用aa.mat[0][j]作为中间变量交换元素
			}
			double c;//倍数
			for (int j = i + 1; j <= aa.m; j++)
			{
				c = -aa.mat[j][i] / aa.mat[i][i];
				for (k = i; k <= aa.n; k++)
				{
					aa.mat[j][k] += c * aa.mat[i][k];//第 i 行 a 倍加到第 j 行
				}
			}
		}
		else //没有找到则说明系数矩阵秩不为 n ，说明方程组中有效方程的个数小于 n
		{
			cout << "系数矩阵奇异，线性方程组无解或有无数解" << endl;
			return false;
		}
	}
	//自下而上求解
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
void testMatrix()//测试解方程组
{
	Mat a(3, 3);
	Mat b(3, 1);
	cout << "请输入 " << a.m << "*" << a.n << " 的矩阵：" << endl;
	a.createMat();
	cout << endl;
	cout << "请输入 " << b.m << "*" << b.n << " 的列向量：" << endl;
	b.createMat();
	cout << endl;

	a.PrintMat();
	b.PrintMat();
		system("pause");
	cout << endl;

	Mat x;
	if (x.solve(a, b))//求线性方程组的解向量
	{
		cout << "解得向量如下：" << endl;
		x.PrintMat();
	}
}
#endif
*/

#include <iostream>
#include <stdio.h>
using namespace std;
long long int m[401][401]; // m为存储最优结果的二维矩阵,相当于备忘录，m[i][j]储存的是i矩阵到j矩阵相乘的最小运算值
int p[401];                // p用于存储矩阵行列信息

long long  findMin(int i, int j) {
	long long min = 10000000000;
	for (int k = i; k < j; k++) {
		int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
		if (t < min) min = t;
	}
	return min;
}
void MatrixChainOrder(int n)
{
	// m[i:i]只有一个矩阵，所以相乘次数为0，即m[i:i]=0;
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	// l表示矩阵链的长度
	// l=2时，计算 m[i:i+1],i=1,2,...,n-1 (长度l=2的链的最小代价)
	// 计算m[i:j]时，以k分割点，需要知道m[i:k]和m[k+1:j]的值，由于i~k以及k+1~j的长度比i~j短，所以此前已经算出，可以直接读取
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l-1 <= n; i++)
			m[i][i + l - 1] = findMin(i, i + l - 1);
		// 实现这个部分
		/* 提示--你需要做的事：
		** (1)计算n个矩阵中每一个长度为l的矩阵链的最小代价m[1:l], m[2:l+1], ...
		** (2)在计算m[i:i+l-1]时，计算不同分割点k的计算代价
		** (3)最小的计算代价即为m[i:i+l-1]，将其存储到m[i][i+l-1]中 */
	}
	printf("%lld", m[1][n]);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> p[i];
	}
	MatrixChainOrder(n);
	return 0;
}

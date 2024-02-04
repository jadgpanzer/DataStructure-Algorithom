#include <iostream>
#include <stdio.h>
using namespace std;
long long int m[401][401]; // mΪ�洢���Ž���Ķ�ά����,�൱�ڱ���¼��m[i][j]�������i����j������˵���С����ֵ
int p[401];                // p���ڴ洢����������Ϣ

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
	// m[i:i]ֻ��һ������������˴���Ϊ0����m[i:i]=0;
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	// l��ʾ�������ĳ���
	// l=2ʱ������ m[i:i+1],i=1,2,...,n-1 (����l=2��������С����)
	// ����m[i:j]ʱ����k�ָ�㣬��Ҫ֪��m[i:k]��m[k+1:j]��ֵ������i~k�Լ�k+1~j�ĳ��ȱ�i~j�̣����Դ�ǰ�Ѿ����������ֱ�Ӷ�ȡ
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l-1 <= n; i++)
			m[i][i + l - 1] = findMin(i, i + l - 1);
		// ʵ���������
		/* ��ʾ--����Ҫ�����£�
		** (1)����n��������ÿһ������Ϊl�ľ���������С����m[1:l], m[2:l+1], ...
		** (2)�ڼ���m[i:i+l-1]ʱ�����㲻ͬ�ָ��k�ļ������
		** (3)��С�ļ�����ۼ�Ϊm[i:i+l-1]������洢��m[i][i+l-1]�� */
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

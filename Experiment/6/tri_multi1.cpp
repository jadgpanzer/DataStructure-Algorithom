#include <stdio.h>

const int Maxn = 5000;

/* a: 3-tuple representation of Matrix a
** b: 3-tuple representation of Matrix b
** q: Matrix a*b
** Q: 3-tuple representation of Matrix q */
int a[Maxn + 1][3], b[Maxn + 1][3], Q[Maxn + 1][3], q[Maxn + 1][Maxn + 1];

void tri_multi()
{
	if (a[0][1] != b[0][0])
		return;

	Q[0][0] = a[0][0];
	Q[0][1] = b[0][1];
	Q[0][2] = 0;

	for (int i = 1; i <= a[0][2]; i++)
		for (int j = 1; j <= b[0][2]; j++)
		{
			// Multiply two matrixes here
			if(a[i][1] == b[j][0] && a[i][2] != 0 && b[j][2] != 0){
				q[a[i][0]][b[j][1]] += a[i][2]*b[j][2];
			}
		}

	for (int i = 1; i <= Q[0][0]; i++)
	{
		for (int j = 1; j <= Q[0][1]; j++)
			printf("%d ", q[i][j]);
		printf("\n");
	}
	for (int i = 1; i <= Q[0][0]; i++)
	{
		for (int j = 1; j <= Q[0][1]; j++)
		{
			// Convert to 3-tuple representation here
			if(q[i][j]!=0){
				int p = ++Q[0][2];
				Q[p][2] = q[i][j];
				Q[p][0] = i ;
				Q[p][1] = j ;
			}
		}
	}

	for (int i = 0; i <= Q[0][2]; i++)
	{
		for (int j = 0; j <= 2; j++)
			printf("%d ", Q[i][j]);
		printf("\n");
	}
}

int main()
{
	for (int j = 0; j <= 2; j++)
		scanf("%d", &a[0][j]);
	for (int i = 1; i <= a[0][2]; i++)
		for (int j = 0; j <= 2; j++)
			scanf("%d", &a[i][j]);
	getchar();

	for (int j = 0; j <= 2; j++)
		scanf("%d", &b[0][j]);
	for (int i = 1; i <= b[0][2]; i++)
		for (int j = 0; j <= 2; j++)
			scanf("%d", &b[i][j]);

	tri_multi();
	return 0;
}
/*

3 4 4 1 1 3 1 4 5 2 2 -1 3 1 2
4 2 4 1 2 2 2 1 1 3 1 -2 3 2 4

*/

#include <stdio.h>
#include <iostream>
using namespace std;
const int Maxn = 50000;

/* a: 3-tuple representation of Matrix a
/* a_rpos: Index of each row of Matrix a
/* b: 3-tuple representation of Matrix b
/* b_rpos: Index of each row of Matrix a
/* temp: Save value of each column of current row
/* Q: 3-tuple representation of Matrix a*b */
int a[Maxn + 1][3]={0}, a_rpos[Maxn + 1]={0}, b[Maxn + 1][3]={0}, b_rpos[Maxn + 1]={0}, temp[Maxn + 1]={0}, Q[Maxn + 1][3]={0};

void tri_multi()
{
	if (a[0][1] != b[0][0])
		return;

	Q[0][0] = a[0][0];
	Q[0][1] = b[0][1];
	Q[0][2] = 0;

	int row = 1, col = 1;
	
	while (row <= Q[0][0])
	{
		
		for (int i = a_rpos[row]; i < a_rpos[row+1]; i++) // Fill missed parts: for each column of current row of Matrix a
			for (int j = b_rpos[a[i][1]]; j <  b_rpos[a[i][1]+1] ; j++) //Fill missed parts: for each row of Matrix b
			{
				// Update value to temp
				temp[b[j][1]] += a[i][2]*b[j][2];
			}

		for (col = 1; col <= Q[0][1]; col++)
		{
			if (temp[col]!=0) // Fill missed constrain: save non-zero value as 3-tuple
			{
				// Save value as 3-tuple here
				int p = ++Q[0][2];
				Q[p][0] = row ;
				Q[p][1] = col;
				Q[p][2] = temp[col] ;
				temp[col] = 0; // Clear temp for next row 
			}
		}
		row++;
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

	int row = 1, index = 1;
	
	int temp = a[1][0];
	int i = 2 ;
	a_rpos[1] = temp ;
	
	for( i = 2 ; i <= a[0][2] ; i++){
		if(temp != a[i][0]){
			a_rpos[a[i][0]] = i ;
			temp = a[i][0];
		}
	}
	a_rpos[a[i-1][0]+1] = a[0][2] + 1 ;
	int p = i-1 ;
	
	for(i = 2 ; i<= a[p][0]+1 ; i++){
		if(a_rpos[i] == 0){
			a_rpos[i] = a_rpos[i-1];
		}
	}
	
	
	
	/*while (index <= a[0][2]) // Calculate a_rpos
	{
		if (a[index][0] == row)
		{
			// Insert your code here
			a_rpos[row] = index ;
			index ++ ;
			row ++ ; 
		}
		else if (a[index][0] < row)
		{
			// Insert your code here
			index ++ ;
		}
		else // a[index][0] > row
		{
			// Insert your code here
			a_rpos[row] = a_rpos[row-1] + 1 ;
			row ++ ;
		}
		
	}
	a_rpos[row] = a[0][2] + 1;*/
	
	getchar();

	for (int j = 0; j <= 2; j++)
		scanf("%d", &b[0][j]);
	for (int i = 1; i <= b[0][2]; i++)
		for (int j = 0; j <= 2; j++)
			scanf("%d", &b[i][j]);

	row = 1, index = 1;
	
	
	
	temp = b[1][0];
	i = 2 ;
	b_rpos[1] = temp ;
	for( i = 2 ; i <= b[0][2] ; i++){
		if(temp != b[i][0]){
			b_rpos[b[i][0]] = i ;
			temp = b[i][0];
		}
	}
	b_rpos[b[i-1][0]+1] = b[0][2] + 1 ;
	p = i-1 ;
	
	for(i = 2 ; i<= b[p][0]+1 ; i++){
		if(b_rpos[i] == 0){
			b_rpos[i] = b_rpos[i-1];
		}
	}
	
	
	
	/*while (index <= b[0][2]) // Calculate b_rpos
	{
		if (b[index][0] == row)
		{
			// Insert your code here
			b_rpos[row] = index;
			index ++ ;
			row ++ ;
		}
		else if (b[index][0] < row)
		{
			// Insert your code here
			index ++ ;
		}
		else // b[index][0] > row
		{
			// Insert your code here
			b_rpos[row] = 	b_rpos[row-1] + 1 ;
			row ++ ;
		}
	}
	b_rpos[row] = b[0][2] + 1;
	*/
	tri_multi();
	return 0;
}
/*3 4 4 1 1 3 1 4 5 2 2 -1 3 1 2
	4 2 4 1 2 2 2 1 1 3 1 -2 3 2 4
*/

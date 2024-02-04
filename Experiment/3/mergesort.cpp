#include <stdio.h>

const int maxn = 1000001;
int A[maxn];

void merge(int arr[], int left, int middle, int right)
{
	int i, j;
	int n1 = middle - left + 1, n2 = right - middle;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];
	// Insert your merge code here
	int pos1 = 0 , pos2 = 0;
	int k = 0;
	while(true){
		if(pos1 == n1){
			while(pos2 < n2){
				arr[left+k] = R[pos2++];	
				k ++ ;
			}
			break;
		}
		else if(pos2 == n2){
			while(pos1 <n1){
				arr[left+k] = L[pos1++];
				k ++ ;
			}
			break;
		}
		if(L[pos1]<R[pos2]){
			arr[left+k] = L[pos1++];
		}
		else{
			arr[left+k] = R[pos2++];
		}
		k ++ ;
	}
}

void mergesort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		// Insert your code here
		mergesort(arr,left,middle);
		mergesort(arr,middle+1,right);
		merge(arr,left,middle,right);
	}
	else if(left == right){
		return ;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	mergesort(A,0,n-1); // Correct this line

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}

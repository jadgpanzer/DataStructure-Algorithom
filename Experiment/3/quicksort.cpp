#include <stdio.h>
#include <cstdlib>
#include <ctime>
#pragma comment(linker, "/STACK:1073741824")
const int maxn = 1000001;
int A[maxn];

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

int partition(int arr[], int low, int high){
  int p = arr[high];
  int i = low - 1;
  for(int j = low ;  j < high; j++){
	if(arr[j]<p){
		swap(arr[++i],arr[j]);
	}
  }
  swap(arr[i+1],arr[high]);
  return i+1;
}
void quickSort(int arr[], int low, int high){
  if (low < high){
	srand(time(nullptr));
		int rand_p = low+rand()%(high-low+1);
		swap(arr[high],arr[low+rand()%(high-low+1)]);
  	int k = partition(arr,low,high);
    quickSort(arr,low,k-1);
    quickSort(arr,k+1,high);
  }
  else{
  	return ;
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &A[i]);
  quickSort(A, 0, n-1);
  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
  return 0;
}

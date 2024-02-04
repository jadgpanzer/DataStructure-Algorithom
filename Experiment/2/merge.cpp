#include <stdio.h>
#include <iostream>
const int maxn = 1000000;

int m, n;
int a[maxn + 1];
int b[maxn + 1];
int c[maxn * 2 + 1];


int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	int number = 0 ;
    //你需要完成这一段代码
	for(int i = 0 , j = 0 ; ; ){
		if(i >= m){
			for(int k = j ; k < n ;){
				c[number++] = b[k++];
				
			}
			break;
		}
		else if(j >= n){
			for(int k = i ; k < m ;){
				c[number++] = a[k++];
			}
			break;
		}
		else{
			if(a[i]>b[j]){
				c[number++] = b[j];
				
				j++;
			}
			else{
				c[number++] = a[i];
				
				i++;
			}
		}
	}
	int s = n+m;
	for (int i = 0; i < s; i++)
		printf("%d ", c[i]);
	return 0;
}

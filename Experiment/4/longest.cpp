#include <stdio.h>

const int MAXN = 12000;
int n, a[MAXN + 1], dp[MAXN + 1];
int min(){
	int i = 2 ;
	int min = a[1];
	while(i < n){
		if(min > a[i]){
			min = a[i];
		}
		i ++ ;
	}
	return min;
}
int longestNum()
{
	int len = 1;
	dp[0] = min() - 1 ;
	dp[1] = a[1];
	// Insert your code here
	for(int i = 2 ; i <= n ; i++){
		int new_l = len ;
		int r = 0;
		while(r <= new_l){
			int mid = (r+new_l)/2 ;
			if(dp[mid] < a[i]){
				r = mid + 1 ;
			}
			if(dp[mid] >= a[i]){
				new_l = mid - 1 ;
			}
		}
		dp[r] = a[i];
		if(r > len){
			len = r ;
		}
	}
	return len ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d", longestNum());
	return 0;
}

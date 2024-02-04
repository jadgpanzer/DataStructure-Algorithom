#include <iostream>
int count = 0 ;
int split(int m , int n){
	if(m == 1 || n == 1){
		return 1 ;
	}
	if(m == n ){
		return 1+ split(m,n-1);
	}
	if(m<n){
		return split(m,m); 
	}else{
		return split(m-n,n) + split(m,n-1) ;
	}
}
int main(){
	int m , n;
	std::cin>>m>>n;
	
	split(m,n);
	std::cout<<split(m,n); ;
}

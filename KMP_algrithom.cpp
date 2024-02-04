#include <iostream>
#include <ctime>
#include "BF_algrithom.cpp"

int *next_pos(const char* &str){
	//此函数给出字符串中每个位置的next值 ,原理与KMP类似 
	int* next = new int[length(str)];
	if(length(str) == 1){
		next[0] = -1;
		return next;
	}
	else if(length(str) == 2){
		next[0] = -1 , next[1] = 0;
		return next;
	}
	
	int i = 0 , j = 0;
	next[0] = -1 , next[1] = 0;
	
	for(i = 1 , j = 0 ; i < length(str) ; ){
		if(j == -1){	//j=-1则子串滑动到开头，当前i指向的位置的next值设置为0 
			i++ , j++;
			next[i] = j;
		}
		else if(str[i] == str[j]){		//如果匹配。则当前位置的next值在原有基础上加1 
			i++ , j++;
			next[i] = j;
		}
		else{							//不匹配则子串滑动到上一个匹配的位置 
			j = next[j];
		}
	}
	return next;
}
int KMP_match(const char* &main_str , const char* &sub_str){
	//此函数使用KMP算法进行字符串的模式匹配 
	int* next = next_pos(sub_str);
	int i = 0 ,j = 0;
	while(i < length(main_str) && j < length(sub_str)){		//设置边界条件 
		if(j == -1){		//若j为-1则模式串跳回到开头，主串移到下一个位置比较 
			i++ , j++;
		}
		else if(main_str[i] == sub_str[j]){		//若匹配则模式串和主串都往下移动一位 
			i++ , j++;
		}
		else{									//若不匹配则模式串滑动到next的下一个位置进行匹配 
			j = next[j];
		}
		if(j == length(sub_str)){
			return i-j;
		}
	}
	return -1;
}
int main(){
	const char* str1 = "aaaabbs4f323abfs";
	const char* str2 = "abs";
	
	std::clock_t start_time = std::clock();
	int result = KMP_match(str1,str2);
	std::clock_t end_time = std::clock();
	
	std::clock_t start_time_1 = std::clock();
	int result1 = BF_match(str1,str2);
	std::clock_t end_time_1 = std::clock();
	
	std::cout<<"结果为："<<'\n'<<"BF:"<<result1<<" KMP:"<<result<<'\n';
	std::cout<<"BF算法用时为："<<(start_time_1-end_time_1)<<'\n'<<"KMP算法用时为："<<(start_time-end_time)<<'\n'; 
	
	system("pause");
	return 0;
}

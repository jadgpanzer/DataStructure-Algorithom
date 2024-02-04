#include <iostream>
#include <ctime>
#include "BF_algrithom.cpp"

int *next_pos(const char* &str){
	//�˺��������ַ�����ÿ��λ�õ�nextֵ ,ԭ����KMP���� 
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
		if(j == -1){	//j=-1���Ӵ���������ͷ����ǰiָ���λ�õ�nextֵ����Ϊ0 
			i++ , j++;
			next[i] = j;
		}
		else if(str[i] == str[j]){		//���ƥ�䡣��ǰλ�õ�nextֵ��ԭ�л����ϼ�1 
			i++ , j++;
			next[i] = j;
		}
		else{							//��ƥ�����Ӵ���������һ��ƥ���λ�� 
			j = next[j];
		}
	}
	return next;
}
int KMP_match(const char* &main_str , const char* &sub_str){
	//�˺���ʹ��KMP�㷨�����ַ�����ģʽƥ�� 
	int* next = next_pos(sub_str);
	int i = 0 ,j = 0;
	while(i < length(main_str) && j < length(sub_str)){		//���ñ߽����� 
		if(j == -1){		//��jΪ-1��ģʽ�����ص���ͷ�������Ƶ���һ��λ�ñȽ� 
			i++ , j++;
		}
		else if(main_str[i] == sub_str[j]){		//��ƥ����ģʽ���������������ƶ�һλ 
			i++ , j++;
		}
		else{									//����ƥ����ģʽ��������next����һ��λ�ý���ƥ�� 
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
	
	std::cout<<"���Ϊ��"<<'\n'<<"BF:"<<result1<<" KMP:"<<result<<'\n';
	std::cout<<"BF�㷨��ʱΪ��"<<(start_time_1-end_time_1)<<'\n'<<"KMP�㷨��ʱΪ��"<<(start_time-end_time)<<'\n'; 
	
	system("pause");
	return 0;
}

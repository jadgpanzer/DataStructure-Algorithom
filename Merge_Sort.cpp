#include <iostream>
#include <vector>
#include <stack>
void merge(std::vector<int>& array,int start,int end){
	if(start == end){
		return ;
	}
	std::vector<int> new_array;
	for(int i = start ,j = (end+start)/2+1 ;  ; ){
		if(array[i] < array[j]){
			new_array.push_back(array[i]);
			i ++ ;
		}
		
		else{
			new_array.push_back(array[j]);
			j ++ ;
		}
		
		if(i == (end+start)/2+1 ){
			while(j < end + 1){
				new_array.push_back(array[j++]);
			}
			break;
		}
		if(j == end + 1){
			while(i < (end+start)/2+1){
				new_array.push_back(array[i++]);
			}
			break;
		}
	}
	for(int i = start ; i < end + 1 ; i ++){
		array[i] = new_array[i-start];
	}
}
/*�鲢�����㷨���ݹ�ʵ�֣�*/
void merge_sort(std::vector<int>& array,int _start ,int _end ){
	/*��ײ�*/
	if(_start == _end){
		return ;
	}
	/*������һ��Ϊ�������з����㷨*/ 
	else{
		merge_sort(array,_start,(_end+_start)/2);
		merge_sort(array,(_end+_start)/2+1,_end);
		merge(array,_start,_end);
	}
}
/*�鲢�����㷨���ǵݹ�ʵ�֣�*/
void _merge_sort_(std::vector<int>& array,int start ,int end){
	for(int i = 1 ; i <= array.size() ; i=i*2){
		for(int j = 0 ;  ; ){
			if( j+i-1 >= array.size() ){
				merge(array,j,array.size()-1);
				break;
			}
			else{
				merge(array,j,j+i-1);
				j = j+i ;
			}
		}
	}
}

int main(){
	/*std::vector<int> arr = {5,3,2,6,8,1,4,2};
	merge_sort(arr, 0 , arr.size()-1);
	for(int i = 0 ; i < arr.size() ; i++){
		std::cout<<arr[i]<<' ';
	}
	std::cout<<'\n';*/
	std::vector<int> arr1 = {5,3,2,6,9,15,8,1,4,2};
	_merge_sort_(arr1, 0 , arr1.size()-1);
	for(int i = 0 ; i < arr1.size() ; i++){
		std::cout<<arr1[i]<<' ';
	}
	return 0;
}


#include <iostream>
using namespace std;
struct Info{
	int row_size;
	int column_size;
	int size;
};
struct Element{
	int row;
	int column;
	int num;
};
void transform(Info* my_info , Element* array,Element* new_array){
	int r = my_info->row_size;
	int c = my_info->column_size;
	int* num = new int[c+1];
	int* cpot = new int[c+1];
	for(int i = 1 ; i <= c ; i++){
		num[i] = 0;
		cpot[i] = 0 ; 
	}
	for(int i = 1 ; i <= my_info->size ;i ++){
		++num[array[i].column];
	}
	cpot[1] = array[1].row;
	for(int i = 2 ; i <= c ;i ++){
		cpot[i] = cpot[i-1]+num[i-1];
	}
	for(int i = 1 ; i <= my_info->size ; i++ ){
		int column = array[i].column ;
		int row = array[i].row ;
		int pos = cpot[column];
		new_array[pos].column = row ;
		new_array[pos].row = column ;
		new_array[pos].num =  array[i].num;
		++cpot[column];
	}
}
int main(){
	Info my_info;
	cin>>my_info.row_size>>my_info.column_size>>my_info.size;
	Element* array = new Element[my_info.size+1];
	for(int i = 1 ; i <= my_info.size ; i++){
		cin>>array[i].row>>array[i].column>>array[i].num;
	}
	Element* new_array = new Element[my_info.size+1];
	transform(&my_info ,array,new_array);
	int x , y ;
	cin>>x>>y;
	cout<<my_info.column_size<<' '<<my_info.row_size<<' '<<my_info.size<<'\n';
	for(int i = 1 ; i <= my_info.size ; i++){
		cout<<new_array[i].row<<' '<<new_array[i].column<<' '<<new_array[i].num<<'\n';
	}
	for(int i = 1 ; i <= my_info.size ; i++){
		if(new_array[i].row == x && new_array[i].column == y){
			cout<<new_array[i].num;
			return 0 ;
		}
	}
	cout<<0;
}
/*6 7 8 1 2 12 1 3 9 3 1 -3 3 6 14 4 3 24 5 2 18 6 1 15 6 4 -7 1 3*/

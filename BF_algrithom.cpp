int length(const char*& str){
	int i = 0;
	for( ; str[i] != '\0' ; i++){
		
	}
	return i;
}
int BF_match(const char*& super_str,const char*& sub_str){
	if(length(super_str) < length(sub_str)){
		return -1;
	}
	int position = 0;
	int pos1 = 0 , pos2 = 0 ;
	for(int i = 0 ; i < length(super_str) ; ){
		int temp = i ;
		for(int j = 0 ; j <= length(sub_str) ; ){
			if( j == length(sub_str)){
				return temp;
			}
			else if(super_str[i] == sub_str[j]){
				i ++ ;
				j ++ ;
			}
			else{
				break;
			}
		}
		i = temp + 1;
	}
	return -1;
}

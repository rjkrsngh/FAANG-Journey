#include <iostream>

using namespace std;

int myAtoi(char* str){
	int ind = 0;
	bool neg = false;
	int num = 0;

	if(str[0] == '-'){ 
		neg = true;
		ind = 1;
	}

	while(str[ind] != '\0'){
		num = num*10 + (str[ind] - '0');
		++ind;
	}
	cout<<endl;

	if(neg){
		num *= -1;
	}

	return num;
}

int main(){
	char str[] = "-12345";
	cout<<myAtoi(str)<<endl;

	return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

class String{
public:
	String(): str{nullptr} {
		cout<<"Inside Non-Parameterized Constructor\n";
		str = new char[1];
		str[0] = '\0';
	}

	String(char* s){
		cout<<"Inside Parameterized Constructor\n";
		if(NULL == s){
			//cout<<"s is NULL\n";
			str = new char[1];
			str[0] = '\0';
		}
		else{
			//cout<<"s is not NULL\n";

			int len = strlen(s)+1;
			str = new char[len];

			// strcpy(str, s);
			// str[len] = '\0';

			//or 

			memcpy(str, s, len);
		}
	}

	String(const String& obj){
		cout<<"Inside Copy Constructor\n";

		int len = strlen(obj.str) + 1;
		str = new char[len];

		//strcpy(str, obj.str);
		//str[len] = '\n';

		// OR

		memcpy(str, obj.str, len);
		
	}

	String operator=(String obj){
		cout<<"Inside assignment operator\n";

		String ret;
		int len = strlen(obj.str)+1;

		// strcpy(ret.str, obj.str);
		// ret.str[len] = '\0';

		//OR

		memcpy(str, obj.str, len);

		return ret;
	}

	void PrintString(){
		if((str == NULL) || (strlen(str) == 0)){
			cout<<"Empty string\n";
			return;
		}

		int i=0;
		while(str[i] != '\0'){
			cout<<str[i++];
		}
		cout<<endl;
		return;
	}

	~String(){
		delete str;
	}

private:
	char* str;
};


int main() {
	String s = "new string"; //basic contructor
	s.PrintString();
	cout<<"Done 1\n";

	String st("this is a string"); //Param Constructor
	st.PrintString();
	cout<<"Done 2\n";

	String st1 = st; //Copy Constructor
	st1.PrintString();
	cout<<"Done 3\n";

	s = st1; //Assignment Op
	s.PrintString();

	return 0;
}
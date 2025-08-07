#include <iostream>

using namespace std;

class Complex {
	int real, imag; 
public:
	Complex(): real{0}, imag{0} {}
	Complex(int r, int i) : real{r}, imag{i} {}

	Complex operator + (const Complex obj){
		std::cout<<"obj1 ->    real: "<<real<<" imag: "<<imag<<std::endl;
		std::cout<<"obj2 ->    real: "<<obj.real<<" imag: "<<obj.imag<<std::endl;

		Complex newObj;
		newObj.real = real + obj.real;
		newObj.imag = imag + obj.imag;

		return newObj;
	}

	void Print() {
		std::cout<<"res -> real: "<<real<<" imag: "<<imag<<std::endl;
	}
};

int main(){
	Complex obj1(1,2);
	Complex obj2(1,2);
	Complex obj3(2,3);
	Complex obj4 = obj1 + obj2 + obj3;	

	obj4.Print();

	return 0;
}
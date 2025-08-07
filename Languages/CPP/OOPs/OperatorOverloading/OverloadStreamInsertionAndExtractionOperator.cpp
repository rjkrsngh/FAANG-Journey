#include <iostream>

using namespace std;

class Complex{
private:
	int real, imag;

public:
	Complex(int r = 0, int i = 0) : real{r}, imag{i} {}

	friend ostream& operator <<(ostream& out, Complex& c);
	friend istream& operator >>(istream& in, Complex& c);
};

ostream& operator <<(ostream& out, Complex& c){
	out<<"The complex object is: "<<c.real<<" + i"<<c.imag<<std::endl;

	return out;
}

istream& operator >>(istream& in, Complex& c){
	std::cout<<"Enter the real part: ";
	in>>c.real;

	std::cout<<"Enter the imaginary part: ";
	in>>c.imag;

	return in;
}

int main(){
	Complex c;
	cin>>c;
	cout<<c;
	return 0;
}
#include <iostream>

using namespace std;

class Complex final {
	public:
		Complex(int real=0, int imag=0){
			_real = real;
			_imag = imag;
		}

		Complex operator + (Complex obj) {
			Complex res;
			
			res._real = _real + obj._real;
			res._imag = _imag + obj._imag;

			return res;
		}

		void PrintValues() const {
			cout<<this->_real << " + " << this->_imag << "i\n";
			return; 
		}
	protected:

	private:
		int _real, _imag;
};

auto main() -> int {
	Complex obj1(2,3);
	Complex obj2(4,5);

	Complex res = obj1 + obj2;
	res.PrintValues();

	return 0;
}
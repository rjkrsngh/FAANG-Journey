#include <iostream>

using namespace std;

class ExplicitKeyword
{
	int x, y;
public:
	explicit ExplicitKeyword(int x_=0, int y_=0) :
		x{x_}, y{y_} {}

	~ExplicitKeyword() {}
	
	//operator int () { return x+y; } 
	bool operator == (ExplicitKeyword ek)
	{
		std::cout<<x<<" "<<ek.x<<endl;
		std::cout<<y<<" "<<ek.y<<endl;

		return ((x == ek.x) && (y==ek.y));
	}
};

int main()
{
	ExplicitKeyword ex(1, 3);
	
	if(ex == ExplicitKeyword(4,3)){
		std::cout<<"Same\n";
	}
	else{
		std::cout<<"Not same\n";
	}

	return 0;
}
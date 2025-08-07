#include <iostream>

using namespace std;

class Parent {

	public:
		Parent(int x){
			cout<<"Parent Created\n";
			_x = x;
		}
		
		virtual ~Parent(){
			cout<<"Parent Destructor called\n";
		}
		
		virtual void fun(){
			cout<<"From parent\n";
		}
	protected:

	private:
		int _x;	
};

class Child : public Parent {
	public:
		Child(int x) : Parent(x){
			//Parent::Parent(x);
			cout<<"Child Created\n";
			_y = x;
		}
		
		~Child(){
			cout<<"Child Destructor called\n";
		}
		
		void fun() {
			cout<<"From Child\n";
		}
	protected:
	
	private:
		int _y;
};

auto main() -> int {
	Parent* p = new Child(5);
	p->fun();
	
	delete(p);
	
	
	return 0;
}
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/* Print Foo Bar alternatively n times using 2 mutexes. */
// class FoorBar {
// 	int n;
// 	std::mutex mtx_foo;
// 	std::mutex mtx_bar;

// public:
// 	FoorBar(int n) {
// 		this->n = n;
// 		mtx_bar.lock();
// 	}

// 	void PrintFoo() {
// 		std::cout<<"Foo";
// 	}

// 	void PrintBar() {
// 		std::cout<<"Bar";
// 	}

// 	void foo() {
// 		for(int i=0; i<n; ++i) {
// 			mtx_foo.lock();
// 			PrintFoo();
// 			mtx_bar.unlock();
// 		}
// 	}

// 	void bar() {
// 		for(int j=0; j<n; ++j) {
// 			mtx_bar.lock();
// 			PrintBar();
// 			mtx_foo.unlock();
// 		}
// 	}
// };

// int main() {
// 	FoorBar fb(5);

// 	std::thread th1(&FoorBar::foo, &fb);
// 	std::thread th2(&FoorBar::bar, &fb);

// 	th1.join();
// 	th2.join();

// 	return 0;
// }


/* Print Foo Bar alternatively n times using ConditionVariable */
class FooBar {
	int n;
	bool isFoo;
	std::mutex mtx;
	std::condition_variable cv;

public:
	FooBar(int num) {
		n = num;
		isFoo = true;
	}

	void PrintFoo() {
		std::cout<<"Foo";
	}

	void PrintBar() {
		std::cout<<"Bar";
	}

	void foo() {
		for(int i=0; i<n; ++i) {
			std::unique_lock<std::mutex> ulk(mtx);
			cv.wait(ulk, [&]{ return isFoo; });	

			PrintFoo();
			isFoo = false;

			cv.notify_one();
		}
	}

	void bar() {
		for(int i=0; i<n; ++i) {
			std::unique_lock<std::mutex> ulk{mtx};
			cv.wait(ulk, [&]{ return !isFoo; });

			PrintBar();
			isFoo = true;

			cv.notify_one();
		}
	}
};

int main()
{
	FooBar fb(5);

	std::thread th1(&FooBar::foo, &fb);
	std::thread th2(&FooBar::bar, &fb);

	th1.join();
	th2.join();

	return 0;
}
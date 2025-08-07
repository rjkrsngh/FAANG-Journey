// // class test{
// // 	int* i;

// // 	test(const test& obj) {
// // 		i = new int;
// // 	}
// // };

// #include <iostream>
// #include <bits/stdc++.h>

// int main() {
// 	// std::map<int, std::string> mp{};

// 	// mp.insert(std::pair<int, std::string>(1, "abc"));
// 	// mp.insert(std::pair<int, std::string>(2, "cdf"));
// 	// mp.insert(std::pair<int, std::string>(3, "gdg"));
// 	// mp.insert(std::pair<int, std::string>(4, "gff"));
// 	// mp.insert(std::pair<int, std::string>(5, "gfgf"));

// 	// std::sort(mp.begin(), mp.end(), [&](auto it1, auto it2){
// 	// 	return it2->first > it1->first;
// 	// });

// 	// for(auto it=mp.begin(); it!=mp.end(); ++it) {
// 	// 	std::cout<<it->first<<" "<<it->second<<std::endl;
// 	// }

// 	test t1;
// 	test t2 = t1;
// 	test t3(t1);
// 	t2 = t3;

// 	return 0;
// } 



class Excep {
public:
	Excep(): code{0}, errMsg{""} {}

	int code;
	std::string errMsg;
};

void test() {
	

	try {
		//operation
		int* i = new int[10];
		std::unique_ptr<int> i = new int[10];
		Excep errObj{};
		errObj.code = 1;
		errObj.errMsg = "invalid test";

		throw errObj;
	}
	catch(Excep obj){
		std::cout<<"error caught\n";
	}

	return 0;
}




// #include <iostream>
// #include <bits/stdc++.h>
// #include <thread>
// #include <condition_variable>
// #include <mutex>

// std::mutex mtx;
// bool isEvenTurn = true;
// std::condition_variable cv;
// int currNum = 0;

// void PrintEven(bool isEven) {
// 	while(currNum < 101) {
// 		std::unique_lock<std::mutex> ulk(mtx);
// 		cv.wait(ulk, [&](){return isEven; });
		
// 		std::cout<<currNum<<" ";
// 		currNum++;
		
// 		ulk.unlock();
		
// 		cv.notify_one();
// 	}
// }

// void PrintOdd() {
// 	while(currNum < 101 ) {
// 		std::unique_lock<std::mutex> ulk(mtx);
// 		cv.wait(ulk, [&](){return !isEvenTurn; });

// 		std::cout<<currNum<<" ";
// 		currNum++;
// 		isEvenTurn = true;
// 		ulk.unlock();

// 		cv.notify_one();
// 	}
// }

int main() {
	std::thread th1(PrintEven, std::ref(isEvenTurn));
	std::thread th2(PrintEven, std::ref(isEvenTurn));

	th1.join();
	th2.join();

	return 0;
}
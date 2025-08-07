#include <iostream>

using namespace std;

// int main() {
// 	int n = 5;
// 	int *q = new(nothrow) int[n];

// 	if(!q){
// 		cout<<"Allocation of memory failed\n";
// 	}
// 	else{
// 		for(int i=0; i<n; ++i){
// 			q[i] = i+1;
// 		}

// 		for(int i=0; i<n; ++i){
// 			cout<<q[i]<<" ";
// 		}
// 	}

// 	delete[] q;

// 	return 0;
// }

template <typename T>
T func(T x, T y){
	return ((x>y) && (x!=y))?x:y;
}

int main() {
	cout<<func<double>((double)' ', (double)(22/7))<<endl;
	cout<<func<int>(7.1, 7.2)<<endl;
	cout<<func<char>('1', 'a')<<endl;

	return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> res;

	for(int i=0; i<6; ++i){
		res.push_back(i);
	}

	for(int x : res){
		cout<< x << " ";
	}
	cout<<endl;
	for_each(res.begin(), res.end(), [](int i) {
		cout<<i<<" ";
	});

	return 0;
}
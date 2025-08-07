// #include <iostream>
// #include <vector>

// using namespace std;

// std::vector<int> vec1;
// std::vector<int> vec2;

// auto f = [](int a, int b){
// 	vec1.push_back(a);
// 	vec2.push_back(b);

// 	return;
// };

// int main()
// {
// 	vec1.push_back(1);
// 	vec1.push_back(1);

// 	vec2.push_back(3);
// 	vec2.push_back(3);

// 	f(1,2);

// 	cout<<"Contents of vec1: ";
// 	for(auto it=vec1.begin(); it!=vec1.end(); ++it)
// 	{
// 		cout<<(*it)<<" ";
// 	}

// 	cout<<endl;

// 	cout<<"Contents of vec2: ";
// 	for(auto it=vec2.begin(); it!=vec2.end(); ++it)
// 	{
// 		cout<<(*it)<<" ";
// 	}
	
// 	return 0;
// }






// #include <algorithm>
// #include <array>
// #include <iostream>
// #include <string_view>
// #include <string>

// int main()
// {
//   std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

//   std::cout << "search for: ";

//   std::string search{};
//   std::cin >> search;

//   // Capture @search                                vvvvvv
//   auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
//     return (str.find(search) != std::string_view::npos);
//   }) };

//   if (found == arr.end())
//   {
//     std::cout << "Not found\n";
//   }
//   else
//   {
//     std::cout << "Found " << *found << '\n';
//   }

//   return 0;
// }


#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	std::vector<int> vec {2,2,3,2,2};
	int val = 2;
	bool allSame { all_of(vec.begin(), vec.end(), [val](int it){
		return (val == it);
	})};

	cout<<(allSame ? "same" : "Not same")<<endl;

	return 0;
}
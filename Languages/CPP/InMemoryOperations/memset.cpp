#include <iostream>
#include <cstring>

using namespace std;

/* memset: Copies a single char for s specified number of times. 
   
   signature: void* memset(void* dest, char ch, std::size_t n)
*/

int main()
{
	char buff[] = "this is a test";
	memset(buff, 'a', sizeof buff);
	std::cout<<std::string(buff, sizeof buff)<<" "<<sizeof(buff);

	return 0;
}
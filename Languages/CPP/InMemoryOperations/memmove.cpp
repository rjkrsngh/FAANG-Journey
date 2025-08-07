#include <iostream>
#include <cstring>

using namespace std;

/* memmove: copies n bytes from src to dest
   
   signature: void* memmove(void* dest, void* src, std::size_t n);

   Slower than memcpy but handles overlaps correctly.
*/

int main()
{
	char src[] = "123456789";
	std::cout<<"b4 copy: "<<src<<std::endl;

	memmove(src+4, src+3, 3);
	std::cout<<"after copy: "<<src<<std::endl;	

	return 0;
}
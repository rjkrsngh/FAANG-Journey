#include <iostream>
#include <cstring>

using namespace std;

/* memcpy: copies first n bytes of src obj against dest obj. 
   
   signature: memcpy(void* dest, void* src, int sizeToCopy)

   NOTE: std::memcpy is meant to be the fastest library routine for memory-to-memory copy.
*/

int main()
{
	char src[] = "once upon a midnight dreary...";
	char dest[4];
	memcpy(dest, src, 4);
	std::cout<<std::string(dest, 4)<<" "<<sizeof(dest)<<std::endl;

	return 0;
}
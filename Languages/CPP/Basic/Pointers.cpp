#include <iostream>

using namespace std;

/* 1. Basic pointer operations */

// int main()
// {
//     int x = 5;
//     int* y = &x;

//     cout<<y<<" "<<&x<<endl; //Both have same addresses
//     *y = 7;

//     cout<<*y<<" "<<x<<endl; //Both have same values

//     x = 10;
//     cout<<*y<<" "<<x<<endl; //Both have same values

//     return 0;
// }


/* 2. Const Pointer :
        - Address must be assigned during declaration 
        - Address cannot be changed after initialization
        - The variable the pointer is pointing to can be changed anytime
          and the same will reflect in the cosntant pointer

    Syntax: int* const var =  &x;
*/

// int main(){
//     int x = 5;
//     int* const ptr = &x;

//     //int y = 6;
//     //ptr = &y; //Error: as ptr is a constant pointer to variable x

//     //However, we can change the value of x as it is non-const 
//     //and the same value will reflect in ptr too

//     x = 10;
//     cout<<x<<" "<<*ptr<<endl;

//     return 0;
// }


/* 3. Pointer to constant value or pointer to constant: 
        - It is a pointer to a constant value and hence the value it pointing to cannot be changed
        - Since it is a pointer to a constant value, the address it is pointing to can be changed


    Syntax: const int* ptr = &x;
*/
// int main(){
//     const int x = 5;
//     const int* ptr = &x;

//     cout<<x<<" "<<*ptr<<endl;

//     const int y = 10;
//     ptr = &y;

//     cout<<y<<" "<<*ptr<<endl;

//     return 0;
// }


/* 4. const pointer to a constant value : 
        - Neither the value nor the address can be changed

    Syntax: const int* const ptr = &x;

    ptr cannot be reassigned
    the value of x cannot be changed
*/
// int main(){
//     const int x = 5;
//     const int* const ptr = &x;

//     return 0;
// }
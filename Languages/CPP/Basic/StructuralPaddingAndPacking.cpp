#include <iostream>

using namespace std;

//#pragma pack(1)

// Alignment requirements
// (typical 32 bit machine)

// char     1 byte
// short int  2 bytes
// int     4 bytes
// double    8 bytes

// structure A
typedef struct structa_tag
{
char    c;
short int  s;
} structa_t;

// structure B
typedef struct structb_tag
{
short int  s;
char    c;
int     i;
} structb_t;

// structure C
typedef struct structc_tag
{
char    c;
double   d;
int 	 s;
} structc_t;

// structure D
typedef struct structd_tag
{
double   d;
int 	 s;
char    c;
} structd_t;

int main()
{
	cout<<sizeof(structa_t)<<" "<<sizeof(structb_t)<<" "<<sizeof(structc_t)<<" "<<sizeof(structd_t)<<endl;

	//If line 5 is commented: Output -> 4 8 24 16
	//If line 5 is uncommented: Output -> 3 7 13 13

	return 0;
}

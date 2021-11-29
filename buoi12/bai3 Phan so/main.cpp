#include "dayPS.h"


int main()
{

//    DayPS a;
//    a.Feature();

	PhanSo a(1,2);
	PhanSo b;
	b = a++;
	b++;
	cout << "a = "<< a << " " << "b = "<< b ;
}

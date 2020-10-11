/*The process in which a function calls itself is call Recursion and 
the corresponding function is known as Recursive Function*/

//Popular example of recursion is Factorial of a Number
//-----------------------Test Input-----------------------
//num = 5
//Output : Factorial of 5 is 120
#include <iostream>
using namespace std;
class Factorial
{
public:
	int f(int n)
	{
		if (n == 1 or n == 0)//base condition
			return 1;
		else
			return n*f(n-1);//recursive function call
	}
};

int main()
{
	Factorial obj;//Object Creation
	int num;
	cout<<"Enter any Number:";
	cin>>num;
	//Function call using class object
	cout<<"Factorial of "<<num<<" is "<<obj.f(num)<<endl;
	return 0;
}


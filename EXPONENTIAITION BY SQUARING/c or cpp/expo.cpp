
// In competitions, for calculating large powers of a number we are given a modulus value(a large prime number) because as the values of x^y is being calculated it can get very large so instead we have to calculate (x^y%modulus value.)
// Given two numbers base and exp, we need to compute baseexp under Modulo 10^9+7
#include<iostream>
using namespace std;

#define N 1000000007 // prime modulo value

long int exponentiation(long int base,
						long int exp)
{
	if (exp == 0)
		return 1;

	if (exp == 1)
		return base % N;

	long int t = exponentiation(base, exp / 2);
	t = (t * t) % N;

	// if exponent is even value
	if (exp % 2 == 0)
		return t;

	// if exponent is odd value
	else
		return ((base % N) * t) % N;
}

// Driver Code
int main()
{
	long int base;
	long int exp;
	cin>>base>>exp;

	long int modulo = exponentiation(base, exp);
	cout << modulo << endl;
	return 0;
}


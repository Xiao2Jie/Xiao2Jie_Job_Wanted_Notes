#include<iostream>
using namespace std;
unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;
	while(N > 0)
	{
		Rem = M%N;
		M = N;
		N = Rem;
	}
	return M;
}

int main()
{
	cout<<Gcd(1989, 1590);
}

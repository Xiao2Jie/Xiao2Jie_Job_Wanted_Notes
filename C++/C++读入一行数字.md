```
\#include<iostream>
\#include <string>
\#include<sstream>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	istringstream iss(str);
	int num;
	int n = 0;
	while(iss>>num)
	{
		++n;
	}
	cout<<endl;
	cout<<n;
}
```
#include <iostream>

using namespace std;

int f(int n)
{
	for (int i = n + 1; i <= 9012; i++)
	{
		int p = i;
		int a = p % 10;
		p/=10;
		int b = p % 10;
		p/=10;
		int c = p % 10;
		p/=10;
		int d = p;
		if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
			return i;
	}
}

int main()
{
	int year;
	cin >> year;
	cout << f(year) << endl;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> v(10000, -1);

int fib(int n)
{
	if (!n or n == 1)
		return n;
	if (v[n] != -1)
		return v[n];
	return fib(n-1) + fib(n-2);
}
int main()
{
	int n;
	cin >> n;
	cout << fib(n) << endl;
}

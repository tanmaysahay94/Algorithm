#include <bits/stdc++.h>

using namespace std;

int get(int n, int i)
{
	return ((n & (1 << i)) >> i);
}

void put(int &n, int i, int bit)
{
	n |= (bit << i);
}

int main()
{
	int a, b, c = 0, carry = 0;
	cin >> a >> b;
	for (int i = 0; i < 32; i++)
	{
		int p = get(a, i), q = get(b, i);
		put(c, i, p ^ q ^ carry);
		carry = (p & q) | (carry & (p ^ q));
	}
	cout << c << endl;
	return 0;
}

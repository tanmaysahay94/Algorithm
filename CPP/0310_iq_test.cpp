#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	bool ap = false, gp = false;
	cin >> a >> b >> c >> d;
	if (a - b == b - c)
	{
		if (b - c == c - d)
		{
			cout << d - (c - d);
			ap = true;
		}
	}
	else if (a * c == b * b)
		if (b * d == c * c)
		{
			if (d * d / c && (d * d) % c == 0)
			{
				cout << d * d / c;
				gp = true;
			}
		}
	if (!ap && !gp)
		cout << 42;
	cout << endl;
}

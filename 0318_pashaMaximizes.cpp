#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(string& v, int a, int b)
{
	char t = v[a];
	v[a] = v[b];
	v[b] = t;
}
int main()
{
	int position, maxDig, remaining, i, j, k;
	string v;
	cin >> v >> k;
	int len = v.length();
	for (i = 0; i < len - 1; ++i)
	{
		remaining = k;		//remaining = remaining swaps
		position = i;		//position = position to maximize digit
		maxDig = '0';
		for (j = i; j < len && remaining >= 0; --remaining, ++j)
			if (v[j] > maxDig)	//getting the position and value of the maximum digit to be swapped
			{
				maxDig = v[j];
				position = j;
			}
		k -= (position - i);
		for (j = position; j > i; --j)	//performing the (position - i) swaps
			swap(v, j, j - 1);
	}
	cout << v << endl;
}

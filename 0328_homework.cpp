#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int main()
{
	bool high = false, low = false;
	string a, b, c, d;
	int p, q, r, s;
	char hans, lans;
	cin >> a >> b >> c >> d;
	p = a.length() - 2;
	q = b.length() - 2;
	r = c.length() - 2;
	s = d.length() - 2;
	if (p >= q << 1 && p >= r << 1 && p >= s << 1) 
	{
		high = true;
		hans = 'A';
	}
	else if	(p <= q >> 1 && p <= r >> 1 && p <= s >> 1)
	{
		low = true;
		lans = 'A';
	}
	if (q >= p << 1 && q >= r << 1 && q >= s << 1)
	{
		high = true;
		hans = 'B';
	}
	else if (q <= p >> 1 && q <= r >> 1 && q <= s >> 1)
	{
		low = true;
		lans = 'B';
	}
	if (r >= p << 1 && r >= q << 1 && r >= s << 1) 
	{
		high = "true";
		hans = 'C';
	}
	else if (r <= p >> 1 && r <= q >> 1 && r <= s >> 1)
	{
		low = true;
		lans = 'C';
	}
	if (s >= p << 1 && s >= q << 1 && s >= r << 1)
	{
		high = true;
		hans = 'D';
	}
	else if (s <= p >> 1 && s <= q >> 1 && s <= r >> 1)
	{
		low = true;
		lans = 'D';
	}
	if (!(high ^ low))
		cout << "C";
	else if (high)
		cout << hans;
	else
		cout << lans;
	cout << endl;
}

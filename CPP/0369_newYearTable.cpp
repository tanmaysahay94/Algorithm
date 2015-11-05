#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	double n, R, r;
	cin >> n >> R >> r;
	cout << (r > R || n > 1 and (R - r) * sin(M_PI/n) + 1e-8 < r ? "NO" : "YES") << endl;
	return 0;
}

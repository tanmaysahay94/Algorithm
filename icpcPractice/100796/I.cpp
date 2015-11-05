#include <bits/stdc++.h>

using namespace std;

int main()
{
	double r, R, h;
	cin >> r >> R >> h;
	double H = (h*R)/(R - r);
	printf("%.7f\n", min(h/2.0, (H*R)/(sqrt(R*R+H*H)+R)));
	return 0;
}

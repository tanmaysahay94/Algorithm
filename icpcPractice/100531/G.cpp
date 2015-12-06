#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("grave.in");
	ofstream fout("grave.out");
	int x1, x2, y1, y2;
	fin>>x1>>y1>>x2>>y2;
	int x3, y3, x4, y4;
	fin>>x3>>y3>>x4>>y4;
	int w, h;
	fin>>w>>h;
	if(((h <= y3 - y1 || h <= y2 - y4) && w <= x2 - x1) || 
			((w <= x3 - x1 || w <= x2 - x4) && h <= y2 - y1))
		fout<<"Yes\n";
	else
		fout<<"No\n";
	return 0;
}

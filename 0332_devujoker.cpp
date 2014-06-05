#include<iostream>  
#include<algorithm>  
#include<string>  
#include<set>  
#include<cstdio>  
#include<string>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<map>

using namespace std;

int main()
{
	int n, d, i, j, v, s = 0, total = 0;
	cin >> n >> d;
	for (i = 0; i < n; i++)
	{
		cin >> v;
		s += v;
		total += v + 10;
	}
	total -= 10;
	if (total > d)
		cout << "-1\n" ;
	else
		cout << (d - s)/5 << endl; 
}

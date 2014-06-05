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
	unsigned long long n, x, i, currlp, total = 0;
	cin >> n >> x;
	currlp = x;
	vector<unsigned long long> c(n);
	for (i = 0; i < n; i++)
		cin >> c[i];
	sort(c.begin(), c.end());
	for (i = 0; i < n; i++)
	{
		total += currlp * c[i];
		if (currlp > 1)
			currlp--;
	}
	cout << total << endl;
}

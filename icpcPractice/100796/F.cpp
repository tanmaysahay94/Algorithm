#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		long long a, b;
		cin>>a>>b;
		printf("%.9lf\n", 1.0/a - 1.0/(b+1));
	}
	return 0;
}

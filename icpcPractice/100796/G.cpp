#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x;
	cin>>n>>x;
	string s;
	char a[100100];
	cin>>s;
	int m; cin>>m;
	scanf("%s", a);
	x--;
	for(int i=0; i<m; x += a[i]=='L'?-1:1, i++)
		cout<<s[x];
	cout<<s[x]<<endl;
	return 0;
}

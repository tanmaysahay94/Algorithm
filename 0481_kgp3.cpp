#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{	
	int T;
	char s[1010], t[1010], tmp[10];
	int m;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s%s", s, t);
		scanf("%d", &m);
		int mp[26] = {0};
		for(int i=0; i<26; i++)
			mp[i] = 1<<i;
		for(int i=0; i<m; i++)
		{
			scanf("%s", tmp);
			int c1 = tmp[0] - 'a', c2 = tmp[3] - 'a';
			mp[c1] |= mp[c2];
			for(int j=0; j<26; j++)
				if(mp[j]&(1<<c1))
					mp[j] |= mp[c1];
		}
		int len = strlen(s);
		int ans = 0;
		if(len == strlen(t))
		{
			ans = 1;
			for(int i=0; i<len; i++)
				if((mp[s[i]-'a']&(1<<(t[i]-'a'))) == 0)
				{
					ans = 0;
					break;
				}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}


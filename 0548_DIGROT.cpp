#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
 
int lrot(int N)
{
	char buf[10];
	sprintf(buf, "%d", N);
	for(int i=1; buf[i]; i++)
		swap(buf[i-1], buf[i]);
	return atoi(buf);
}
 
int rrot(int N)
{
	char buf[10];
	sprintf(buf, "%d", N);
	for(int i=strlen(buf)-1; i>0; i--)
		swap(buf[i-1], buf[i]);
	return atoi(buf);
}
 
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int ans=0;
		ans=max(ans, lrot(rrot(N)));
		ans=max(ans, rrot(lrot(N)));
		for(int i=0, L=N; i<6; i++)
		{
			L=lrot(L);
			ans=max(ans, L);
		}
		for(int i=0, R=N; i<6; i++)
		{
			R=rrot(R);
			ans=max(ans, R);
		}
		printf("%d\n", ans);
	}
	return 0;
}


LL fn(string& s)
{
	LL ans = 0;
	for (LL i = 0; i < s.length(); i++)
	{
		char dig = s[i];
		ans = ans*10 + dig - '0';
	}
	return ans;
}

int main()
{
	LL n;
	SLL(n);
	while (n--)
	{
		string s;
		cin >> s;
		LL maxval = 0, idx;
		LL len = s.length();
		for (LL i = 0; i < len; i++)
		{
			string tmp;
			for (LL j = i; j < len; j++)
				tmp += s[j];
			for (LL j = 0; j < i; j++)
				tmp += s[j];
			maxval = max(maxval, fn(tmp));
		}
		cout << maxval << endl;
	}
	return 0;
}

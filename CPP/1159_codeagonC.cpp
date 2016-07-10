#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
	cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
	__f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

const int maxn = 1005;
const int inf = maxn * maxn;

vector<vector<int> > dp(maxn, vector<int> (maxn));

int specialCase(string &S, char c)
{
	int n = S.size();
	for (int i = 0; i < n; i++)
	{
		dp[0][i] = -inf; 
		if(S[i] == c) 
			dp[0][i] = 1;
	}
	for (int l = 1; l < n; l++)
		for (int i = 0; i + l < n; i++)
		{
			dp[l][i] = max(dp[l - 1][i] , dp[l - 1][i + 1]);
			if (l > 1 and S[i] == S[i + l])
				dp[l][i] = max(dp[l][i], dp[l - 2][i + 1] + 2);
		}
	return dp[n - 1][0];
}

int lps(string& S)
{
	int n = S.size();
	vector<vector<int> > L(n, vector<int> (n, 0));
	for (int i = 0; i < n; i++) L[i][i] = 1;
	for (int c1 = 2; c1 <= n; c1++)
		for (int i = 0; i < n - c1 + 1; i++)
		{
			int j = i + c1 - 1;
			if (S[i] == S[j] and c1 == 2) L[i][j] = 2;
			else if (S[i] == S[j]) L[i][j] = L[i + 1][j - 1] + 2;
			else L[i][j] = max(L[i][j - 1], L[i + 1][j]);
		}
	return L[0][n - 1];
}

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		string A, B;
		cin >> A >> B;
		int a = lps(A), b = lps(B);
		int ans = a + b;
		if (a & 1 and b & 1)
		{
			ans--;
			for (char c = 'a'; c <= 'z'; c++)
				ans = max(ans, specialCase(A, c) + specialCase(B, c));
		}
		cout << ans << endl;
	}
	return 0;
}

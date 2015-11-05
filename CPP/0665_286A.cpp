#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

bool isPalin(string& str)
{
	int len = str.length();
	for (int i = 0; i < len/2; i++)
		if (str[i] != str[len-i-1])
			return false;
	return true;
}

int main()
{
	bool possible = false;
	string str, test;
	cin >> str;
	int len = str.length();
	for (char ch = 'a'; ch <= 'z' and not possible; ch++)
		for (int i = 0; i <= len and not possible; i++)
		{
			test = "";
			for (int j = 0; j < i; j++)
				test += str[j];
			test += ch;
			for (int j = i; j < len; j++)
				test += str[j];
			if (isPalin(test))
				possible = true;
		}
	if (possible)
		cout << test << endl;
	else
		cout << "NA\n";
	return 0;
}

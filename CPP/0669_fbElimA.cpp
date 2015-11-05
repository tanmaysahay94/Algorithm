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

LL strToNum(string& str)
{
	LL ret = 0;
	for (int i = 0; i < (int) str.length(); i++)
		ret = 10 * ret + str[i] - '0';
	return ret;
}

int main()
{
	int t;
	si(t);
	for (int test = 1; test <= t; test++)
	{
		string num, low, high;
		cin >> num;
		low = high = num;
		LL lowNum = strToNum(num);
		LL highNum = lowNum;
		for (int i = 0; i < (int) num.length(); i++)
			for (int j = i + 1; j < (int) num.length(); j++)
				if (not(i == 0 and num[j] == '0'))
				{
					swap(num[i], num[j]);
					LL val = strToNum(num);
					if (val < lowNum)
					{
						lowNum = val;
						low = num;
					}
					if (val > highNum)
					{
						highNum = val;
						high = num;
					}
					swap(num[i], num[j]);
				}
		cout << "Case #"<<test<<": "<<low<<" "<<high<<endl;
	}
	return 0;
}

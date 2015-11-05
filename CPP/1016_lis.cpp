#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL maxn = 2.5e5 + 5;

LL length, last;
LL v[maxn], temp[maxn], freq[301];

void solve(LL n) 
{
	for (LL i = 0; i < n; i++) 
	{
		LL loc = upper_bound(temp, temp + length, v[i]) - temp;
		if (loc == length)
			temp[loc] = v[i], last = max(last, i);
		else if (temp[loc - 1] <= v[i])
			temp[loc] = v[i], last = max(last, i);
		length = max(length, loc + 1);
	}
}

int main() 
{
	LL n, t;
	cin >> n >> t;
	LL x = min(t, 500LL);
	for (LL i = 0; i < n; i++) 
	{
		cin >> v[i];
		freq[v[i]]++;
		for (LL j = 1; j < x; j++)
			v[i + j * n] = v[i];
	}
	length = last = 0;
	solve(x * n);
	LL cnt = 0;
	for (LL i = 0; i < 301; i++)
		cnt = max(cnt, freq[v[i]]);
	t -= 500;
	if (t > 0)
		length += t * cnt;
	cout << length << endl;
}

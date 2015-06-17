#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	string s, a, b;
	cin >> s >> a >> b;
	if (a.size() > b.size())
		swap(a, b);
	map<char, int> mpa, mpb, mps;
	for (int i = 0; s[i]; i++)
		mps[s[i]]++;
	for (int i = 0; a[i]; i++)
		mpa[a[i]]++;
	for (int i = 0; b[i]; i++)
		mpb[b[i]]++;
	int mx = INT_MIN, amx = INT_MIN, bmx = INT_MIN, lim = INT_MAX;
	for (map<char, int>::iterator it = mpa.begin(); it != mpa.end(); it++)
	{
		char ch = (*it).first;
		int foo = (*it).second;
		lim = min(lim, mps[ch] / foo);
	}
	for (amx = 0; amx <= lim; amx++)
	{
		int blim = INT_MAX;
		for (map<char, int>::iterator it = mpb.begin(); it != mpb.end(); it++)
		{
			char ch = (*it).first;
			int foo = (*it).second;
			if (mps[ch] >= mpa[ch])
				blim = min(blim, (mps[ch] - amx * mpa[ch]) / foo);
		}
		if (blim != INT_MAX)
			if (blim + amx > mx)
				mx = blim + amx, bmx = blim;
	}
	amx = mx - bmx;
	string ans;
	for (int i = 0; i < amx; i++)
		ans += a;
	for (int i = 0; i < bmx; i++)
		ans += b;
	for (map<char, int>::iterator it = mps.begin(); it != mps.end(); it++)
	{
		char ch = (*it).first;
		int foo = (*it).second;
		for (int i = 0; i < foo - amx * mpa[ch] - bmx * mpb[ch]; i++)
			ans.push_back(ch);
	}
	cout << ans << endl;
	return 0;
}

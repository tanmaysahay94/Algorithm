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

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<pair<int, string> > > S(m, vector<pair<int, string> > ());
	for (int i = 0; i < n; i++)
	{
		string name;
		int region, score;
		cin >> name >> region >> score;
		S[--region].push_back(make_pair(score, name));
	}
	for (int i = 0; i < m; i++)
	{
		sort(S[i].begin(), S[i].end(), greater<pair<int, string> > ());
		if (S[i].size() > 2)
		{
			if (S[i][1].first == S[i][2].first) cout << "?\n";
			else cout << S[i][0].second << " " << S[i][1].second << endl;
		}
		else cout << S[i][0].second << " " << S[i][1].second << endl;
	}
	return 0;
}

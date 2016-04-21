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

const int mnval = 0;
const int mxval = 1e9 + 1;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> type;
	type.push_back(mnval);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		type.push_back(val);
	}
	sort(type.begin(), type.end());
	type.push_back(mxval);
	vector<int> ans;
	bool finish = false;
	for (int i = 1; i < (int) type.size() and not finish; i++)
	{
		int curr = type[i - 1] + 1;
		int end = type[i];
		while (curr < end)
		{
			if (m - curr >= 0)
			{
				ans.push_back(curr);
				m -= curr;
			}
			else
			{
				finish = true;
				break;
			}
			curr++;
		}
	}
	cout << ans.size() << endl;
	for (auto a: ans)
		cout << a << ' '; cout << endl;
	return 0;
}

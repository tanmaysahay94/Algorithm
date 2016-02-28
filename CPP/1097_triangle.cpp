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

void generate(vector<int>& v)
{
}

int triangleCount(vector<int>& v)
{
	int n = v.size();
	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		int k = i + 2;
		for (int j = i + 1; j + 1 < n; j++)
		{
			while (k < n and v[i] + v[j] > v[k])
				k++;
			ans += k - j - 1;
		}
	}
	return ans;
}

int main()
{
	vector<int> v;
	generate(v);
	sort(v.begin(), v.end());
	cout << triangleCount(v);
	return 0;
}

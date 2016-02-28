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
	int r = 0, g = 0, b = 0, n;
	cin >> n;
	string s;
	cin >> s;
	for (auto &ss: s)
		if (ss == 'R') r++;
		else if (ss == 'G') g++;
		else b++;
	if (!b&&!g&&r) cout << "R";
	else if (!b&&g&&!r) cout << "G";
	else if (b&&!g&&!r) cout << "B";
	else if (b&&g&&r) cout << "BGR";
	else if (!b&&g&&r)
	{
		if (g==1&&r==1) cout << "B";
		else if (g==1&&r>1) cout << "BG";
		else if (g>1&&r==1) cout << "BR";
		else cout << "BGR";
	}
	else if (b&&!g&&r)
	{
		if (b==1&&r==1) cout << "G";
		else if (b==1&&r>1) cout << "BG";
		else if (b>1&&r==1) cout << "GR";
		else cout << "BGR";
	}
	else if (b&&g&&!r)
	{
		if (b==1&&g==1) cout << "R";
		else if (b==1&&g>1) cout << "BR";
		else if (b>1&&g==1) cout << "GR";
		else cout << "BGR";
	}
	cout<<endl;
	return 0;
}

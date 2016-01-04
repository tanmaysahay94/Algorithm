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

typedef unsigned long long ULL;

bool yes(ULL val)
{
	int cnt = 0;
	while (val)
	{
		if ((val & 1) == 0) cnt++;
		val >>= 1;
	}
	return cnt == 1;
}

int main()
{
	ULL a, b;
	cin >> a >> b;
	ULL one = 1;
	int cnt = 0;
	unordered_set<ULL> u_set;
	for (int i = 0; i < 63; i++)
	{
		ULL num = (one << i) - one;
		for (int j = 0; j < i; j++)
		{
			ULL foo = one << j;
			ULL val = num ^ foo;
			if (a <= val and val <= b and yes(val))
				u_set.insert(val);
		}
	}
	cout << u_set.size();
	/*
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
	}
	*/
	return 0;
}

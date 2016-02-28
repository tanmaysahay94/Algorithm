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

void move(char m, int& x, int& y)
{
	if (m == 'U') y++;
	else if (m == 'D') y--;
	else if (m == 'L') x--;
	else x++;
}

int main()
{
	int n;
	scanf("%d", &n);
	string seq;
	cin >> seq;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			int currX = 0, currY = 0;
			for (int k = i; k <= j; k++)
				move(seq[k], currX, currY);
			ans += (!currX && !currY);
		}
	printf("%d\n", ans);
	return 0;
}

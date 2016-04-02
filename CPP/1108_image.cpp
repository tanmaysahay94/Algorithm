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

const int maxn = 5e5 + 5;
int n, a, b, T;
char s[maxn];

int solve(int dir)
{
	int time = 1 + b * (s[0] == 'w');
	if (time > T) return 0;
	time += a;
	int count = 1;
	trace(count, time);
	for (int i = (dir + n) % n; count < n and time < T; i += dir)
	{
		time += 1 + b * (s[i] == 'w');
		if (time <= T) count++;
		trace(i, count, time);
		time += a;
	}
	return count;
}

int main()
{
	scanf("%d%d%d%d%s", &n, &a, &b, &T, s);
	printf("%d\n", max(solve(1), solve(-1)));
	return 0;
}

#include <cstdio>
#include <vector>

using namespace std;

const unsigned long long large = 1000000007;
int main()
{
	unsigned long long t, n, i;
	scanf("%llu", &t);
	while (t--)
	{
		scanf("%llu", &n);
		vector<unsigned long long> a(n), dp(n, 1), sum(105);
		for (i = 0; i < n; i++)
			scanf("%llu", a + i);
	}
}

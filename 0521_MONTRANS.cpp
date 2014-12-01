#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pair<int, int> mx = make_pair(a, b);
		int cnt = 0;
		for(int i=1; i<=10000 && ((100*a + b) >= c); i++)
		{
			if(b >= c)
				b-=c;
			else
			{
				a--;
				b += 100-c;
			}
			swap(a, b);
			pair<int, int> tmp = make_pair(a, b);
			if(tmp > mx)
			{
				mx = tmp;
				cnt = i;
			}
		}
		printf("%d\n", cnt);
	}
}

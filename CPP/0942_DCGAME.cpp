#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int V[maxn], preSum[maxn], postSum[maxn];
pair<int, int> PR[maxn];
set<int> S;

void read(int &n)
{
	n = 0;
	register int c = getchar_unlocked();
	for(; c < 48 or c > 57; c = getchar_unlocked());
	for(; c > 47 and c < 58; c = getchar_unlocked())
		n = (n << 3) + (n << 1) + c - 48;
}

int main()
{
	int m, n, var;
	read(n), read(m);
	for(int i = 0 ; i < n - 1; i++)
	{
		read(var);
		PR[i] = make_pair(var, (long long)(i + 1));
	}
	scanf("%d", &var);
	PR[n - 1] = make_pair(var, (long long) n);
	sort(PR, PR + n);
	for(int i = 0; i < n; i++) 
		V[i] = PR[i].first;
	S.insert(0);
	S.insert(n + 1);
	for(int i = n - 1; i >= 0; i--)
	{
		int idx = PR[i].second;
		S.insert(idx);
		set<int>::iterator it = S.find(idx);
		set<int>::iterator next = it, prev = it;
		next++, prev--;
		int foo = (*next - idx) & 1;
		int bar = (idx - *prev) & 1; 
		PR[i].second = foo * bar;
	}
	postSum[n - 1] = PR[n - 1].second;
	preSum[0] = PR[0].second;
	for(int i = 1; i < n; i++)
		preSum[i] = preSum[i - 1] + PR[i].second, postSum[n - 1 - i] = postSum[n - i] + PR[n - 1 - i].second;
	for(int i = 0; i < m; i++)
	{
		getchar();
		char sign, player;
		int k, ans;
		scanf("%c %d %c", &sign, &k, &player);
		if(sign == '>')
		{
			int foo = upper_bound(V, V + n, k) - V;
			if(foo < n && V[foo] > k)
				ans = postSum[foo];
			else
				ans = 0;
		}
		else if(sign == '=')
		{
			int foo = lower_bound(V, V + n, k) - V;
			int bar = upper_bound(V, V + n, k) - V;
			if(n <= foo or V[foo] > k) 
				ans = 0;
			else if(n <= bar)
				ans = preSum[n - 1] - (foo > 0 ? preSum[foo - 1] : 0);
			else 
				ans = preSum[bar - 1]- (foo > 0 ? preSum[foo - 1] : 0);
		}
		else if(sign == '<') 
		{
			int foo = lower_bound(V, V + n, k) - V;
			if(foo < n && V[foo] >= k)
				ans = foo > 0 ? preSum[foo - 1] : 0;
			else 
				ans = preSum[foo];
		}
		if(ans & 1)
			printf("%c", player);
		else if (player == 'D')
			printf("C");
		else
			printf("D");
	}
	printf("\n");
	return 0;
}

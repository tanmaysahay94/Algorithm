#include<iostream>  
#include<algorithm>  
#include<string>  
#include<set>  
#include<cstdio>  
#include<string>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<map>

using namespace std;  

const int maxn = 100010;  
char p[maxn];  
int prime[maxn], cnt;  
int n, d[maxn];  
vector<pair<int,int> >ans;  

int find(int i)  
{  
	int l = 0, r = cnt - 1;  
	while(l <= r)  
	{  
		int mid = (l + r) >> 1;  
		if(prime[mid] <= i)  
			l = mid + 1;  
		else  
			r = mid - 1;  
	}  
	return prime[l - 1];  
}  
void init()  
{  
	p[0] = 1;  
	p[1] = 1;  
	for(int i = 2; i < maxn; i++)  
		if(!p[i])  
		{  
			prime[cnt++] = i;  
			for(int j = i << 1; j < maxn; j += i)  
				p[j] = 1;  
		}  
}  
void dfs(int l,int r)  
{  
	if(l > r)   
		swap(l, r);  
	int diff = r - l + 1;  
	if(p[diff] == 0)  
	{  
		swap(d[l], d[r]);  
		ans.push_back(make_pair(l, r));  
		return;  
	}
	int x = l + find(diff) - 1;  
	swap(d[l], d[x]);  
	ans.push_back(make_pair(l, x));  
	dfs(x, r);  
}  
void solve()  
{  
	for(int i = 1; i <= n; i++)  
	{  
		int j = i;  
		while(j != d[j] )  
			dfs(j, d[j]);  
	}  
}  
int main()  
{  
	init();  
	scanf("%d", &n);  
	for(int i = 1; i <= n; i++)  
		scanf("%d", d + i);  
	solve();  
	printf("%d\n", ans.size());  
	for(int i = 0; i < ans.size(); i++)  
		printf("%d %d\n", ans[i].first, ans[i].second);    
} 

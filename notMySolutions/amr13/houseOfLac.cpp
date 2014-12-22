
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define r first
#define c second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

char a[550][550];
vector< VI > done;

int burn(int r, int c)
{
	done[r][c]++;
	if(done[r][c] >= 2 || a[r][c] == '.')
		return 1;
	return 0;
}

int bfs(PI s, PI e, int n, int m)
{
	int visited[550][550] = {0};
	queue<PI> q;
	q.push(s);
	visited[s.r][s.c] = 1;
	while(!q.empty() && !visited[e.r][e.c])
	{
		PI ele = q.front();
		q.pop();
		int r = ele.r;
		int c = ele.c;
		if(r<n-1 && !visited[r+1][c] && burn(r+1, c))
		{
			visited[r+1][c] = 1;
			q.push(mp(r+1, c));
		}
		if(c<m-1 && !visited[r][c+1] && burn(r, c+1))
		{
			visited[r][c+1] = 1;
			q.push(mp(r, c+1));
		}
		if(r>0 && !visited[r-1][c] && burn(r-1, c))
		{
			visited[r-1][c] = 1;
			q.push(mp(r-1, c));
		}
		if(c>0 && !visited[r][c-1] && burn(r, c-1))
		{
			visited[r][c-1] = 1;
			q.push(mp(r, c-1));
		}
	}
	return visited[e.r][e.c];
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		SI(n); SI(m);
		done = vector< VI >(550, VI(550, 0));
		for(int i=0; i<n; i++)
			scanf("%s", a[i]);
		PI s, e;
		SI(s.r); SI(s.c); SI(e.r); SI(e.c);
		s.r--; s.c--; e.r--; e.c--;
		if(bfs(s, e, n, m))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

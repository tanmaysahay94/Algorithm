#include <bits/stdc++.h>

#define f first
#define s second
#define EACH(it, container) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

typedef long long LL;
typedef pair<int, set<int> > pis;		//Value and Intersection List
typedef pair<pis, pis> spl;		//For diameter and Height

const int maxn = 10010;

vector<int> G[10010];
int done[10010];

void intersect_sets(set<int> &s1, set<int> &s2)
{
	if(s1.size() < s2.size())
	{
		intersect_sets(s2, s1);
		s1 = s2;
		return;
	}
	EACH(it, s2)
		if(s1.find(*it) == s1.end())
			s1.erase(*it);
}

void union_sets(set<int> &s1, set<int> &s2)
{
	EACH(it, s2)
		s1.insert(*it);
}

spl dfs(int root)
{
	done[root] = 1;
	int childNodes = 0;
	EACH(it, G[root])
		if(!done[*it])
			childNodes++;
	if(childNodes == 0)
	{
		spl ans;
		ans.f.f = 0;
		ans.f.s.insert(root);
		ans.s.f = 0;
		ans.s.s.insert(root);
		return ans;
	}
	else if(childNodes == 1)
	{
		spl a1;
		EACH(it, G[root])
			if(!done[*it])
			{
				a1 = dfs(*it);
				break;
			}
		a1.s.s.insert(root);
		a1.s.f++;
		if(a1.s.f > a1.f.f)
			a1.f = a1.s;
		else if(a1.s.f == a1.f.f)
			intersect_sets(a1.f.s, a1.s.s);
		return a1;
	}
	else
	{
		pis max_dia, max_ht, max2_ht;
		EACH(it, G[root])
			if(!done[*it])
			{
				spl tmp = dfs(*it);
				if(tmp.f.f > max_dia.f)
					max_dia = tmp.f;
				else if(tmp.f.f == max_dia.f)
					max_dia.s = set<int>();
				if(tmp.s.f >= max_ht.f)
				{
					if(max_ht.f > max2_ht.f)
						max2_ht = max_ht;
					else if(max_ht.f == max2_ht.f)
						intersect_sets(max2_ht.s, max_ht.s);
					max_ht = tmp.s;
				}
				else if(tmp.s.f > max2_ht.f)
					max2_ht = tmp.s;
				else if(tmp.s.f == max2_ht.f)
					intersect_sets(max2_ht.s, tmp.s.s);
			}
		max_ht.f++;
		max_ht.s.insert(root);
		if(max_ht.f + max2_ht.f + 1 > max_dia.f)
		{
			union_sets(max2_ht.s, max_ht.s);
			return spl(pis(max_ht.f + max2_ht.f + 1, max2_ht.s), max_ht);
		}
		else if(max_ht.f + max2_ht.f + 1 == max_dia.f)
		{
			union_sets(max2_ht.s, max_ht.s);
			intersect_sets(max_dia.s, max2_ht.s);
			return spl(max_dia, max_ht);
		}
		else
			return spl(max_dia, max_ht);
	}
}

int not_adjacent(int a, int b)
{
	EACH(it, G[a])
		if(*it == b)
			return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, u, v;
		cin>>n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		memset(done, 0, n*sizeof(done[0]));
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int root = 0;
		spl ans = dfs(root);
		set<int> s = ans.f.s;
		set<int>::iterator it = s.begin();
		it++;
//		EACH(it, s)
//			cout<<"-----"<<*it<<"-----\n";
		if(s.size() >= 3 || (s.size() == 2 && not_adjacent(*(s.begin()), *(it))))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

class segmentTree {
	VLL st;
	LL identity;
	int N, size;
	LL function(LL a, LL b) {
		return a + b;
	}
	LL get(int ts, int te, int qs, int qe, int root) {
		if(qs == ts and qe == te)
			return st[root];
		int mid = (ts+te)/2;
		LL v1 = qs<=mid?get(ts, mid, qs, min(qe, mid), 2*root):identity;
		LL v2 = qe>mid?get(mid+1, te, max(qs, mid+1), qe, 2*root+1):identity;
		return function(v1, v2);
	}
	public:
	segmentTree(vector<LL> &v) {
		identity = 0;
		size = v.size();
		int level = ceil(log2(size));
		N = 1<<(level+1);
		st = vector<LL>(N, identity);
		for(int i=0; i<size; i++)
			st[N/2 + i] = v[i];
		for(int i=level-1; i>=0; i--)
			for(int j=(1<<i); j<(1<<(i+1)); j++)
				st[j] = function(st[2*j], st[2*j+1]);
	}
	void set(int pos, LL val) {
		int idx = (N/2) + pos;
		st[idx] = val;
		for(idx/=2; idx>0; idx/=2)
			st[idx] = function(st[2*idx], st[2*idx+1]);
	}
	LL get(int start, int end) {
		return get(0, N/2 - 1, start, end, 1);
	}
};

int main()
{
	int n, q;
	char s[5];
	int idx, val;
	scanf("%d%d", &n, &q);
	VLL v(n);
	for(int i=0; i<n; i++)
		SLL(v[i]);
	segmentTree st(v);
	while(q--)
	{
		scanf("%s%d%d", s, &idx, &val);
		if(s[0] == 'S')
			printf("%lld\n", st.get(idx, val));
		else if(s[0] == 'G')
			st.set(idx, st.get(idx, idx) + val);
		else if(s[0] == 'T')
			st.set(idx, st.get(idx, idx) - val);
	}
	return 0;
}

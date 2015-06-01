#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

class segmentTree {
	private:
		int n;
		vector<int> A, ST;

		// build s.t. idx represents [l, r)
		void build(int idx, int l, int r)
		{
			if (l + 1 == r)
			{
				ST[idx] = l;
				return;
			}
			int m = (l + r) >> 1;
			int left = idx << 1;
			int right = left | 1;
			build(left, l, m);
			build(right, m, r);
			if (A[ST[left]] < A[ST[right]]) ST[idx] = ST[left];
			else ST[idx] = ST[right];
		}

		// idx represent [l, r) whereas our query is [s, e)
		int rangeQuery(int idx, int l, int r, int s, int e)
		{
			if (s >= r or s >= e or e <= l) return -1;
			if (s <= l and e >= r) return ST[idx];
			int m = (l + r) >> 1;
			int left = idx << 1;
			int right = left | 1;
			int lq = rangeQuery(left, l, m, s, e);
			int rq = rangeQuery(right, m, r, s, e);
			if (lq == -1) return rq;
			if (rq == -1) return lq;
			if (A[lq] < A[rq]) return lq;
			else return rq;
		}

		// node being updated is idx represents [l, r) whereas we wish to update [s, e)
/*		void rangeUpdate(int idx, int l, int r, int s, int e)
		{
			if (s >= r or s >= e or e <= l) return;
			if (l + 1 == r)
				f(ST[idx]);
			int m = (l + r) >> 1;
			int left = idx << 1;
			int right = left | 1;
			if (e <= m) rangeUpdate(left, l, m, s, e);
			else if (s >= m) rangeUpdate(right, m, r, s, e);
			else rangeUpdate(left, l, m, s, m), rangeUpdate(right, m, r, m, e);
			// Node specific fn.
		}
*/	
	public:
		segmentTree()
		{
			n = 0;
			A.clear();
			ST.clear();
		}
		segmentTree(vector<int>& V)
		{
			A = V;
			n = A.size();
			ST = vector<int> (n << 2);
			build(1, 0, n);
		}
		segmentTree(int *start, int *end)
		{
			A = vector<int> (start, end);
			n = A.size();
			ST = vector<int> (n << 2);
			build(1, 0, n);
		}
		// returns query over range [s, e)
		int rquery(int s, int e)
		{
			return rangeQuery(1, 0, n, s, e);
		}
		void show()
		{
			for (int i = 1; i < (int) ST.size(); i++)
				cout << ST[i] << ' ';
			cout << endl;
		}
};

segmentTree tree;
int n;
int A[200001], ans[200001];

void build(int s, int e)
{
	if (s >= e) return;
	int len = e - s;
	int idx = tree.rquery(s, e);
	int foo = max(idx - s - 1, e - idx - 1);
	for (int i = len; i > foo; i--)
		ans[i] = max(ans[i], A[idx]);
	build(s, idx);
	build(idx + 1, e);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A + i);
	tree = segmentTree(A, A + n);
	build(0, n);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

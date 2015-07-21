#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

class segmentTree {
	private:
		vector<LL> ST;
		vector<int> A;
		LL n;

		void build(int node, int l, int r)
		{
			if (l == r - 1)
			{
				ST[node] = A[l];
				return;
			}
			int left = node << 1;
			int right = left | 1;
			int mid = (l + r) >> 1;
			build(left, l, mid);
			build(right, mid, r);
			// merging
			ST[node] = ST[left] + ST[right];
		}

		LL range_query(int node, int qs, int qe, int s, int e)
		{
			if (qs >= e or qe <= s)
				return 0LL;
			if (qs <= s and qe >= e)
				return ST[node];
			int left = node << 1;
			int right = left | 1;
			int mid = (s + e) >> 1;
			LL lq = range_query(left, qs, qe, s, mid);
			LL rq = range_query(right, qs, qe, mid, e);
			if (lq == 0)
				return rq;
			if (rq == 0)
				return lq;
			return lq + rq;
		}

		void range_update(int node, int qs, int qe, int s, int e)
		{
			if (qs >= e or qe <= s)
				return;
			LL check = e;
			check -= s;
			if (ST[node] == check)
				return;
			if (s == e - 1)
			{
				ST[node] = sqrt(ST[node] + 0.0);
				return;
			}
			int left = node << 1;
			int right = left | 1;
			int mid = (s + e) >> 1;
			if (qe <= mid) range_update(left, qs, qe, s, mid);
			else if (qs >= mid) range_update(right, qs, qe, mid, e);
			else range_update(left, qs, mid, s, mid), range_update(right, mid, qe, mid, e);
			ST[node] = ST[left] + ST[right];
		}

	public:
		void show(){for(int i = 1; i <= 15; i++)cout<<ST[i]<<' ';cout<<endl;}
		segmentTree() 
		{
			ST.clear();
			A.clear();
			n = 0;
		}
		segmentTree(vector<int>& v)
		{
			A = v;
			n = v.size();
			ST = vector<LL> (4 * n);
			build(1, 0, n);
		}
		segmentTree(int *begin, int *end)
		{
			A = vector<int> (begin, end);
			n = A.size();
			ST = vector<LL> (4 * n);
			build(1, 0, n);
		}
		// returns [l, r)
		LL rng_query(int l, int r)
		{
			return range_query(1, l, r, 0, n);
		}
		LL pt_query(int idx)
		{
			return rng_query(idx, idx + 1);
		}
		void update(int l, int r)
		{
			range_update(1, l, r, 0, n);
		}
};

int arr[131072];

int main()
{
	int nn, cnt = 0;
	while (scanf("%d", &nn) != EOF)
	{
		printf("Case #%d:\n", ++cnt);
		for (int i = 0; i < nn; i++)
			scanf("%d", arr + i);
		segmentTree S = segmentTree(arr, arr + nn);
		int op, x, y, m;
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d%d%d", &op, &x, &y);
			if (op)
				printf("%lld\n", S.rng_query(x - 1, y));
			else
				S.update(x - 1, y);
			S.show();
		}
		printf("\n");
	}
	return 0;
}

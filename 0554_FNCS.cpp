#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef unsigned long long int ULL;
typedef vector<ULL> VULL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

class FenwickTree {
	VULL tree;
	public:
	FenwickTree(int n) {
		tree.resize(n + 1, 0);
	}
	FenwickTree(const VI& nums) {
		tree.resize(nums.size() + 1);
		for(int i = 0; i < nums.size(); i++) {
			increase(i, nums[i]);
		}
	}
	void increase(int i, int delta) {
		i++;
		for (; i < (int) tree.size(); i |= i + 1) {
			tree[i] += delta;
		}
	}
	ULL getsum(int left, int right) {
		return sum(right) - sum(left-1); 
	}
	ULL sum(int idx) {
		idx++;
		ULL sum = 0;
		while (idx>=0) {
			sum += tree[idx];
			idx &= idx + 1;
			idx--;
		}
		return sum;
	}
};

class Bucket {
	VI matches_;
	ULL sum_;
	public:
	Bucket(const VI& matches, ULL sum): matches_(matches), sum_(sum) {}
	void increase(int idx, int increment) {
		sum_ += matches_[idx] * (ULL) increment;
	}
	ULL sum() {
		return sum_;
	}
};

class SquareRootDecompostion {
	int p;
	VI& l_, r_, nums_;
	vector<Bucket> buckets;
	FenwickTree tree_;
	public:
	SquareRootDecompostion(VI& l, VI& r, VI& nums): tree_(nums), l_(l), r_(r), nums_(nums) {
		int size = l.size();
		p = (int) sqrt(size);
		int n = ((size - 1) / p + 1);
		FenwickTree tree(size + 1);
		VI matches(size);
		for (int i = 0; i < n; i++) {
			for (int j = i * p; j < min((i + 1) * p, size); j++) {
				tree.increase(l[j], 1);
				tree.increase(r[j] + 1, -1);
			}
			ULL sum = 0;
			for (int j = 0; j < size; j++) {
				matches[j] = tree.sum(j);
				sum += matches[j] * (ULL) nums[j];
			}
			buckets.push_back(Bucket(matches, sum));
		}
	}
	void set(int idx, int value) {
		int increment = value - nums_[idx];
		nums_[idx] = value;
		tree_.increase(idx, increment);
		for (int i = 0; i < buckets.size(); i++) {
			buckets[i].increase(idx, increment);
		}
	}
	ULL getsum(int left, int right) {
		ULL sum = 0;
		int left_block_idx = left / p;
		int right_block_idx = right / p;
		if (left_block_idx == right_block_idx) {
			for (int i = left; i <= right; i++) {
				sum += tree_.getsum(l_[i], r_[i]);
			}
			return sum;
		}
		for (int i = left; i < (left_block_idx + 1) * p; i++) {
			sum += tree_.getsum(l_[i], r_[i]);
		}
		sum += buckets[right_block_idx - 1].sum() - buckets[left_block_idx].sum();
		for (int i = right_block_idx * p; i <= right; i++) {
			sum += tree_.getsum(l_[i], r_[i]);
		}
		return sum;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	VI arr(n), l(n), r(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d%d", &l[i], &r[i]);
		l[i]--; r[i]--;
	}
	SquareRootDecompostion decomp(l, r, arr);
	int q;
	scanf("%d", &q);
	while (q--) 
	{
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		if (type == 1) 
			decomp.set(x - 1, y);
		else
			printf("%llu\n", decomp.getsum(x - 1, y - 1));
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool isPossible(int tm, int K, int T, vector<int>& L) {
	int idx = 0;
	int ppl = 1;
	int sum = 0;
	while (idx < (int) L.size()) {
		if (sum + T * L[idx] <= tm) {
			sum += T * L[idx];
		}
		else {
			sum = T * L[idx];
			ppl++;
		}
		idx++;
	}
	return (ppl <= K and sum <= tm);
}

void showV(vector<int>& v)
{
	for (auto it: v)
		cout << it << ' '; cout << endl;
}

int paint(int K, int T, vector<int> &L) {
	int mod = 10000003;
//	sort(L.begin(), L.end());
	showV(L);
	int low = 0, high = 1e9;
	while (low < high - 1) {
		int mid = (low + high) / 2;
		cout << low << ' ' << mid << ' ' << high << endl;
		if (isPossible(mid, K, T, L)) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	return (high % mod);
}

void f(vector<int>& C, int v)
{
	C.push_back(v);
}

int main()
{
	int A = 6;
	int B = 10;
	vector<int> C;
	f(C, 762), f(C, 798), f(C, 592), f(C, 899), f(C, 329);
//	f(C, 640), f(C, 435), f(C, 647), f(C, 352), f(C, 8), f(C, 90), f(C, 960), f(C, 329), f(C, 859);
	cout << paint(A, B, C);
	return 0;
}

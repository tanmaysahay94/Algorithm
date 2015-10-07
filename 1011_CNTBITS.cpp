const int mod = 1e9 + 7;

void fix(int& v) {
	v %= mod;
	while (v < 0) {
		v += mod;
	}
}

void operate(vector<int>& x) {
	vector<int> c(2);
	for (auto xx: x) {
		c[xx]++;
	}
	for (int i = 0; i < c[0]; i++) {
		x[i] = 0;
	}
	for (int i = c[0]; i < (int) x.size(); i++) {
		x[i] = 1;
	}
}

int solve(vector<int>& x) {
	operate(x);
	int ret = 0;
	vector<int> orig(x);
	for (int i = 1; i < (int) x.size(); i++)
		x[i] += x[i - 1];
	for (int i = 1; i < (int) x.size(); i++) {
		int val = x[x.size() - 1] - x[i - 1];
		int rem = orig[i - 1] * ((int) (x.size() - i));
		ret += val - rem;
	}
	return ret;
}

int Solution::cntBits(vector<int> &A) {
	int n = A.size();
	vector<vector<int> > v(32, vector<int> (n));
	for (int i = 0; i < n; i++) {
		int val = A[i];
		for (int b = 0; b < 32; b++) {
			v[b][i] = (val >> b) & 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		ans += solve(v[i]);
		fix(ans);
	}
	ans <<= 1;
	fix(ans);
	return ans;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int init = -1;
long long shuru, khatam;
vector<long long> A(maxn), H(maxn), I(maxn);
void subsolve(long long, long long);

int main()
{
	long long n, k;
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &A[i]);
		I[i] = init;
	}
	H[A[n - 1]] = I[A[n - 1]] = n - 1, shuru = khatam = n;
	long long ans = 1;
	if (A[n - 1] > k)
		shuru = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int aj = A[i] - k;
		subsolve(aj, k);
		ans += khatam - i;
		H[A[i]] = 1, I[A[i]] = i;
		if (k < A[i])
			shuru = i;
	}
	printf("%lld\n", ans);
	return 0;
}

void subsolve(long long num, long long k)
{
	if (num == 0)
		khatam = shuru;
	if (num <= 0)
		return;
	long long lim = sqrt(num);
	for (long long i = 1; i <= lim; i++)
	{
		if (num % i)
			continue;
		if (H[i] and (num + k) % i == k)
				khatam = min(khatam, I[i]);
		if (H[num / i] and (num + k) % (num / i) == k)
				khatam = min(khatam, I[num / i]);
	}
}

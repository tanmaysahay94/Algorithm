#include <stdio.h>

const long long mod = 1e7 + 7;

int main()
{
	long long t, n, a, b, c, d, e, f, i, j, k;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d, &e, &f);
		a %= mod; b %= mod; c %= mod; d %= mod; e %= mod; f %= mod;
		if (n == 1)
			printf("%lld\n", d % mod);
		else if (n == 2)
			printf("%lld\n", e % mod);
		else if (n == 3)
			printf("%lld\n", f % mod);
		else
		{
			long long mat[3][3];
			mat[0][0] = mat[0][1] = mat[1][1] = mat[2][0] = 0;
			mat[1][0] = mat[2][1] = 1;
			mat[0][2] = c;
			mat[1][2] = b;
			mat[2][2] = a;
			n -= 3;
			long long identity[3][3] = {0};
			for (i = 0; i < 3; i++)
				identity[i][i] = 1;
			while (n)
			{
				if (n & 1)
				{
					long long temp[3][3] = {0};
					for (i = 0; i < 3; i++)
						for (j = 0; j < 3; j++)
							for (k = 0; k < 3; k++)
								temp[i][j] = (temp[i][j]%mod + (identity[i][k]%mod * mat[k][j]%mod)%mod)%mod;
					for (i = 0; i < 3; i++)
						for (j = 0; j < 3; j++)
							identity[i][j] = temp[i][j];
				}
				long long temp[3][3] = {0};
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						for (k = 0; k < 3; k++)
							temp[i][j] = (temp[i][j]%mod + (mat[i][k]%mod * mat[k][j]%mod)%mod)%mod;
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						mat[i][j] = temp[i][j];
				n >>= 1;
			}
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
					mat[i][j] = identity[i][j];
			long long ans = 0;
			ans = (ans + (d * mat[0][2])%mod)%mod;
			ans = (ans + (e * mat[1][2])%mod)%mod;
			ans = (ans + (f * mat[2][2])%mod)%mod;
			printf("%lld\n", ans);
		}
	}
}

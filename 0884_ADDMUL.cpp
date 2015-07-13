#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef vector<LL> VLL;
 
const LL mod = 1e9 + 7;
 
LL n,q;
vector<LL>A(4e5 + 4, 0), T(4e5 + 4, 0), LA(4e5 + 4, 0), LM(4e5 + 4, 1);
 
void initializeSegTree(LL v, LL a, LL b) 
{
	if (a == b) 
	{
		T[v] = A[a];
		return;
	}
	LL mid = (a + b) / 2;
	initializeSegTree(2*v+1, a, mid);
	initializeSegTree(2*v+2, mid + 1, b);
	T[v] = (T[2*v+1] + T[2*v+2]) % mod;
}
 
void U(LL v, LL rangeStart, LL rangeEnd)
{
	T[v] = (LM[v] * T[v] + LA[v] * (rangeEnd - rangeStart + 1)) % mod;
	if (rangeStart!=rangeEnd)
	{
		LM[2*v+1] = (LM[2*v+1] * LM[v]) %mod;
		LA[2*v+1] = (LA[2*v+1] * LM[v] + LA[v]) %mod;
		LM[2*v+2] = (LM[2*v+2] * LM[v]) %mod;
		LA[2*v+2] = (LA[2*v+2] * LM[v] + LA[v]) %mod;
	}
	LA[v] = 0;
	LM[v] = 1;
}
void update(LL v, LL rangeStart, LL rangeEnd, LL x, LL y, LL val, LL type) 
{
	val %= mod;
	U(v, rangeStart, rangeEnd);
	if (rangeStart > y or rangeEnd < x or rangeStart > rangeEnd)
		return;
	if (x <= rangeStart and rangeEnd <= y) 
	{
		if (type == 1) 
		{
			T[v] = (T[v] + (rangeEnd - rangeStart + 1) * val) % mod;
			if (rangeStart != rangeEnd) 
			{
				LA[2*v+1]= (LA[2*v+1] + val) % mod;
				LA[2*v+2]= (LA[2*v+2] + val) % mod;
			}
		}
		else if (type==2) 
		{
			T[v] = (val * T[v]) % mod;
			if (rangeStart != rangeEnd) 
			{
				LA[2*v+1] = (LA[2*v+1] * val) % mod;
				LA[2*v+2] = (LA[2*v+2] * val) % mod;
				LM[2*v+1] = (LM[2*v+1] * val) % mod;
				LM[2*v+2] = (LM[2*v+2] * val) % mod;
			}
		}
		else if (type==3) 
		{
			T[v] = (val * (rangeEnd - rangeStart + 1)) % mod;
			if (rangeStart!=rangeEnd) 
			{
				LM[2*v+1] = LM[2*v+2] = 0;
				LA[2*v+1] = LA[2*v+2] = val;
			}
		}
		return;
	}
	LL mid = (rangeStart + rangeEnd) / 2;
	update(2*v+1, rangeStart, mid, x, y, val, type);
	update(2*v+2, mid+1, rangeEnd, x, y, val, type);
	T[v] = (T[2*v+1] + T[2*v+2]) % mod;
}
 
LL query(LL v, LL rangeStart, LL rangeEnd, LL x, LL y) 
{
	if (rangeStart > y or rangeEnd < x or rangeStart > rangeEnd)
		return 0;
	U(v, rangeStart, rangeEnd);
	if (x <= rangeStart and rangeEnd <= y)
		return T[v];
	LL mid = (rangeStart + rangeEnd) / 2;
	return (query(2 * v + 1, rangeStart, mid, x, y) % mod + query(2 * v + 2, mid + 1, rangeEnd, x, y)) %mod;
}
 
int main() 
{
	scanf("%lld%lld", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	initializeSegTree(0, 0, n - 1);
	for (int i=0; i<q; i++)
	{
		LL type;
		LL x;
		LL y;
		LL v;
		scanf("%lld%lld%lld", &type, &x, &y);
		if (type==4)
			printf("%lld\n", query(0, 0, n - 1, --x, --y));
		else 
		{
			scanf("%lld", &v);
			update(0, 0, n - 1, --x, --y, v, type);
		}
	}
	return 0;
}

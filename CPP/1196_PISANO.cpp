#include<bits/stdc++.h>
using namespace std;

// Find the Pisano period of a number
// ***************
//  head function ->
//  LL pisano_period(n)
// ***************
// N =  sqrt(max)
// ***************
// precomputations -> 
// sieve();
// list_primes();
// ***************
// global variable used ->
// fact , prime_map , prime_pairs, primes, N , gP, rP . primes_piss, pisano
// ***************

#define LL long long int
LL gcd(LL a,LL b){if(a==0)return(b);else return(gcd(b%a,a));}
LL lcm(LL a,LL b){return (a*b)/gcd(a,b);}
unordered_map < LL , LL > primes_piss;
int piss[]={1,3,8,6,20,24,16,12,24,60,10,24,28,48,40,24,36,24 ,18 ,60 };
#define N 1000010
unsigned int prime[N / 63];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
	memset( prime, -1, sizeof( prime ) );

	unsigned int i;
	unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
	for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
	{
		unsigned int i2 = i + i;
		for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
	}
}
vector < LL > primes;
void list_primes()
{
	primes.clear();
	primes.push_back(2);
	for(int i=3;i<=N;i=i+2)
		if( gP(i) != 0)
			primes.push_back(i);
}
LL mul(LL val,LL n,LL mod)
{
	LL q=((double)val*(double)n/(double)mod);
	LL res=val*n-mod*q;
	res=(res%mod+mod)%mod;
	return res;
}
LL fib(LL n, LL mod)
{
	LL fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
	LL i,j,k;
	while(n)
	{
		if(n&1)
		{
			memset(tmp,0,sizeof tmp);
			for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
				tmp[i][j]=(tmp[i][j]+mul(ret[i][k],fib[k][j],mod)) %mod; 
			for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j] % mod;
		}
		memset(tmp,0,sizeof tmp);
		for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
			tmp[i][j]=(tmp[i][j]+mul(fib[i][k],fib[k][j],mod)) %mod;
		for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j] % mod;
		n/=2;
	}
	//return (ret[0][1]);
    return (ret[0][1] and ret[1][1]);
//	if(ret[0][1] == 1 and ret[1][1] == 0)
//		return true;
//	return false;
}
vector < pair <  LL , int  > > prime_map;
void prime_factorize(LL x)
{
	prime_map.clear();
	LL sqrtN = ( LL )sqrt( ( double )x ) + 1;
	LL y = x;
	for(int i=0;i<primes.size();i++)
	{
		LL j = primes[i];
		if( j > sqrtN)
			break;
		int c =0 ;
		while(y%j == 0)
		{
			y/=j;
			c+=1;
		}
		if(c!=0)
			prime_map.push_back(make_pair(j,c));
		if (y == 1) 
			break;
	}
	if(y!=1)
	{
		prime_map.push_back(make_pair(y,1));
	}
}
vector < pair <  LL ,int > > prime_pairs;
void prime_break(LL x)
{
	prime_pairs.clear();
	LL sqrtN = ( LL )sqrt( ( double )x ) + 1;
	LL y = x;
	for(int i=0;i<primes.size();i++)
	{
		LL j = primes[i];
		if( j > sqrtN)
			break;
		int c =0 ;
		while(y%j == 0)
		{
			y/=j;
			c+=1;
		}
		if(c!=0)
			prime_pairs.push_back(make_pair(j,c));
		if(y==1)
			break;
	}
	if(y!=1)
	{
		prime_pairs.push_back(make_pair(y,1));
	}
}
vector < LL > fact;
void factorize(LL val, LL ind)
{
	int le = prime_pairs.size();
	if(ind == le)
	{
		if(val != 1)
			fact.push_back(val);
		return;
	}
	factorize(val,ind+1);
	for(int i = 0;i < prime_pairs[ind].second;i++)
	{
		val*=prime_pairs[ind].first;
		factorize(val,ind+1);
	}
}
LL pisano_period(LL n){
	if(n<10)
	{
		return piss[n-1];
		return 0;
	}
	prime_factorize(n);
	vector < LL > lc;
	for(int k=0;k<prime_map.size();k++)
	{
		fact.clear();
		LL j = prime_map[k].first;

		if(j<10)
		{
			LL tmp = piss[j-1];
			if(prime_map[k].second>1)
				tmp*=(LL)(pow(j,prime_map[k].second-1));
			lc.push_back(tmp);
			continue;
		}

		if(primes_piss.find(j)!=primes_piss.end())
		{
			LL tmp = primes_piss[j];
			if(prime_map[k].second>1)
				tmp*=(LL)(pow(j,prime_map[k].second-1));
			lc.push_back(tmp);
			continue;
		}

		if(j%10 ==1 or j%10 == 9)
			prime_break(j-1);
		else if(j%10 == 3 or j%10 == 7)
			prime_break(2*j+2);
		factorize(1,0);
		if(j==5)
			fact.push_back(20);
		LL ma = LLONG_MAX;

		LL tmp2 = 0;
		for(int i=0;i<fact.size();i++)
		{

			if(fact[i]>3 and fact[i]%2!=0)
				continue;
			if(j%10 ==3 or j%10==7)
			{
				if((j+1)%fact[i]==0)
					continue;
			}

			if(fib(fact[i]+1,j))
			{
				LL tmp = fact[i];
				if(prime_map[k].second>1)
				{
					tmp*=(LL)(pow(j,prime_map[k].second-1));
				}
				if(tmp < ma)
				{
					ma = tmp;
					tmp2 = fact[i];
				}
			}
		}
		if(ma!=LLONG_MAX)
		{
			lc.push_back(ma);
			primes_piss[j]=tmp2;
		}
	}
	LL ans = 1;
	for(int i=0;i<lc.size();i++)
		ans = lcm(ans,lc[i]);
	return ans;
}

int main(){
	sieve();
	list_primes();
	int t; 
	scanf("%d",&t);
	while(t--){
		LL n;scanf("%lld",&n);LL ans = pisano_period(n); printf("%lld\n",ans); 
	}
	return 0;
}



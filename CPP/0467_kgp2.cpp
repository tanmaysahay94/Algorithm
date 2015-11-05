#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int n;
vector<int> tmp;

LL my_merge(int a[], int start, int mid, int end)
{
	LL i=start, j=mid, k=start, inv_count = 0;

	while(i<mid && j<=end)
		if(a[i] <= a[j])
			tmp[k++] = a[i++];
		else
		{
			tmp[k++] = a[j++];
			inv_count += mid-i;
		}

	while(i<mid)
		tmp[k++] = a[i++];
	while(j<=end)
		tmp[k++] = a[j++];

	for(i=start; i<=end; i++)
		a[i] = tmp[i];

	return inv_count;
}


LL my_merge_sort(int a[], int start, int end)
{
	LL mid, inv_count=0, i=start, j=end;
	if(j <= i)
		return 0;
	mid = (i+j)/2;
	inv_count += my_merge_sort(a, i, mid);
	inv_count += my_merge_sort(a, mid+1, j);

	inv_count += my_merge(a, i, mid+1, j);

	return inv_count;
}

int main()
{	
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		int k;
		scanf("%d%d", &n, &k);
		int a[n];
		tmp.resize(n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		LL inv = my_merge_sort(a, 0, n-1);
		int same = 0;
		for(int i=1; i<n; i++)
			if(a[i] == a[i-1])
			{
				same = 1;
				break;
			}
		printf("Case %d: ", t);
		if(k >= inv)
		{
			if(same)
				printf("0\n");
			else
				printf("%lld\n", (k-inv)%2);
		}
		else
			printf("%lld\n", inv-k);
	}
	return 0;
}


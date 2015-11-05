#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int lim = 1e5 + 1;
const int maxn = 1e5;
const int maxq = 1e5;

int n, q;

struct cmpS1
{
	bool operator() (const PII& a, const PII& b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

struct cmpS2
{
	bool operator() (const pair<PII, int>& a, const pair<PII, int>& b)
	{
		if (a.second == b.second)
		{
			if (a.first.second == b.first.second)
				return a.first.first < b.first.first;
			return a.first.second < b.first.second;
		}
		return a.second < b.second;
	}
};

int parent[lim];
vector<int> members(lim);
multiset<PII, cmpS1> S1;
multiset<pair<PII, int>, cmpS2> S2;

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		members[i] = 1;
		S1.insert(make_pair(i, 1));
	}

	multiset<PII, cmpS1>::iterator ahead = S1.begin();
	multiset<PII, cmpS1>::iterator behind = ahead;

	ahead++;
	while (ahead != S1.end())
	{
		PII a = *ahead;
		PII b = *behind;
		S2.insert(make_pair(make_pair(a.first, b.first), abs(a.second - b.second)));
		ahead++;
		behind++;
	}
}

int ancestor(int a)
{
	if (parent[a] != a)
		parent[a] = ancestor(parent[a]);
	return parent[a];
}

void merge(int a, int b)
{
	a = ancestor(a);
	b = ancestor(b);
	if (a == b)
		return;

	if (members[b] > members[a])
		swap(a, b);
	else if (members[b] == members[a])
		if (b > a)
			swap(a, b);

	multiset<PII, cmpS1>::iterator foo = S1.find(make_pair(a, members[a]));
	multiset<PII, cmpS1>::iterator bar = S1.find(make_pair(b, members[b]));

	multiset<PII, cmpS1>::iterator fooA, fooB, barA, barB;
	fooA = foo; fooA++;
	fooB = foo; fooB--;
	barA = bar; barA++;
	barB = bar; barB--;

	PII FOO, FOOA, FOOB, BAR, BARA, BARB;

	multiset<PII, cmpS1>::iterator buz;

	multiset<PII, cmpS1>::iterator it1, it2, it3, it4, it5;
	it1 = foo; it1--;
	it2 = bar;
	if (S2.size() == 2)
	{
		multiset<PII, cmpS1> S3;
		for (auto saviour: S1)
		{
			if (saviour.first == a and saviour.second == members[a])
				continue;
			if (saviour.first == b and saviour.second == members[b])
				continue;
			S3.insert(make_pair(saviour.first, saviour.second));
		}
		parent[b] = a;
		members[a] += members[b];
		S3.insert(make_pair(a, members[a]));
		S1 = S3;
		S2.clear();
		multiset<PII, cmpS1>::iterator ahead = S1.begin();
		multiset<PII, cmpS1>::iterator behind = ahead;

		ahead++;
		while (ahead != S1.end())
		{
			PII a = *ahead;
			PII b = *behind;
			S2.insert(make_pair(make_pair(a.first, b.first), abs(a.second - b.second)));
			ahead++;
			behind++;
		}
		return;
	}
	if (it1 == it2)		// it1 is bigger group, it2 is smaller group
	{
		it1++;
		multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair((*it1).first, (*it2).first), abs((*it1).second - (*it2).second)));
		if (fml != S2.end())
			S2.erase(fml);
		it3 = it1;
		it3++;
		if (it3 != S1.end())
		{
			fml = S2.find(make_pair(make_pair((*it3).first, (*it1).first), abs((*it3).second - (*it1).second)));
			if (fml != S2.end())
				S2.erase(fml);
		}
		if (it2 != S1.begin())
		{
			it4 = it2;
			it4--;
			fml = S2.find(make_pair(make_pair((*it2).first, (*it4).first), abs((*it2).second - (*it4).second)));
			if (fml != S2.end())
				S2.erase(fml);
		}
		if (it3 != S1.end() and it2 != S1.begin())
		{
			it4 = it2;
			it4--;
			S2.insert(make_pair(make_pair((*it3).first, (*it4).first), abs((*it3).second - (*it4).second)));
		}
		S1.erase(foo);
		S1.erase(bar);
		members[a] += members[b];
		parent[b] = a;
		S1.insert(make_pair(a, members[a]));
		foo = S1.find(make_pair(a, members[a]));
		fooA = fooB = foo;
		fooA++, fooB--;

		buz = S1.begin(); buz--;
		if (fooA != S1.end() and fooB != buz)
		{
			FOOA = *fooA;
			FOO = *foo;
			FOOB = *fooB;
			multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair(FOOA.first, FOOB.first), abs(FOOA.second - FOOB.second)));
			if (fml != S2.end())
				S2.erase(fml);
		}

		if (fooA != S1.end())
		{
			FOOA = *fooA;
			FOO = *foo;
			S2.insert(make_pair(make_pair(FOOA.first, FOO.first), abs(FOOA.second - FOO.second)));
		}

		buz = S1.begin(); buz--;
		if (fooB != buz)
		{
			FOOB = *fooB;
			FOO = *foo;
			S2.insert(make_pair(make_pair(FOO.first, FOOB.first), abs(FOO.second - FOOB.second)));
		}

		return;
	}

	if (fooA != S1.end())
	{
		FOOA = *fooA;
		FOO = *foo;
		multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair(FOOA.first, FOO.first), abs(FOOA.second - FOO.second)));
		if (fml != S2.end())
			S2.erase(fml);
	}
	buz = S1.begin(); buz--;
	if (fooB != buz)
	{
		FOOB = *fooB;
		FOO = *foo;
		multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair(FOO.first, FOOB.first), abs(FOO.second - FOOB.second)));
		if (fml != S2.end())
			S2.erase(fml);
	}

	buz = S1.begin(); buz--;
	if (fooA != S1.end() and fooB != buz)
	{
		FOOA = *fooA;
		FOOB = *fooB;
		S2.insert(make_pair(make_pair(FOOA.first, FOOB.first), abs(FOOA.second - FOOB.second)));
	}

	if (barA != S1.end())
	{
		BARA = *barA;
		BAR = *bar;
		multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair(BARA.first, BAR.first), abs(BARA.second - BAR.second)));
		if (fml != S2.end())
			S2.erase(fml);
	}

	buz = S1.begin(); buz--;
	if (barB != buz)
	{
		BARB = *barB;
		BAR = *bar;
		multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair(BAR.first, BARB.first), abs(BAR.second - BARB.second)));
		if (fml != S2.end())
			S2.erase(fml);
	}

	buz = S1.begin(); buz--;
	if (barA != S1.end() and barB != buz)
	{
		BARA = *barA;
		BARB = *barB;
		S2.insert(make_pair(make_pair(BARA.first, BARB.first), abs(BARA.second - BARB.second)));
	}

	multiset<PII,cmpS1>::iterator fml = S1.find(make_pair(a, members[a]));
	S1.erase(S1.find(make_pair(a, members[a])));
	fml = S1.find(make_pair(b, members[b]));
	S1.erase(S1.find(make_pair(b, members[b])));

	members[a] += members[b];
	parent[b] = a;

	S1.insert(make_pair(a, members[a]));

	foo = S1.find(make_pair(a, members[a]));
	fooA = fooB = foo;
	fooA++, fooB--;

	buz = S1.begin(); buz--;
	if (fooA != S1.end() and fooB != buz)
	{
		FOOA = *fooA;
		FOO = *foo;
		FOOB = *fooB;
		multiset<pair<PII,int>, cmpS2>::iterator fml = S2.find(make_pair(make_pair(FOOA.first, FOOB.first), abs(FOOA.second - FOOB.second)));
		if (fml != S2.end())
			S2.erase(fml);
	}

	if (fooA != S1.end())
	{
		FOOA = *fooA;
		FOO = *foo;
		S2.insert(make_pair(make_pair(FOOA.first, FOO.first), abs(FOOA.second - FOO.second)));
	}

	buz = S1.begin(); buz--;
	if (fooB != buz)
	{
		FOOB = *fooB;
		FOO = *foo;
		S2.insert(make_pair(make_pair(FOO.first, FOOB.first), abs(FOO.second - FOOB.second)));
	}
}

int printAns()
{
	if (S1.size() == 1)
		return 0;
	return (*(S2.begin())).second;
}

int main()
{
	scanf("%d%d", &n, &q);
	assert(1 <= n and n <= maxn);
	assert(1 <= q and q <= maxq);

	init(n);

	for (int i = 1; i <= q; i++)
	{
		int a, b;

		scanf("%d%d", &a, &b);
		assert(1 <= a and a <= n);
		assert(1 <= b and b <= n);

		merge(a, b);

		printf("%d\n", printAns());
	}
	return 0;
}

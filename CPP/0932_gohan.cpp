#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string S;
deque<char> sahay;
multiset<deque<char> > M;
set<deque<char> > UNIQ;

void solve(deque<char> Q, deque<char> ST, deque<char> F)
{
	if (F.size() == sahay.size())
	{
		M.insert(F);
		UNIQ.insert(F);
		return;
	}
	if (Q.size() and ST.size())
	{
		char foo = Q.front();
		Q.pop_front();
		ST.push_front(foo);
		solve(Q, ST, F);
		ST.pop_front();
		Q.push_front(foo);
		foo = ST.front();
		ST.pop_front();
		F.push_back(foo);
		solve(Q, ST, F);
	}
	else if (Q.size())
	{
		char foo = Q.front();
		Q.pop_front();
		ST.push_front(foo);
		solve(Q, ST, F);
	}
	else if (ST.size())
	{
		char foo = ST.front();
		ST.pop_front();
		F.push_back(foo);
		solve(Q, ST, F);
	}
}

int main()
{
	optimizeIO();
	cin >> S;
	deque<char> Q, ST, F;
	for (auto s: S)
		Q.push_back(s);
	sahay = Q;
	solve(Q, ST, F);
	int a1 = M.count(sahay);
	int a2 = UNIQ.size();
	cout << a1 << ' ' << a2 << '\n';
	return 0;
}

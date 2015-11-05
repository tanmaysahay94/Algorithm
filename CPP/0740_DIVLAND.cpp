#include <bits/stdc++.h>
#include <time.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	long long n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a >> b >> c;
	srand(time(NULL));
	set<long long> firstSon;
	while ((int) firstSon.size() != n/2)
		firstSon.insert(rand() % n);
	set<long long>::iterator sit;
	for (sit = firstSon.begin(); sit != firstSon.end(); sit++)
		cout << *sit << ' ';
	cout << endl;
	return 0;
}

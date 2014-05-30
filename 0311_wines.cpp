#include <iostream>
#include <vector>

using namespace std;

int cache[1000][1000];
int max(int a, int b)
{
	return a > b ? a : b;
}
int f(vector<int>& v, int first, int last, int year)
{
	if (cache[first][last] != -1)
		return cache[first][last];
	if (first <= last)
		return cache[first][last] = max(f(v, first+1, last, year+1) + year * v[first], f(v, first, last-1, year+1) + year * v[last]);
	return 0;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < 1000; i++)
		for(int j = 0; j < 1000; j++)
			cache[i][j] = -1;
	for (vector<int> :: iterator i = v.begin(); i != v.end(); i++)
		cin >> *i;
	cout << f(v, 0, n-1, 1) << endl;
}

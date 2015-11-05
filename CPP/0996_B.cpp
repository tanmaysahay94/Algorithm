#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, s, f;
	cin >> n >> m >> s >> f;
	char move;
	int inc;
	if (s < f)
		move = 'R', inc = 1;
	else
		move = 'L', inc = -1;
	int cur = s, i = 1, cnt = 0;
	while (cur != f)
	{
		int t, l, r;
		if (cnt < m)
		{
			cin >> t >> l >> r;
			cnt++;
		}
		while (i < t)
		{
			cur += inc;
			cout << move;
			if (cur == f)
				return 0;
			i++;
		}
		if ((i == t) and ((l <= cur and cur <= r) or (l <= cur + inc and cur + inc <= r)))
			cout << "X";
		else
		{
			cout << move;
			cur += inc;
		}
		i++;
	}
	cout<<endl;
	return 0;
}

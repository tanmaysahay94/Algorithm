#include <vector>
#include <cstdio>

using namespace std;

inline int read()
{
	int n = 0;
	char c;
	while ((c = getchar_unlocked()) < '0');
	n += c-'0';
	while ((c = getchar_unlocked()) >= '0')
		n = (n << 3) + (n << 1) + (c - '0');
	return n;
}

int owner(int idx, vector<int>& belong)				// head recursion for the win. so much better do it recursively than iteratively
{
	if (belong[idx] != idx)
		belong[idx] = owner(belong[idx], belong);
	return belong[idx];
}

int main()
{
	char err[] = "Invalid query!";
	int t, n, q, type, x, y, i;
	t = read();
	while (t--)
	{
		n = read();
		vector<int> score(n), belong(n);
		for (i = 0; i < n; i++)
			belong[i] = i;
		for (i = 0; i < n; i++)
			score[i] = read();
		q = read();
		while (q--)
		{
			type = read();
			if (type)
			{
				x = owner(read() - 1, belong);
				printf("%d\n", x + 1);
			}
			else
			{
				x = owner(read() - 1, belong); y = owner(read() - 1, belong);
				if (x != y)
				{
					if (score[x] > score[y])
						belong[y] = x;
					else if (score[y] > score[x])
						belong[x] = y;
				}
				else
					puts(err);
			}
		}
	}
	return 0;
}

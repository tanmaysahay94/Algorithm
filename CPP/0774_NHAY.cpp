#include <bits/stdc++.h>

using namespace std;

char needle[5000000], hay[5000000];
int len, table[5000001];

void build()
{
	table[0] = table[1] = 0;
	for (int i = 2; i <= len; i++)
	{
		int j = table[i - 1];
		for (;;)
		{
			if (needle[j] == needle[i - 1])
			{
				table[i] = j + 1;
				break;
			}
			else if (j == 0)
			{
				table[i] = 0;
				break;
			}
			else
				j = table[j];
		}
	}
}

void eval()
{
	int m = len;
	int n = strlen(hay);
	int i(0), j(0);
	for (;;)
	{
		if (j == n)
			return;
		if (needle[i] == hay[j])
		{
			i++;
			j++;
			if (i == m)
			{
				printf("%d\n", j - i);
				i = table[i];
			}
		}
		else if (i > 0)
			i = table[i];
		else
			j++;
	}
}

int main()
{
	while (scanf("%d", &len) != EOF)
	{
		scanf("%s%s", needle, hay);
		build();
		eval();
		printf("\n");
	}
	return 0;
}

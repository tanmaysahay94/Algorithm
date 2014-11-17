#include <stdio.h>
#include <string.h>

int main()
{
	long long int t;
	char num[100100];
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%s", num);
		long long len = strlen(num);
		if (len == 1)
		{
			if (num[0] == '0' || num[0] == '4' || num[0] == '8')
				printf("4\n");
			else
				printf("0\n");
		}
		else
		{
			int val = 0;
			val += 10 * (num[len - 2] - '0');
			val += num[len - 1] - '0';
			if (val % 4 == 0)
				printf("4\n");
			else
				printf("0\n");
		}
	}
	return 0;
}

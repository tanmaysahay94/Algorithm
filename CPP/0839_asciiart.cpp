#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("  /\\\n");
	for (int i = 0; i < n; i++)
		printf("  ||\n");
	printf(" /||\\\n");
	printf("/:||:\\\n");
	for (int i = 0; i + 1 < n; i++)
		printf("|:||:|\n");
	printf("|/||\\|\n");
	printf("  **\n  **\n");
	return 0;
}

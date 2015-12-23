#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL a, b, c; LL d = 42;
	cin >> a >> b >> c;
	if (a * b * c == d)
		printf("%lld*%lld*%lld", a, b, c);
	else if (a * b + c == d)
		printf("%lld*%lld+%lld", a, b, c);
	else if (a + b * c == d)
		printf("%lld+%lld*%lld", a, b, c);
	else if (a + b + c == d)
		printf("%lld+%lld+%lld", a, b, c);
	else
		printf("This is not the ultimate question");
	return 0;
}

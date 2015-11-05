#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n, i, press = 0;
	cin >> n;
	i = n-1;
	while (i >= 0)
	{
		press++;
		press += i * (n-i);
		i--;
	}
	cout << press << endl;
}

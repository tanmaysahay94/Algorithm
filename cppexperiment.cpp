#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>

using namespace std;

int main()
{
	int i = 113236, count = 0;
	while (i != 1)
	{
		if (i & 1) i = 3 * i + 1;
		else i /= 2;
		cout << i << endl;
		count ++;
	}
	cout << count << endl;
}

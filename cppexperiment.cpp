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
	int C[64][64];
	C[0][0] = 1;
	for (int i = 1; i <= 63; i++)
		for (int j = 0; j <= i; j++)
			C[i][j]=C[i-1][j]+((j)?(C[i-1][j-1]):0);
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
			cout << C[i][j];
		cout << endl;
	}
}

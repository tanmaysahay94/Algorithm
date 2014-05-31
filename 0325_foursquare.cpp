#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>
#include <map>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	vector<long long> cal(4);
	for (long long i = 0; i < 4; i++)
		cin >> cal[i];
	string moves;
	cin >> moves;
	long long len = moves.length(), out = 0;
	for (long long i = 0; i < len; i++)
		out += cal[moves[i] - '1'];
	cout << out << endl;
}

#include <iostream>
#include <vector>

using namespace std;

int longestZigZag(vector<int>& v)		// return length of longest zigzag sequence
{
	if (v.size() == 1)
		return 1;
	// direction vector contains all the differences
	vector<int> direction(v.size() - 1);
	for (int i = 1; i < v.size(); i++)
		direction[i-1] = v[i-1] - v[i];

	long long int d, check = 0, length = 2;	// length initialized to 2 as all other cases return 1
	// check goes upto the index where difference is 0
	while (check < direction.size() && direction[check] == 0)
		check++;
	if (check == direction.size())
		return 1;
	
	d = direction[check];
	for (int i = check + 1; i < direction.size(); i++)		// keep reversing direction every time condition (line 24) is fulfilled
		if (d * direction[i] < 0)
		{
			d *= -1;
			length++;
		}
	return length;
}
int main()
{
	vector<int> v;
	int n, val;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	cout << longestZigZag(v) << endl;
}

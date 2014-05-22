#include<iostream>
#include<string>
#include<vector>
using namespace std;
void update(int k[], int i, int val)
{
	k[i] = val;
}
int main()
{
	int k[10];
	int i, val;
	for(i = 0; i < 10; i++)
	{
		cin >> val;
		update(k, i, val);
		cout << k[i];
	}
}

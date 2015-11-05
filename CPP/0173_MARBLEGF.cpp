#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void update(int tree[], int val, int index, int maxSize)
{
	while (index < maxSize)
	{
		tree[index] += val;
		index += (index & (-index));
	}
}
int cumFre(int tree[], int index)
{
	int freq = 0;
	while (index >= 1)
	{
		freq += tree[index];
		index -= (index & (-index));
	}
	return freq;
}
int main()
{
	int n, q, i, index, val;
	char choice, dump;
	cin >> n >> q;
	n++;
	int tree[n];
	memset(tree, 0, sizeof(tree));
	for (i = 1; i < n; i++)
	{
		cin >> val;
		update(tree, val, i, n);
	}
	while (q--)
	{
		scanf("%c%c", &dump, &choice);
		cin >> index >> val;
		if(choice == 'S')
		{
			if (index < val)
				index = index + val - (val = index);
			cout << cumFre(tree, index+1) - cumFre(tree, val) << '\n';
		}
		else if(choice == 'G')
			update(tree, val, index+1, n);
		else if(choice == 'T')
			update(tree, -val, index+1, n);
	}
}

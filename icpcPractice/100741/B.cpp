#include <bits/stdc++.h>

using namespace std;

int n;

int cnt;

map<string, int> names;
map<int, string> word;

vector< vector<int> > eds;

stack<int> ans;

vector<int> done(100100, 0);

void dfs(int num)
{
	done[num] = 1;
	for(vector<int>::reverse_iterator it = eds[num].rbegin(); it != eds[num].rend(); it++)
		if(!done[*it])
			dfs(*it);
	ans.push(num);
}

int main()
{
	//PS: I love you
	scanf("%d", &n);
	string s;
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>s;	//def
		cin>>s;	//functionName
		names[s] = cnt++;
		eds.push_back(vector<int>());
		while(1)
		{
			cin>>s;	//with / =
			if(s != "with")
				break;
			else
			{
				cin>>s;	//oldFunction
				eds[cnt-1].push_back(names[s]);
			}
		}
		cin>>s;	//Value
		word[cnt-1] = s;
	}
	cin>>s;
	int a = names[s];
	dfs(a);
	while(!ans.empty())
	{
		cout<<word[ans.top()]<<" ";
		ans.pop();
	}
	cout<<endl;
	return 0;
}

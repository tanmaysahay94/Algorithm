#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int pow_10[8], dp[8][2];
bool valid[10][10];
string S,M,R;

int solve(int, int);
void update(int, int, int);

void init()
{
	pow_10[0] = 1;
	for(int i = 1; i < 8; i++)
		pow_10[i] = pow_10[i-1] * 10;
	memset(valid, false, sizeof valid);
	valid[0][8] = true;
	valid[1][0] = true;
	valid[1][3] = true;
	valid[1][4] = true;
	valid[1][7] = true;
	valid[1][8] = true;
	valid[1][9] = true;
	valid[2][8] = true;
	valid[3][8] = true;
	valid[3][9] = true;
	valid[4][8] = true;
	valid[4][9] = true;
	valid[5][6] = true;
	valid[5][8] = true;
	valid[5][9] = true;
	valid[6][8] = true;
	valid[7][0] = true;
	valid[7][3] = true;
	valid[7][8] = true;
	valid[7][9] = true;
	valid[9][8] = true;
}

bool convert(char i, char j)
{
	if (i == 'X' || i == j)
		return true;
	else
		return valid[i-'0'][j-'0'];
}

int convertString(string s)
{
	int num;
	stringstream sstr(s);
	sstr >> num;
	return num;
}

int solve(int i, int j)
{
	if (i >= M.size())
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int off = M.size() - 1;
	if (j == 0)
	{
		char val = R[i];
		for(int k = '0'; k <= M[i]; k++)
			if (convert(R[i], k))
				val = k;	
		update(val, i, j);
		val = R[i];
		for(int k = '0'; k < M[i]; k++)
			if (convert(R[i], k))
				val = k;	
		update(val, i, j);
	}
	else
	{
		if (convert(R[i], '9'))
			dp[i][j] = 9 * pow_10[off - i] + solve(i + 1, 1);
		else
			dp[i][j] = 8 * pow_10[off - i] + solve(i + 1, 1);
	}
	return dp[i][j];
}

void update(int val, int i, int j)
{
	int off = M.size() - 1;
	if (val > M[i])
	{
		if (dp[i][j] == -1)
			dp[i][j] = -2;
		else
			dp[i][j] = max(-2, dp[i][j]);
	}
	else if (val < M[i])
		dp[i][j] = max((val - '0') * pow_10[off - i] + solve(i + 1, 1), dp[i][j]);
	else
	{
		int value = solve(i + 1, 0);
		if (value == -2)
		{
			if (dp[i][j] == -1)
				dp[i][j] = -2;
		}
		else
			dp[i][j] = max((val - '0') * pow_10[off - i] + value, dp[i][j]);
	}
}

int main()
{
	init();
	LL t;
	SLL(t);
	while (t--)
	{
		cin >> S >> M;
		int ans = convertString(S);
		int diff = M.size() - S.size();
		for(int i = 0; i <= diff; i++)
		{
			R.clear();
			for(int j = 0; j < i; j++)
				R.push_back('X');
			R.append(S);
			for(int j = 0; j < diff-i; j++)
				R.push_back('X');
			memset(dp, -1, sizeof dp);
			ans = max(ans, solve(0, 0));
		}
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> keep;

bool can(string& s)
{
    keep = vector<int> (n);
    int mismatch = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] != s[j])
        {
            mismatch++;
            if (s[i] > s[j])
                keep[i] = 1;
            else
                keep[i] = -1;
        }
    return mismatch <= k;
}

int main()
{
    string s;
    cin >> n >> k >> s;
    if (not can(s))
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (keep[i] == 1)
            s[j] = s[i], k--;
        else if (keep[i] == -1)
            s[i] = s[j], k--;
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] == '9')
            continue;
        else
        {
            if (not keep[i])
            {
                if (k > 1)
                    s[i] = s[j] = '9', k -= 2;
            }
            else
            {
                if (k > 0)
                    s[i] = s[j] = '9', k--;
            }
        }
    if (n&1 and s[n/2] < '9' and k > 0)
        s[n/2] = '9', k--;
    cout << s << endl;
    return 0;
}

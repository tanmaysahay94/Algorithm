#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        int len = s.length();
        if (len > 26)
                printf("-1\n");
        else
        {
                set<char> S;
                for (auto c: s)
                        S.insert(c);
                printf("%d\n", len - (int)S.size());
        }
        return 0;
}

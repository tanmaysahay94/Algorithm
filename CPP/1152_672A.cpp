#include <bits/stdc++.h>

using namespace std;

string s;

void init()
{
        for (int i = 1; i <= 1000; i++)
                s += to_string(i);
}

int main()
{
        init();
        int n;
        scanf("%d", &n);
        printf("%c\n", s[n - 1]);
        return 0;
}

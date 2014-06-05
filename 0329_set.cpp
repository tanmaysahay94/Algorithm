#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int lowbit(long long val)
{
    return val & (-val);
}
int main()
{
    long long sum, limit, i, curr = 0;
    cin >> sum >> limit;
    vector<long long> answer;
    vector<pair<long long, long long> > bit;
    for (i = 1; i <= limit; i++)
        bit.push_back(make_pair(lowbit(i), i));
    sort(bit.begin(), bit.end());
    i = limit - 1;
    while (i >= 0)
    {
        if (curr + bit[i].first <= sum)
        {
            curr += bit[i].first;
            answer.push_back(bit[i].second);
        }
        i--;
    }
    if (curr != sum)
        cout << "-1";
    else
    {
        cout << answer.size() << endl;
        for (i = 0; i < answer.size() - 1; i++)
            cout << answer[i] << " ";
        cout << answer[i] << endl;
    }
}

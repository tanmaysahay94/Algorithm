
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <stack>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
    __f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

typedef long long LL;

class node
{
    private:
        int cnt;
        node *c[2];
    public:
        node()
        {
            cnt = 0;
            c[0] = NULL;
            c[1] = NULL;
        }
        void add(LL val, node *root)
        {
            node *t = root;
            for (int i = 0; i < 18; i++)
            {
                int dig = val % 10;
                val /= 10;
                dig %= 2;
                if (not t -> c[dig])
                    t -> c[dig] = new node();
                t = t -> c[dig];
                t -> cnt++;
            }
        }
        void remove(LL val, node *root)
        {
            node *t = root;
            for (int i = 0; i < 18; i++)
            {
                int dig = val % 10;
                val /= 10;
                dig %= 2;
                t = t -> c[dig];
                t -> cnt--;
            }
        }
        int query(string& S, node *root)
        {
            node *t = root;
            for (auto &s: S)
            {
                int dig = s - '0';
                if (not t -> c[dig])
                    t -> c[dig] = new node();
                t = t -> c[dig];
            }
            return t -> cnt;
        }
};

int main()
{
    int __T;
    scanf("%d", &__T);
    node *root = new node();
    char foo[100];
    for (int T = 1; T <= __T; T++)
    {
        getchar();
        char c;
        scanf("%c", &c);
        LL val;
        if (c == '+')
        {
            scanf("%lld", &val);
            root -> add(val, root);
        }
        else if (c == '-')
        {
            scanf("%lld", &val);
            root -> remove(val, root);
        }
        else
        {
            scanf("%s", foo);
            string S;
            int len = strlen(foo);
            for (int i = 0; i < 18 - len; i++)
                S.push_back('0');
            for (int i = 0; foo[i]; i++)
                S.push_back(foo[i]);
            reverse(S.begin(), S.end());
            printf("%d\n", root -> query(S, root));
        }
    }
    return 0;
}

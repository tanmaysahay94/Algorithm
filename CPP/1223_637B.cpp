
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

class node
{
    public:
        node(string &s)
        {
            name = s;
            prev = next = NULL;
        }
        string name;
        node *prev, *next;
};

class deck
{
    node *head, *tail;
    unordered_map<string, node *> u_map;
    void push(string &s)
    {
        node *toAdd = new node(s);
        if (u_map.size() == 0)
            head = tail = toAdd;
        else
        {
            head -> prev = toAdd;
            toAdd -> next = head;
            toAdd -> prev = NULL;
            head = toAdd;
        }
        u_map[s] = toAdd;
    }
    public:
    deck() {}
    void access(string &s)
    {
        auto it = u_map.find(s);
        if (it == u_map.end())
            push(s);
        else
        {
            if (u_map.size() == 1) return;
            if (head -> name == s) return;
            node *loc = (*it).second;
            loc -> prev -> next = loc -> next;
            if (loc -> next) loc -> next -> prev = loc -> prev;
            head -> prev = loc;
            loc -> next = head;
            loc -> prev = NULL;
            head = loc;
        }
    }
    void show()
    {
        node *t = head;
        while (t)
        {
            cout << t -> name << '\n';
            t = t -> next;
        }
    }
};

int main()
{
    int __T;
    scanf("%d", &__T);
    string name;
    deck d;
    for (int T = 1; T <= __T; T++)
    {
        cin >> name;
        d.access(name);
    }
    d.show();
    return 0;
}


#include "bits/stdc++.h"
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

class Node {
    public:
    int val;
    Node *next;
    Node(int v): val(v), next(nullptr) {}
};

class CircularSortedLinkedList {
    Node *first, *last;
    public: CircularSortedLinkedList():
            first(nullptr), last(nullptr) {}

    void insert(int val) {
        if (first == nullptr) {
            first = new Node(val);
            first->next = first;
            last = first;
        
        } else if (first == last) {
            Node *toInsert = new Node(val);
            if (val < first->val) {
                toInsert->next = first;
                first = toInsert;
            } else {
                last = toInsert;
                first->next = toInsert;
            }
            
            last->next = first;

        } else {
            Node *traverse = first, *prev = last;
            Node *toInsert = new Node(val);

            while (traverse->val < val and traverse != last) {
                prev = traverse;
                traverse = traverse->next;
            }
                
            if (traverse == last) {
                toInsert->next = traverse->next;
                traverse->next = toInsert;
            } else {
                prev->next = toInsert;
                toInsert->next = traverse;
            }
        }
    }

    void show() {
        cout << "-------------------" << endl;
        cout << "first: " << first->val << " last: " << last->val << endl;
        cout << "first-next: " << first->next->val << " last-next: " << last->next->val << endl;
        cout << "-------------------" << endl;
        if (first == last) cout << first->val << endl;
        else {
            Node *current = first;
            while (current != last) {
                cout << current->val << " -> ";
                current = current->next;
            }
            cout << current->val << endl;
        }
        cout << "-------------------" << endl;
    }
};

int main()
{
    int n;
    cout << "Input number of number you wish to insert: ";
    cin >> n;

    CircularSortedLinkedList csll;
    for (int idx = 1; idx <= n; ++idx) {
        int num;
        cout << "Input number to insert into circular linked list: ";
        cin >> num;
        csll.insert(num);
        csll.show();
    }
    return 0;
}

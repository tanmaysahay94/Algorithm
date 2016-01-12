#include <bits/stdc++.h>
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

typedef struct node
{
	int data;
	node *prev, *next;
	node(int d): data(d), prev(NULL), next(NULL) {}
}node;

class LRU
{
	int cacheSize;
	node *head, *tail;
	unordered_map<int, node *> presentPages;
	public:
	LRU(int cSize): head(NULL), tail(NULL), cacheSize(cSize){}
	void access(int pageNo)
	{
		if (cacheSize == 1)
		{
			node *newNode = new node(pageNo);
			head = tail = newNode;
			presentPages.clear();
			presentPages[pageNo] = newNode;
			return;
		}
		if (presentPages.count(pageNo))
		{
			if (head -> data == pageNo) return;
			node *tmp = presentPages[pageNo];
			node *agla = tmp -> next;
			node *pichla = tmp->prev;
			if (pichla) pichla -> next = agla;
			if (agla) agla -> prev = pichla;
			tmp -> next = head;
			head -> prev = tmp;
			head = tmp;
		}
		else
		{
			if ((int) presentPages.size() == cacheSize)
			{
				node *toDel = tail;
				int valToDelete = toDel -> data;
				tail = tail -> prev;
				delete toDel;
				tail -> next = NULL;
				presentPages.erase(valToDelete);
			}
			node *toAdd = new node(pageNo);
			if ((int) presentPages.size() == 0)
				head = tail = toAdd;
			else 
			{
				toAdd -> next = head;
				head -> prev = toAdd;
				head = toAdd;
				toAdd -> prev = NULL;
			}
			presentPages[pageNo] = toAdd;
		}
	}
	void show()
	{
		node* tmp = head;
		while (tmp)
		{
			printf("%d ", tmp -> data);
			tmp = tmp -> next;
		}
		printf("\n");
	}
};

int main()
{
	int cSize;
	cin>>cSize;
	LRU lru(cSize);
	while (1)
	{
		int val;
		cin >> val;
		lru.access(val);
		lru.show();
	}
	return 0;
}

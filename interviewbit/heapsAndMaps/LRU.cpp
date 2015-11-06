class item {
    public:
        int k, val;
        item *left, *right;
        item(int _val, int _k): left(0), right(0), k(_k), val(_val) {}
};

class deck {
    public:
        item *front, *rear;
        deck(): front(0), rear(0) {}
        item *push_front(int, int);
        int pop_back();
        void recent_use(item *);
        void clear();
};

item* deck::push_front(int a, int b) {
    item *foo = new item(a, b);
    if (not front) {
        front = rear = foo;
    }
    else {
        foo -> right = front;
        front -> left = foo;
        front = foo;
    }
    return foo;
}

int deck::pop_back() {
    item *foo = rear;
    int key = foo -> k;
    rear = rear -> left;
    if (rear) {
        rear -> right = 0;
    }
    else {
        front = 0;
    }
    foo -> left = 0;
    delete foo;
    return key;
}

void deck::recent_use(item *foo) {
    if (not foo) {
        return;
    }
    item *prev = foo -> left;
    if (prev) {
        prev -> right = foo -> right;
    }
    else {
        return;
    }
    item *next = foo -> right;
    if (next) {
        next -> left = prev;
    }
    if (rear == foo) {
        rear = foo -> left;
    }
    rear -> right = 0;
    foo -> right = front;
    front -> left = foo;
    foo -> left = 0;
    front = foo;
}

void deck::clear() {
    item *foo = front;
    while (foo) {
        front = front -> right;
        delete foo;
        foo = front;
    }
    front = 0;
    rear = 0;
}

unordered_map<int, item *> mp;
int sz = 0;
deck D;

LRUCache::LRUCache(int capacity) {
    sz = capacity;
    mp.clear();
    D.clear();
}

int LRUCache::get(int key) {
    if (mp.find(key) == mp.end()) {
        return -1;
    }
    item *foo = mp[key];
    D.recent_use(foo);
    return D.front -> val;
}

void LRUCache::set(int key, int value) {
    int n = mp.size();
    if (mp.find(key) == mp.end()) {
        if (n >= sz) {
            mp.erase(D.pop_back());
        }
        mp[key] = D.push_front(value, key);
    }
    else {
        item *foo = mp[key];
        foo -> val = value;
        D.recent_use(foo);
    }
}

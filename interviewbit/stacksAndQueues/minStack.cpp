struct node {
    int num;
    int cnt;
    node(int a, int b): num(a), cnt(b) {}
};
stack<int> val;
stack<node> minUpto;
MinStack::MinStack() {
    while (val.size()) {
        val.pop();
    }
    while (minUpto.size()) {
        minUpto.pop();
    }
}

void MinStack::push(int x) {
    if (minUpto.size()) {
        if (x < minUpto.top().num) {
            minUpto.push(node(x, 0));
        }
        else if (x == minUpto.top().num) {
            minUpto.top().num++;
        }
    }
    else {
        minUpto.push(node(x, 0));
    }
    val.push(x);
}

void MinStack::pop() {
    if (minUpto.size()) {
        if (val.top() == minUpto.top().num) {
            if (minUpto.top().cnt == 0) {
                minUpto.pop();
            }
            else {
                minUpto.top().cnt--;
            }
        }
        val.pop();
    }
}

int MinStack::top() {
    if (val.size() == 0) {
        return -1;
    }
    return val.top();
}

int MinStack::getMin() {
    if (val.size() == 0) {
        return -1;
    }
    return minUpto.top().num;
}


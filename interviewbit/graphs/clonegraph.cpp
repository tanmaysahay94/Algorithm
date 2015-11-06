/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

typedef UndirectedGraphNode UDN;

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if (not node) {
        return node;
    }
    unordered_map<UDN*, UDN*> u_map;
    queue<UDN*> Q;
    Q.push(node);
    UDN* ret = new UDN(node -> label);
    u_map[node] = ret;
    while (Q.size()) {
        UDN* udn = Q.front();
        Q.pop();
        for (auto n: udn -> neighbors) {
            if (u_map.count(n)) {
                u_map[udn] -> neighbors.push_back(u_map[n]);
            }
            else {
                UDN* tmp = new UDN(n -> label);
                u_map[n] = tmp;
                u_map[udn] -> neighbors.push_back(u_map[n]);
                Q.push(n);
            }
        }
    }
    return ret;
}
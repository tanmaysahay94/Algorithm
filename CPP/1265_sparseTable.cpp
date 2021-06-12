
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

class SparseTable {
    private:
        vector<vector<int>> sparseTable;
        vector<int>& V;

        void build() {
            int logTableSize = 1 << (int) floor(log2((int) V.size()));

            sparseTable.assign(logTableSize, vector<int> (V.size(), INT_MAX));
            sparseTable[0] = V;

            for (int logLen = 1; logLen < (int) sparseTable.size(); ++logLen) {
                for (int idx = 0; idx + (1 << (logLen - 1)) < (int) V.size(); ++idx) {
                    int otherIdx = idx + (1 << (logLen - 1));

                    if (sparseTable[logLen - 1][idx] < sparseTable[logLen - 1][otherIdx]) {
                        sparseTable[logLen][idx] = idx;
                    } else {
                        sparseTable[logLen][idx] = otherIdx;
                    }
                }
            }
        }

    public:
        SparseTable(vector<int>& _V): V(_V) {
            build();
        }

        int argMin(pair<int, int> query) {
            if (query.first > query.second) {
                swap(query.first, query.second);
            }

            int length = query.second - query.first + 1;
            int logLevel = log2(length);

            if (query.first + (1 << logLevel) >= (int) V.size()) {
                return sparseTable[logLevel][query.first];
            }

            query.second -= (1 << logLevel) - 1;
            return V[sparseTable[logLevel][query.first]] < V[sparseTable[logLevel][query.second]]
                ? sparseTable[logLevel][query.first]
                : sparseTable[logLevel][query.second];
        }

        int min(pair<int, int>& query) {
            return V[argMin(query)];
        }
};

int main()
{
    
    vector<int> V = {1, 3, 5, 2, 6, 8, 1, 0, 3, 5, 1};
    cout << "Vector: [ ";
    for (auto &v: V) cout << v << " ";
    cout << "]\n";

    vector<pair<int, int>> queries = {{1, 3}, {0, 7}, {4, 4}};

    SparseTable st(V);
    for (auto &query: queries) {
        int idx = st.argMin(query);
        printf("Querying range (0-indexed): [%d, %d] -> min = %d at index %d\n", query.first, query.second, V[idx], idx); 
    }
    return 0;
}

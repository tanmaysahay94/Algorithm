bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, int> > tm;
    for (int i = 0; i < (int) arrive.size(); i++) {
        tm.push_back(make_pair(arrive[i], 1));
        tm.push_back(make_pair(depart[i], 0));
    }
    sort(tm.begin(), tm.end());
    int cnt = 0;
    for (int i = 0; i < (int) tm.size(); i++) {
        if (tm[i].second == 1) {
            cnt++;
            if (cnt > K) {
                return 0;
            }
        }
        else {
            cnt--;
        }
    }
    return 1;
}

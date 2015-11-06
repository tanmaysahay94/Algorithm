string Solution::countAndSay(int A) {
    string ret("1");
    for (int i = 1; i < A; i++) {
        int count = 1;
        string tmp;
        int j(0), k(1);
        for (; k < (int) ret.length(); k++, j++) {
            if (ret[j] == ret[k]) {
                count++;
            }
            else {
                tmp += to_string(count);
                tmp.push_back(ret[j]);
                count = 1;
            }
        }
        tmp += to_string(count);
        tmp.push_back(ret[j]);
        count = 1;
        ret = tmp;
    }
    return ret;
}

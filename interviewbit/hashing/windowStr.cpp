string Solution::minWindow(string S, string T) {
	string ans = "";
	unordered_map <char, pair<int, int> > u_map;
	int p(0), q(0);
	for (int i = 0; i < (int) T.size(); i++) {
		if (u_map.count(T[i]) == 0) {
			u_map[T[i]].first = 1, u_map[T[i]].second = 0;
		}
		else {
			u_map[T[i]].first++;
		}
	}
	int len = 0, n = T.length(), N = S.length(), minIdx = 0, maxIdx = 0, minLen = INT_MAX;
	while (true) {
		if (len < n) {
			if (q == N)
				break;
			if (u_map.count(S[q])) {
				u_map[S[q]].second++;
				if (u_map[S[q]].second <= u_map[S[q]].first)
					len++;
			}
			q++;
		}
		else if (len == n) {
			if(q - p < minLen) {
				minLen = q - p, minIdx = p, maxIdx = q;
			}
			if (u_map.count(S[p])){
				u_map[S[p]].second--;
				if (u_map[S[p]].first > u_map[S[p]].second)
					len--;
			}
			p++;
		}
	}
	for(int i = minIdx; i < maxIdx; i++)
		ans += S[i];
	return ans;
}

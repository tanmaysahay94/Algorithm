bool diffPossible(vector<int> &num, int diff) {
	if (num.size() < 2 || diff < 0) return false;
	int j = 0, len = num.size();
	for (int i = 0; i < len - 1; i++) {
		j = max(j, i + 1);
		while (j < len && num[j] - num[i] < diff) j += 1;
		if (j < len && num[j] - num[i] == diff) return true;
	}
	return false;
}

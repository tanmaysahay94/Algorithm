bool isValid(char ch) {
	return (isdigit(ch) && ch > '0');
}

int numDecodings(string s) {
	memset(solution, -1, s.length() * sizeof(int));
	if (s.length() == 0) return 0;
	return ways(s, 0);
}

int ways(string &s, int startIndex) {
	if (startIndex == s.length()) return 1;
	if (!isValid(s[startIndex])) return 0;

	// memoize
	if (solution[startIndex] != -1) return solution[startIndex];

	int answer = 0;
	// 1 digit
	answer += ways(s, startIndex + 1);
	// 2 digit
	if (startIndex < s.length() - 1 && isdigit(s[startIndex + 1]) && ((s[startIndex] - '0') * 10 + s[startIndex + 1] - '0') <= 26) {
		answer += ways(s, startIndex + 2);
	}

	return solution[startIndex] = answer;
}

int Solution::divide(int dividend, int divisor) {
    long long a = dividend, b = divisor;
    bool aneg(false), bneg(false);
    if (a < 0) {
        aneg = true;
        a = abs(a);
    }
    if (b < 0) {
        bneg = true;
        b = abs(b);
    }
    long long ans = 0;
    while (b <= a) {
        int shift = 0;
        while ((b << (shift + 1)) <= a) {
            shift++;
        }
        a -= (b << shift);
        ans += ((1LL) << (shift));
		if (a < b) {
			break;
		}
    }
    if (aneg xor bneg) {
        ans *= -1;
    }
    if (ans > INT_MAX) {
        ans = INT_MAX;
    }
    return ans;
}
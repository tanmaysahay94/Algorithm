int Solution::sqrt(int A) {
    if (not A) {
        return A;
    }
    long long low = 1, high = 1e6;
    long long a = A;
    while (high - low > 1) {
        long long mid = (high + low) / 2;
        if (mid * mid == a) {
            return mid;
        }
        else if (mid * mid < a) {
            if ((mid + 1) * (mid + 1) == a) {
                return mid + 1;
            }
            if ((mid + 1) * (mid + 1) > a) {
                return mid;
            }
            low = mid;
        }
        else {
            high = mid;
        }
    }
    if (low * low == a) {
        return low;
    }
    if (high * high == a) {
        return high;
    }
    return low;
}

int Solution::isNumber(const string &S) {
    const char *s = S.c_str();
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == '\0') {
        return false;
    }
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    int num_digits, num_points;
    for (num_digits = 0, num_points = 0; (s[i] >= '0' and s[i] <= '9') or s[i] == '.'; i++) {
        if (s[i] == '.') {
            num_points++;
        }
        else {
            num_digits++;
        }
    }
    if (num_points > 1 or num_digits < 1 or s[i - 1] == '.') {
        return false;
    }
    if (s[i] == 'e') {
        i++;
        if (s[i] == '+' or s[i] == '-') {
            i++;
        }
        num_digits = 0;
        while (s[i] >= '0' and s[i] <= '9') {
            i++;
            num_digits++;
        }
        if (num_digits < 1) {
            return false;
        }
    }
    while (s[i] == ' ') {
        i++;
    }
    return s[i] == '\0';
}

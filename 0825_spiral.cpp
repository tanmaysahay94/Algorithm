#include <bits/stdc++.h>

using namespace std;

void chdir(int& d) {
    d = (d + 1) % 4;
}
vector<vector<int> > generateMatrix(int A) {
    vector<vector<int> > ret(A, vector<int> (A, 0));
    int num = 1;
    int dir = 1;
    int i = 0, j = 0;
    int target = A * A;
    int left = 0, right = A - 1, top = 0, bottom = A - 1;
    while (num <= target) {
        ret[i][j] = num;
        num++;
        if (dir == 1) {
            if (j == right) {
				top++;
                chdir(dir);
                i++;
            }
            else {
                j++;
            }
        }
        else if (dir == 2) {
            if (i == bottom) {
				right--;
                chdir(dir);
                j--;
            }
            else {
                i++;
            }
        }
        else if (dir == 3) {
            if (j == left) {
				bottom--;
                chdir(dir);
                i--;
            }
            else {
                j--;
            }
        }
        else {
            if (i == top) {
				left++;
                chdir(dir);
                j++;
            }
            else {
                i--;
            }
        }
    }
    return ret;
}
int main() {
	int n;
	cin >> n;
	vector<vector<int> > v = generateMatrix(n);
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < n; j++)
			cout << v[i][j] << ' ';
	return 0;
}

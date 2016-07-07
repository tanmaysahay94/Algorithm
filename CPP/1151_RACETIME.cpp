#include <bits/stdc++.h>

using namespace std;

class Solution
{
        private:
                vector<int> A;
                vector<vector<int> > SQ;
                int N, sLim, bSize;

        public:
                Solution() {}

                void input(int lim)
                {
                        N = lim;
                        sLim = ceil(bSize = sqrt(lim));

                        A.reserve(lim + 10);
                        SQ.reserve(sLim + 10);

                        for (int i = 0; i < lim; i++)
                        {
                                scanf("%d", &A[i]);
                                SQ[i / bSize].push_back(A[i]);
                        }

                        for (auto &sq: SQ)
                                sort(sq.begin(), sq.end());
                }

                void modify(int idx, int val)
                {
                        int bNum = idx / bSize;
                        int loc = lower_bound(SQ[bNum].begin(), SQ[bNum].end(), A[idx]) - SQ[bNum].begin();

                        SQ[bNum][loc] = val;
                        A[idx] = val;
                }

                int count(int l, int r, int val)
                {
                        int lBlock = l / bSize;
                        int rBlock = r / bSize;

                        int count = 0;

                        if (lBlock == rBlock)
                                for (int i = l; i <= r; i++)
                                        count += (A[i] <= val);
                        else
                        {
                                for (int i = l; i < (lBlock + 1) * bSize; i++)
                                        count += (A[i] <= val);
                                for (int i = r; i >= rBlock * bSize; i--)
                                        count += (A[i] <= val);
                                for (int i = lBlock + 1; i < rBlock; i++)
                                        count += upper_bound(SQ[i].begin(), SQ[i].end(), val) - SQ[i].begin();
                        }

                        return count;
                }

                void operation(char c)
                {
                        if (c == 'M')
                        {
                                int idx, val;
                                scanf("%d%d", &idx, &val);
                                idx--;
                                modify(idx, val);
                        }
                        else
                        {
                                int l, r, val;
                                scanf("%d%d%d", &l, &r, &val);
                                l--; r--;
                                printf("%d\n", count(l, r, val));
                        }
                }
};

int main()
{
        int N, Q;
        scanf("%d%d", &N, &Q);
        Solution S = Solution();
        S.input(N);
        while (Q--)
        {
                char c = getchar();
                scanf("%c", &c);
                S.operation(c);
        }
        return 0;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 struct cmp
 {
     bool operator() (const Interval& a, const Interval& b)
     {
         if (a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
     }
 };
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), cmp());
    vector<Interval> ret;
    ret.push_back(A[0]);
    for (int i = 1; i < (int) A.size(); i++)
    {
        Interval foo = A[i];
        Interval &bar = ret[ret.size() - 1];
        if (foo.start >= bar.start and foo.start <= bar.end) {
            bar.end = max(bar.end, foo.end);
        }
        else {
            ret.push_back(foo);
        }
    }
    return ret;
}

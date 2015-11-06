 /* Definition for an interval.*/
 /* struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };*/
  
bool intersect(Interval& a, Interval& b) {
    if (max(a.start, b.start) > min(a.end, b.end)) {
        return false;
    }
    return true;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int sz = intervals.size();
    vector<Interval> result;
    if (sz == 0) {
        result.push_back(newInterval);
        return result;
    }
    if (newInterval.end < intervals[0].start or newInterval.start > intervals[sz-1].end) {
        if (newInterval.end < intervals[0].start) {
            result.push_back(newInterval);
        }
        for (int i = 0; i < sz; i++) {
            result.push_back(intervals[i]);
        }
        if (newInterval.start > intervals[sz - 1].end) {
            result.push_back(newInterval);
        }
        return result;
    }
    for (int i = 0; i < sz; i++) {
        bool damn = intersect(newInterval, intervals[i]);
        if (not damn) {
            result.push_back(intervals[i]);
            if (i < sz - 1 and newInterval.start > intervals[i].end and newInterval.end < intervals[i + 1].start) {
                result.push_back(newInterval);
            }
            continue;
        }
        int st = i;
        while (i < sz and damn) {
            i++;
            if (i == sz) {
                damn = false;
            }
            else {
                damn = intersect(intervals[i], newInterval);
            }
        }
        i--;
        Interval toInsert(min(newInterval.start, intervals[st].start), max(newInterval.end, intervals[i].end));
        result.push_back(toInsert);
    }
    return result;
}

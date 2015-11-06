int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int sumGas = 0;
	int sumCost = 0;
	int start = 0;
	int tank = 0;
	for (int i = 0; i < gas.size(); i++) {
		sumGas += gas[i];
		sumCost += cost[i];
		tank += gas[i] - cost[i];
		if (tank < 0) {
			start = i + 1;
			tank = 0;
		}
	}
	if (sumGas < sumCost) {
		return -1;
	} else {
		return start;
	}
}

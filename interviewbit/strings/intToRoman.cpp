string Solution::intToRoman(int num) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	// 1000, 2000, 3000
	string M[] = {"", "M", "MM", "MMM"};
	// 100, 200, 300, .. 900
	string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	// 10, 20, ... 90
	string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	// 1, 2, ... 9
	string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

#include <iostream>

using namespace std;

int day(int d, int m, int y)
{
	static int t[] = {0, 3, 2, 5, 0 , 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m - 1] + d) % 7;
}

int main()
{
	int d, m, y;
	cin >> d >> m >> y;
	switch (day(d, m, y))
	{
		case 0: 
			cout << "Sunday"; break;
		case 1:
			cout << "Monday"; break;
		case 2:
			cout << "Tuesday"; break;
		case 3:
			cout << "Wednesday"; break;
		case 4:
			cout << "Thursday"; break;
		case 5:
			cout << "Friday"; break;
		case 6:
			cout << "Saturday"; break;
	}
	cout << endl;
	return 0;
}

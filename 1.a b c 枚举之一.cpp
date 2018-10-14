#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double ans = a + b + c;
	ans = min(ans, a + b - c);
	ans = min(ans, a + b * c);

	ans = min(ans, a - b + c);
	ans = min(ans, a - b - c);
	ans = min(ans, a - b * c);

	ans = min(ans, a * b + c);
	ans = min(ans, a * b - c);
	ans = min(ans, a * b * c);

	cout << ans << endl;
}

#include <iostream>
#include<algorithm>
using namespace std;
bool check(int i)
{
	int cnt = 0;
	while (i)//逐位检查i的二进制表达
	{
		if (i & 1)
			++cnt;
		i >>= 1;
	}
	if (cnt == 2)
		return true;
	return false;
}
int main()
{
	int ans = 0;
	for (int i = 0; i < (1 << 8); ++i)
	{
		/*
		i即为枚举出的状态
		接下来写个check函数检验即可
		*/
		if (check(i))
			++ans;
	}
	cout << ans << endl;
}

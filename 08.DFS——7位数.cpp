#include <iostream>
using namespace std;
//已经枚举出的数字、剩余需要枚举的层数
void dfs(int num, int depth)
{
	//剩余层数为0，到达终点
	if (depth == 0)
	{
		cout << num << endl;
		return;
	}
	//获取枚举的最后一位
	int bit = num % 10;
	//开始枚举下一位
	for (int i = bit - 1; i >= 0; --i)
		dfs(num * 10 + i, depth - 1);
}
int main()
{
	for (int i = 1; i <= 9; ++i)
		dfs(i, 6);
}

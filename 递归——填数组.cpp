#include <iostream>
using namespace std;
int a[2][2];
void dfs(int x, int y)//得到坐标为(x, y)的元素状态
{
	for (int i = 1; i <= 3; ++i)
	{
		a[x][y] = i;	//得到状态
		//判断是否有下一步的状态，
		if (y < 1)
			dfs(x, y + 1);
		else if (x < 1)
			dfs(x + 1, 0);	//如果有，就得到下一步的状态
		
		//到达分支终点，得到一个需要的状态，输出
		else if (x == 1 && y == 1)
		{
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
					cout << a[i][j];
				cout << endl;
			}
			cout << endl;
		}
	}
}
int main()
{
	dfs(0, 0);//从初始状态开始搜索即可
	return 0;
}


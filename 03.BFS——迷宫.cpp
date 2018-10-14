#include <iostream>
#include<queue>
using namespace std;
char maze[50][50];//储存迷宫
int vis[50][50];//到达该坐标的最少耗时
//bool vis[50][50];代表是否已经经过该点
const int xi[] = { 1,-1,0,0 };
const int yi[] = { 0,0,1,-1 };//行走方向
struct p//表达状态的结构体
{int x, y, t;};
queue<p>bfs;//按顺序存放状态的队列
int main()
{
	int n, m;
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'S')
				bfs.push({ i, j, 0 });
		}
	//得到初始状态，接下来开始广搜
	while (!bfs.empty())
	{
		p now = bfs.front();
		bfs.pop();				//取出一个状态
		for (int i = 0; i < 4; ++i)
		{
			int nx = now.x + xi[i], ny = now.y + yi[i], nt = now.t + 1;

			//该点有比现在更快到达的方法，跳过			该点更新为已到
			if (vis[nx][ny] && vis[nx][ny] <= nt)	//if(vis[nx][ny])
				continue;

			//更新该点到达时间		更新该点为到过
			vis[nx][ny] = nt;	//vis[nx][ny] = 1;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == '#')
				continue;		//排除不合法情况

			if (maze[nx][ny] == 'E')
			{
				cout << nt << endl;	//最快到达终点即为答案
				return 0;			//输出，结束程序
			}
			bfs.push({ nx, ny, nt });
		}
	}
	//遍历完所有状态就到了这里，说明走不通
	cout << "impossible" << endl;
}

#include <iostream>
#include <queue>
char maze[50][50];
bool vis[50][50];
const int xi[] = { 1,-1,0,0 };
const int yi[] = { 0,0,1,-1 };
struct p//表达状态的结构体
{
	int x, y, t;
};
queue<p>bfs;//按顺序存放状态的队列
int main()
{
	memset(vis, 0, sizeof(vis));
	int n, m;
	cin >> n >> m;
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

			if (vis[nx][ny])	//跳过之前已经走过的点
				continue;
			vis[nx][ny] = 1;

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

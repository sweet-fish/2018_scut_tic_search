char maze[50][50];
bool vis[50][50];
struct p//表达状态的结构体
{
	int x, y, t;
};
queue<p>bfs;//按顺序存放状态的队列
int main()
{
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
}

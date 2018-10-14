#include <iostream>
using namespace std;
char s[50][50];
bool v[50][50];
int n, m, ans = 0;
void dfs(int x, int y)
{
	v[x][y] = 1;	//打上标记
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		{
			//遍历周围八个格子
			int nx = x + i, ny = y + j;
			//跳过界外
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			//跳过*和被标记的#
			if (s[nx][ny] != '#' || v[nx][ny])
				continue;
			v[nx][ny] = 1;	//打上标记
			dfs(nx, ny);	//深搜这一步
		}
}
int main()
{
	memset(v, 0, sizeof(v));
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> s[i][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if (s[i][j] == '#' && !v[i][j])
			{
				//找到没标记的#，答案+1，开始标记
				++ans;
				dfs(i, j);
			}
	cout << ans << endl;
}


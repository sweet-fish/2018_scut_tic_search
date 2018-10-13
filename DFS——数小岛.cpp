
#include <iostream>
using namespace std;
char s[50][50];
bool v[50][50];
int n, m, ans = 0;
void dfs(int x, int y)
{
	v[x][y] = 1;
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		{
			int nx = x + i, ny = y + j;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (s[nx][ny] != '#' || v[nx][ny])
				continue;
			v[nx][ny] = 1;
			dfs(nx, ny);
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
				++ans;
				dfs(i, j);
			}
	cout << ans << endl;
}

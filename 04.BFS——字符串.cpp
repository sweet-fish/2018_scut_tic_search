#include<bits/stdc++.h>
using namespace std;
int main()
{
	string S, E;
	while (cin >> S >> E)
	{
		queue<string>q;
		q.push(E);    //放入初始状态
		bool fail = 1;    //是否可转化的标志
		while (!q.empty())
		{
			string tp = q.front();
			q.pop();
			if (tp.size() == S.size())    //只有长度相等时才可为答案
			{                             //优化较慢的判断string是否相等
				if (tp == S)
				{
					fail = 0;
					cout << "Explosion!" << endl;
					break;
				}
			}
			else if (tp.size() < S.size())
				continue;     //状态长度不可小于S的长度
			else if (tp.size() > S.size());
			{
				if (tp[tp.size() - 1] == 'a')
					q.push(tp.substr(0, tp.size() - 1));
				if (tp[tp.size()-1] == 'b')
				{
					tp = tp.substr(0, tp.size() - 1);
					reverse(tp.begin(), tp.end());
					q.push(tp);
				}
			}
		}
		if (fail)
			cout << "Dekimasen" << endl;
	}
	return 0;
}

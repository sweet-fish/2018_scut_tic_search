#include <iostream>
using namespace std;
void all_perm(int a[], int left, int right)
{
	if (left == right)
	{
		//已经到达递归终点，输出该处全排列，停止		
		for (int i = 0; i < right; ++i)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	for (int go = left; go < right; ++go)
	{
		//向左移动排列端点，开始第一个交换
		swap(a[left], a[go]);
		all_perm(a, left + 1, right);
		//排列完后换还原，继续对原数组进行全排列
		swap(a[go], a[left]);
	}
}
int main()
{
	int a[3];
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	all_perm(a, 0, 3);
}

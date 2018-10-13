#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;	//输入
//获得数字
int getnum(int left, int right)
{
	int res = 0;
	for (int i = left; i <= right; ++i)
	{
		res += s[i] - '0';
		res *= 10;
	}
	res /= 10;
	return res;
}
//是否为一个完全被括号包围的表达式
bool is_expr(int left, int right)
{
	int cnt = 0;	//左括号数量
	bool flag = 0;
	for (int i = left; i <= right; ++i)
	{
		if (s[i] == '(')
		{
			++cnt;
			flag = 1;
		}
		else if (s[i] == ')')
			--cnt;

		//表明仍有没计算的运算符
		if (cnt == 0 && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'))
			return 0;
	} 
	return flag;
}
//找到对应运算符的位置		c:要寻找的运算符
int find_cal(int left, int right, char c)
{
	int cnt = 0;
	//根据优先级，从右往左找
	for (int i = right; i >= left; --i)
	{
		if (s[i] == ')')
			--cnt;
		else if (s[i] == '(')
			++cnt;
		if (cnt == 0 && (s[i] == c))
			return i;
	}
	return -1;
}
//计算指定范围的表达式的值
int cal_expr(int left, int right)
{
	//去掉左右括号
	if (is_expr(left, right))
		return cal_expr(left + 1, right - 1);

	//先处理优先级底的+-号的逻辑，先递归的值在递归末才计算
	int calc = -1, cal1 = -1, cal2 = -1;
	cal1 = find_cal(left, right, '+');	//找到最右的+
	cal2 = find_cal(left, right, '-');	//找到最右的-
	calc = max(cal1, cal2);		//找到最右的+或-
	if (calc != -1)
	{
		if (cal1 == calc)	//+是要先运算的符号
			return cal_expr(left, cal1 - 1) + cal_expr(cal1 + 1, right);
		else if (cal2 == calc)		//-是要先运算的符号
			return cal_expr(left, cal2 - 1) - cal_expr(cal2 + 1, right);
		else if (cal2 == calc && cal2 == left)	//为负数，如-1这样的表达式
			return 0 - cal_expr(cal2 + 1, right);
	}
	//同样的逻辑处理*/，在先递归+-后，会优先计算*/的值
	cal1 = find_cal(left, right, '*');
	cal2 = find_cal(left, right, '/');
	calc = max(cal1, cal2);
	if (calc != -1)
	{
		if (cal1 == calc)
			return cal_expr(left, cal1 - 1) * cal_expr(cal1 + 1, right);
		else if (cal2 == calc)
			return cal_expr(left, cal2 - 1) / cal_expr(cal2 + 1, right);
	}
	//没有运算符了，只剩下一个数字
	return getnum(left, right);
}
int main()
{
	while (cin >> s)
		cout << cal_expr(0, s.size() - 1) << endl;
}

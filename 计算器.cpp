string to_suf(string s)
{
	string res;
	//加括号，处理开头为数字、括号或+-号的情况
	s = '(' + s + ')';
	//临时的运算符栈
	stack<char>tmp;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			//特殊处理括号后为+-号的情况
			if ((s[i - 1] == '+' || s[i - 1] == '-') && s[i - 2] == '(')
			{
				//做法：视为(0-num)即可
				res += "0 ";
				tmp.push(s[i - 1]);
			}
			//获得数字
			while ((s[i] >= '0'&&s[i] <= '9') || s[i] == '.')
			{
				res += s[i];
				++i;
			}
			//空格区分不同数字
			res += ' ';
			--i;//细节，小心跳过当前符号
		}
		//左括号直接入栈
		else if (s[i] == '(')
			tmp.push(s[i]);
		//遇到右括号，依次把栈顶符号加入运算式，直到遇到左括号
		else if (s[i] == ')')
		{
			while (tmp.top() != '(')
			{
				res += tmp.top();
				tmp.pop();
			}
			//左括号不加入表达式，要删去
			tmp.pop();
		}
		//处理+-
		else if (s[i] == '+' || s[i] == '-')
		{
			//前面已经处理过的	(-number)	的情况
			if (s[i - 1] == '(')
				continue;
			//弹出优先级高于或等于当前运算符的符号，加入表达式
			while (!tmp.empty() && tmp.top() != '(')
			{
				res += tmp.top();
				tmp.pop();
			}
			//最后把当前运算符入栈
			tmp.push(s[i]);
		}
		//相同方法处理*/号
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!tmp.empty() && (tmp.top() == '*' || tmp.top() == '/' || tmp.top() == '^'))
			{
				res += tmp.top();
				tmp.pop();
			}
			tmp.push(s[i]);
		}
	}
	//最后把栈内运算符全部加入表达式
	while (!tmp.empty())
	{
		res += tmp.top();
		tmp.pop();
	}
	return res;
}

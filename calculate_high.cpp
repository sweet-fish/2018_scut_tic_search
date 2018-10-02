#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),b,sizeof((a)))
#define clr(sum) (sum).clear()
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define Endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|
using namespace std;
string to_suf(string s)
{
    stack<char>q;
    s = '(' + s + ')';
    string res;
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if ((s[i - 1] == '+' || s[i - 1] == '-') && s[i - 2] == '(')
            {
                res += "0 ";
                q.push(s[i - 1]);
            }
            while (s[i] >= '0' && s[i] <= '9')
            {
                res += s[i];
                ++i;
            }
            res += ' ';
            --i;
        }
        else if (s[i] == '(')
            q.push(s[i]);
        else if (s[i] == ')')
        {
            while (q.top() != '(')
            {
                res += q.top();
                q.pop();
            }
            q.pop();
        }
        else
        {
            if (s[i] == '+' || s[i] == '-')
            {
                if (s[i - 1] == '(')
                    continue;
                while (q.top() != '(')
                {
                    res += q.top();
                    q.pop();
                }
                q.push(s[i]);
            }
            else
            {
                while (q.top() == '*' || q.top() == '/')
                {
                    res += q.top();
                    q.pop();
                }
                q.push(s[i]);
            }
        }
    }
    while (!q.empty())
    {
        res += q.top();
        q.pop();
    }
    return res;
}
stack<int>num;
int main()
{
    string s;
    while (cin >> s)
    {
        s = to_suf(s);
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int val = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    val += s[i] - '0';
                    val *= 10;
                    ++i;
                }
                val /= 10;
                num.push(val);
            }
            else
            {
                int r = num.top();
                num.pop();
                int l = num.top();
                num.pop();
                if (s[i] == '+')
                    num.push(l + r);
                else if (s[i] == '-')
                    num.push(l - r);
                else if (s[i] == '*')
                    num.push(l * r);
                else if (s[i] == '/')
                    num.push(l / r);
            }
        }
        cout << num.top() << endl;
        num.pop();
    }
}

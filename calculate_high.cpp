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


/*
sin:a
cos:c
tan:t
asin:S
acos:C
atan:T
pow:^
ln:l
优先级：+ - < 函数 < * / < ^
*/
const string pi="3.1415926535897932384626433 ";
string to_suf(string s)
{
	string res;
	s='('+s+')';
	stack<char>q;
	int len=s.size();
	for(int i=0;i<len;++i)
	{
        if(s[i]=='p')
            res+=pi;
		else if(s[i]>='0'&&s[i]<='9')
		{
			if((s[i-1]=='+'||s[i-1]=='-')&&s[i-2]=='(')
			{
				res+="0 ";
				q.push(s[i-1]);
			}
			while((s[i]>='0'&&s[i]<='9')||s[i]=='.')
			{
				res+=s[i];
				++i;
			}
			res+=' ';
			--i;
		}
		else if(s[i]=='(')
			q.push(s[i]);
		else if(s[i]==')')
		{
			while(q.top()!='(')
			{
				res+=q.top();
				q.pop();
			}
			q.pop();
		}
		else if(s[i]=='+'||s[i]=='-')
		{
			if(s[i-1]=='(')
				continue;
			while(!q.empty()&&q.top()!='(')
			{
				res+=q.top();
				q.pop();
			}
			q.push(s[i]);
		}
		else if(s[i]>='a'&&s[i]<='z')
		{
			while(!q.empty()&&q.top()!='('&&q.top()!='+'&&q.top()!='-')
			{
				res+=q.top();
				q.pop();
			}
			if(s[i]=='a')
			{
				++i;
				q.push(s[i]+'A'-'a');
				i+=2;
			}
			else if(s[i]=='l')
			{
				++i;
				q.push('l');
			}
			else
			{
				q.push(s[i]);
				i+=2;
			}
		}
		else if(s[i]=='*'||s[i]=='/')
		{
			while(!q.empty()&&(q.top()=='*'||q.top()=='/'||q.top()=='^'))
			{
				res+=q.top();
				q.pop();
			}
			q.push(s[i]);
		}
		else if(s[i]=='^')
		{
			while(!q.empty()&&q.top()=='^')
			{
				res+=q.top();
				q.pop();
			}
			q.push(s[i]);
		}
	}
	while(!q.empty())
	{
		res+=q.top();
		q.pop();
	}
	return res;
}
stack<double>num;
int main()
{
	string s;
	while(cin>>s)
	{
		s=to_suf(s);
		int len=s.size();
		for(int i=0;i<len;++i)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				double val1=0,val2=0;
				while(s[i]>='0'&&s[i]<='9')
				{
					val1+=s[i]-'0';
					val1*=10;
					++i;
				}
				val1/=10;
				if(s[i]=='.')
				{
					++i;
					while(s[i]>='0'&&s[i]<='9')
					{
						val2+=s[i]-'0';
						val2*=10;
						++i;
					}
					while(val2>=1)
						val2/=10;
				}
				num.push(val1+val2);
			}
			else
			{
				double r=num.top();
				num.pop();
				if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
				{
					double l=num.top();
					num.pop();
					double ans;
					if(s[i]=='+')
						ans=l+r;
					else if(s[i]=='-')
						ans=l-r;
					else if(s[i]=='*')
						ans=l*r;
					else if(s[i]=='/')
						ans=l/r;
					else if(s[i]=='^')
						ans=pow(l,r);
					num.push(ans);

				}
				else
				{
					double ans;
					if(s[i]=='s')
						ans=sin(r);
					else if(s[i]=='c')
						ans=cos(r);
					else if(s[i]=='t')
						ans=tan(r);
					else if(s[i]=='S')
						ans=asin(r);
					else if(s[i]=='C')
						ans=acos(r);
					else if(s[i]=='T')
						ans=atan(r);
					else if(s[i]=='l')
						ans=log(r);
					num.push(ans);
				}
			}
		}
		cout<<num.top()<<endl;
		num.pop();
	}
}
					

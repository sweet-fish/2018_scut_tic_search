#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    bool ok1 = 1, ok2 = 1;
    vector<string>res;
    while (getline(cin, s))
    {
        int n = s.size(), i = 0;
        if (!ok2)
        {
            ok2 = 1;
            if (s[s.size() - 1] == '\\')
                ok2 = 0;
            continue;
        }
        s += '#';
        string ans;
        if (!ok1)
        {
            for (i = 0; i < n; ++i)
            {
                if (s[i] == '*'&&s[i + 1] == '/')
                {
                    ok1 = 1;
                    i += 2;
                    break;
                }
            }
        }
        if (!ok1)
            continue;
        for (; i < n; ++i)
        {
            if (ok1)
            {
                if (s[i] == '/')
                {
                    if (s[i + 1] == '/')
                    {
                        if (s[s.size() - 2] == '\\')
                            ok2 = 0;
                        break;
                    }
                    else if (s[i + 1] == '*')
                        ok1 = 0;
                    else ans += s[i];
                }
                else
                {

                    if (s[i] == '\'')
                    {
                        int cnt = 3;
                        if (s[i + 1] == '\\')
                            ++cnt;
                        for (int k = 0; k < cnt; ++k, ++i)
                            ans += s[i];
                        --i;
                    }
                    else if (s[i] == '"')
                    {
                        ans += s[i];
                        ++i;
                        for (; i < n; ++i)
                        {
                            ans += s[i];
                            if (s[i] == '"')
                                break;
                        }
                    }
                    else
                        ans += s[i];
                }
            }
            else
            {
                if (s[i] == '*'&&s[i + 1] == '/')
                {
                    ok1 = 1;
                    ++i;
                }
            }
        }
        bool empt = 0;
        for (int i = 0; i < ans.size(); ++i)
            if (ans[i] != ' ')
            {
                empt = 1;
                break;
            }
        if (empt)
            res.push_back(ans);
    }
    for (int i = 0; i < res.size() - 1; ++i)
        cout << res[i] << endl;
    cout << res.back();
}

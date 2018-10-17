#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main()
{
    int _;
    for (cin >> _; _ > 0; --_)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        a[n] = a[0];
        b[n] = b[0];
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ll cnt = 0;
            cnt += abs(b[i] - a[i]);
            cnt += 2;
            cnt += abs(a[i] - b[i + 1]);
            ans += cnt;
            cout << cnt << endl;
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


bool check(ll a[], ll n, ll key, ll cows)
{
    int last = -1;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] - last >= key || last == -1)
        {
            cows--;
            last = a[i];
        }
        if (cows == 0)
            return true;
    }
    return cows <= 0;
}

void solve()
{

    ll TC;
    cin >> TC;
    while (TC--)
    {
        ll n, c;
        cin >> n >> c;
        ll a[n];
        ll maxi = -1;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            maxi = max(a[i], maxi);
        }
        sort(a, a + n);
        ll hi = maxi;
        ll lo = 0;
        ll mid;
        ll ans = 0;
        while (hi >= lo)
        {
            mid = (hi + lo) / 2;

            if (check(a, n, mid, c))
            {
                lo = mid + 1;
                ans = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false), cin.tie(__null), cout.tie(__null);

    solve();

    return 0;
}

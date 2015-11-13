 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <cmath>
 # include <set>
 # include <cstring>
 # define pii pair<int, int>
 # define forit(it, S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
 # define f first
 # define s second
 # define sz(xxx) (int)xxx.size()
 # define FOR(xxx, yyy, zzz) for(int xxx = yyy; xxx <= zzz; ++xxx)


 using namespace std;

 typedef long long ll;
 const double PI = atan (1) * 4;

 int n;
 int a[22222], s[22222];
 int u[22222];

 int main () {
    scanf ("%d", &n);
    FOR (i, 1, n) {
        scanf ("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
        while (s[i] >= n) s[i] -= n;
    }
   // FOR (i, 1, n) cout << s[i] << ' ';
   // cout << endl;
    memset (u, -1, sizeof u);
    u[0] = 0;
    FOR (i, 1, n) {
        if (u[s[i]] != -1) {
            cout << i - u[s[i]] << endl;
            FOR (j, u[s[i]] + 1, i)
            cout << a[j] << '\n';
            return 0;
        }
        u[s[i]] = i;
    }
 }

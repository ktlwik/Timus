 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <cmath>
 # include <set>
 # define pii pair<int, int>
 # define forit(it, S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
 # define FOR(xxx, yyy, zzz) for(int xxx = yyy; xxx <= zzz; ++xxx)
 # define f first
 # define s second
 # define sz(xxx) (int)xxx.size()


 using namespace std;

 typedef long long ll;
 const double PI = atan (1) * 4;

 int n;
 ll a[1111];

 int main () {
    scanf ("%d", &n);
    FOR (i, 1, n) scanf ("%ld", &a[i]);
    sort (a + 1, a + n + 1);
    FOR (i, 1, n) {
        FOR (j, 2, n)
            if (a[j] != a[j - 1]) {
                a[j] = a[j] % a[j - 1];
                if (!a[j]) a[j] = a[j - 1];
            }
        sort (a + 1, a + n + 1);
    }
    cout << a[1] << endl;

 }

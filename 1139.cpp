 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <cmath>
 # include <set>
 # define pii pair<int, int>
 # define forit(it, S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
 # define f first
 # define s second
 # define sz(xxx) (int)xxx.size()


 using namespace std;

 typedef long long ll;
 const double PI = atan (1) * 4;
 set <pii> st;
 int n, m;
 int main () {
    scanf ("%d%d", &n, &m);
    n --; m --;
    if (n < m) swap (n, m);
    double m_over_n = m * 1.0 / n;
    if (m <= n) {
        for (double h = 0; h <= n - 1.0; h = h + 1.0) {
               // cout << n - int ((x + delta) * n_over_m) << ' ' << int (x) << endl;

                st.insert (make_pair (n - int(h), int((h + 0.000001) * m_over_n)));
             //   st.insert (make_pair (n - int(h), int((h + 0.3333333) * m_over_n)));
           //     st.insert (make_pair (n - int(h), int((h + 0.6666666) * m_over_n)));
               st.insert (make_pair (n - int(h), int((h + 0.999999) *  m_over_n)));
         }
    }
    //  forit(it, st) {
    //        cout << it-> f << ' ' << it-> s << endl;
     // }


    printf ("%d\n", sz (st));
    return 0;
 }

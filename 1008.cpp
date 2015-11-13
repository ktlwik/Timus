 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <cmath>
 # include <set>
 # include <cassert>
 # include <queue>
 # define pii pair<int, int>
 # define forit(it, S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
 # define FOR(xxx, yyy, zzz) for(int xxx = yyy; xxx <= zzz; ++xxx)
 # define f first
 # define s second
 # define sz(xxx) (int)xxx.size()
 # define MP make_pair

 using namespace std;

 typedef long long ll;
 const double PI = atan (1) * 4;
 const int inf = (int) 1e9;

 const int dx[] = {1, 0, -1, 0};
 const int dy[] = {0, 1, 0, -1};
 const char dir[] = {'R', 'T', 'L', 'B'};

 int n, x, y;
 pii cur;
 bool mp[222][222];
 bool mark[222][222];
 queue <pii> Q;

 void bfs (pii start) {
    mark[start.f][start.s] = true;
    Q.push (start);
    int iter = 0;
    while (!Q.empty ()) {
        pii cur = Q.front ();
        ++ iter;
        FOR (i, 0, 3) {
            int nx = cur.f + dx[i];
            int ny = cur.s + dy[i];
            if (mp[nx][ny] && !mark[nx][ny]) {
                printf ("%c", dir[i]);
                mark[nx][ny] = 1;
                Q.push (MP (nx, ny));
            }
        }
        if (iter == n) printf (".\n");
        else printf (",\n");
        Q.pop ();
    }
 }

 int main () {
    scanf ("%d", &n);
    scanf ("%d", &x);

    string s;
    cin >> s;
    y = s[0];
    if (sz (s) == 1 && y >= '0' && y <= '9') {
        y = 0;
        FOR (i, 0, sz(s) - 1) {
            y *= 10;
            y += s[i] - '0';
        }
        cur = MP (x, y);
        mp[x][y] = 1;
        FOR (i, 1, n - 1) {
            scanf ("%d%d", &x, &y);
        //assert (x >= 1 && x <= 10 && y >= 1 && y <= 10);
            mp[x][y] = 1;
        }
        //cout << cur.f << ' ' << cur.s << endl;
        printf ("%d %d\n", cur.f, cur.s);
        bfs (cur);
    }
    else {
        cur = MP (n, x);
        mp[n][x] = 1;
        FOR (i, 0, sz (s) - 1) {
            FOR (j, 0, 3)
            if (s[i] == dir[j]) {
                int nx = cur.f + dx[j];
                int ny = cur.s + dy[j];
                mp[nx][ny] = 1;
                Q.push (MP (nx, ny));
            }
        }
        while (cin >> s) {
            cur = Q.front ();
            Q.pop ();
            bool breaK = false;
            FOR (i, 0, sz (s) - 1) {
                breaK |= (s[i] == '.');
                FOR (j, 0, 3)
                if (s[i] == dir[j]) {
                    int nx = cur.f + dx[j];
                    int ny = cur.s + dy[j];
                    mp[nx][ny] = 1;
                    Q.push (MP (nx, ny));
                }
            }
            if(breaK) break;
        }
       // mp[n][x] = true;
       // char a =
       int res = 0;
       FOR (x, 0, 10) FOR (y, 0, 10) res += mp[x][y];
       printf ("%d\n", res);
       FOR (x, 0, 10)
        FOR (y, 0, 10)
            if (mp[x][y])
                printf ("%d %d\n", x, y);
    }
 }

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N;
VPII vec;
int ans[22][22];
int ni = 0, nj = 0;
bool next() {
    if (nj + 1 < N / 2) nj++;
    else if (ni + 1 < N / 2) {
        ni++;
        nj = 0;
    } else {
        return false;
    }
    return true;
}

void next2() {
    if (ni == N / 2) {
        if (nj + 1 < N / 2) nj++;
        else ni = 0, nj = N / 2;
    } else {
        ni++;
    }
}

int main(void) {
    scanf("%d", &N);
    {
        map<int, int> mp;
        REP(i, N * N) {
            int a;
            scanf("%d", &a);
            mp[a]++;
        }
        FORE(e, mp) {
            vec.EB(e.second, e.first);
        }
    }
    if (N % 2 == 0) {
        FORE(e, vec) if (e.first % 4) {
            puts("NO");
            return 0;
        }
        puts("YES");
        FORE(e, vec) {
            REP(_, e.first / 4) {
                ans[ni][nj] = e.second;
                ans[N - 1 - ni][nj] = e.second;
                ans[ni][N - 1 - nj] = e.second;
                ans[N - 1 - ni][N - 1 - nj] = e.second;
                next();
            }
        }
        REP(i, N) {
            REP(j, N) {
                printf("%d%c", ans[i][j], " \n"[j + 1 == N]);
            }
        }
        return 0;
    }

    VI mod2, mod4, odd;
    FORE(e, vec) {
        int cnt = e.first;
        while (cnt > 0) {
            if (cnt % 4 == 0) {
                mod4.EB(e.second);
                cnt -= 4;
            } else if (cnt % 2 == 0) {
                mod2.EB(e.second);
                cnt -= 2;
            } else {
                odd.EB(e.second);
                cnt--;
            }
        }
    }
    if (odd.size() > 1) {
        puts("NO");
        return 0;
    }
    ans[N / 2][N / 2] = odd[0];
    bool f = true;
    FORE(e, mod4) {
        if (f) {
            ans[ni][nj] = e;
            ans[N - 1 - ni][nj] = e;
            ans[ni][N - 1 - nj] = e;
            ans[N - 1 - ni][N - 1 - nj] = e;
            if (!next()) {
                f = false;
            }
        } else {
            mod2.EB(e);
            mod2.EB(e);
        }
    }
    ni = N / 2, nj = 0;
    FORE(e, mod2) {
        ans[ni][nj] = e;
        if (ni == N / 2) ans[ni][N - 1 - nj] = e;
        else ans[N - 1 - ni][nj] = e;
        next2();
    }
    puts("YES");
    REP(i, N) {
        REP(j, N) {
            printf("%d%c", ans[i][j], " \n"[j + 1 == N]);
        }
    }
}

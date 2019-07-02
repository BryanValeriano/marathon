#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    int oper = 0;
    int vel = 0;
    int lim = INF;
    int overtake = 0;
    int ans = 0;
    v.pb(INF);

    for(int i = 0; i < n; i++) {
        cin >> oper;
        if(oper == 1) {
            cin >> vel;
            if(lim < vel) {
                while(v.size() and v.back() < vel) {
                    ans++;
                    v.pop_back();
                }
                lim = v.back();
            }
        }
        else if(oper == 2) {
            if(overtake) ans += overtake, overtake = 0;
        }
        else if(oper == 3) {
            cin >> lim;
            if(lim < vel) ans++;
            else v.pb(lim);
        }
        else if(oper == 4) {
            overtake = 0; 
        }
        else if(oper == 5) {
            lim = INF;
            v.pb(lim);
        }
        else if(oper == 6) overtake++;
    }

    cout << ans << endl;
    return 0;
}


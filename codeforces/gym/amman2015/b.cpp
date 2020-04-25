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
const int T = 1010;
char s[T];
int R[T];
int P[T];
int S[T];
int DR[T];
int DP[T];
int DS[T];


int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> s[i];
        
        if(s[1] == 'R') P[1] = 1; 
        else P[1] = 0;
        if(s[1] == 'P') DP[1] = 1;
        else(DP[1] = 0);
        if(s[1] == 'P') S[1] = 1; 
        else S[1] = 0;
        if(s[1] == 'S') DS[1] = 1;
        else(DS[1] = 0);
        if(s[1] == 'S') R[1] = 1; 
        else R[1] = 0;
        if(s[1] == 'R') DR[1] = 1;
        else(DR[1] = 0);
        for(int i = 2; i <= n; i++) {
            if(s[i] == 'R') P[i] = P[i-1] + 1; 
            else P[i] = P[i-1];
            if(s[i] == 'P') DP[i] = DP[i-1] + 1;
            else DP[i] = DP[i-1];
            if(s[i] == 'P') S[i] = S[i-1] + 1; 
            else S[i] = S[i-1];
            if(s[i] == 'S') DS[i] = DS[i-1] + 1;
            else DS[i] = DS[i-1];
            if(s[i] == 'S') R[i] = R[i-1] + 1; 
            else R[i] = R[i-1];
            if(s[i] == 'R') DR[i] = DR[i-1] + 1;
            else DR[i] = DR[i-1];
        }
        //for(int i = 0; i <= n; i++) 
        //    cout << DR[i] << " "; 
        //cout << endl;
        //for(int i = 0; i <= n; i++) 
        //    cout << DP[i] << " "; 
        //cout << endl;
        //for(int i = 0; i <= n; i++) 
        //    cout << DS[i] << " "; 
        //cout << endl;
        int wr, ws, wp;
        int dr, ds, dp;
        ll ans = 0;
        int win;
        for(int i = 0; i <= n; i++) {
            wr = R[i];
            dr = DR[i];
            for(int j = i; j <= n; j++) {
                wp = P[j] - P[i]; 
                dp = DP[j] - DP[i]; 
                ws = S[n] - S[j];
                ds = DS[n] - DS[j];
                int draws = dr + dp + ds; 
                win = (n-draws)/2 + 1;
                if((wr + ws + wp) >= win) { 
                    ans++; 
                    //cout << "I: " << i << " " << j << endl; 
                    //cout << "R: " << wr+ws+wp << " " << draws << " " << win << endl;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}


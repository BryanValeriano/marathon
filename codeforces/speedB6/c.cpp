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

string a,b;
int n, t;
int dif, eq;

char outro(char x, char y) {
    for(char i = 'a'; i <= 'z'; i++) 
        if(i != x and i != y) return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t;
    cin >> a >> b;
    t = n-t;

    for(int i = 0; i < n; i++) if(a[i] != b[i]) dif++; 

    eq = n - dif;
    int maxi = dif/2 + eq;
    int pegadif = 0;

    if(t <= maxi) {
        if(t > eq) pegadif = t - eq;
        else eq = min(eq,t);
        int aa = 0;
        int bb = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(aa < pegadif) cout << a[i], aa++;
                else if(bb < pegadif) cout << b[i], bb++;
                else cout << outro(a[i],b[i]);
            } else {
                if(eq) cout << a[i], eq--;
                else cout << outro(a[i],a[i]);
            }
        }
        cout << endl;
    } else cout << -1 << endl;



    return 0;
}


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

const int T = 3123;
int a[3];
//123, 132, 213, 232, 312, 321

bool test(string ord) {
    int ini0 = 1;
    int ini1 = -1;
    int ini2 = -1;

    for(int i = 1; i <= T; i++) {
        if((i - ini0) % a[ord[0]-'0'] == 0) continue;
        else {
            if(ini1 == -1) ini1 = i;
            if((i - ini1) % a[ord[1]-'0'] == 0) continue;
            else {
                if(ini2 == -1) ini2 = i;
                if((i - ini2) % a[ord[2]-'0'] == 0) continue;
                else return false;
            }
        }
    } 

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a[0] >> a[1] >> a[2];
    string permu = "012"; 
    bool ok = false;

    do {
        ok |= test(permu);
    }while(next_permutation(permu.begin(), permu.end()));
     
    cout << (ok? "YES" : "NO") << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 102;
int freqA[T];
int freqB[T];

int calc() {
    int l = 0, r = T-1;
    int fl = 0, fr = 0;
    int maxi = 0;

    while(r >= 0 and !freqB[r]) r--;
    while(l < T and !freqA[l]) l++;

    while(l < T and r >= 0) {
        maxi = max(maxi,l+r);

        if(fl+freqA[l] < fr+freqB[r]) fl += freqA[l], l++;
        else if(fl+freqA[l] == fr+freqB[r]) {
            fl += freqA[l], l++;
            fr += freqB[r], r--;
        }
        else fr += freqB[r], r--;


        while(r >= 0 and !freqB[r]) r--;
        while(l < T and !freqA[l]) l++;
    }

    return maxi;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        int x,y; cin >> x >> y;
        freqA[x]++;
        freqB[y]++;
        cout << calc() << endl;
    }
    return 0;
}


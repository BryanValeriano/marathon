#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int M;
int TMP;

int dist(int N) {
    int cont = 0;
    M = 0;
    TMP = 0;
    for(int i = 31; i >= 0; i--) {
        int num = (1 << i);
        
        /*bitset<32>y(N);
        bitset<32>x(num);
        cout << "num: " << x << endl;
        cout << "N  : " << y << endl;
        cout << "if : " << (N &(1<<i)) << endl;*/
        if((N & (num)) != 0) {
            cont++;
            if(cont == 1) M += num + (1 << i-1);
            if(cont > 2) TMP += num;
        }
    }
    if(cont == 1) return 1;
    else return min(TMP, abs(M-N)); 
}

int main() {
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) {
        long N;
        cin >> N;
        cout << dist(N) << endl;
    }

    return 0;
}


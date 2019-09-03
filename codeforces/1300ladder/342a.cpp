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

int main() {
    ios::sync_with_stdio(false);
    int ini = 0;
    int dois = 0;
    int tres = 0;
    int quatro = 0;
    int seis = 0;
    int n; cin >> n;
    int aux;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(aux == 1) ini++;
        if(aux == 2) dois++;
        if(aux == 4) quatro++;
        if(aux == 3) tres++;
        if(aux == 6) seis++;
        if(aux == 7 or aux == 5) flag = true;
    }
    int sobra = dois - quatro;
    if(flag or ini != dois + tres or ini != quatro + seis or dois < quatro or tres + sobra != seis) {
        cout << -1 << endl; return 0; 
    }
    for(int i = 0; i < ini; i++) {
        cout << 1 << " ";
        if(dois-- > 0) cout << 2 << " ";
        else cout << 3 << " ";
        if(quatro-- > 0) cout << 4 << endl;
        else cout << 6 << endl;
    }
    return 0;
}


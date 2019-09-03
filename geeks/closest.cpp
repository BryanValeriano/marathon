#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int binsec(int row[], int n, int k) {
    int ini = 0;
    int fim = n;
    int meio;
    while(fim - ini > 1) {
        meio = (ini + fim)/2;
        if(row[meio] > k) fim = meio;
        else if(row[meio] < k) ini = meio;
        else break;
    }
    //cout<<"TESTE"<<endl;
    //cout<<"INI :"<<row[ini]<<endl;
    //cout<<"MEIO:"<<row[meio]<<endl;
    //cout<<"FIM :"<<row[fim]<<endl;
    if(abs(row[meio] - k) >= abs(row[fim] - k)) {
        if(abs(row[fim] - k) <= abs(row[ini] - k)) return row[fim];
        else return row[ini];
    }
    else return row[meio];
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int k; cin >> k;
        int row[n];
        for(int i = 0; i < n; i++)
            cin >> row[i];
        cout << binsec(row, n, k) << endl;
    }

    return 0;
}


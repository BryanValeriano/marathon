#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int k; cin >> k;
    
    int sinal = 0;
    if(k <= 2*(n-2)) {
        if(k % 2 == 0) { cout << "YES"; sinal = 1; }
        else if(k == (n-2)) { cout << "YES"; sinal = 2; }
        else if(k > (n-2) + 1){ cout << "YES"; sinal = 2; }
        else { cout << "NO"; sinal = 0; }
    }
    else { cout << "NO"; sinal = 0; }
    cout << endl;

    if(sinal != 0) {
        int cont = k;
        bool flag = true;
        bool flag2 = true;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 2 && j == n-2 && flag2 == false) flag2 = true;
                if(sinal == 2 && flag2 == true && cont > 0 && i != 0 && i != 3 && j != 0 && j != n-1) { 
                    cout << "#"; cont--; if(cont == 1 && j < n-2 && i == 2) flag2 = false;
                }
                else if(sinal == 1 && flag == true && cont > 0 && i != 0 && i != 3 && j != 0 && j != n-1) {
                    cout << "#"; cont--; if(cont == k/2)flag = false;     
                }
                else cout << ".";
            }
            cout << endl;
            flag = true;
        }
    }

    return
}


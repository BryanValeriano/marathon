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

bool isP(int x) {
    for(int i = 2; i < x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
    fflush(stdout);
    string ans;
    int qtd = 0;

    for(int i = 2; i <= 47; i++) {
        if(isP(i)) {
            cout << i << '\n';
            cin >> ans;
            if(ans == "yes") qtd++;
            if(ans == "yes" and i*i <= 100) {
                cout << i*i << endl;
                cin >> ans;
                if(ans == "yes") qtd++;
            }
        }
        if(qtd >= 2) { cout << "composite" << endl; return 0; }
    }

    cout << (qtd <= 1? "prime" : "composite") << '\n';

    return 0;
}


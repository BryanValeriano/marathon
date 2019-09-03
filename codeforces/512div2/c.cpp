#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

string s;
int n;

bool tenta(int ini, int alvo) {
    int tmp = 0;
    for(int i = ini; i < n; i++) {
        tmp += s[i] - '0';
        if(tmp > alvo) return false;
        if(tmp == alvo) tmp = 0;
    }
    if(tmp > 0 && tmp != alvo) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    int toten = 0;

    for(int i = 0; i < n; i++) {
        toten += s[i] - '0';
        int pega = 0;
        for(int j = i + 1; j < n; j++) {
            pega += s[j] - '0';
            if(pega > toten) break;
            if(toten == pega) {
                if(tenta(j+1, toten)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
             
    cout << "NO" << endl;

    return 0;
}


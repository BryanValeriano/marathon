#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 5;
int row[T];
int n, l;
int tc = 0;

bool checktot(double tempo) {
    double cary = 0;
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if(row[i] <= (tempo * l) + cary) { 
            cary = ((tempo * l) + cary) - row[i];
            cont++;
        }
        else cary = 0;
    }
    if(cont == n) return true;
    return false;
}

bool checklast(double tempo) {
    double cary = 0;
    for(int i = 0; i < n; i++) {
        if(row[i] <= (tempo * l) + cary) { 
            cary = ((tempo * l) + cary) - row[i];
            if(i == n-1) return true;
        }
        else cary = 0;
    }
    return false;
}

double bin(int n, int op) {
    double ini = 0;
    double fim = 1e9 + 10;
    int cont = 0;
    while(++cont <= 50) {
        double meio = (ini + fim)/2;
        bool flag;
        if(op == 1) flag = checktot(meio);
        else flag = checklast(meio);
        if(flag) fim = meio;
        else ini = meio;
    }
    return ini;
}

int main() {
    while(~scanf("%d", &n)) {
        ++tc;
        cin >> l;
        for(int i = 0; i < n; i++) 
            scanf("%d ", &row[i]);
        printf("%.8lf ", bin(n,2));
        printf("%.8lf\n", bin(n,1));
    }

    return 0;
}


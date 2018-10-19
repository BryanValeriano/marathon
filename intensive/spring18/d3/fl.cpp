#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    char s;
    double n2;
    const double t = 10000;
    while(~scanf("%c", &s)) {
        scanf("%c", &s);
        scanf("%lf\n", &n2);
        double num = t/n2;
        int cont = 0;
        for(double i = n2+1; i <= n2*2; i++) {
            double j = i;
            double tmp = t/i + t/j;
            int ini = j;
            int fim = 1e9 + 100; 
            while(ini <= fim) {
                int meio = (ini + fim)/2;
                j = meio; tmp = t/i + t/j; 
                if(tmp - num < 0) fim = meio - 1;
                if(tmp - num > 0) ini = meio + 1;
                if(tmp - num == 0){ cont++; break; }
            }
        }
        printf("%d\n", cont);
    }
    return 0;
}


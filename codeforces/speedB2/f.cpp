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

const int T = 100;

char mat[T][T];

int a,b,c,d,n;
int v[30];

void build() {
    char ok = 'a';
    int pqp = 0;
    int qtd = 0;
    int j, fim;

    for(int i = 0; i < max(a,c); i++)
        for(int j = 0; j < b+d; j++) 
            mat[i][j] = '.';

    for(int i = 0; i < a; i++) {
        if(i&1) j = b-1, fim = -1;
        else j = 0, fim = b;
        while(j != fim) {
            if(qtd == v[pqp]) ok++, pqp++;
            if(pqp == n) return;
            mat[i][j] = ok;
            qtd++;
            if(i&1)j--;
            else j++;
        }
    }
    
    for(int i = 0; i < c; i++) {
        if((i&1)) j = d, fim = -1;
        else j = 0, fim = d;
        while(j != fim) {
            if(qtd == v[pqp]) ok++, pqp++;
            if(pqp == n) return;
            mat[i][j] = ok;
            qtd++;
            if(i&1)j--;
            else j++;
        }
    }
}

void print() {
    for(int i = 0; i < max(a,c); i++) {
        for(int j = 0; j < d; j++)
            cout << mat[i][j];
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int sum = 0;

    cin >> b >> a >> d >> c >> n;
    for(int i = 0; i < n; i++) cin >> v[i], sum += v[i];
    if(sum > a*b + c*d) { cout << "NO" << endl; return 0; }
    
    d += b;

    cout << "YES" << endl;
    build();
    print();

    return 0;
}


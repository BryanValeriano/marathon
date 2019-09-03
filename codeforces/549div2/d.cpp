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
    ll n,k,a,b;
    cin >> n >> k >> a >> b;

    ll inicial = 1 + a;
    ll tam = n*k;

    ll proxMenor;
    ll proxMaior;
   
    if(b == a) {
        proxMenor = inical;
        proxMaior = inicial + n*k;
    }
    else if(b > a) {
        proxMenor = inicial+b;
        proxMaior = k+inicial+b;
    }
    else {
        proxMenor = 1+b;
        proxMaior = 1+k+b;
    }

    ll passoMenor = abs(inicial - proxMenor);
    ll passoMaior = abs(inicial - proxMaior);

    cout << proxMenor << " " << passoMenor << endl;
    cout << proxMaior << " " << passoMaior << endl;

    cout << (passoMaior*tam)/__gcd(passoMaior, tam) << " "; 
    cout << (passoMenor*tam)/__gcd(passoMenor, tam) << endl; 

    return 0;
}


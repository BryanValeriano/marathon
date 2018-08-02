#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

void search(int din, int dias[], int qtd) {
    for(int i = 1; i < qtd; i++) 
        for(int j= i + 1; j <= qtd; j++) 
            if(dias[i] + dias[j] == din) {
                cout << min(i,j) << " " << max(i,j) << endl;
                return;
            }            
}

int main() {
    int mes;
    cin >> mes;
    while(mes--) {
        int din;
        cin >> din;
        int qtd;
        cin >> qtd;
        int dias[qtd+1];
        for(int i = 1; i <= qtd; i++)
            cin >> dias[i];
        search(din, dias, qtd);
           
    }
    return 0;
}


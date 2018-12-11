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
string s;
int v[110];
int um,dois,tres;

void busc(int qtd) {
    int ini, fim, best, cont, last;
    best = INF;
    for(int i = 0; i < s.size(); i++) {
        if(v[i] != 1) {
            ini = i; 
            if(qtd == 1) { um = i; return; }
        }
        else continue;
        cont = 0;
        for(int j = i + 1; j < s.size(); j++) {
            if(v[j] != 1) {
                if(qtd == 2){ 
                    fim = j;
                    if(best > fim-ini+1) {
                        best = fim-ini+1;
                        um = i; 
                        dois = j;
                    }
                }
                else if(qtd == 3) {
                    if(cont >= 1) fim = j;
                    if(best > fim-ini+1) {
                        best = fim-ini+1;
                        um = i;
                        dois = last;
                        tres = j;
                    }
                cont++;
                last = j;
                }
            }
        }
    }
}

void trans(int flag) {
    if(flag == 7) {
        busc(3);
        s[um] = 'A';
        s[dois] = 'a';
        s[tres] = '1';
    }
    else if(flag >= 4 and flag <= 6) {
        busc(2);
        if(flag == 6) { s[um] = 'a'; s[dois] = 'A'; } 
        else if(flag == 5) { s[um] = 'a'; s[dois] = '1'; }
        else if(flag == 4) { s[um] = 'A'; s[dois] = '1'; }
    } else {
        busc(1);
        if(flag == 3) s[um] = 'a';
        else if(flag == 2) s[um] = 'A';
        else if(flag == 1) s[um] = '1';
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        int a = 0;
        int A = 0;
        int num = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 48 and s[i] <= 57) num++; 
            else if(s[i] >= 65 and s[i] <= 90) A++;
            else if(s[i] >= 97 and s[i] <= 122) a++;       
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 48 and s[i] <= 57) v[i] = num;
            else if(s[i] >= 65 and s[i] <= 90) v[i] = A;
            else if(s[i] >= 97 and s[i] <= 122) v[i] = a;       
        }
        if(a > 0 and A > 0 and num > 0) cout << s << endl;
        else {
            if(a == 0 and A == 0 and num == 0) trans(7);
            else if(a == 0 and A == 0) trans(6);
            else if(a == 0 and num == 0) trans(5);
            else if(A == 0 and num == 0) trans(4);
            else if(a == 0) trans(3);
            else if(A == 0) trans(2);
            else if(num == 0) trans(1);
            cout << s << endl;
        }
    }
    return 0;
}


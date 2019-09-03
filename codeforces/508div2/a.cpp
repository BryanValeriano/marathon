#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int n, qtd; cin >> n >> qtd;
    string s; cin >> s; 
    int row[qtd];
    memset(row, 0, sizeof row);
    for(int i = 0; i < s.length(); i++)
        row[s[i] - 'A']++;
    sort(row, row+qtd); 
    cout << row[0] * qtd << endl;
    return 0;
}


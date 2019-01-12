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
const int T = 5e4 + 10;
const int N = 510;
map<int,int> cards; 
int player[N];
int fav[N];
int pontos[12];
int n,k;
ll joy;

void guloso() {
    for(int i = 0; i < n; i++) {
        while(cards.count(fav[i]) {
                if(abs(pontos[player[i] + 1] - pontos[player[i]])

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int x;
    for(int i = 0; i < n*k; i++) {
        cin >> x;
        cards[x]++;
    }

    for(int i = 0; i < n; i++)
        cin >> fav[i];

    for(int i = 1; i <= k; i++)
        cin >> pontos[i];

    guloso();

    return 0;
}


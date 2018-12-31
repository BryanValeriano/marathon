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
const int T = 1e6 + 10;
bool fe[T];
bool aber[T];
string s;

void solve() {
    int token = -1;
    int ans = 0;
    if(a > b) {
        for(int i = s.size() -1; i >= 0; i--) {
            if(cont[i] == 0) { token = i; break; }
        if(token == -1) token = 0;
        for(int i = token + 1; i < s.size() - 1; i++) {
            if(aber[i] == true) ans++;

bool read() {
    cin >> s;
    int a = 0;
    int f = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == "(") { aber[i] = true; a++; cont[i]++; }
        else { fe[i] = true; f++; cont[i]--; }
    }
    return (abs(a-b) == 2? true : false); 
}

int main() {
    ios::sync_with_stdio(false);
    read();
    return 0;
}


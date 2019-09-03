#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

struct botton {
    float x1;
    float y1;
    float x2;
    float y2;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<botton> row;

    for(int i = 0; i < n; i++) {
        int tmp1, tmp2, tmp3, tmp4;
        cint >> tmp1, tmp2, tmp3, tmp4;
        botton aux;
        aux.x1 = tmp1; aux.y1 = tmp2;
        aux.x2 = tmp3; aux.y2 = tmp4;
    }

    int m; cin >> m;
    while(m--) {
        cin >> tmp1 >> tmp2;
        for(int i = 0; i < n; i++) {
            int dist = INF;
            int tmpdist;
            int tmpdist2;
            tmpdist = floor(botton.x1 + botton.x2)/2; 
            tmpdist = ceil(botton.x1 + botton.x2)/2; 



    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
char word[3][3];
bool val;

void bk(int pos, string resp) {
    if(pos == 3) {
        if(resp == "bob" || resp == "bbo" || resp == "obb")
        val = true;
        //cout << resp << endl;
    }
    
    else {
        char a = word[pos][0];
        char b = word[pos][1];
        
        bk(pos+1, resp + a);
        bk(pos+1, resp + b);
    }
}
    

    
int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        val = false;
        for(int i = 0; i < 3; i++) 
            cin >> word[i][0];
        
        for(int i = 0; i < 3; i++) 
            cin >> word[i][1];

        bk(0, "");
        val ? cout << "yes" : cout << "no";
        cout << endl;
    }

    return 0;
}


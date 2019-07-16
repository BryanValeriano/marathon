#include <bits/stdc++.h>
using namespace std;

const int T = 23;

double conv[T][T][T];
int path[T][T][T];
int ans[T];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;

    while(cin >> n) {
        memset(conv, 0, sizeof conv);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(i == j) conv[i][j][0] = 1;
                else cin >> conv[i][j][0];
                path[i][j][0] = i;
            }

        for(int s = 1; s <= n; s++)
            for(int k = 1; k <= n; k++)
                for(int i = 1; i <= n; i++)
                    for(int j = 1; j <= n; j++) {
                        double x = conv[i][k][s-1] * conv[k][j][0];
                        if(x > conv[i][j][s]) {
                            conv[i][j][s] = x;
                            path[i][j][s] = k;
                        }
                    }


        bool ok = 1;
        int steps,coin;

        for(int i = 1; i <= n and ok; i++)
            for(int j = 1; j <= n and ok; j++)
                if(conv[j][j][i] >= 1.01) {
                    coin = j;
                    steps = i;
                    ok = 0;
                }

        if(ok) {
            cout << "no arbitrage sequence exists" << '\n';
            continue;
        }
        
        ans[steps] = path[coin][coin][steps];

        for(int j = steps-1; j >= 0; j--)
            ans[j] = path[coin][ans[j+1]][j];

        for(int i = 0; i <= steps; i++) cout << ans[i] << " ";
        cout << coin << '\n';
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int T = 52;

class MessageMess {
public:
    ll dp[T][T];
    bool ok[T][T];
    int n;
    unordered_set<string> bag;

    ll solve(int ini, int at) {
        ll &r = dp[ini][at];

        if(at == n-1) return r = ok[ini][at];
        if(~r) return r;
        r = 0;

        r += solve(ini,at+1);
        if(ok[ini][at]) r += solve(at+1,at+1);
        return r;
    }

    string subs(int ini, int at, const string &s) {
        string t;
        for(int i = ini; i <= at; i++) t += s[i];
        return t;
    }

    string build(int ini, int at, const string &s) {
        if(at == n-1) return subs(ini,at,s);
        if(dp[at+1][at+1] == 1) return subs(ini,at,s) + " " + build(at+1,at+1,s);
        return build(ini,at+1,s);
    }

    bool exist(int a, int b, const string &s) {
        string t = subs(a,b,s);
        return bag.count(t);
    }

    string restore(vector<string> dictionary, string message) {
        bag.clear();
        for(auto s : dictionary) bag.insert(s);
        memset(dp, -1, sizeof dp);
        n = message.size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(exist(i,j,message)) ok[i][j] = 1;
                else ok[i][j] = 0;
            }
        }

        ll x = solve(0,0);
        if(x == 1) return build(0,0,message);
        else if(x > 1) return "AMBIGUOUS!";
        return "IMPOSSIBLE!";
    }
};


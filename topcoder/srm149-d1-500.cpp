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

class MessageMess {
public:
    unordered_set<string> bag;
    vector<string> tmp;
    string ans;

    string restore(vector<string> dictionary, string message) {
        bool am = prefix(dictionary);
        for(auto d : dictionary) bag.insert(d);

        string x;
        for(int i = 0; i < message.size(); i++) {  
            if(bag.count(x)) tmp.pb(x), x = "";
            x += message[i];
        }
        if(bag.count(x)) {
            tmp.pb(x)
            return (am? "


    }
};


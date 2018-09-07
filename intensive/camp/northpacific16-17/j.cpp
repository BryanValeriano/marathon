#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int casas, cap;

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    return a.fi < b.fi;
}

ll busca(vector< pair<int,ll> > vet) {
    ll resp = 0;
    ll rest = 0;
    while(vet.size()) {
        pair<int,int> top = vet.back();
        vet.pop_back();
        while(rest > 0) {
            if(top.sec < 0 && vet.size()) {
                top = vet.back(); 
                vet.pop_back();
            }
            if(top.sec > 0) {
                top.sec -= rest;
                if(top.sec > 0) rest = 0;
                else rest = abs(top.sec);
            }else rest = 0; 
        }
        ll vezes = ceil((double)top.sec / (double)cap);
        resp += vezes * top.fi * 2;
        if(vezes * cap > top.sec) rest = vezes * cap - top.sec;
        else rest = 0;
    }
    return resp;         
}

 
int main()
{
    vector< pair <int,ll> >pos;
    vector< pair<int,ll> >neg;
    cin >> casas >> cap;
    int aux, aux2;
    for(int i = 0; i < casas; i++) {
        cin >> aux >> aux2;
        aux > 0 ? pos.pb(mk(aux,aux2)): neg.pb(mk(abs(aux), aux2));
    }
    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmp);

    ll viagens = 0;
    viagens += busca(pos);
    viagens += busca(neg);
    cout << viagens << endl; 
    return 0;
}


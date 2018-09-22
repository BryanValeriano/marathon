#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

struct linha {
	int indice;
	map<string,int>chave;
	int soma;

	bool operator < (const linha &b) const {
		if(chave.size() != b.chave.size())
			return chave.size() > b.chave.size();
		return false;
	}
};

int main() {
    ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	linha tmp[n+m+1];
	int num;
	string aux;
	map<string, int> vars;
	for(int i = 1; i <= n; i++) {
		for(int j = n+1; j <= n+m+1; j++) {
			if(j != n+m+1) {
				cin >> aux;
				tmp[i].indice = i;
				if(tmp[i].chave.count(aux))
					tmp[i].chave[aux]++;
				else tmp[i].chave[aux] = 0;
				tmp[j].indice = j;
				if(tmp[j].chave.count(aux))
					tmp[j].chave[aux]++;
				else tmp[j].chave[aux] = 0;
			} else {
				cin >> num;
				tmp[i].soma = num;
			}
		}
	}
	for(int j = n+1; j <= n+m; j++) {
		cin >> num;
		tmp[j].soma = num;
	}

	priority_queue<linha, vector<linha> > pq;

	for(int i = 1; i <= n+m; i++) 
		pq.push(tmp[i]);	

	linha top = pq.top();
	map<string, int>:: iterator it = top.chave.begin();
	int vall = top.soma / it->sec;
	vars[it->fi] = vall;
	pq.pop();
	//cout << vall << endl;
	while(pq.size()) {
		top = pq.top(); 
		for
	}

	//debug
	for(int i = 1; i <= n+m; i++) {
		cout << "i: " << i << ", " << tmp[i].indice << " " << tmp[i].chave.size() << " " << tmp[i].soma << endl; 
	}
    return 0;
}


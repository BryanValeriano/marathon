#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2002;
int v[T];
map<int,int> vzs;
map<int,int> tmp;
int n;
int repetidos;

int me() {
	bool primeiro = false;
	bool ultimo = false;

	int reps = 0;
	int tam = 0;
	tmp.clear();

	for(int i = 0; i < n; i++) {
		if(tmp[v[i]] >= 1) {
			if(!primeiro) tmp.clear();
			primeiro = true;
		}

		tmp[v[i]]++;

		if(primeiro and vzs[v[i]] - tmp[v[i]] <= 1 and vzs[v[i]] > 1) reps++;

		if(primeiro and !ultimo) tam++;
		if(repetidos == reps) ultimo = true;
	}

	return tam;
}

int comeco() {
	tmp.clear();
	int reps = 0;

	for(int i = 0; i < n; i++) {
		if(reps == repetidos) return i;
		tmp[v[i]]++;
		if(vzs[v[i]] - tmp[v[i]] == 1) reps++;
	}
	return n;
}

int ultimo() {
	tmp.clear();
	int reps = 0;

	for(int i = n-1; i >= 0; i--) {
		if(reps == repetidos) return (n-1) - i;
		tmp[v[i]]++;
		if(vzs[v[i]] - tmp[v[i]] == 1) reps++;
	}

	return n;
}


int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		vzs[v[i]]++;
	}
	for(auto ok : vzs) if(ok.se > 1) repetidos++;

	int ini = comeco();
	int meio = me();
	int ult = ultimo();

	cout << ini << " " << meio << " " << ult << endl;

	cout << min({ini,meio,ult}) << endl;

    return 0;
}


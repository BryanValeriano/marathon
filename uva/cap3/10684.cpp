#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int maior = 0, soma = 0, N, input;
	cin >> N;
	
	while (N) {
		for (int i = 0; i < N; i++) {
			cin >> input;
			soma += input;
			if (soma < 0) soma = 0;
			maior = max(soma, maior);
		}
		if (maior > 0) cout << "The maximum winning streak is " << maior  << '.' << endl;
		else 		   cout << "Losing streak." << endl;
		maior = soma = 0;
		cin >> N;
	}
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
	double h1, h2, w1, w2;

	cin >> h1 >> w1;
	cin >> h2 >> w2;

	if(h1*w1 > h2*w2)
	{
		cout << "Primeiro" << endl;
	}

	else if(h1*w1 < h2*w2)
	{
		cout << "Segundo" << endl;
	}

	else
	{
		cout << "Empate" << endl;
	}

	return 0;
	
}

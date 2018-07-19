#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the lanParty function below.
 */
vector<int> lanParty(vector<int> games, vector<vector<int>> wires, int m) {
    /*
     * Write your code here.
     */

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmq_temp;
    getline(cin, nmq_temp);

    vector<string> nmq = split_string(nmq_temp);

    int n = stoi(nmq[0]);

    int m = stoi(nmq[1]);

    int q = stoi(nmq[2]);

    string games_temp_temp;
    getline(cin, games_temp_temp);

    vector<string> games_temp = split_string(games_temp_temp);

    vector<int> games(n);

    for (int games_itr = 0; games_itr < n; games_itr++) {
        int games_item = stoi(games_temp[games_itr]);

        games[games_itr] = games_item;
    }

    vector<vector<int>> wires(q);
    for (int wires_row_itr = 0; wires_row_itr < q; wires_row_itr++) {
        wires[wires_row_itr].resize(2);

        for (int wires_column_itr = 0; wires_column_itr < 2; wires_column_itr++) {
            cin >> wires[wires_row_itr][wires_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = lanParty(games, wires, m);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


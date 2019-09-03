#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
map<string,string>dic;
map<string,string>dic2;

int main() {
    ios::sync_with_stdio(false);
    dic["A"] = ".-";   dic2[".-"]   = "A";
    dic["B"] = "-..."; dic2["-..."] = "B";
    dic["C"] = "-.-."; dic2["-.-."] = "C";
    dic["D"] = "-..";  dic2["-.."]  = "D";
    dic["E"] = ".";    dic2["."]    = "E";
    dic["F"] = "..-."; dic2["..-."] = "F";
    dic["G"] = "--.";  dic2["--."]  = "G";
    dic["H"] = "...."; dic2["...."] = "H";
    dic["I"] = "..";   dic2[".."]   = "I";
    dic["J"] = ".---"; dic2[".---"] = "J";
    dic["K"] = "-.-";  dic2["-.-"]  = "K";
    dic["L"] = ".-.."; dic2[".-.."] = "L";
    dic["M"] = "--";   dic2["--"]   = "M";
    dic["N"] = "-.";   dic2["-."]   = "N";
    dic["O"] = "---";  dic2["---"]  = "O";
    dic["P"] = ".--."; dic2[".--."] = "P";
    dic["Q"] = "--.-"; dic2["--.-"] = "Q";
    dic["R"] = ".-.";  dic2[".-."]  = "R";
    dic["S"] = "...";  dic2["..."]  = "S";
    dic["T"] = "-";    dic2["-"]    = "T";
    dic["U"] = "..-";  dic2["..-"]  = "U";
    dic["V"] = "...-"; dic2["...-"] = "V";
    dic["W"] = ".--";  dic2[".--"]  = "W";
    dic["X"] = "-..-"; dic2["-..-"] = "X";
    dic["Y"] = "-.--"; dic2["-.--"] = "Y";
    dic["Z"] = "--.."; dic2["--.."] = "Z";
    dic["_"] = "..--"; dic2["..--"] = "_";
    dic[","] = ".-.-"; dic2[".-.-"] = ",";
    dic["."] = "---."; dic2["---."] = ".";
    dic["?"] = "----"; dic2["----"] = "?";
    string s;
    while(cin >> s) {
        int num;
        string n;
        string dec;
        for(int i = 0; i < s.size(); i++) {
            string t;
            t += s[i];
            num = dic[t].size();
            n = to_string(num) + n;
            dec += dic[t];
        }
        int j = 0;
        for(int i = 0; i < n.size(); i++) {
            string t;
            string g;
            g += n[i];
            int k = stoi(g);
            int last = j; 
            while(j < last+k) {
                string x;
                t += dec[j];
                j++;
            }
            cout << dic2[t];
        }
        cout << endl;
    } 
    return 0;
}


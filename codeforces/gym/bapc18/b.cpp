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

const int M = 12;
const int m_days[M] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int d, m;
    Date(){}
    Date(int day, int month) {
        d = day;
        m = month;
    }

    bool operator < (const Date &date) const {
        if(m != date.m) return m < date.m;
        return d < date.d;
    }

    Date operator + (const int v) {
        int curr_d = d;
        int curr_m = m;
        for(int i = 0; i < v; i++) {
            curr_d++;
            if(curr_d > m_days[curr_m]) curr_d = 1, curr_m++;
            curr_m %= M;
        }
        return Date(curr_d, curr_m);
    }

    bool operator == (const Date &date) const {
        return d == date.d and m == date.m;
    }

    int operator - (const Date &date) {
        int cont = 0;
        Date ini = date;
        Date fim = *this;
        while(!(ini == fim)) {
            ini = ini+1;
            cont++;
        }
        return cont;
    }
    Date operator - (int v) {
        
    }

    void print() {
        printf("%02d-%02d\n", m+1, d);
    }
};

int main() {

    int n; cin >>n;
    vector<Date> dates;
    set<Date> s_dates;
    for(int i = 0; i < n; i++) {
        string s; cin >>s;
        int d, m;
        char c;
        cin >>m >>c >>d;
        dates.pb(Date(d, m-1));
        s_dates.insert(Date(d, m-1));
    }

    sort(dates.begin(), dates.end());

    Date last_date = dates.back();
    
    int ans = 0;
    Date date_ans = dates.back();

    for(Date date:dates) {
        int dist = (date-last_date)-1;

        Date curr_date  = last_date+dist;
        while(s_dates.count(curr_date) and dist > 0) {
            dist--;
            curr_date = last_date+dist;
        }

        if(dist > ans) ans = dist, date_ans = last_date;
        else if(dist == ans) {
            int dif1 = (date_ans+ans)-Date(28,9);
            int dif2 = (curr_date)-Date(28,9);
            if(dif2 < dif1) date_ans = last_date;
        }
        last_date = date;
    }
    
    (date_ans+ans).print();
    
    return 0;
}


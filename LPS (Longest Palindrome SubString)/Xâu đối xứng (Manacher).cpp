//https://lqdoj.edu.vn/problem/23ts10dna2
#include <bits/stdc++.h>
using namespace std;
#define endline "\n"
#define ll long long
#define ld long double
#define FOR(i,a,b,c) for(int i = (a); i <= (b); i+=c)
#define FOD(i,a,b,c) for(int i = (a); i <= (b); i-=c)
#define AnDepTrai ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
const int MOD = 1e9 + 7;
int main(){
    AnDepTrai
    file("DOIXUNG");
    string s; cin >> s;
    string t = "";
    for(char c : s){
        t += '|';
        t += c;
    }
    t += '|';
    vector<ll> p(t.size(), 0);
    vector<string> ans;
    ll c = 0, r = 0;
    for(ll i = 1; i < t.size() - 1; i++){
        ll m = 2 * c - i;
        if(i < r){
            p[i] = min(r - i, p[m]);
        }
        while(i + p[i] + 1 < t.size() && i - p[i] - 1 >= 0 && t[i + 1 + p[i]] == t[i - 1 - p[i]]){
            p[i]++;
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }

    }
    ll cnt = 0;
    for (auto it : p) {
        cnt += (it + 1) / 2;
    }

    cout << cnt << endline;
    return 0;
}
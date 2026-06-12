#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

// probability freq
map<char, double> eng_freq = {
    {'a', 0.08167}, {'b', 0.01492}, {'c', 0.02782}, {'d', 0.04253}, {'e', 0.12702},
    {'f', 0.02228}, {'g', 0.02015}, {'h', 0.06094}, {'i', 0.06966}, {'j', 0.00153},
    {'k', 0.00772}, {'l', 0.04025}, {'m', 0.02406}, {'n', 0.06749}, {'o', 0.07507},
    {'p', 0.01929}, {'q', 0.00095}, {'r', 0.05987}, {'s', 0.06327}, {'t', 0.09056},
    {'u', 0.02758}, {'v', 0.00978}, {'w', 0.02360}, {'x', 0.00150}, {'y', 0.01974},
    {'z', 0.00074}
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string cipher; 
    // cin >> cipher;
    getline(cin, cipher);
    
    // Convert to lowercase
    for (char &c : cipher) c = tolower(c);
    
    int n = cipher.size();
    vector<int> L;
    
    // indexes of 3 size substrings appearing at least 3 times
    for(int i=0; i < n-2; i++){
        int cnt = 0;
        vector<int> S;
        for(int j = i+3; j< n-2; j++){
            if(cipher[i] == cipher[j] && cipher[i+1] == cipher[j+1] && cipher[i+2] == cipher[j+2]){
                cnt++;
                if(find(L.begin(), L.end(), j) == L.end()){
                    S.push_back(j);
                }
            }
            if(cnt == 2){
                L.push_back(i);
                L.insert(L.end(), S.begin(), S.end());
                break;
            }
        }
        if(L.size() == 3) break;
    }
    
    // Find key length using GCD
    int g = __gcd(L[1] - L[0], L[2] - L[1]);
    
    // Divide ciphertext into key-length columns
    int d = n / g;
    vector<string> Lcols(g);
    for (int j = 0; j < g; j++) {
        string col = "";
        for (int i = j; i < n; i += g) {
            col += cipher[i];
        }
        Lcols[j] = col;
    }
    
    string key = "";
    for (string col : Lcols) {
        double diff = 0.065;
        int shift = 0;
        for (int j = 0; j < 26; j++) {
            double p = 0.0;
            for (auto &kv : eng_freq) {
                char letter = ((kv.first - 'a' + j) % 26) + 'a';
                double f = count(col.begin(), col.end(), letter) / (double)col.size();
                p += f * kv.second;
            }
            if (fabs(p - 0.065) < diff) {
                diff = fabs(p - 0.065);
                shift = j;
            }
        }
        key += char(shift + 'a');
    }
    
    // Extend key to cipher length
    while((int)key.size() < n) key += key;
    
    string plain = "";
    for(int i=0; i<n; i++){
        if(isalpha(cipher[i])){
            char a = ((cipher[i] - key[i]+26) % 26) + 'a';
            plain += a;
        }
    }
    cout << plain << "\n";
    return 0;
}

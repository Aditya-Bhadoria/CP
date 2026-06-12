#include <bits/stdc++.h>
using namespace std;
int main(){
    //checks no. of primes till n
    int n; cin >> n;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    int count = 0;
    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;
            //mark all multiple of prime as non-prime
            for(int j=2*i; j<n; j = j+i){
                prime[j] = 0;
            }
        }
    } //time complexity = O(n*log(log n));
    cout << count << endl;
    return 0;
}
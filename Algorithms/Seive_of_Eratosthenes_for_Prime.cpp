//Find Prime Numbers in a Range
#include <iostream>
#include <vector>
using namespace std;
void isPrime(int N){
    for(int n = 2; n<N; n++){
        bool isPrime = true;
        for(int i = 2; i*i<=n; i++){
            if(i%n == 0){
                isPrime = false;
                break;
            }
        }
    }
}
int seive_of_Eratosthenes(int n){
    vector<int> prime(n+1,1);
    int ans = 0;
    for(int i = 2; i<n; i++){
        if(prime[i] == 1){
            ans++;
            for(int j = i*2; j<n; j+=i){
                prime[j] = 0;
            }
        }
    }
    return ans;
}
int main(){
    int n= 50;
    cout<<seive_of_Eratosthenes(n)<<endl;
    return 0;
}
//Output: 15
#include <iostream>
#include <vector>
using namespace std;
class DisjointSetUnion{
public:
    int n;
    vector<int> par, rank;
    DisjointSetUnion(int x){
        this->n = x;
        for(int i = 0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    void unionByRank(int A, int B){
        int parA = find(A);
        int parB = find(B);
        if(parA == parB){
            return;
        }
        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }
        else{
            par[parA] = parB;
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    void getInfo(){
        for(int i = 0; i<n; i++){
            cout<<par[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i<n; i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    DisjointSetUnion dsu(6);
    dsu.unionByRank(0,2);
    cout<<dsu.find(2)<<endl;

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);
    cout<<dsu.find(2)<<endl;
    dsu.unionByRank(0,4);
    dsu.getInfo();
    return 0;
}
//Output : 
// 0
// 0
// 0 0 0 1 0 0 
// 2 1 0 0 0 0 
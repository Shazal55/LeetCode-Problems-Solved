#include <iostream>
using namespace std;
int minInsertions(string s) {
    int insertion = 0;
    int need = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            if(need%2 == 1){
                insertion++;
                need--;
            }
            need += 2;
        }
        else{
            need--;
            if(need < 0){
                insertion++;
                need = 1;
            }
        }
    }
    return insertion + need;
}
int main(){
    string s = "()";
    cout<<minInsertions(s)<<endl;
    return 0;
}
//Output : 1
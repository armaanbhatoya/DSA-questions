#include<bits/stdc++.h>
using namespace std;

int main(){
    
    char arr[200] = "uuuuihihjlgyhyyliu";
    map<char,int> hash;
    for(int i=0; arr[i]!='\0';i++){
        hash[arr[i]]++;
    }
    for(auto it : hash){
        cout<<it.first<<"  "<<it.second<<endl;
    
    }
    return 0;
}
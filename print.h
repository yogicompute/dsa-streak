#include <bits/stdc++.h>
using namespace std;
void print(vector<int>& arr){
    cout<<'[';
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i];
        if(i != arr.size() - 1) cout<<',';
    }
    cout<<"]\n";
}
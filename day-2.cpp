#include <bits/stdc++.h>
#include "print.h"
using namespace std;

void rotate_by_k_places(vector<int>& arr, int k, string dir){

    //right
    if(dir == "right"){

    reverse(arr.begin(), arr.end());

    reverse(arr.begin(), arr.begin() + k - 1);

    reverse(arr.begin() + k, arr.end());
    }
    //left 
    else{

    reverse(arr.begin(), arr.begin() + k - 1);

    reverse(arr.begin() + k, arr.end());

    reverse(arr.begin(), arr.end());

    }
}

void move_zeroes_to_end(vector<int>&arr){
    int j = 0;

    for(int i = 1;i<arr.size();i++){
        if(arr[i] != 0){
            j++;
            swap(arr[i], arr[j]);
        }
    }
}


int main(){
    vector<int> arr = {1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    move_zeroes_to_end(arr);
    print(arr);
}
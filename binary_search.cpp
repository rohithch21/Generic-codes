#include<bits/stdc++.h>

using namespace std;

void binary_search(vector<int>&vec,int high, int low,int num){
    int mid;
    if(high >= low){


    mid = (high+low)/2;
    if(num < vec[mid]){
        binary_search(vec,mid-1,low,num);
    }
    else if(num > vec[mid]){
        binary_search(vec,high,mid+1,num);
    }
    else if(num == vec[mid]){
        cout << num << " " << "found in array" << endl;
    }
    
    }
    else{
        cout << num << " " << "NOT found in array" << endl;
    }
    
}


int main(){

    vector<int> vec{4,6,7,8,9,10,11,12,13,14};
    int i,num=15;
    int high,low;
    high = vec.size()-1;
    low = 0;
    binary_search(vec,high,low,num);
    
}
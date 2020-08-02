#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>merged;
    int i=0,j=0,k=0,maxl,minl,n;
    
    maxl = nums1.size() >= nums2.size() ? nums1.size() : nums2.size();
    minl = nums1.size() < nums2.size() ? nums1.size() : nums2.size();
    
    for(i=0;i<maxl;i++){
        if(min(j,k) >= minl){
            if(nums1.size() == minl) merged.push_back(nums2[i]);
            else merged.push_back(nums1[i]);
        }
        else{

            if(nums1[j] == nums2[k]) {
                merged.push_back(nums1[j]);
                j++;
                k++;
            }
            while(nums1[j] < nums2[k] && j < nums1.size()){
                merged.push_back(nums1[j]);
                if(j == nums1.size()) break;
                j++;
            }
            while(nums2[k] < nums1[j] && k < nums2.size()){
                merged.push_back(nums2[k]);
                if(k == nums2.size()) break;
                k++;
            }   
            i = j>=k?j:k; 
            i--;          
        }                                                       
    }
    for(int x =0;x<merged.size();x++){
        cout << merged[x] << " ";
    }
    cout << endl;
    n = merged.size();
    if (n%2 == 0)
        return ((merged[n/2] + merged[(n/2)]+1)/2);
    else return merged[n/2];  
}



int main(){
    vector<int> vec1{1,3};
    vector<int> vec2{2};
    cout << findMedianSortedArrays(vec1,vec2);


}

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> merged;
//         int m,n,p1=0,p2=0,i,s;
//         m = nums1.size();
//         n = nums2.size();
        
//         while(p1 < m || p2 < n){
//             if(p1 < m && p2 < n){
//                 if (nums1[p1] < nums2[p2]){
//                     merged.push_back(nums1[p1++]);
//                 }
//                 else merged.push_back(nums2[p2++]);
//             }
//             else if(p1 < m && p2 >= n){
//                 merged.push_back(nums1[p1++]);
//             }
//             else{
//                 merged.push_back(nums2[p2++]);
//             }
                
//         }
//         for(int x =0;x<merged.size();x++){
//         cout << merged[x] << " ";
//     }
//     cout << endl;
        
//         s = merged.size();
//         if(s%2 ==0 ) return ((merged[s/2] + merged[(s/2)+1]/2));
//         else return merged[s/2];
//     }
#include<bits/stdc++.h>
using namespace std;

class myStack {
    private:
    vector<int> vec;
    public:

    
    void push(int num){
        vec.push_back(num);
        // cout << "Number pushed into stack\n";
        // for(int a=0;a<vec.size();a++){
        //     cout << vec[a] << " ";
        // }
        // cout << endl;
    }
    void pop(){
        vec.pop_back();
    }
    int top(){
        for(int i=0;i<vec.size();i++){
            if(i==vec.size()-1) {
                // cout << vec[i] << " ";
                return vec[i];
            }
        }
    }
    bool empty(){
        if(vec.size() == 0) return true;
        return false;
    }

};

int getMin(myStack s1){
    myStack support;
    int min = INT_MAX;
    while(!s1.empty()){
        if(support.empty()){
            if(s1.top() < min) min = s1.top();
            support.push(s1.top());
            s1.pop();
        }
        else{
            if(s1.top() < support.top()){
                if(s1.top() < min) min = s1.top();
                support.push(s1.top());
                s1.pop();
            }
            else{
                support.push(s1.top());
                s1.pop();
            }
        }
    }
    cout << "Is our stack empty? " << s1.empty() << endl; 
    while(!support.empty()){
        s1.push(support.top());
        support.pop();
    }
    return min;
}

int main() {
    myStack s;
    s.push(5);
    s.push(4);
    // s.pop();
    s.push(1);
    s.push(3);
    s.push(0);
    s.pop();
    s.push(2);
    cout << "Min Element of stack : " << getMin(s) << endl;
    


}
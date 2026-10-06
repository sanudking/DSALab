#include <iostream>
using namespace std;
class Stack{
    
    int arr[100];
    int i=-1;
    public:
    void push (int n){
        if(!isfull())
        arr[++i]=n;
    }
    int pop(){
        if(!isempty())
        return arr[i--];
        return -1;
    }
    int top(){
        if(!isempty())
        return arr[i];
        return -1;
    }
    bool isempty(){
        if (i==-1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isfull(){
        if(i==(99)){
            return true;
        }
        else {
            return false;
        }
    }
    
};

int main() {
    cout << "Hello, World!" << endl;
    string p;
    cout<<"enter parentheses : ";
    cin>>p;
    
    Stack s;
    s.push(-1);
    int max=0;


    int len = p.length();
    
    for(int i=0; i<len; i++){

        char c=p[i];
        
        if(c=='(') s.push(i);

        else if(c==')'){
            s.pop();
        if(s.isempty()){
            s.push(i);
        }
        else{
            int len2 =i-s.top();
            if(len2>max) max=len2;
        }
        

    }
}
    cout<<"max valid length : "<< max;
    
    
    return 0;
}

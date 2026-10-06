#include <iostream>
using namespace std;
class Stack{
    
    char arr[100];
    int i=-1;
    public:
    void push (char n){
        if(!isfull())
        arr[++i]=n;
    }
    char pop(){
        if(!isempty())
        return arr[i--];
        return -1;
    }
    char top(){
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
int precedence(char c){
        if (c=='+'  || c=='-') {
            return 1;}
        else if (c=='*' || c=='/' || c=='%') {return 2;}
        else if (c== '^') {return 3;}
        return 0;
    }
int main() {
    cout << "Enter infix expression " << endl;
    string infix;
    cin>>infix;
    Stack s;
    string postfix;
    int len=infix.length();
    int num=0;
    char c;
    char z;
    
    for(int i=0;i<len;i++){
        if (infix[i]>='0' && infix[i]<='9'){
            num = num*10 + (infix[i]-'0');
        }

        else {
            if (num!=0){
                cout<<num<<" ";
                num=0;
            }
            
            

            if(infix[i]=='('){
            num=0;
            s.push(infix[i]);
            }
            else if(infix[i]==')'){
                while(!s.isempty() && s.top() != '(') {
                    c= s.pop();
                    printf(" %c",c);
            }
            s.pop();
        }
            
            else{
                char y=s.top();
                if (s.isempty() || y=='(' || (precedence(y) <precedence(infix[i]))){
                    s.push(infix[i]);
                }
                else if (precedence(y) >= precedence(infix[i])){
                    while(!s.isempty() &&
                        s.top()!='(' &&
                        (precedence(s.top()) > precedence(infix[i]) ||
                        (precedence(s.top()) == precedence(infix[i]) && infix[i] != '^'))) {

                        cout << s.pop() << " ";
                    }

                    s.push(infix[i]);

                }
            }
        }
        }
        while (!s.isempty()) {
        cout << s.pop();
}
        cout<<num;
        


    

    return 0;
}

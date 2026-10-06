#include <iostream>
using namespace std;

class Stack{
    
    char arr[100];
    int i=-1;
    
    public:
    
    void push(char n){
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
        if(i==-1)
            return true;
        else
            return false;
    }
    
    bool isfull(){
        if(i==99)
            return true;
        else
            return false;
    }
    
};

string removeGroups(string str){
    
    bool flag=true;
    
    while(flag){
        
        flag=false;
        string temp="";
        
        for(int i=0;i<str.length();){
            
            int j=i;
            
            while(j<str.length() && str[j]==str[i])
                j++;
            
            if(j-i>=3){
                flag=true;
            }
            else{
                temp += str.substr(i,j-i);
            }
            
            i=j;
        }
        
        str=temp;
    }
    
    return str;
}

int solve(string board,string hand){
    
    board=removeGroups(board);
    
    if(board=="")
        return 0;
    
    if(hand=="")
        return -1;
    
    int ans=100;
    
    for(int i=0;i<hand.length();i++){
        
        char ball=hand[i];
        
        string newhand=hand.substr(0,i)+hand.substr(i+1);
        
        for(int j=0;j<=board.length();j++){
            
            string newboard=board.substr(0,j)+ball+board.substr(j);
            
            if((j>0 && board[j-1]==ball) ||
               (j<board.length() && board[j]==ball)){
                
                int x=solve(newboard,newhand);
                
                if(x!=-1){
                    ans=min(ans,x+1);
                }
            }
        }
    }
    
    if(ans==100)
        return -1;
    
    return ans;
}

int main(){
    
    string board,hand;
    
    cout<<"Enter board: ";
    cin>>board;
    
    cout<<"Enter hand: ";
    cin>>hand;
    
    int ans=solve(board,hand);
    
    cout<<"Minimum balls needed: "<<ans<<endl;
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(vector<string> &v, int open, int close, int n, string str){
    if(close>open || close>n || open >n){
        return;
    }

    if(open==n && close==n){
        v.push_back(str);
    }

    helper(v, open+1, close, n, str+"(");
    helper(v, open, close+1, n, str+")");
}

vector<string> generateParenthesis(int n)
{
    vector<string> v;
    helper(v, 0, 0, n, "");
    return v;
}

int main()
{

    int n;
    cin>>n;
    vector<string> v=generateParenthesis(n);
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<" "<<endl;
    }
    return 0;
}
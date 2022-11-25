#include <bits/stdc++.h>
using namespace std;

// E -> E+T/T
// T -> T*F/F
// F -> (E)/id

// after removing left recursion

// E -> TD
// D-> +TD/∈
// T -> FS
// S-> *FS/∈
// F -> (E)/id

//unordered_map<char, int> umap;
unordered_map<char,int> loc={
    {'E',0},{'D',1},{'T',2},{'S',3},{'F',4},
    {'a',0},{'+',1},{'*',2},{'(',3},{')',4},{'$',5}
};

void result(int ras){
    if(ras==1) cout<<"Can't parse the parsetable ;("<<endl;
    else
        cout << "Successfully parsed the parsetable :)" << endl;
}

int main(){
    cout<<"Enter the input string:  "<<endl;
    string inp;
    cin>>inp;
    inp=inp+"$";
    int i=0,err=0; //pointer for traversing the input 
    //a stack for deducing the input from parsing table
    stack<char> st;
    //parsing table
    string p_table[5][6] = {
        {"TD", "error", "error", "TD", "error","error"},
        {"error", "+TD", "error", "error", "",""},
        {"FS", "error", "error", "FS", "error","error"},
        {"error", "", "*FS", "error", "",""},
        {"a", "error", "error", "(E)", "error","error"}
    };
    //Pushing the start symbol
    st.push('E');
    while(!st.empty() || inp[i]!='$'){
        if(st.top() == char(inp[i])){
            st.pop();
            i++;
        }
        else if(islower(st.top()) && st.top()!=char(inp[i])){
            err=1;
            break;
        }
        else if (p_table[loc[st.top()]][loc[char(inp[i])]] == "error")
        {
            err=1;
            break;
        }
        else{
            if (p_table[loc[st.top()]][loc[char(inp[i])]] == "")
                st.pop();
            else{
                char topo = st.top();
                st.pop();
                string h = p_table[loc[topo]][loc[char(inp[i])]];
                for(auto j=h.size();j>0;j--) st.push(h[j-1]); 
            }
        }

        for(int l=i;l<inp.size();l++) cout<<inp[l];
        cout<<endl;
    }
    result(err);
    return 0;
}
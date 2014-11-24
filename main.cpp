#include <vector>
#include <stack>
#include <iostream>

using namespace std;
/*
string: afg##c#bd#e###
     a
   / | \
  f  c  b
  |    / \
  g   d   e

*/

typedef struct node_t{
    char value;
    vector<node_t *>children;
}node;

node *string2tree(string &str){
    node *child, *top;
    string::iterator it;
    stack<node*> st;
    node *dummy_root = new node;
    st.push(dummy_root);
    
    for (it=str.begin(); it<str.end(); ++it){
        if (*it=='#')
            st.pop();
        else{
            child = new node;
            child->value = *it;
            top = st.top();
            top->children.push_back(child);
            st.push(child); 
        }
    }
    return dummy_root->children[0];
}
void visit(node &node, string &buffer)
{
    buffer += node.value;
    for (int i=0; i<node.children.size(); i++){
        visit(*node.children[i], buffer); 
    }
    buffer += '#';
}

string tree2string(node *root)
{
    string buffer;
    visit(*root, buffer);
    return buffer;
}

int main(int argc, char *argv[])
{
    string str="afg##c#bd#e###";
    string str2;
    node *root;
    root = string2tree(str);
    str2 = tree2string(root);
    cout<<str2<<endl;
}


class Trie {
public:
struct Node{
    bool isendofword;
    Node* children[26];
};

Node* getNode(){
    Node* newNode=new Node();
    newNode->isendofword=false;
    for(int i=0;i<26;i++) newNode->children[i]=NULL;
    return newNode;
}

Node* root=getNode();

    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(temp->children[idx]==NULL){
                temp->children[idx]=getNode();
            }
            temp=temp->children[idx];
        }
          temp->isendofword=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(temp->children[idx]==NULL){
                return false;
            }
            temp=temp->children[idx];
        }
          return temp->isendofword==true;
        
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        int i=0;
        for(;i<prefix.size();i++){
            char ch=prefix[i];
            int idx=ch-'a';
            if(temp->children[idx]==NULL){
                return false;
            }
            temp=temp->children[idx];
        }
          return i==prefix.size();
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
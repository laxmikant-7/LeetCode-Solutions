class Node{
public:
    Node* links[26];
    bool flag;
    Node(){
    for(int i=0;i<26;i++){
        links[i]=NULL;
    }
    flag=false;
    }
    bool iscontains(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    } 
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->iscontains(word[i])){
                node->put(word[i],new Node());
            }
            node=node->links[word[i]-'a'];
        }
        node->flag=true;  
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->iscontains(word[i])) return false;
            node=node->links[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->iscontains(prefix[i])) return false;
            node=node->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
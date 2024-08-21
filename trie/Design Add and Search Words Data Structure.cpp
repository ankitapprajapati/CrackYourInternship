class WordDictionary {
public:
    class Node{
        public:
        vector<Node*>links;
        bool flag;
        Node(){
            links.resize(26,NULL);
            flag=false;
        }
        bool checkChar(char c){
            return (links[c-'a']!=NULL);
        }
        void makeChar(char c){
            if(!links[c-'a'])
            links[c-'a']=new Node();
        }
        Node* getChar(char c){
            return links[c-'a'];
        }
        void endWord(){
            flag=true;
        }
    };
    Node*root;
         WordDictionary(){
            root=new Node();
         }
         void addWord(string word){
            Node*curr=root;
            for(int i=0;i<word.length();i++){
                curr->makeChar(word[i]);
                curr=curr->getChar(word[i]);
            }
            curr->endWord();
         }
    bool searchWord(Node* current ,int index,string &word){
        if(index>=word.length()){
            return current->flag;
        }
        if(word[index]!='.'){
            if(current->checkChar(word[index])){
                 return searchWord(current->getChar(word[index]),index+1,word);
            }else return false;
        }else{
            bool ans=false;
            for(int i=0;i<26;i++){
                if(current->links[i]){
                    ans=ans|searchWord(current->links[i],index+1,word);
                }
            }
            return ans;
        }
        return true;
    }
    bool search(string word){
        return searchWord(root,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
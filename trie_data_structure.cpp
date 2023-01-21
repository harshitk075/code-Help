//implementation of trie data-structure
#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> mp;
    bool isEndofWord;

    TrieNode(){
        isEndofWord= false;
    }
};

struct Trie{
    TrieNode* root= NULL;

    //iterative insert
    void insert(string str){
        if(root==NULL){
            root= new TrieNode();
        }
        TrieNode* move= root;
        for(int i=0;i<str.length();i++){
            if(move->mp.find(str[i])== move->mp.end()){
                TrieNode* newnode= new TrieNode();
                move->mp[str[i]]= newnode;
            }
            move= move->mp[str[i]];
        }
        move->isEndofWord= true;
    }

    //itertive search in trie return true if key found else false
    bool search(string str){
        if(root==NULL)
            return false;

        TrieNode* move= root;
        for(int i=0;i<str.length();i++){
            if(move->mp.find(str[i]) == move->mp.end())
                return false;
            else    
                move= move->mp[str[i]];
        }
        return move->isEndofWord;
    }

    bool isHavingChildren(TrieNode* curr)
    {
        if(curr->mp.size()==0)
            return false;
        else  
            return true;
    }

    //recursive delete
    //return true if keyword is deleted else return false
    bool del_util(int idx, TrieNode* &curr, string str)
    {
        if(idx == str.length()){
            if(curr->isEndofWord==false)
                return false;
            
            if(isHavingChildren(curr)){
                curr->isEndofWord= false;
                return false;
            }
            else{
                delete curr;
                curr=NULL;
                return true;
            }
        }
        else{
            if(curr->mp.find(str[idx]) == curr->mp.end())
                return false; 
            else{
                bool res= del_util(idx+1,curr->mp[str[idx]],str);
                if(res){
                    curr->mp.erase(str[idx]);
                    if(isHavingChildren(curr))
                        return false;
                    else{
                        delete curr;
                        curr=NULL;
                        return true;
                    }
                }
                else
                    return false;
            }
        }
    }

    void del_word(string key){
        int n= key.length();
        if(root==NULL)
            return;
        
        del_util(0,root,key);
    }  
};

int main(){
    Trie tr;

    tr.insert("Hello");
    cout<<tr.search("Hello")<<endl;

    // // tr.insert("Pello");

    // tr.insert("Helloworld");
    // cout<<tr.search("Helloworld")<<endl;

    // tr.insert("Hell");
    // cout<<tr.search("Hell")<<endl;

    tr.del_word("Hello");

    cout<<tr.search("Hello")<<endl;
    return 0;
}
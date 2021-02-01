
#include<bits/stdc++.h>

using namespace std;
struct TrieData
{
    TrieData *child[26];
    bool isEnd;
};
struct TrieData *getNode()
{
    struct TrieData *newNode = new TrieData;
    newNode->isEnd = NULL;
    for(int i = 0; i < 26; i++)
        newNode->child[i] = NULL;
    return newNode;
} ;
void inserts(struct TrieData *root,string  &key)
{
    TrieData *lists = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i]- 'a';
        if(lists->child[index]==NULL)
            lists->child[index] = new TrieData();
        lists = lists->child[index];
    }
    lists->isEnd = true;
}
bool searchs(struct TrieData *root,string &key)
{
    TrieData *data = root;
    for(int i = 0; i < key.length(); i++)
    {
        int ptr = key[i] - 'a';
       if(data->child[ptr]==NULL)
            return false;
       data = data->child[ptr];

    }
    return data->isEnd;

}
int main()
{
    string s = "ravi";
    struct TrieData *root = getNode();
    inserts(root,s);
    if(searchs(root,s))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"No.\n";
    }

    return 0;
}

///A simple Trie implementation... Thank you GFG.. :)


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
bool isEmpty(TrieData *lists)
{
    for(int i = 0; i < 26; i++)
    {
        if(lists->child[i])
            return false;
    }
    return true;
}
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
bool searchs(struct TrieData *root,string key)
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
TrieData *deleteKey(TrieData *lists, string key, int pos)
{
    if(lists==NULL)
    {
        return NULL;
    }
    if(pos==key.length())
    {
        lists->isEnd = NULL;
        if(isEmpty(lists))
        {
            delete(lists);  lists = NULL;
        }
        return lists;
    }
    int index = key[pos]-'a';
    lists->child[index] = deleteKey(lists->child[index],key, pos+1);
        if(isEmpty(lists)&& lists->isEnd == false)
        {
            delete(lists); lists = NULL;
        }
        return lists;
}
int main()
{
    string s[] = {"ravi", "doremon", "saurav", "saurabh"};
    struct TrieData *root = getNode();
    for(int i = 0; i < sizeof(s)/sizeof(s[0]); i++)
    {

        inserts(root,s[i]);

    }
    searchs(root,"saurav")?cout<<"Found.\n":cout<<"Not Found.\n";
    root = deleteKey(root, "saurav", 0);
    searchs(root,"saurav")?cout<<"Found.\n":cout<<"Not Found.\n";

    return 0;
}

///A simple Trie implementation... Thank you GFG.. :)

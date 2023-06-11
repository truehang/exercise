// 前缀树是一颗多叉树

// 前缀树结构体
struct Trie{
    Trie():children(26), isEnd(false){}
    vector<Trie *> children;
    bool isEnd;
};

// 建立前缀树
Trie *root = new Trie();
for(auto &word: dictionary)
{
    Trie *node = root;
    for(auto ch : word)
    {
        if(node->children[ch - 'a'] == nullptr) 
            node->children[ch - 'a'] = new Trie();
        node = node->children[ch - 'a'];
    }
    node->isEnd = true;
}

// 查找前缀
Trie *node = root;
for(char ch: word)
{
    ch -= 'a';
    if(node->children[ch] == nullptr)
        return false;
    node = node->children[ch];
}
return node->isEnd;


// 统计每个叶子节点的深度
void dfs(Trie *node, int len, int res)
{
    bool isLeaf = true;
    for(auto child : node->children)
    {
        if(child != nullptr)
        {
            isLeaf = false;
            dfs(child, len + 1, res);
        }
    }
    if(isLeaf) res += len;
}

// 当然前缀树也可以变成二叉树，0， 1序列这种
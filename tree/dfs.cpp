
// BFS 有两种实现方式

// 基于递归的实现方式
// 基于栈的实现方式

// 中序遍历，递归
void dfs(Node *node)
{
    if(node == nullptr) return;
    dfs(node->left);
    add_node(node);
    dfs(node->right);
}
// 中序遍历，栈
vector<Node *> inorder(Node *root)
{
    stack<Node *> stk;
    vector<Node *> vec;
    Node *cur = root;
    while(cur != nullptr || !stk.empty())
    {
        while(cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        stk.pop();
        vec.emplace_back(cur);
        cur = cur->right;
    }
    return vec;
}

// 前序遍历，递归
void dfs(Node *node)
{
    if(node != nullptr)
    {
        add_node(node);
        dfs(node->left);
        dfs(node->right);
    }
}

// 前序遍历，栈
vector<Node *> preorder(Node *root)
{
    stack<Node *> stk;
    vector<Node *> vec;
    Node *cur = root;
    while(cur != nullptr || !stk.empty())
    {
        while(cur != nullptr)
        {
            vec.emplace_back(cur);
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        stk.pop();
        cur = cur->right;
    }
}

// 后续遍历，递归
void dfs(Node *node)
{
    if(node != nullptr)
    {
        dfs(node->left);
        dfs(node->right);
        add_node(node);
    }
}

// 后续遍历，栈
vector<Node *> postorder(Node *root)
{
    stack<Node *> stk;
    vector<Node *> vec;
    Node *cur = root;
    Node *prev = nullptr;
    while(cur != nullptr || !stk.empty())
    {
        while(cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        if(cur->right != nullptr && cur->right != prev)
        {
            cur = cur->right;
        }else{
            stk.pop();
            vec.emplace_back(cur);
            prev = cur;
            cur = nullptr;
        }
    }
    return vec;
}


// Encodes a tree to a single string.
// 采用前序遍历的方式
string serialize(TreeNode* root) {
    if(root == nullptr) return "#";
    auto left = serialize(root->left);
    auto right = serialize(root->right);
    return to_string(root->val) + ","+left + "," + right;
}

// Decodes your encoded data to tree.
// 先分割字符串，再根据"#"和数字建立起树
TreeNode* deserialize(string data) {
    vector<string> vec;
    int prev = 0;
    do{
        int pos = data.find(",", prev);
        if(pos == -1) break;
        vec.emplace_back(data.substr(prev, pos - prev));
        prev = pos + 1;
    }while(1);
    vec.emplace_back(data.substr(prev, data.size() - prev));
    int i = 0;
    return dfs(vec, i);
}
TreeNode *dfs(vector<string> &vec, int &i)
{
    if(vec[i] == "#")
        return nullptr;
    int tmp = i;
    auto left = dfs(vec, ++i);
    auto right = dfs(vec, ++i);
    TreeNode *cur = new TreeNode(stoi(vec[tmp]));
    cur->left = left;
    cur->right = right;
    return cur; 
}
// c++ 支持批量插入
// 批量插入来构造一个hash集合
unordered_set<string> hashset(accounts[i].begin() + 1, accounts[i].end());
// 批量插入
hashset.insert(accounts[i].begin()+1, accounts[i].end());
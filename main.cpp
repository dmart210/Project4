#include <iostream>
#include <vector>
#include "Post.hpp"
#include "Poll.hpp"
#include "Promotional.hpp"
#include "General.hpp"
#include "Account.hpp"
// #include "Network.hpp"
#include "Node.hpp"
// #include "LinkedList.hpp"
#include <cstring>
using namespace std;

int main(){
    vector<string> options;
    for(int i =0 ;i < 5; i++)options.push_back(to_string(i));
    Network<Account> net;
    Account account("username", "password");
    Post* ptr1 = new General("gen_title","gen_body", "gen_username");
    Post* ptr2 = new Promotional("pro_title","pro_body","pro_username", "https://theuselessweb.com/");
    Post* ptr3 = new Poll("Poll_title","poll_question?", "poll_username",options);
    account.addPost(ptr1);
    account.addPost(ptr2);
    account.addPost(ptr3);
    account.viewPosts();
    Account* account_ptr = &account;
    net.addAccount(account_ptr);
    cout << net.removeIfContains("password") << endl;

}
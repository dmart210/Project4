#include <iostream>
#include <vector>
#include "Post.hpp"
#include "Poll.hpp"
#include "Promotional.hpp"
#include "General.hpp"
#include "Account.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"
using namespace std;

int main(){
    vector<string> options;
    for(int i =0 ;i < 5; i++)options.push_back(to_string(i));
    Network<Account> net;
    Network<Account>* net_ptr;
    net_ptr = &net;
    Account account("username", "password");
    Post* ptr1 = new General("gen_title","gen_body", "gen_username");
    Post* ptr2 = new Promotional("pro_title","pro_body","pro_username", "https://theuselessweb.com/");
    Post* ptr3 = new Poll("Poll_title","poll_question?", "poll_username",options);
    account.addPost(ptr1);
    Account* acc_ptr = &account;
    acc_ptr->setNetwork(net_ptr);
//
}
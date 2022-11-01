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

int main() {
    vector<string> options;
    for (int i = 0; i < 5; i++)options.push_back(to_string(i));
    Network<Account> net;
    Network<Account> *net_ptr;
    net_ptr = &net;
    Account account("username", "password");
    Post *ptr1 = new General("gen_title", "gen_body", "gen_username");
    Post *ptr2 = new Promotional("pro_title", "pro_body", "pro_username", "https://theuselessweb.com/");
    Post *ptr3 = new Poll("Poll_title", "poll_question?", "poll_username", options);
    Account* acc_pointer = &account;
    net_ptr->addAccount(acc_pointer);
    acc_pointer->setNetwork(net_ptr);
    acc_pointer->addPost(ptr1);
    acc_pointer->addPost(ptr2);
    acc_pointer->addPost(ptr3);

    Account new_acc = *acc_pointer;
    cout << "Feed TEST:";
    net_ptr->printFeedForAccount(acc_pointer);
    cout << "ACCOUNT POST TEST:";
    acc_pointer->viewPosts();
    cout << "Amount removed:"  << net_ptr->removeIfContains("title") << endl;

}

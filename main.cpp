#include <iostream>
#include <vector>
#include "Post.hpp"
#include "Poll.hpp"
#include "Promotional.hpp"
#include "General.hpp"
#include "Account.hpp"
#include "Network.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"
#include <cstring>
using namespace std;

int main(){
    vector<string> options;
    for(int i =0 ;i < 5; i++)options.push_back(to_string(i));
    LinkedList<Post*> Llist;
    Post* ptr1 = new General("gen_title","gen_body", "gen_username");
    Post* ptr2 = new Promotional("pro_title","pro_body","pro_username", "https://theuselessweb.com/");
    Post* ptr3 = new Poll("Poll_title","poll_question?", "poll_username",options);
    Llist.insert(ptr1,0);
    Llist.insert(ptr2,0);
    Llist.insert(ptr3,0);
    cout << Llist.getIndexOf(ptr1) << endl;
    cout << Llist.getIndexOf(ptr2) << endl;
    cout << Llist.getIndexOf(ptr3) << endl;
    // Llist.moveItemToTop(ptr3);
    // cout << Llist.getIndexOf(ptr3) << endl;
    // cout << Llist.getIndexOf(ptr1) << endl;
    // cout << Llist.getIndexOf(ptr2) << endl;
    /*--------------------------------------------------------------------------------------------------------------*/

    LinkedList<Post*> List2;
    cout << "before size is: " << List2.getSize() << endl;
    // List2.insert(ptr1,0);
    List2.reverseCopy(Llist);
    cout << "After size is: " << List2.getSize() << endl;
}
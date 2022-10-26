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

using namespace std;

int main(){
    // Post* test = new General("title", "body", "username");
    // test->displayPost();
    // Post* test2 = new Promotional("title", "body", "username", "https://theuselessweb.com/");
    // test2->displayPost();
    // Account acc("username", "passworr");
    // acc.addPost(test);
    LinkedList<int>* test = new LinkedList<int>();
    LinkedList<int> test2;
    test2.insert(2,0);
    test2.insert(3,1);
    test2.insert(21,2);

    test->insert(1,0);
    test->insert(3,1);
    cout << "Size: " << test->getSize() << endl;
    test->reverseCopy(test2);
    cout << "Size: " << test->getSize() <<endl;
    cout << test->getIndexOf(21) << endl;
    test->displayList();
}
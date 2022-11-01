
/**
 * @author: Dariel A. Martinez
 * @date:  11 October 2022
 * @post: Account.cpp file thats basically the same as the Account in Project 1. There are 5 new modifications. Those being the getNetwork
 *        and setNetwork methods. These methods are supposed to either return the network the Account is currently in (getNetwork), and the
 *        other is setting a network to the specific Account. 
 * @file: Account.cpp
 */
#include "Account.hpp"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


/**
 * @return: A getter that returns the username of the account created. (As string)
 */
string Account::getUsername()const {
    return username;
}

/**
 * @return: A getter that returns the password of the account created. (As string)
 */
string Account::getPassword()const{
    return password;
}
/**
 * @return: returns the current network the Account is in
 */
Network<Account>* Account::getNetwork(){
    return account_in_network;
}
/**
 * @param: sets the current Account to a the network {net_ptr} is pointing to 
 */
void Account::setNetwork(Network<Account>* net_ptr){
    account_in_network = net_ptr;
}

/**
 * @param: the string named _username that the user wants to set the username as.
 */
void Account::setUsername(const string& _username){
    username = _username;
}
/**
 * @param: the string named _password that the user wants to set the password as.
 */

void Account::setPassword(const string& _password){
    password = _password;
}

void Account::getTimeStamp() const{
    cout << asctime(localtime(&current_time));
}

/**
 * @param: title, which is the title of the post
 * @param: body, the actual post or the body of the post
 * @return: It returns false if theres no title or body
 * @return: Returns true otherwise and creates a post and adds it to the string vector
 */

bool Account::addPost(Post* post) {
    all_posts.insert(post,0);
    account_in_network->addToFeed(post);
    cout << this->account_in_network << endl;
    return true;

}


/**
 * @note: A for loop that prints out the posts in the accounts
 */

void Account::viewPosts() const {
    Node<Post*>* iterator;
    iterator = all_posts.getHeadPtr();
    while (iterator != nullptr){
        Post* ptr = iterator->getItem();
        ptr->displayPost();
        iterator = iterator->getNext();
    }

}
/**
 * 
 */
bool Account::followAccount(const string& username_to_follow){
    unsigned int vecSize = usernames_of_following.size();
    bool already_following = false;
    for (unsigned int i = 0; i < vecSize;i++){
        if (usernames_of_following[i] == username_to_follow) already_following = true;
    }
    if (already_following == false && account_in_network != nullptr) {
        usernames_of_following.push_back(username_to_follow);
    }
    return false;
}

/**
 * @return:
 */
vector<string> Account::viewFollowing() const{
    cout << usernames_of_following.size() << endl;
    return usernames_of_following;
}

void Account::updatePost(const Post* post_ptr,const string& new_title,const  string& new_body) {
    Post *new_ptr = const_cast<Post *>(post_ptr);
    LinkedList<Post *> linkedFeed = account_in_network->getFeed();
    new_ptr->setTitle(new_title);
    new_ptr->setBody(new_body);
    Node<Post *> *iterator;
    Node<Post *> *feed_iterator;
    iterator = all_posts.getHeadPtr();
    feed_iterator = linkedFeed.getHeadPtr();
    while (iterator != nullptr) {
        if (iterator->getItem() == post_ptr) {
            all_posts.remove(all_posts.getIndexOf(iterator->getItem()));
            all_posts.insert(new_ptr, 0);
        }
        iterator = iterator->getNext();
    }
    while (feed_iterator != nullptr){
        if(feed_iterator->getItem() == post_ptr){
            linkedFeed.remove(linkedFeed.getIndexOf(feed_iterator->getItem()));
            linkedFeed.insert(new_ptr,0);
        }
        feed_iterator = feed_iterator->getNext();
    }
    account_in_network->setFeed(linkedFeed);
}

bool Account::removePost(Post* post_ptr){
    all_posts.remove(all_posts.getIndexOf(post_ptr));
    return true;
}

LinkedList<Post*> Account::getPost() {
    return all_posts;
}

void Account::setPost(LinkedList<Post *> list) {
    all_posts = list;
}

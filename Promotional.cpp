//Promotional.cpp
#include <iostream>
#include <time.h>
#include <regex>
#include "Promotional.hpp"
using namespace std;
/**
 * 
 * @post: mutator that returns the current link
 * 
 */
string Promotional::getLink()const {
    return url;
}
/***
 * @param: string reference that gets the link the user provided
 */
bool Promotional::setLink(string& _link){
    //using regex to look for the https: and to make sure the end has at least 2 characters
    regex end ("[a-z][.][a-z][a-z]");
    regex front("https:");
    //_link becomes broken link if its not right
    if (!regex_search(_link,front) || !regex_search(_link,end)) _link = "Broken Link";
    //else set the url to the link
    else url = _link;
    return true;
}
/**
 * @post: method that prints out the the title body nd the time it was created
 * 
 */
void Promotional::displayPost(){
    string x = Post::getTitle();
    string y = Post::getBody();
    string z = getLink();
    char * time_pointer =asctime(localtime(&current_time));
    string date_formated;
    //A for loop to go through the char pointer and to remove the \n that is attached to the asctime() function. The purpose to is make the date look more appealing
    for (int i = 0; i < strlen(time_pointer) -1; i++){
        date_formated+=*(time_pointer+i);
    }
    cout << "\n" << x << " at " <<date_formated << ":\n" << y << "\n" << z << "\n";
}

//Promotional.hpp


#include <iostream>
#include "Post.hpp"

using namespace std;

class Promotional:public Post{
    private: 
        string url;
        time_t current_time;
    public:
        Promotional (string _title, string _body, string _username, string link) : Post (_title, _body, _username){
            Post::setTitle(_title);
            Post::setBody(_body);
            Post::setUsername(_username);
            url = link;
            time(&current_time);
        }
        string getLink()const;
        bool setLink(string& _link);
        void displayPost() override;

};

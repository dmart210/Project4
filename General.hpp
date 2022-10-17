//General.hpp

#include <iostream>
#include "Post.hpp"
using namespace std;
// enum with all the reactions as an int
enum Reactions:int{LIKE, DISLIKE, LAUGH, WOW ,SAD , ANGRY }; 
//General class inherited but the post class
class General: public Post{
    private:
        //react refers to the amount of reactions which are initialized to 0. and it is private
        int react[6]{0};
        time_t current_time;
    public:  
        bool reactToPost(const Reactions& reaction);
        void getReactions() const;
        virtual void displayPost()const ;
        General(string _title, string _body, string& _username): Post (_title, _body, _username){
            Post person(_title,_body, _username);
            time(&current_time);
        }
};

/*
List class implementation for term projects
CSCI 235 Fall 2022
Hunter College
*/


#include <iostream>

/* Default constructor*/
template<class T>
LinkedList<T>::LinkedList() : head_{nullptr}, size_{0} {}

/*Parameterized Constructor*/
template<class T>
LinkedList<T>::LinkedList(LinkedList<T>& list){
    this->size_ = list->getSize();
    this->head_ = list->getHeadPtr();
}

/* Destructor */
template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}



/* @return  : the head pointer
This function is for grading purposes*/
template<class T>
Node<T>* LinkedList<T>::getHeadPtr() const {
    return head_;
}




/*
    @post   : removes all items from the caller list
**/
template<class T>
void LinkedList<T>::clear() {

    Node<T>* curr_item = head_;
    while(curr_item != nullptr) {
        Node<T>* temp = curr_item;
        curr_item = curr_item->getNext();
        // delete temp->getItem();
        // temp->setItem(NULL);
        // temp->setNext(nullptr);
        delete temp;
        temp = nullptr;
    }

}



/*
    @param  item: the item to insert in the list
    @param  position: the position where to inserted
    @pre position is a valid place within the list, otherwise false will be returned
    @return   :  true if the item has been inserted in the caller list,
                false otherwise
    @post     : Inserts item in  list at  position

**/
template<class T>
bool LinkedList<T>::insert(const T& item, const int &position){
    if((position < 0 || position > size_)){
        return false;
    }

    Node<T> *node = new Node<T>();
    node->setItem(item);

    if(size_ == 0){
        head_ = node;
    }
    else {
        Node<T> *iterator;

        if(position == 0){
            node->setNext(head_);
            head_ = node;
        }

        else if (position == size_){
            iterator = getAtPos(size_-1);
            iterator->setNext(node);
        }
        else {
            iterator = getAtPos(position-1);
            node->setNext(iterator->getNext());
            iterator->setNext(node);
        }
    }
    size_++;
    return true;
}




/*
    @param  position:  the position where to remove
    @pre position is a valid place within the list, otherwise false will be returned
    @pre      : returns true if the item at position has been removed from the list,
                false otherwise
    @post     : removes node at  position
**/
template <class T>
bool LinkedList<T>::remove(const int&position) {
    if (position < 0 || position >= size_) {
        return false;
    }

    Node<T> *iterator;

    if (position == 0){
        iterator = head_;
        head_ = head_->getNext();
    }
    else {
        iterator = getAtPos(position-1);
        iterator->setNext(iterator->getNext()->getNext());
        iterator = iterator->getNext();
    }

    return true;

}



/*
    @param   item : the item to find in the list
    @pre      : takes item object and checks if exist in list and return
    @return   : returns the position (index) of object in the list

**/
template<class T>
int LinkedList<T>::getIndexOf(const T &item) const {
    Node<T>* curr_item = head_;
    int counter = 0;
    while(curr_item != nullptr) {
        if(curr_item->getItem() == item) {
            return counter;
        }
        counter++;
        curr_item = curr_item->getNext();
    }
    return -1;
}




/* @return  : the size of the list */
template<class T>
int LinkedList<T>::getSize() const {
    return size_;
}


  /* @return  : true if the list is empty, false otherwise */
template<class T>
bool LinkedList<T>::isEmpty() const {
    return size_ == 0 ? true : false;
}

template<class T>
bool LinkedList<T>::moveItemToTop(Node<T>*& move_to_top){
    return true; 
}


// PRIVATE METHODS

/*
    @param   pos : the position of the item
    @pre     : pos is a valid place in the list
    @return  : a pointer to the node at pos, if pos is invalid, returns nullptr
**/
template<class T>
Node<T>* LinkedList<T>::getAtPos(const int &pos) const {

    if(pos < 0 || pos >= size_) {
        return nullptr;
    }

    Node<T>* curr_item = head_;
    int counter = 0;
    while(counter < pos && curr_item != nullptr) {
        counter++;
        curr_item = curr_item->getNext();
    }
    return curr_item;
}

template<class T>
void LinkedList<T>::displayList(){
    while (head_ != nullptr){
        std::cout << head_->getItem() << "-> ";
        head_ = head_->getNext();
    }
    std::cout << endl;
}

template<class T>
void LinkedList<T>::reverseCopy(LinkedList<T>& linked_being_reversed){
    clear();
    remove(1);
    remove(3);
    size_t counter = 0;
    Node<T>* head_ptr = linked_being_reversed.getHeadPtr();
    while(head_ptr != nullptr){
        cout << "ok" << endl;
        insert(head_ptr->getItem(),counter);
        head_ptr = head_ptr->getNext();
        counter++;
    }
}
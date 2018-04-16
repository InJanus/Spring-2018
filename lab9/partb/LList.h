#ifndef LLIST_H
#define LLIST_H

/*
    Linked List class that store integers, with [] operator.
    Uses head pointer.
    Paul Talaga
    September 2015
*/
#include <ostream>
#include <stdexcept>

#define int int

using namespace std;

struct node_t {
    int data;
    node_t* next;
};

typedef struct node_t* node_tPtr;

// This implementation will use a head pointer,
// allowing O(1) insertion on the front,
// and O(n) on the end.
class LList {

public:
    LList(){
        head = NULL;
    }

    ~LList(){
        clear();
    }

    LList(const LList& other){
        // Do the same as the default constructor
        head = NULL;
        // Check if the other LList is empty
        if(other.head == NULL){
            return;
        }
        // Not empty?  Iterate through the other list
        // and push_back on myself.
        node_tPtr temp = other.head;
        while(temp){
            push_back(temp->data);
            temp = temp->next;
        }
    }

    // Similar to copy constructor, but check for self
    // assignment, if not, clear and copy all data.
    LList& operator= (const LList& other){
        if(this == &other){
            return *this;
        }
        clear();
        if(other.head == NULL){
            return *this;
        }
        node_tPtr temp = other.head;
        while(temp){
            push_back(temp->data);
            temp = temp->next;
        }
        return *this;
    }


   bool empty() const {
        return (head == NULL);
    }

    unsigned int size() const {
        node_tPtr temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    void push_back(int value){
        node_tPtr curr = head;
        node_tPtr n = new node_t;
        n->next = NULL;
        n->data = value;

        if(head != NULL){   // in list is empty
            while(curr->next != NULL){  //finds the end of the list by going through each one
                curr = curr->next;
            }
            curr->next = n; //when curr does equal NULL then set n to equal curr->next
        }else{
            head = n;
        }

        
    }

    void push_front(int value){
        // Empty list?
        if(head == NULL){
            head = new node_t;
            head->data = value;
            head->next = NULL;
        }else{ // Not empty
            node_tPtr temp = new node_t;
            temp->data = value;
            temp->next = head;
            head = temp;
        }
    }

    void pop_front(){
        if(head == NULL) return;
        node_tPtr temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back(){
        if(head == NULL) return;
        node_tPtr curr = head;
        while(curr->next != NULL){
            curr = curr->next;
            if(curr->next->next == NULL){
                break;
            }
        }
        curr->next = NULL;  //done
        
        
    }


    // Overload [] operator
    // Return logic error if index out of bounds
    int& operator[](unsigned pos){
        node_tPtr temp = head;
        while(temp != NULL && pos > 0){
            temp = temp->next;
            pos--;
        }
        // As long as I don't have a null pointer, assign.
        if(pos == 0 && temp != NULL){
            return temp->data;
        }
        throw logic_error("Index invalid");
    }

    LList reverse() const {
        LList temp;
        node_tPtr curr = head;


        for(int i = 0; i < size(); i++){
            //cout << curr->data << endl;
            temp.push_front(curr->data);
            curr = curr->next;
        }

        return temp;
    }

    bool operator==(const LList& other) const {
        
        node_tPtr curr = head;
        
        if(size() == other.size()){
            for(unsigned int i = 0; i < other.size();i++){
                //if((curr->data) == other.getAt(i)){
                    cout << other.getAt(i) << endl;
                    curr = curr->next;
               // }else{
                    //return false;
                //}
            }
            return true;
        }
        return false;





        /*
        
        if(size() == other.size()){
            for(int i = 0; i < size(); i++){
                if(getAt(i) != other.getAt(i)){
                    return false;
                }
            }
            return true;
        }
        return false;
        */
    }

    bool operator!=(const LList& other) const {
        return !operator==(other);
    }

    void clear(){
        node_tPtr last = head;
        while(head){
            head = head->next;
            delete last;
            last = head;
        }
        // Normaly you never want to change head or you'll orphan part
        // of the list, but in this case we are wiping the list,
        // so it is ok to so and saves us a variable.
        head = NULL;
    }

    int getAt(unsigned int temp){
        //i could not find the function for this so i made it myself
        //start counting at 0
        node_tPtr tempPtr = head;
        int count = temp;


        while(count > 0){
            tempPtr = tempPtr->next;
            count--;
        }

        return (tempPtr->data);
    }

    void setAt(unsigned int temp, int value){
        node_tPtr tempPtr = head;
        int count = temp;

        while(count > 0){
            tempPtr = tempPtr->next;
            count--;
        }
        tempPtr->data = value;

    }

private:
    node_tPtr head;
    
    //so for this, you make a constant list connected by pointers

};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.
/*
ostream& operator<<(ostream& out, const LList other){
    out << "[";
    for(unsigned int i = 1; i < other.size(); i++){
        out << other.getAt(i-1) << ", ";
    }
    if(other.size() > 0){
        out << other.getAt(other.size() - 1);
    }
    out << "]";
    return out;
}
*/

#endif

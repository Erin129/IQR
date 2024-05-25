//Programming partner: Lexi Bobb
#include <iostream>
#include <iomanip>

class Node {
public:
    int value;
    Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if (head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* fast = head;
    Node* q1PTR = head;
    Node* q3PTR = head->next->next;

    int counter = -1;
    float q1 = 0.0;
    float q3 = 0.0;

    while (fast != nullptr) {
        counter++;
        fast = fast->next;        
        
        if(counter>3){
            if(counter%4 ==0 || counter%4 ==2){
                q3PTR = q3PTR->next;
            }
            else if (counter%4 ==1){
                q1PTR = q1PTR->next;
                q3PTR = q3PTR->next;
            }
        }          
    }//end while 

    counter++;
    if (counter % 2 == 0 && counter %4 == 0) {        
        q1 = (float)((q1PTR->next->value) + (q1PTR->value)) / 2;
        q3 = (float)((q3PTR->next->value) + (q3PTR->value)) / 2;        
    }
    else if (counter % 2 == 0 && counter % 4 != 0)
    {
        q1 = q1PTR->value;
        q3 = q3PTR->value;
    }
    //else total odd 7
    else if (counter % 2 != 0 && counter %4==3) {
        q1 = q1PTR->value;
        q3 = q3PTR->value;
    }
    else if (counter % 2 != 0 && counter % 4 != 3)
    {
        q1 = (float)((q1PTR->next->value) + (q1PTR->value)) / 2;
        q3 = (float)((q3PTR->next->value) + (q3PTR->value)) / 2;    
    }    
    return q3-q1;   
}

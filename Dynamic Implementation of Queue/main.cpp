#include<iostream>
class Queue {

    struct node {
        int data;
        struct node *next;
    }*front,*rear;

public:
    Queue();

    void enqueue(int);

    void dequeue();

    void display();
};
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

void Queue::dequeue()
{
    struct node *q;
    if (front == NULL)
    {
        std::cout << "Queue is Empty!!!";
    } else {
       q = front;
        front = front->next;
        std::cout << "Deleted element:" << q->data;
        delete q;

    }
}

void Queue::enqueue(int value)
{
    struct node *t;
    t=new node;
    t->data = value;
    t -> next = NULL;
    if(front == NULL)
        front = rear = t;
    else{
        rear -> next = t;
        rear = t;
    }
    std::cout<<"Insertion is Success!!!";
}



 void Queue::display()
{
        struct node *q;
        q=front;
        if(front==NULL)
        {
       std::cout<<"Queue empty";
        }
        else
        {
            while(q!=NULL)
            {
                std::cout<<"The data stored is::"<<q->data;
                q=q->next;
            }
        }
    }

int main()
{
    using namespace std;
    Queue queue;
    int choice, value;
    std::cout<<"\n:: Queue Implementation using Linked List ::\n";
    while(1)
    {
        std::cout<<"\n****** MENU ******\n";
        std::cout<<"1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        std::cout<<"Enter your choice: ";
       std::cin>>choice;
        switch(choice){
            case 1:
                std::cout<<"Enter the value to be insert: ";
              std::cin>>value;
               queue.enqueue(value);
                break;
            case 2:
               queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                exit(0);
            default:
                std::cout<<"\nWrong selection!!! Please try again!!!\n";
        }
    }
}
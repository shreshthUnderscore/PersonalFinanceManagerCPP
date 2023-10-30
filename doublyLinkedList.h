#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include<iostream>

template <typename T>
class doublyLinkedList;

template <typename T>
class doublyLinkedList
{
    public:
        template <typename U>
        class NODE
        {
            private:
                T data;
                std::string title;
                std::string type;
                NODE<T>* prev;
                NODE<T>* next;

                friend class doublyLinkedList;

            public:
                NODE()
                    : prev{nullptr}
                    , next{nullptr}
                {
                }

                NODE(const T& data, std::string title, std::string type)
                    : data {data}
                    , title {title}
                    , type {type}
                    , prev {nullptr}
                    , next {nullptr}
                {
                }
        };

    private:
        NODE<T>* head;
        NODE<T>* tail;
        int size;
    
    public:
        doublyLinkedList()
            : head {nullptr}
            , tail {nullptr}
            , size {0}
        {
        }

        bool isEmpty()
        {
            return size==0;
        }

        void insertAtStart(const T& data, std::string title, std::string type)
        {
            if(isEmpty())
            {
                head = new NODE<T>(data, title, type);
                tail = head;
                size++;
            }
            else
            {
                NODE<T>* newNode = new NODE<T>(data, title, type);

                newNode->next = head;
                head->prev = newNode;
                head = newNode;

                size++;
            }
        }

        void insertAtEnd(const T data, std::string title, const std::string type)
        {
            if(isEmpty())
            {
                head = new NODE<T>(data, title, type);
                tail = head;
                size++;
            }
            else
            {
                NODE<T>* newNode = new NODE<T>(data, title, type);

                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;

                size++;
            }

        }

        void insertAtNth(const T data, std::string title, std::string type, int position)
        {
            if(position == 1)
            {
                insertAtStart(data, title, type);
            }
            else if(position == size+1)
            {
                insertAtEnd(data, title, type);
            }
            else
            {
                
            }
        }

        void printList()
        {
            NODE<T>* trav = head;
            int position{1};

            while(trav != nullptr)
            {
                std::cout << "Transaction ID " << position << "\nTransaction Type: " << trav->type << "\nTitle: " << trav->title
                    << "\nAmount: Rs " << trav->data << "\n";

                int userChoice;

                std::cout<<"\t\t\t|  Press 1 to View Next Transaction       |" << std::endl;
                std::cout<<"\t\t\t|  Press 2 to View Previous Transaction   |" << std::endl;
                std::cout<<"\t\t\t|  Press 3 to EXIT                        |" << std::endl;
                std::cout<<"\n\t\t Please enter your choice : ";
                std::cin>>userChoice;

                switch (userChoice)
                {
                    case 1:
                        if (trav->next != nullptr)
                        {
                            trav = trav->next;
                            position++;
                        }
                        else
                        {
                            std::cout << "NO NEW NEXT TRANSACTION !!" << std::endl;
                        }
                        break;
                    
                    case 2:
                        if (trav->prev != nullptr)
                        {
                            trav = trav->prev;
                            position--;
                        }
                        else
                        {
                            std::cout << "NO NEW PREVIOUS TRANSACTION !!" << std::endl;
                        }
                        break;
                    case 3:
                        return;
                    
                    default:
                        std::cout << "Invalid Choice. Please Enter Again";
                }

            }
            std::cout << '\n';
        }
};

#endif
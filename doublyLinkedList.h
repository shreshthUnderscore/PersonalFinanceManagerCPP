#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

void mainScreen();
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
                system("clear");
                std::cout << "Transaction ID " << position << "\nTransaction Type: " << trav->type << "\nTitle: " << trav->title
                    << "\nAmount: Rs " << trav->data << "\n\n\n\n";

                int userChoice;

                if (trav->next != nullptr)
                {
                    std::cout<<"\t\t\t|  Press 1 to View Next Transaction       |" << std::endl;
                }

                if (trav->prev != nullptr)
                {
                    std::cout<<"\t\t\t|  Press 2 to View Previous Transaction   |" << std::endl;
                }
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
                        system("clear");
                        mainScreen();
                    
                    default:
                        std::cout << "Invalid Choice. Please Enter Again";
                }

            }
            std::cout << '\n';
        }

        void sum()
        {
            NODE<T>* trav = head;
            int sum{0};

            while(trav != nullptr)
            {
                if(trav->type == "EXPENSE")
                {
                    sum -= trav->data;
                    trav = trav->next;
                }else
                {
                    sum += trav->data;
                    trav = trav->next;
                }
            }

            std::cout << "\n Balance Amount is: Rs " << sum << "\n";
        }

        void search()
        {
            NODE<T>* trav = head;

            std::string userTitle;

            system("clear");

            std::cout << "Enter the transaction title you wanna search: ";
            std::cin >> userTitle;

            int position{1};
            int flag = 0;

            while(trav != nullptr)
            {
                if(trav->title == userTitle)
                {
                    flag = 1;
                    break;
                }
                trav = trav->next;
                position++;
            }

            if(flag == 1)
            {
                std::cout << "Transaction Found !! \n" << "Transaction ID " << position << "\nTransaction Type: " << trav->type << "\nTitle: " << trav->title
                    << "\nAmount: Rs " << trav->data << "\n\n\n\n";
            }else
            {
                std::cout << "Transaction Not Found !!!";
            }
            std::cout << '\n';
        }


};

#endif
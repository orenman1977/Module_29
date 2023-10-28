/*
Ш
*/
#pragma once

#include <mutex>
#include <vector>
#include <iostream>

namespace m29hw
{
    template <class T>
    class Mylist
    {
    private:
        struct Node
        {
            T value;
            Node *next;
            std::mutex node_mutex;
            Node(T v, Node *n = nullptr)
            { 
            value = v; 
            next = n;
            }
        };

        Node *head{ nullptr };
        std::mutex mylist_mutex;

    public:
        ~Mylist()
        {
            Node* node = head;
            Node* nextnode = nullptr;
            while(node)
            {
                std::cout << "Delete node: " << node << '\n';
                if(node->next) nextnode = node->next;
                else nextnode = nullptr;
                delete node;
                node = nextnode;
            }
        }
        void insertIntoMiddle(T value, int pos)
        {
            Node *prev, *cur;
            size_t current_position = 1;

            mylist_mutex.lock();               // блокируем список
            if(!head) 
            {
                head = new Node(value);
                mylist_mutex.unlock();
                return;
            }

            if(pos == 0)
            {
                Node *temp = new Node(value, head);
                head = temp;
                mylist_mutex.unlock();
                return;
            }

            prev = this->head;
            cur = prev->next;
            prev->node_mutex.lock();
            mylist_mutex.unlock();             // разблокируем список

            if(cur){ cur->node_mutex.lock(); }
            while(cur && (current_position != pos))
            {
                Node* old_prev = prev;
                prev = cur;
                cur = cur->next;
                old_prev->node_mutex.unlock();
                if(cur){ cur->node_mutex.lock(); }
                ++current_position;
            }
            Node* temp = new Node(value, cur);
            prev->next = temp;
            prev->node_mutex.unlock();
            if(cur){ cur->node_mutex.unlock(); }            
        }

        template <class Type>
        friend std::ostream& operator<<(std::ostream& out, Mylist<Type>& obj);
    };

    template <class T>
    std::ostream& operator<<(std::ostream& out, Mylist<T>& obj)
    {
        typename Mylist<T>::Node* temp = obj.head;
        size_t counter = 1;
        if(!temp) { 
            return out << "No nodes\n"; 
        } 
        out << "Nodes: \n";
        while(temp){
            out << counter << ' ' << temp << ' ' << temp->value << '\n';
            temp = temp->next;
            ++counter;
        }
        out << '\n';
        return out;
    }
};

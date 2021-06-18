#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
using std::endl;

/*
 * NODE TEMPLATE
 */
template<typename T>
struct Node {
    T     key;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(T key) : key(key) {}
};

/*
 * LIST TEMPLATE
 */
template<typename T>
class List {
  private:
    Node<T> *head;
    Node<T> *tail;

    void _print_list(const Node<T> *n) {
        if (n->next == nullptr) {
            cout << n->key;
            return;
        }
        cout << n->key << ", ";
        _print_list(n->next);
    }

  public:
    List(T key) : head(new Node<T>(key)) {}
    ~List() { clear_list(this->head); }

    void insert(T key) {
        /* if no tail, i.e. list contains only 1 node */
        if (this->head->next == nullptr) {
            this->tail       = new Node<T>(key);
            this->head->next = this->tail;
            this->tail->prev = this->head;
        }
        /* otherwise, insert at tail */
        else {
            Node<T> *n       = new Node<T>(key);
            this->tail->next = n;
            n->prev          = this->tail;
            this->tail       = n;
        }
    }

    void print_list() {
        cout << "list: [";
        _print_list(this->head);
        cout << "]" << endl;
        cout << "head=" << this->head->key << endl;
        cout << "tail=" << this->tail->key << endl;
    }

    void clear_list(Node<T> *n) {
        if (n == nullptr)
            return;
        Node<T> *curr = n->next;
        delete n;
        clear_list(curr);
    }
};

#endif

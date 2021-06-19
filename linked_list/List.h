#ifndef LIST_H
#define LIST_H
#include <iostream>
using std::cout;
using std::endl;

/*****************************************************************************
 * NODE CONTAINER TEMPLATE
 *****************************************************************************/
template<typename T>
struct Node {
    T     key;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(T key) : key(key) { }
};

/*****************************************************************************
 * LIST CONTAINER TEMPLATE
 *****************************************************************************/
template<typename T>
class List {
  private:
    Node<T> *head;
    Node<T> *tail;
    int      size;

    void show(Node<T> *n);

  public:
    /* CONSTRUCTOR */
    explicit List(const T &key);

    void show();
    void insert(const T &key);
    void clear(Node<T> *n);

    /* DESTRUCTOR */
    ~List();
};

/*****************************************************************************
 * IMPLEMENTED DEFINITIONS FOR MEMBERS OF NODE AND LIST
 *****************************************************************************/
/* PRIVATE */
template<typename T>
inline void List<T>::show(Node<T> *n) {
    /* base case */
    if (n->next == nullptr) {
        cout << n->key;
        return;
    }
    cout << n->key << ", ";
    show(n->next);
}

/* PUBLIC */
template<typename T>
inline List<T>::List(const T &key) : head(new Node<T>(key)),
                                     size(1) { }

template<typename T>
inline void List<T>::show() {
    cout << "list: [";
    show(this->head);
    cout << "]" << endl;
    cout << "head=" << this->head->key << endl;
    cout << "tail=" << this->tail->key << endl;
    cout << "size=" << this->size << endl;
}

template<typename T>
inline void List<T>::insert(const T &key) {
    /* if no tail, i.e. list contains only the head */
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
    ++this->size;
}

template<typename T>
inline void List<T>::clear(Node<T> *n) {
    if (n == nullptr) return;
    Node<T> *curr = n->next;
    delete n;
    clear(curr);
}

template<typename T>
inline List<T>::~List() { clear(this->head); }

#endif

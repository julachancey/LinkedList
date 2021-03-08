//
// Created by julia on 02/17/2020.
// modified by julia on 03/08/2021.
//

#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <typename T>
class LinkedList {

public:
    struct Node{
        Node* next;
        Node* prev;
        T data;

    };


    Node* Head();
    Node* Tail();

    //accessors
    unsigned int NodeCount() const;
    void FindAll(vector<Node*>& outData, const T& value) const;
    const Node* Find(const T& data) const;
    Node* Find(const T& data);
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    const Node* Head() const;
    const Node* Tail() const;

    //behaviours

    void Clear();

    void PrintForward() const;
    void PrintReverse() const;
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

    //insertion
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);
    void InsertAfter(Node* node, const T& data);
    void InsertBefore(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);

    //removal
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T& data);
    bool RemoveAt(unsigned int index);

    //operators
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
    bool operator==(const LinkedList<T>& list) const;
    LinkedList<T>& operator=(const LinkedList<T>& rhs);

    //construction and destruction
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

private:
    Node * head;
    Node * tail;

};

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;

}

template <typename T>
void LinkedList<T>::AddHead(const T &data) {

    Node * temp = new Node;
    temp->data = data;

    if (head == nullptr){
        tail = temp;
        head = temp;
    }
else{

    head->prev = temp;
    temp->prev = nullptr;
    temp->next = head;

    head = temp;
}

}

template <typename T>
void LinkedList<T>::AddTail(const T& data){
    Node * temp = new Node;
    temp->data = data;

    if (tail == nullptr){
        tail = temp;
        head = temp;
    }

    else{

    tail->next = temp;
    temp->next = nullptr;
    temp->prev = tail;

    tail = temp;
    }
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count){

    for (int i = count-1; i>-1; i--)
        AddHead(data[i]);
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count){
    for (unsigned int i = 0; i<count; i++)
        AddTail(data[i]);
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const{
    unsigned int amount = 0;
    if (head == nullptr)
        return 0;
    else {
        Node *temp = head;
        ++amount;
        while (temp != tail) {
            temp = temp->next;
            ++amount;
        }



        return amount;
    }
}

template <typename T>
void LinkedList<T>::PrintForward() const{
    if (head != nullptr){

    Node* temp = head;
    while (temp != tail){
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << tail->data << endl;
    }
}

template <typename T>
void LinkedList<T>::PrintReverse() const{
    if (tail!=nullptr){

    Node* temp = tail;
    while (temp != nullptr){
        cout << temp->data << endl;
        temp = temp->prev;
    }
    }
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const{
    return head;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const{
    return tail;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head(){
    return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail(){
    return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
    if (index >= NodeCount()){
        throw std::out_of_range("Index is out of range.");
    }

    Node* temp = head;
    for (unsigned int i = 0; i <= index; i++){
        temp = temp->next;
    }
    return temp;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index){
    if (index >= NodeCount()){
        throw std::out_of_range("Index is out of range.");
    }

    Node* temp = head;
    for (unsigned int i = 0; i <= index; i++){
        temp = temp->next;
    }
    return temp;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index){
    if (index >= NodeCount()){
        throw out_of_range("Index is out of range.");
    }

    Node* temp = head;
    for (unsigned int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const{
    if (index >= NodeCount()){
        throw out_of_range("Index is out of range.");
    }

    Node* temp = head;
    for (unsigned int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data){
    Node* temp = head;
    for (unsigned int i=0; i<NodeCount();i++){
        if (temp->data == data)
            return temp;
        else
            temp = temp->next;
    }
    return nullptr;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const{
    Node* temp = head;
    for (unsigned int i=0; i<NodeCount();i++){
        if (temp->data == data)
            return temp;
        else
            temp = temp->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const{
    Node* temp = head;
    while (temp != nullptr){
            if (temp->data == value) {
                outData.push_back(temp);
            }
            temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::InsertAfter(Node *node, const T &data) {
    Node* temp = head;
    unsigned int i;
    for (i=0; i<NodeCount(); i++){
        if (temp->data == node->data){
            break;
        }
        else {
            temp = temp->next;
        }
    }

    Node* a = temp;
    a=temp->next;

    Node* hello = new Node;
    hello->data = data;

    hello->prev = temp;
    temp->next = hello;

    hello->next = a;
    a->prev = hello;
}

template <typename T>
void LinkedList<T>::InsertBefore(Node *node, const T &data) {
    Node* temp = head;
    unsigned int i;
    for (i=0; i<NodeCount(); i++){
        if (temp->data == node->data){
            break;
        }
        else {
            temp = temp->next;
        }
    }

    Node* a = temp;
    a=temp->prev;

    Node* hello = new Node;
    hello->data = data;

    hello->next = temp;
    temp->prev = hello;

    hello->prev = a;
    a->next = hello;


}

template <typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index) {
    Node* hello = new Node;
    hello->data = data;

    Node* welp = head;

    if (index == 0){
        head = hello;

        hello->next = welp;
        welp->prev = hello;
    }
    else if(index == NodeCount()){
        welp = tail;
        tail = hello;
        welp->next = hello;
        hello->prev = welp;
        hello->next = nullptr;
    }
    else
        {
        for (unsigned int i=0; i<index; i++){
            welp = welp->next;
        }

        Node* prior = welp->prev;

        prior->next = hello;
        hello->prev = prior;

        hello->next = welp;
        welp->prev = hello;
    }
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &list) const {
    bool same = false;
    Node* temp = head;
    Node* bro = list.head;
    for (unsigned int i = 0; i<NodeCount(); i++){
        if (temp->data != bro->data){
            break;
        }
        else {
            temp = temp->next;
            bro = bro->next;
        }
    }
    same = true;
    return same;
}

template <typename T>
bool LinkedList<T>::RemoveHead() {
    bool deletion = false;

            if (NodeCount() == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                deletion = true;
            } else if (NodeCount() > 1){
                Node *temp = head;

                head = head->next;
                head->prev = nullptr;

                delete temp;
                deletion = true;
            }



    return deletion;
}

template <typename T>
bool LinkedList<T>::RemoveTail() {
    bool deletion = false;
        if (NodeCount() == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            deletion = true;
        } else if (NodeCount() > 1) {
            Node *temp = tail;

            tail = tail->prev;
            tail->next = nullptr;

            delete temp;
            deletion = true;

    }

    return deletion;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    bool deletion = false;

    if (index >= NodeCount()){
        return deletion;
    }

    Node* temp = head;

    for (unsigned int i=0; i<index; i++){
        temp = temp->next;
    }
    if (index == 0){
        Node* c = temp->next;
        c->prev = nullptr;
        head = c;
        delete temp;
        if (head->data == c->data){
            deletion = true;
        }
    }
    else if (index == NodeCount()-1){
        Node* d = temp->prev;
        d->next = nullptr;
        tail = d;
        delete temp;
        if (tail->data == d->data){
            deletion = true;
        }
    }
    else {

        Node *a = temp->prev;
        Node *b = temp->next;

        a->next = b;
        b->prev = a;

        delete temp;

        Node *test = head;
        for (unsigned int i = 0; i < index; i++) {
            test = test->next;
        }
        if (test->data == b->data) {
            deletion = true;
        }
    }

    return deletion;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data){
    Node* temp = head;
    Node* assist = head;
    unsigned int counter = 0;
    while (temp!=nullptr){
        if (temp->data == data){
            Node* dell = temp;
            temp = temp->next;
            assist = assist->prev;
            assist->next = temp;
            temp->prev = assist;
            assist = temp;
            delete dell;
            ++counter;
        }
        else{
            temp = temp->next;
            assist = assist->next;
        }
    }
    return counter;

}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node *node) const {
    if (tail == node){
        cout << node->data << endl;
        return;
    }
    else{
        cout << node->data << endl;
        node = node->next;
        PrintForwardRecursive(node);
    }
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const LinkedList<T>::Node *node) const {
    if (head == node){
        cout << node->data << endl;
        return;
    }
    else{
        cout << node->data << endl;
        node = node->prev;
        PrintReverseRecursive(node);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list){
    tail = nullptr;
    Node * temp = list.head;
    for (unsigned int i =0; i< list.NodeCount(); i++){
        AddTail(temp->data);
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T>&LinkedList<T>::operator=(const LinkedList<T>& list){

    Clear();
    tail = nullptr;
    Node * temp = list.head;
    for (unsigned int i =0; i< list.NodeCount(); i++){
        AddTail(temp->data);
        temp = temp->next;
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Clear();
}

template <typename T>
void LinkedList<T>::Clear(){
    Node * temp = head;
    Node * hello = head;
    while (temp != nullptr){
        temp = temp->next;
        delete hello;
        hello = temp;
    }
    delete temp;
    delete hello;
    head = nullptr;
    tail = nullptr;

}
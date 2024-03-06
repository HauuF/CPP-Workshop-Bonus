#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>* previous;

    Node() {
        value = NULL;
        next = nullptr;
        previous = nullptr;
    }

    Node(T value) {
        this->value = value;
        next = nullptr;
        previous = nullptr;
    }
};

template <typename T>
struct LinkedList {
    
    Node<T>* head;
    int size;

    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void add(T& value) {

        Node<T>* newNode = new Node<T>(value);

        

        
    }

    bool remove(int index) {
        
        Node <T>* searchNode = getNode(index);
       
        
       
        return true;
    }

    T get(int index) {
        
        Node<T>* searchNode = getNode(index);

        if (searchNode == nullptr) {
            return NULL;
        }
        
        return searchNode->value;
        
    }

    Node<T>* getNode(int index) {
        
        if (index < 0 || index >= size) {
            return nullptr;
        }

        Node<T>* currentNode = head;
        int currentIndex = 0;
        
        while (currentIndex < index) {
            currentNode = currentNode->next;
            currentIndex++;
        }

        return currentNode;
    }

    Node<T>* getLastNode() {
        
        Node<T>* currentNode = head;

        if (currentNode == nullptr) {
            return nullptr;
        }

        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }

        return currentNode;
    }

    T* getAddressOf(int index) {
       
        Node<T>* searchNode = getNode(index);
        if (searchNode == nullptr) {
            return nullptr;
        }
        return &searchNode->value;
    }

    T set(int index, T& newValue) {
       
        Node<T>* searchNode = getNode(index);
        if (searchNode == nullptr) {
            return NULL;
        }

        T oldValue = searchNode->value;
        searchNode->value = newValue;

        return oldValue;
    }

    bool contains(T& value) {
        
        Node<T>* currentNode = head;

        while (currentNode != nullptr) {
            if (currentNode->value == value) {
                return true;
            }
            currentNode = currentNode->next;
        }

        return false;

    }

    void clear() {

        Node<T>* currentNode = head;

        

        size = -1;
        
    }

    LinkedList<T> copy() {
        LinkedList<T> newList;

        Node<T>* currentNode = head;

        while (currentNode != nullptr) {
            newList.add(currentNode->value);
            currentNode = currentNode->next;
        }

        return newList;
    }

    string toString() {
        string result = "[";
        
        Node<T>* currentNode = head;

        while (currentNode != nullptr) {
            result += currentNode->value;
            if (currentNode->next != nullptr) {
                result += ", ";
            }
            currentNode = currentNode->next;
        }

        result += "]";

        return result;
    }

    bool operator==(LinkedList<T>& other) {
       
        if (size != other.size) {
            return false;
        }

        Node<T>* currentNode = head;
        Node<T>* otherCurrentNode = other.head;

        while (currentNode != nullptr) {
            if (currentNode->value != otherCurrentNode->value) {
                return false;
            }
            currentNode = currentNode->next;
            otherCurrentNode = otherCurrentNode->next;
        }

        return true;
    }
};

#endif /* MYHEADER_H */
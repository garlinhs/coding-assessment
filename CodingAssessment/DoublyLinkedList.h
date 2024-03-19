#pragma once
#include <iostream>

// Node class representing a node in the doubly linked list
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    // Constructor
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class representing a doubly linked list
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to add a node to the end of the list
    void addNode(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Method to remove a node from the list
    void removeNode(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                }
                else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                }
                else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                size--;
                return;
            }
            current = current->next;
        }
    }

    // Method to print the list forward
    void printForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Method to print the list backward
    void printBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Method to get the size of the list
    int getSize() {
        return size;
    }
};
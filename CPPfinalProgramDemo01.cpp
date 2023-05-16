// CPPfinalProgramDemo01.cpp
// dH 4/10/23 
// modified by RV 05/15/2023

// Understand pointers and linked lists.
// Create a linked list of animals

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string m_id;
    string m_name;
    int m_age;

public:
    // Default constructor
    Animal() {}

    // Constructor with parameters
    Animal(string _id, string _name, int _age) {
        m_id = _id;
        m_name = _name;
        m_age = _age;
    }

    // Getter functions
    string get_id() const { return m_id; }
    string get_name() const { return m_name; }
    int get_age() const { return m_age; }

    // Setter functions
    void set_id(string _id) { m_id = _id; }
    void set_name(string _name) { m_name = _name; }
    void set_age(int _age) { m_age = _age; }
};

class Node {
public:
    int value;
    Node* next;
};

class AnimalNode {
public:
    int anInt;
    Animal* animalObj;
    AnimalNode* next;
};

void printList(Node* head) {
    // Loop through the linked list and print the values
    while (head != nullptr) {
        cout << head->value << endl;
        head = head->next;
    }
}

void printAnimalList(AnimalNode* head) {
    cout << "\n\n";
    // Loop through the linked list and print the animal info
    while (head != nullptr) {
        cout << "\n " << head->anInt << " " << head->animalObj->get_name() << " " << head->animalObj->get_age() << " " << head->animalObj->get_id() << endl;
        head = head->next;
    }
    cout << "\n\n";
}

void addNode(Node* &current, int value) {
    // Add a new node to the linked list
    current->next = new Node();
    current = current->next;
    current->value = value;
    current->next = nullptr;
}

void addAnimalNode(AnimalNode* &current, int anInt, Animal* animalObj) {
    // Add a new animal node to the linked list
    current->next = new AnimalNode();
    current = current->next;
    current->anInt = anInt;
    current->animalObj = animalObj;
    current->next = nullptr;
}

void deleteList(Node* head) {
    // Delete the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void deleteAnimalList(AnimalNode* head) {
    // Delete the linked list
    AnimalNode* current = head;
    while (current != nullptr) {
        AnimalNode* next = current->next;
        delete current->animalObj;
        delete current;
        current = next;
    }
}

int main() {

    // Create a linked list of integers

    // Create the head node
    Node* head = new Node();
    head->value = 1;
    head->next = nullptr;

    // Add two more nodes to the list
    Node* current = head;
    for (int i = 2; i <= 3; i++) {
        addNode(current, i);
   
    // Print the list
    printList(head);

    // Delete the list
    deleteList(head);

    // Create a linked list of Animal objects

    // Create the head node
    AnimalNode* animalHead = new AnimalNode();
    Animal* animal1 = new Animal("1", "Lion", 5);
    animalHead->anInt = 1;
    animalHead->animalObj = animal1;
    animalHead->next = nullptr;

    // Add two more animal nodes to the list
    AnimalNode* currentAnimal = animalHead;
    Animal* animal2 = new Animal("2", "Giraffe", 3);
    addAnimalNode(currentAnimal, 2, animal2);
    Animal* animal3 = new Animal("3", "Elephant", 7);
    addAnimalNode(currentAnimal, 3, animal3);

    // Print the animal list
    printAnimalList(animalHead);

    // Delete the animal list
    deleteAnimalList(animalHead);

    return 0;
}
}

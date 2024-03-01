#include "libs/LinkedList.h"
#include "libs/List.h"

#include <iostream>

using namespace std;

void testAddLinkedList();
void testRemoveLinkedListWithMultipleElements();
void testRemoveLinkedListWithNoneElementsShouldReturnFalse();
void testRemoveLinkedListFirstElementShouldReturnTrue();
void testClearIsDeletingAllElements();
void printList(List<int> list);
void printLinkedList(LinkedList<int> list);

int main() {
    
    testAddLinkedList();
    testRemoveLinkedListWithMultipleElements();
    testRemoveLinkedListWithNoneElementsShouldReturnFalse();
    testRemoveLinkedListFirstElementShouldReturnTrue();
    testClearIsDeletingAllElements();

    return 0;
}

void printList(List<int> list) {
    cout << list.toString() << endl;
}

void printLinkedList(LinkedList<int> list) {
    cout << list.toString() << endl;
}

List<int> createList() {
    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.add(i);
    }
    return list;
}

LinkedList<int> createLinkedList() {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.add(i);
    }
    return list;
}

bool listsAreEqual(List<int> list, LinkedList<int> linkedList) {
    Node<int>* currentNode = linkedList.head;
    for (int i = 0; i < list.size; i++) {
        if (currentNode->value != list.get(i)) {
            return false;
        }
        currentNode = currentNode->next;
    }
    return true;
}


void testAddLinkedList() {

    cout << "TESTING ADD METHOD" << endl;
    cout << "Adding 10 elements to the list" << endl;

    LinkedList<int> list = createLinkedList();
    List<int> expectedList = createList();
    

    Node<int>* currentNode = list.head;
    int i = 0;

    bool firstNodePreviousIsNull = currentNode->previous == nullptr;
    
    if(!firstNodePreviousIsNull) {
        cout << "Test failed. First node previous should be null" << endl;
    }

    bool lastNodeNextIsNull = list.getLastNode()->next == nullptr;

    if(!lastNodeNextIsNull) {
        cout << "Test failed. Last node next should be null" << endl;
    }

    if(!listsAreEqual(expectedList, list) || list.size != 10) {
        cout << "Test failed. Lists are different" << endl;
        cout << "Expected list: ";
        printList(expectedList);
        cout << "Current list: ";
        printLinkedList(list);
        
    } else {
        cout << "LinkedList add method test passed" << endl;
    }

    cout << endl;

}

void testRemoveLinkedListWithMultipleElements() {
    
    cout << "TESTING REMOVE METHOD" << endl;
    cout << "Adding 10 elements to the list" << endl;
    LinkedList<int> list = createLinkedList();
    List<int> expectedList = createList();

    cout << "Removing element with index 5" << endl;
    bool result = list.remove(5);
    bool expectedResult = expectedList.remove(5);

    if(!listsAreEqual(expectedList, list)) {
        cout << "Test failed. Lists are different" << endl;
        cout << "Expected list: ";
        printList(expectedList);
        cout << "Current list: ";
        printLinkedList(list);
        
    } 

    if (result != expectedResult) {
        cout << "Test failed. Expected " << expectedResult << " but got " << result << endl;
    }

    if (list.size != expectedList.size) {
        cout << "Test failed. Expected size should be " << expectedList.size << " but got " << list.size << endl;
    }

    else {
        cout << "LinkedList remove method test passed" << endl;
    }

    cout << endl;

}

void testRemoveLinkedListWithNoneElementsShouldReturnFalse() {
    
    cout << "TESTING REMOVE METHOD WITH INVALID INDEX" << endl;
    
    LinkedList<int> list;

    cout << "Removing element with index 5 in an empty list" << endl;
    bool result = list.remove(5);
    bool expectedResult = false;

    if(result != expectedResult) {
        cout << "Test failed. Expected false" << endl;
    } else {
        cout << "LinkedList remove method test passed" << endl;
    }

    cout << "Removing element with index -1 in an empty list" << endl;
    bool result2 = list.remove(-1);
    bool expectedResult2 = false;

    if(result2 != expectedResult2 ) {
        cout << "Test failed. Expected false" << endl;
    }
    
    if (list.size != 0) {
        cout << "Test failed. Expected size should be 0 but was "  << list.size << endl;
    }

    if (list.head != nullptr) {
        
        cout << "Test failed. Expected head should be nullptr" << endl;
    } else {
        cout << "LinkedList remove method test passed" << endl;
    }

    cout << endl;

}

void testRemoveLinkedListFirstElementShouldReturnTrue() {
    
    cout << "TESTING REMOVE METHOD " << endl;
    
    LinkedList<int> list;
    cout << "Adding 1 element to the list" << endl;
    int element = 1;
    list.add(element);

    cout << "Removing element with index 0 in an list with one value" << endl;
    bool result = list.remove(0);
    bool expectedResult = true;

    if(result != expectedResult) {
        cout << "Test failed. Expected result should be false" << endl;
    } 
    
    if (list.size != 0) {
        cout << "Test failed. Expected size should be 0 but was "  << list.size << endl;
    }

    if (list.head != nullptr) {
        
        cout << "Test failed. Expected head should be nullptr" << endl;
    }

    else {
        cout << "LinkedList remove method test passed" << endl;
    }

    cout << endl;

}

void testClearIsDeletingAllElements() {
    
    cout << "TESTING CLEAR METHOD " << endl;
    
    LinkedList<int> list;
    cout << "Adding 10 elements to the list" << endl;
    for (int i = 0; i < 10; i++) {
        list.add(i);
    }

    cout << "Clearing the list" << endl;
    list.clear();

    if (list.size != 0) {
        cout << "Test failed. Expected size should be 0 but was "  << list.size << endl;
    }

    if (list.head != nullptr) {
        
        cout << "Test failed. Expected head should be nullptr" << endl;
    }

    else {
        cout << "LinkedList clear method test passed" << endl;
    }

    cout << endl;

}










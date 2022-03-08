//Variation A subvariation 1 of my unnamed data structure
//This variation's keywords are : "non-switching", "shifting"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>


/*
One of the more basic version of this data structure
This structure uses generics, and may hold objects of any type, therefore, when instantiating a structure
you must declare which type the data will be.
NOTE: The amount of elements declared constitutes the size of the structure. After declaration
this size can only stay the same or decrease. You cannot add a new element/node. Although, you
can modify an existing one.
When an instance of this structure with all of the elements, each element will be contained in
a node. A node contains a data value, which holds an element, an integer representing its position in the structure,
and a list pointing to all of the succeeding nodes in the order that they are at that moment in time.
A node can access every succeeding node's data, but cannot alter it or use it do switch the current pointer
to a different node.
The initial order of the nodes is the same as the order of the elements declared during instantiation
A node contains a utility function to return the element and position.
It also has a function to access the succeding nodes data, but does not return the node object itself.
In this data structure the current node is always the head node.
Further, at any moment in the data structure, there is only one usable node.
When first initialized, the data structure's node holds the first element

The data structure has a few functions:
1. returning the node/its data in the current order
2. traversing to a specified node
3. deleting current node
4. succeed node (deletion aswell)
4. purging current node

Traversal function
takes an element or index as parameter and "traverses" from the current node to the new node
however, the nodes traversed inbetween to get to the target node are inaccessible to the user, only the target is.
once arrived at target node, that node now becomes the current node, as well as the head of the structure.
it is now located at index 0.
The order of the nodes changes every time a traversal function is called

the target node becomes the head, or top of the order, taking with it all nodes that previously succeeded it.
ex:
[5, 4, 3, 2, 1]
traverse(3)
[3, 2, 1, 5, 4]

deleting current node
deletes current node, current node becomes node next in order

succeed current node
deletes the current node, sets current node as the node that succeeded in the original order during init
the new current node takes with all of its succeeding nodes in the CURRENT order
ex //idk about this one

purge current node
removes current node as well as all of the nodes that succeeded it in the original order
*/

using namespace std;



template <typename U>
class Node {
private:
    int position;
    vector<U> current_succession;
    vector<U> original_succession;
    template <typename> friend class DataStructure;
public:
    U element;
    int getPosition() {return position;}
    vector<U> curr_succession() {return current_succession;}
    vector<U> orig_succession() {return original_succession;}

    Node(U element) {
        this->element = element;
    }
};

template<typename T>
class DataStructure {
public:
    vector<T> original_order;
    vector<Node<T>*> order;
    Node<T>* head;

    DataStructure(vector<Node<T>*> elements) {
        int num_elements = elements.size();
        for (int i = 0; i < num_elements; i++) {
            Node<T>* node = elements[i];
            node->position = i;
            original_order.push_back(node->element);
            order.push_back(node);
        }
        head = order[0];

    }

    void printOrder() {
        for (Node<T>* i : order) {
            cout << i->element << " : " << i->position << " \n";
        }
    }

    Node<T> node(int index) {
        return *order[index];
    }
    void traverse(int index) {
        for (int i = 0; i < index; i++) {
            Node<T>* temp = head;
            order.erase(order.begin()+0);
            order.push_back(temp);
            head = order[0];
        }

    }

    void delete_node() {
        order.erase(order.begin());
    }

    void purge() {
        int head_pos = head->position;
        vector<Node<T>*> temp;
        int index = 0;
         for (Node<T>* i : order) {
             if(i->position < head_pos) {
                 temp.push_back(i);
             }
         }
         order = temp;
    }

    vector<T> current_succession(Node<T>* node) {
        if (node->current_succession.size() != 0)
            return node->curr_succession();
        bool go = false;
        for (int i = 0; i < order.size(); i++) {
            if (order[i] == node || go) {
                go = true;
                node->current_succession.push_back(order[i]->element);
            }
        }
        return node->current_succession;
    }


};

int main() {
    Node<int>* node1 = new Node(5);
    Node<int>* node2 = new Node(4);
    Node<int>* node3 = new Node(3);
    Node<int>* node4 = new Node(2);
    Node<int>* node5 = new Node(1);
    vector<Node<int>*> nodes;
    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    nodes.push_back(node5);

    DataStructure<int>* ds = new DataStructure(nodes);

    ds->traverse(2);


    vector<int> node_succession = ds->current_succession(node2);

    for (int i : node_succession) {
        cout << i << " ";
    }
    return 0;
}
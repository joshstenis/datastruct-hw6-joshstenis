#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Converts a string number into an integer -- (ex. "-140" == -140)
 * @param str The string number
 */
int strToInt(string str) {
    int val = 0;
    for(int i=0 ;i < str.length(); i++) {
        if(str[i] != '-')
            val += pow(10, str.length()-i) * (str[i] - 48);
    } if(str[0] == '-') val *= -1;
    
    return val/10;
}

class Node {

        int key;
    public:

        Node() : key(NULL) {}

        Node(int k) : key(k) {}

        /**
         * Sets key value
         * @param k new key value
         */
        void setKey(int k) {
            key = k;
        }

        /**
         * Returns key value
         * @return the key
         */
        int getKey() {
            return key;
        }
};

/**
 * Places key onto heap
 * @param heap the address of the heap
 * @param k the key
 * @return exit code
 */
int insert(vector<Node*> &heap, int k) {
    bool found = false;
    for(int i=0; i < heap.size(); i++) {
        if(heap[i]->getKey() == k) {
            found = true;
            break;
        }
    }
    
    if(found) return -1;
    else {
        Node* n = new Node(k);
        heap.push_back(n);
        return 0;
    }
}

/**
 * Enumerates the heap
 * @param heap the heap
 */
void enumerate(vector<Node*> &heap) {
    cout << heap[0]->getKey();

    for(int i=1; i < heap.size(); i++) {
        cout << " " << heap[i]->getKey();
    }
}

/**
 * Removes the root node of heap
 * @param heap the heap
 * @return exit code
 */
int removeRoot(vector<Node*> &heap) {
    if(heap[0]->getKey() == NULL) return -1;
    else {
        heap.erase(heap.begin());
        return 0;
    }
}

/**
 * Creates a heap
 * @param keys a vector of initial keys
 * @return the heap
 */
vector<Node*> createHeap(vector<int> keys) {
    vector<Node*> h;

    for(int i=0; i < keys.size(); i++) {
        Node* n = new Node(keys[i]);
        h.push_back(n);
    } return h;
}

int main() {
    string val;
    int op, key;
    vector<int> init;

    while(!cin.fail()) {                        // Takes input for initial tree
        cin >> val;
        if(val == "s") break;
        init.push_back(strToInt(val));
    }

    cin.ignore(1, '\n');
    cin >> op;

    cin.ignore(1, '\n');
    cin >> key;

    vector<Node*> heap = createHeap(init);

    switch(op) {
        case 0:
        {
            enumerate(heap);
        } break;

        case 1:
        {
            if(insert(heap, key) == -1) cout << -1;
            else enumerate(heap);
        } break;

        case 2:
        {
            if(removeRoot(heap) == -1) cout << -1;
            else enumerate(heap);
        } break;

        default: break;
    }
}
#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs.root;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> rhs)
{
    swap(rhs);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& rhs)
{
    std::swap(root, rhs.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{

    //if tree is empty, make the node the root
    if(isEmpty()){
        Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
        newNode->key = key;
        newNode->data = item;
        root = newNode;
        return true;
    }
    //if tree not empty, ind appropriate spot
    else{
        //make helper nodes and find the nearest spot
        Node<KeyType, ItemType>* searchNode = root;
        Node<KeyType, ItemType>* parentNode = 0;
        search(key, searchNode, parentNode);

        //if node exist, return false
        if(searchNode->key == key){
            return false;
        }
        else{
            
            //create new node 
            Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
            newNode->key = key;
            newNode->data = item;

            //insert node
            if(key < searchNode->key){
                searchNode->left = newNode;
            }
            else{
                searchNode->right = newNode;
            }

            return true;
        }   
    }
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    //if empty, return false
    if (isEmpty())
        return false; 


    //find node and its parent
    Node<KeyType, ItemType>* searchNode = root;
    Node<KeyType, ItemType>* parentNode = 0;
    search(key, searchNode, parentNode);
    bool childSide;

    //if key does not exist, return 0
    if(key != searchNode->key){
        return false;
    }

    else{

        //if node is not the root of the entire tree, go here
        if(!(parentNode == 0)){
            
            
            if(parentNode->right == searchNode){
                childSide = 1; 
            }
            else{
                childSide = 0;
            }
            

            //if node has no children
            if((searchNode->right == 0) && (searchNode->left == 0)){
                if(childSide){
                    parentNode->right = 0;
                }
                else{
                    parentNode->left = 0;
                }
            }
            //if node has only a right child
            else if(!(searchNode->right == 0) && (searchNode->left == 0)){
                if(childSide){
                    parentNode->right = searchNode->right;
                }
                else{
                    parentNode->left = searchNode->right;
                }
            }
            //if node has only a left child
            else if((searchNode->right == 0) && !(searchNode->left == 0)){
                if(childSide){
                    parentNode->right = searchNode->left;
                }
                else{
                    parentNode->left = searchNode->left;
                    
                }   

            }
            else{
                Node<KeyType, ItemType>* in;
                Node<KeyType, ItemType>* in_parent;
                inorder(searchNode, in, in_parent);
                
                
                if (in_parent == searchNode){
                    if(childSide){
                        parentNode->right = in;
                    }
                    else{
                        parentNode->left = in;
                    } 
                }
                else{
                    
                    in_parent->left = in->right;

                    if(childSide){
                        in->left = searchNode->left;
                        in->right = searchNode->right;
                        parentNode->right = in;
                    }
                    else{
                        in->left = searchNode->left;
                        in->right = searchNode->right;
                        parentNode->left = in;
                    } 
                }
            }
        }
        //if the slected node is a the root for the entire tree, but it has children
        else if(!(searchNode->right == 0) || !(searchNode->left == 0)){

            
            //if node has a right child
            if(!(searchNode->right == 0) && (searchNode->left == 0)){
                root = searchNode->right;
            }
            //if node has a left child
            else if((searchNode->right == 0) && !(searchNode->left == 0)){
                root = searchNode->left; 
            }
            else{
                Node<KeyType, ItemType>* in;
                Node<KeyType, ItemType>* in_parent;
                inorder(searchNode, in, in_parent);

                if (in_parent == searchNode){
                    root = in;
                    root->left = searchNode->left;
                }
                else{
                    
                    in_parent->left = in->right;

                  
                    in->left = searchNode->left;
                    in->right = searchNode->right;
                    root = in;
                   
                }
            }
        }
        //if the selected node is the only node in the tree
        else{
            destroy();
        }

        return true;
    }
    
    
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    
    in = curr;
    parent = in;
    in = in->right;

    while(true){
        //if a both children exists go left
        if((in->left != 0)){
            parent = in;
            in = in->left;
        }
        //if not more children, stop
        else{
          break;  
        }
    }
    

}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values
}

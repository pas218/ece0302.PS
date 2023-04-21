#include "Database.hpp"

template <typename T>
Database<T>::Database() {
    entries = 0;
}

template <typename T>
bool Database<T>::isEmpty() {
    return entries == 0;
}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() {
    return entries;
}

template <typename T>
bool Database<T>::add(std::string key1, std::string key2, const T& item) {
    
    //get the new position of new item
    std::size_t position = items.getLength();

    //make sure the key does not previously exist
    for(std::size_t i = 0; i < keyPairs.getLength(); i++){
        if((keyPairs.getEntry(i).key1 == key1) || (keyPairs.getEntry(i).key1 == key2)){
            return 0;
        }
        if((keyPairs.getEntry(i).key1 == key2) || (keyPairs.getEntry(i).key2 == key2)){
            return 0;
        }
    }

    //add key to the key list
    itemStruct keyPair; keyPair.key1 = key1; keyPair.key2 = key2;
    keyPairs.insert(keyPairs.getLength(), keyPair);

    //add item to item list and trees
    items.insert(position, item);
    treeKey1.insert(key1, position);
    treeKey2.insert(key2, position);

    entries++;
    return 1;

}

template <typename T>
bool Database<T>::remove(std::string key) {
    
    //helepr vars
    bool found;
    std::size_t position;

    //check if key refers to tree 1
    found = treeKey1.retrieve(key, position);

    //if key does refer to tree 1, keep going
    if(found){

        //remove key from tree
        treeKey1.remove(key);
        
        //find the pair of the key
        for (std::size_t i = 0; i < keyPairs.getLength(); i++){
            if(keyPairs.getEntry(i).key1 == key){
                key = keyPairs.getEntry(i).key2;
                break;
            }
        }

        //remove the key from the other tree
        treeKey2.remove(key);

        //remove the key from the key list
        for(std::size_t i = 0; i < keyPairs.getLength(); i++){
            if((keyPairs.getEntry(i).key1 == key) || (keyPairs.getEntry(i).key1 == key)){
                keyPairs.remove(i);
            }
            if((keyPairs.getEntry(i).key1 == key) || (keyPairs.getEntry(i).key2 == key)){
                keyPairs.remove(i);
            }
        }

        entries--;
        return 1;
    }
    else{

        //same exact idea as in the other case, just start with tree key 2
        found = treeKey2.retrieve(key, position);
        
        if(found){

            treeKey2.remove(key);
        
            for (std::size_t i = 0; i < keyPairs.getLength(); i++){
                if(keyPairs.getEntry(i).key2 == key){
                    key = keyPairs.getEntry(i).key1;
                    break;
                }
            }
            treeKey1.remove(key);

            for(std::size_t i = 0; i < keyPairs.getLength(); i++){
                if((keyPairs.getEntry(i).key1 == key) || (keyPairs.getEntry(i).key1 == key)){
                    keyPairs.remove(i);
                }
                if((keyPairs.getEntry(i).key1 == key) || (keyPairs.getEntry(i).key2 == key)){
                    keyPairs.remove(i);
                }
            }

            entries--;
            return 1;
        }
        else{
            return 0;            
        }
        
    }


}

template <typename T>
void Database<T>::clear() {
    entries = 0;
    items.clear();
    treeKey1.destroy();
    treeKey2.destroy();
}

template <typename T>
T Database<T>::getValue(std::string key) {
    
    //helper vars
    bool found;
    std::size_t position;

    //assume key refers to tree 1
    found = treeKey1.retrieve(key, position);

    if(found){
        return items.getEntry(position);
    }

    //if does not refer to tree one, check if it is in tree 2, if not, return a dummy
    else{
        found = treeKey2.retrieve(key, position);
        
        if(found){
            return items.getEntry(position);
        }
        else{
            T dummy;
            return dummy;
        }
    }

}

template <typename T>
bool Database<T>::contains(std::string key) {
    
    //helper vars
    bool found;
    std::size_t position;

    //assume key refers to tree 1
    found = treeKey1.retrieve(key, position);

    if(found){
        return 1;
    }

    //if not in tree 1, assume it is in tree 2, if not, then false
    else{
        found = treeKey2.retrieve(key, position);
        
        if(found){
            return 1;
        }
        else{
            return 0;
        }
    }
}

#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //holder variable for later use
  int sizeQueue = queue.size();

  //in the case the heap is only one node
  if(sizeQueue == 1){
    //State<T> returnState;
    State<T> returnState = queue[0];
    queue.pop_back();
    return returnState;
  }

  //State<T> returnState;
  State<T> returnState = queue[0];

  //bring last element to front
  queue[0] = queue[sizeQueue - 1];
  queue.pop_back();
  sizeQueue--;

  //helper vars
  int locationHolder = 0;
  bool keepGoing = 1;
  bool sideSmaller;

  //loop to put node in right place
  while(keepGoing){
    
    //keep going if location holde is valid
    if((locationHolder < sizeQueue) && ((locationHolder*2+1)  < sizeQueue)){

      //start on the smaller side
      sideSmaller = (queue[locationHolder*2+1].getFCost() < queue[locationHolder*2+2].getFCost());

      //if left is smaller, start there
      if(sideSmaller){
        if(queue[locationHolder].getFCost() > queue[locationHolder*2+1].getFCost()){
          //swap nodes
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+1];
          queue[locationHolder*2+1] = swapHolder;
          locationHolder = locationHolder*2+1;
        }
        else if (queue[locationHolder].getFCost() > queue[locationHolder*2+2].getFCost()){
          //swap nodes
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+2];
          queue[locationHolder*2+2] = swapHolder;
          locationHolder = locationHolder*2+2;
        }
        else{
          keepGoing = 0;
        }
      }
      //if right is smaller, start there
      else{
        if (queue[locationHolder].getFCost() > queue[locationHolder*2+2].getFCost()){
          //swap nodes
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+2];
          queue[locationHolder*2+2] = swapHolder;
          locationHolder = locationHolder*2+2;
        }
        else if(queue[locationHolder].getFCost() > queue[locationHolder*2+1].getFCost()){
          //swap nodes
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+1];
          queue[locationHolder*2+1] = swapHolder;
          locationHolder = locationHolder*2+1;
        }
        else{
          keepGoing = 0;
        }
      }
    }
    else{
      keepGoing = 0;
    }
  }

  


  return returnState;
   
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //make new state
  State<T> newState(p, cost, heur);
  
  //add state to the end
  queue.push_back(newState);

  //helper vars
  int keepGoing = 1;
  int locationHolder = queue.size() - 1;

  //bubble loop if vector isnt only one distance long
  if(locationHolder != 0){

    while(keepGoing){
      
      //switch with parent if parent is larger
      if(queue[(locationHolder - 1)/2].getFCost() > newState.getFCost()){
        queue[locationHolder] = queue[(locationHolder - 1)/2];
        queue[(locationHolder - 1)/2] = newState;
        locationHolder = (locationHolder - 1)/2;
      }
      else{
        keepGoing = 0;
      }
    }
  }
}

template <typename T>
bool frontier_queue<T>::empty() {
  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //loop to find element
  for(int i = 0; i < queue.size(); i++){

    if(p == queue[i].getValue()){
      return 1;
    }
  }

  //if not element, return 0
  return 0;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {


  //helepr vars
  bool keepGoing = 1;
  int indexTracker = 0;
  int fCostHolder;
  int size = queue.size();

  //as long as conditions are valid
  while((indexTracker < size) && (keepGoing)){

    //only contiue if the current element has a larger path cost
    if(queue[indexTracker].getPathCost() > cost){

      //get f cost of the new node
      fCostHolder = (queue[indexTracker].getFCost() - queue[indexTracker].getPathCost()) + cost;

      if(indexTracker != 0){

        //if new node fits, replace
        if((fCostHolder >= queue[(indexTracker - 1)/2].getFCost()) 
        && (fCostHolder <= queue[indexTracker*2+1].getFCost()) 
        && (fCostHolder <= queue[indexTracker*2+2].getFCost())){
          State<T> replaceState(p, cost, fCostHolder - cost);
          queue[indexTracker] = replaceState;
          keepGoing = 0;
        }
      }
      else if ((size == 1) && (indexTracker == 0)){
         //if new node fits, replace
        State<T> replaceState(p, cost, fCostHolder - cost);
        queue.pop_back();
        queue.push_back(replaceState);
        keepGoing = 0;
      }
      else{
         //if new node fits, replace
        if((fCostHolder <= queue[indexTracker*2+1].getFCost()) 
        && (fCostHolder <= queue[indexTracker*2+2].getFCost())){
          State<T> replaceState(p, cost, fCostHolder - cost);
          queue[indexTracker] = replaceState;
          keepGoing = 0;
        }
      }
    }
    indexTracker++;
  }
}


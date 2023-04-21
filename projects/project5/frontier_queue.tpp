#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {


  int sizeQueue = queue.size();

  if(sizeQueue == 1){
    //State<T> returnState;
    State<T> returnState = queue[0];
    queue.pop_back();
    return returnState;
  }

  //State<T> returnState;
  State<T> returnState = queue[0];

  queue[0] = queue[sizeQueue - 1];
  queue.pop_back();
  sizeQueue--;

  int locationHolder = 0;
  bool keepGoing = 1;
  bool sideSmaller = 0;
  //State<T> swapHolder;

  while(keepGoing){
    
    if((locationHolder < sizeQueue) && ((locationHolder*2+1)  < sizeQueue)){

      sideSmaller = (queue[locationHolder*2+1].getFCost() < queue[locationHolder*2+2].getFCost());

      if(sideSmaller){
        if(queue[locationHolder].getFCost() > queue[locationHolder*2+1].getFCost()){
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+1];
          queue[locationHolder*2+1] = swapHolder;
          locationHolder = locationHolder*2+1;
        }
        else if (queue[locationHolder].getFCost() > queue[locationHolder*2+2].getFCost()){
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+2];
          queue[locationHolder*2+2] = swapHolder;
          locationHolder = locationHolder*2+2;
        }
        else{
          keepGoing = 0;
        }
      }
      else{
        if (queue[locationHolder].getFCost() > queue[locationHolder*2+2].getFCost()){
          State<T> swapHolder = queue[locationHolder];
          queue[locationHolder] = queue[locationHolder*2+2];
          queue[locationHolder*2+2] = swapHolder;
          locationHolder = locationHolder*2+2;
        }
        else if(queue[locationHolder].getFCost() > queue[locationHolder*2+1].getFCost()){
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

  


  //State<T> test;
  return returnState;
  //return queue[0];
   
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  State<T> newState(p, cost, heur);
  

  queue.push_back(newState);

  int keepGoing = 1;
  int locationHolder = queue.size() - 1;

  if(locationHolder != 0){

    while(keepGoing){
      
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
  //return 0;
  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  for(int i = 0; i < queue.size(); i++){

    if(p == queue[i].getValue()){
      return 1;
    }
  }

  return 0;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {


  
  bool keepGoing = 1;
  int indexTracker = 0;
  int fCostHolder;
  int size = queue.size();

  while((indexTracker < size) && (keepGoing)){

    if(queue[indexTracker].getPathCost() > cost){

      fCostHolder = (queue[indexTracker].getFCost() - queue[indexTracker].getPathCost()) + cost;

      if(indexTracker != 0){

        if((fCostHolder >= queue[(indexTracker - 1)/2].getFCost()) 
        && (fCostHolder <= queue[indexTracker*2+1].getFCost()) 
        && (fCostHolder <= queue[indexTracker*2+2].getFCost())){
          State<T> replaceState(p, cost, fCostHolder - cost);
          queue[indexTracker] = replaceState;
          keepGoing = 0;
        }
      }
      else if ((size == 1) && (indexTracker == 0)){
        State<T> replaceState(p, cost, fCostHolder - cost);
        queue.pop_back();
        queue.push_back(replaceState);
        keepGoing = 0;
      }
      else{
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


#include "adjacency_list_graph.hpp"

template <typename LabelType>
AdjacencyListGraph<LabelType>::AdjacencyListGraph() {numEdges = 0;}

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumVertices() const {return existingNodes.size();}

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumEdges() const {return numEdges;}
        
template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::add(LabelType start, LabelType end) {

    //check to see which nodes exist
    bool existStart = (existingNodes.count(start) > 0);
    bool existEnd = (existingNodes.count(end) > 0);

    //if both nodes dont exist, and they are not the first two nodes, then exit
    if ((!(existStart) && !(existEnd)) && !(getNumVertices() == 0)){
        return 0;
    }
    //cases for node/ edga adding
    else if ((!(existStart) && !(existEnd)) && (getNumVertices() == 0)){
        //insert new node
        existingNodes.insert(start);
        existingNodes.insert(end);
        std::set<LabelType> holder1;
        std::set<LabelType> holder2;
        holder1.insert(end);
        holder2.insert(start);
        listOfNodes.insert({{start, holder1}, {end, holder2}});
    }
    else if (!(existStart) && (existEnd)){
        //insert new node
        existingNodes.insert(start);
        std::set<LabelType> holder1;
        std::set<LabelType> holder2;
        holder2 = listOfNodes[end];
        holder1.insert(end);
        holder2.insert(start);
        listOfNodes[end] = holder2;
        listOfNodes.insert({{start, holder1}});
    }
    else if ((existStart) && !(existEnd)){
        //insert new node
        existingNodes.insert(end);
        std::set<LabelType> holder1;
        std::set<LabelType> holder2;
        holder1 = listOfNodes[start];
        holder1.insert(end);
        holder2.insert(start);
        listOfNodes[start] = holder1;
        listOfNodes.insert({{end, holder2}});
    }
    else {
        if(listOfNodes[start].count(end) > 0){
            return 0;
        }
        else{
            //insert new node
            std::set<LabelType> holder1;
            std::set<LabelType> holder2;
            holder1 = listOfNodes[start];
            holder2 = listOfNodes[end];
            holder1.insert(end);
            holder2.insert(start);
            listOfNodes[start] = holder1;
            listOfNodes[end] = holder2;
        }
        
    }

    numEdges++;
    return 1;
}   

template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::remove(LabelType start, LabelType end) {

    //check to make sure nodes exist
    bool existStart = (existingNodes.count(start) > 0);
    bool existEnd = (existingNodes.count(end) > 0);

    //if both nodes dont exist, exit
    if(!(existStart || existEnd)){
        return 0;
    }

    std::set<LabelType> helperSet;

    helperSet = listOfNodes[start];

    //helper vars
    bool found = 0; int location;

    
    if (helperSet.count(end) > 0){
        found = 1;
    }
        
    //erase pointer to each node, and delete node if it has no poiinters
    if(found){

        helperSet.erase(end);
        listOfNodes[start] = helperSet;

        if(helperSet.empty()){
            existingNodes.erase(start);
            listOfNodes.erase(start);
        }

        helperSet.clear();
        helperSet = listOfNodes[end];
        helperSet.erase(start);
        listOfNodes[end] = helperSet;
       
        if(helperSet.empty()){
            existingNodes.erase(end);
            listOfNodes.erase(end);
        }


        numEdges--;
        return 1;
    }

    else{
        return 0;
    }

}

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}
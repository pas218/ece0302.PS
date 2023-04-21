#include "adjacency_matrix_graph.hpp"

template <typename LabelType>
AdjacencyMatrixGraph<LabelType>::AdjacencyMatrixGraph() {numEdges = 0;}

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumVertices() const {return existingNodes.size();}

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumEdges() const {return numEdges;}
        
template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::add(LabelType start, LabelType end) {
    
    //check to see which nodes exist
    bool existStart = (nodeMatrix.count(start) > 0);
    bool existEnd = (nodeMatrix.count(end) > 0);

    //exit if nodes will be disconnected
    if ((!(existStart) && !(existEnd)) && !(getNumVertices() == 0)){
        return 0;
    }
    //add nodes
    else if ((!(existStart) && !(existEnd)) && (getNumVertices() == 0)){
        //insert new node
        existingNodes.push_back(start);
        existingNodes.push_back(end);
        nodeMatrix.insert({{start, "11"},{end, "11"}});
    }
    else if (!(existStart) && (existEnd)){
        //insert new node
        existingNodes.push_back(start);
        std::string holder1 = "";
        std::string holder2;

        for(int i = 0; i < existingNodes.size(); i++){
            if ((existingNodes[i] == end) || (existingNodes[i] == start)){
                holder1 += '1';
            }
            else{
                holder1 += '0';
            }
        }

        holder2 = nodeMatrix[end];
        holder2 += '1';
        nodeMatrix[end] = holder2;

        nodeMatrix.insert({start, holder1});


        
    }
    else if ((existStart) && !(existEnd)){
        //insert new node

        existingNodes.push_back(end);
        std::string holder1;
        std::string holder2 = "";

    

        for(int i = 0; i < existingNodes.size(); i++){
            if ((existingNodes[i] == end) || (existingNodes[i] == start)){
                holder2 += '1';
            }
            else{
                holder2 += '0';
            }
        }

        holder1 = nodeMatrix[start];
        holder1 += '1';
        nodeMatrix[start] = holder1;

        nodeMatrix.insert({end, holder2});
    }
    else {

            //insert new node
            std::string holder1;
            std::string holder2;
            holder1 = nodeMatrix[start];
            holder2 = nodeMatrix[end];

            for(int i = 0; i < existingNodes.size(); i++){
                if (existingNodes[i] == end){
                    if (holder1[i] == '1'){
                        return 0;
                    }
                    else{
                        holder1[i] = '1';
                    }
                }
            }

            for(int i = 0; i < existingNodes.size(); i++){
                if (existingNodes[i] == start){
                    if (holder2[i] == '1'){
                        return 0;
                    }
                    else{
                        holder2[i] = '1';
                    }
                }
            }

            nodeMatrix[start] = holder1;
            nodeMatrix[end] = holder2;
        

    }


    numEdges++;
    return 1;
}   

template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::remove(LabelType start, LabelType end) {
    
    //check to see wich nodes exist
    bool existStart = (nodeMatrix.count(start) > 0);
    bool existEnd = (nodeMatrix.count(end) > 0);
    
    //if either doesnt exsit, then exit
    if((!(existStart) && !(existEnd))){
        return 0;
    }
    else if(((existStart) && !(existEnd))){
        return 0;
    }
    else if((!(existStart) && (existEnd))){
        return 0;
    }

    
    //get rows of maatrix
    std::string holder1;
    std::string holder2;
    holder1 = nodeMatrix[start];
    holder2 = nodeMatrix[end];


    //get rid of marks for the removing nodes
    for(int i = 0; i < existingNodes.size(); i++){
        
        if (existingNodes[i] == end){
            if (holder1[i] == '1'){
                holder1[i] = '0';
            }
            
        }
    }

    //get rid of marks for the removing nodes
    for(int i = 0; i < existingNodes.size(); i++){
        if (existingNodes[i] == start){
            if (holder2[i] == '1'){
                holder2[i] = '0';
            }
        }
    }
    //upload new rows
    nodeMatrix[start] = holder1;
    nodeMatrix[end] = holder2;
        
    //see which nodes are disconnected
    bool startDisconnected = 1, endDisconnected = 1;

    //see which nodes are disconnected
    for(int i = 0; i < existingNodes.size(); i++){
        if ((holder1[i] == '1') && !(existingNodes[i] == start)){
            startDisconnected = 0;
        }
        if ((holder2[i] == '1') && !(existingNodes[i] == end)){
            endDisconnected = 0;
        }
    }

    //if disconnected, get rid of it
    if(startDisconnected){
        for(int i = 0; i < existingNodes.size(); i++){
            if (existingNodes[i] == start){
                existingNodes.erase(existingNodes.begin() + i);
                break;
            }
        }
        nodeMatrix.erase(start);
    }
    if(endDisconnected){
        for(int i = 0; i < existingNodes.size(); i++){
            if (existingNodes[i] == end){
                existingNodes.erase(existingNodes.begin() + i);
                break;
            }
        }
        nodeMatrix.erase(end);
    }

    numEdges--;
    return 1;
}

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}
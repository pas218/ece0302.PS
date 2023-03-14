#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{

	//**USING BUBBLE SORT

	//helper variable to exit loop if no swaps were made 
	bool madeSwap;
	//holder variable to help with swapping
	T holderVar;
	
	//start total bubble sort loop
	for (int i = 0; i < list.getLength(); i++){

		madeSwap = 0;

		//inner loop for swappng variables
		for (int j = 0; j < list.getLength() - 1; j++){
			
			if (list.getEntry(j) > list.getEntry(j+ 1)){
				
				//if the before element is greater than, swap two elements
				holderVar = list.getEntry(j);
				list.setEntry(j, list.getEntry(j + 1));
				list.setEntry(j + 1, holderVar);
				
				madeSwap = 1;

			}
		

		}

		//leave loop if no swaps were made
		if (madeSwap == 0){
			break;
		}
		

	}
	return list;
}

#endif

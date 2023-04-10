#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

bool isGoal(Image<Pixel>, intmax_t[2]);
bool getRedDotLocation(intmax_t[2], Image<Pixel>);
void writeGreenDot(intmax_t, intmax_t, Image<Pixel>&);
bool isValidSpot(intmax_t, intmax_t, Image<Pixel>);
Image<Pixel> changeRedDotLocationTo(intmax_t, intmax_t, Image<Pixel>);
int returnListOfState(Image<Pixel>, intmax_t[2], Image<Pixel>[4]);
bool scanForWrongColor(Image<Pixel>);


int main (int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }
  

  //make frontier queue
  Queue<Image<Pixel>, List<Image<Pixel>>> frontier;

  
  std::string input_file = argv[1];
  std::string output_file = argv[2];
  
  //see if files can be opened
  try{
    Image<Pixel> image = readFromFile(input_file);
    writeToFile(image, output_file);
  }catch(std::runtime_error e){
    std::cout << "Error " << e.what();
    return EXIT_FAILURE;
  }

  Image<Pixel> image = readFromFile(input_file);

  //holder class tp keep origianl image
  Image<Pixel> origImage = image;

  //variables that hold the width and height of the image
  intmax_t width = image.width();
  intmax_t height = image.height();

  //for passing coordinates through functions
  intmax_t coord[2];
  intmax_t coordCompare[2];

  //array of all explored variations
  Image<Pixel> explored[width*height];
  Image<Pixel> holder[4];

  //holder array to add to frontier
  int length;
  bool validDot;\
  bool validColor;
  intmax_t exploredLength = 0;

  //get states of initial conditions
  validColor =  scanForWrongColor(image);
  validDot = getRedDotLocation(coord, image);

  //check for some initial failures
  try{
    if(!validColor){
      throw(std::runtime_error("Incorrect Color"));
    }

    if(!validDot){
      throw(std::runtime_error("More than one red dot"));
    }

   }catch(std::runtime_error e){
        std::cout << "Error " << e.what();
        return EXIT_FAILURE;
      }
    

  //check if image fits initial condition
  if (isGoal(image, coord)){
    writeGreenDot(coord[0], coord[1], image);

    // Write solution image to file
    writeToFile(image, output_file);
    std::cout << "Solution Found";
    return EXIT_SUCCESS;
  }

  //add image to frontier
  frontier.enqueue(image);
  
  //helper variable
  bool inExplored = 0;

  while(1){
      if(frontier.isEmpty()){
        std::cout << "No Solution Found";
        return EXIT_SUCCESS;
      }

      image = frontier.peekFront();
      
      frontier.dequeue();
      getRedDotLocation(coord, image);

      if (isGoal(image, coord)){
        writeGreenDot(coord[0], coord[1], origImage);

        // Write solution image to file
        writeToFile(origImage, output_file);
        std::cout << "Solution Found";
        return EXIT_SUCCESS;
      }


      explored[exploredLength] = image;
      exploredLength++;
      
      //get possible states
      length = returnListOfState(image, coord, holder);

      //loop to verify next states
      for(int i = 0; i < length; i++){
        inExplored = 0;
        
        getRedDotLocation(coord, holder[i]);
        for (int j = 0; j < exploredLength; j++){

            //check if its in explored
            getRedDotLocation(coordCompare, explored[j]);
            if ((coord[0] == coordCompare[0]) && (coord[1] == coordCompare[1])){
              inExplored = 1;
            }

        }

        //check if its in frontier
        getRedDotLocation(coordCompare, frontier.peekFront());
        if ((coord[0] == coordCompare[0]) && (coord[1] == coordCompare[1])){
          inExplored = 1;
        }
        
        //if not in queue, add to frontier
        if (!inExplored){
          frontier.enqueue(holder[i]);
        }
      }
  }
  
}

bool isGoal(Image<Pixel> image, intmax_t coord[2]){

  //variables that hold the width and height of the image
  intmax_t width = image.width();
  intmax_t height = image.height();
  
  //check goal conditions
  if ((coord[0] == 0) || (coord[0] == height - 1) || (coord[1] == 0) || (coord[1] == width - 1))
  {
    return 1;
  }
  else{
    return 0;
  }
}

bool getRedDotLocation(intmax_t coord[2], Image<Pixel> image){

  //variables that hold the width and height of the image
  intmax_t width = image.width();
  intmax_t height = image.height();

  int numRed = 0;

  //scan for the red dot
  for (intmax_t i = 0; i < height; i++){
    for(intmax_t j = 0; j < width; j++){

      //see if red dot 
      if (image(i,j) == RED){
        coord[0] = i;
        coord[1] = j;
        numRed++;
      }
    }
  }
  //if there are mor than one reds, return 0
  if((numRed == 0) || (numRed > 1)){
    return 0;
  }
  else{
    return 1;
  }
}


void writeGreenDot(intmax_t i, intmax_t j, Image<Pixel>& image){image(i,j) = GREEN;}

bool isValidSpot(intmax_t i, intmax_t j, Image<Pixel> image){
  
  //check if spot is valid
  if(image(i,j) == WHITE){
    return 1;
  }
  else{
    return 0;
  }

}

Image<Pixel> changeRedDotLocationTo(intmax_t i, intmax_t j, Image<Pixel> image){

  //get red dot locations
  intmax_t coord[2];
  getRedDotLocation(coord, image);

  //switch old location with new location
  image(coord[0], coord[1]) = WHITE;
  image(i,j) = RED;

  return image;
}

int returnListOfState(Image<Pixel> image, intmax_t coord[2], Image<Pixel> holder[4]){

  //helper variables
  int num = 0;
  num = 0;
  int i = coord[0];
  int j = coord[1];

  //get all valid next positions
  if (isValidSpot(i - 1, j, image)){
    holder[num] = changeRedDotLocationTo(i - 1, j, image);
    num++;
  }
  if (isValidSpot(i + 1, j, image)){
    holder[num] = changeRedDotLocationTo(i + 1, j, image);
    num++;
  }
  if (isValidSpot(i, j - 1, image)){
    holder[num] = changeRedDotLocationTo(i, j- 1, image);
    num++;
  }
  if (isValidSpot(i, j + 1, image)){
    holder[num] = changeRedDotLocationTo(i, j + 1, image);
    num++;
  }
  return num;
}

bool scanForWrongColor(Image<Pixel> image){
  //variables that hold the width and height of the image
  intmax_t width = image.width();
  intmax_t height = image.height();

  int numRed = 0;

  //scan the image
  for (intmax_t i = 0; i < height; i++){
    for(intmax_t j = 0; j < width; j++){

      //see if pixel is valid
      if ((image(i,j) != RED) && (image(i,j) != BLACK) && (image(i,j) != WHITE)){
        return 0;
      }
    }
  }
  return 1;
}


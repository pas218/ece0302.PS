#include "bitset.hpp"



Bitset::Bitset()
{
    stringSize = 8;
    bitString = new int[stringSize];

    for (unsigned int i = 0; i < stringSize; i++)
    {
        bitString[i] = 0;
    }

    isValid = 1;
}

Bitset::Bitset(intmax_t size)
{
    if(size > 0){

        stringSize = size;
        bitString = new int[stringSize];

        for (unsigned int i = 0; i < stringSize; i++)
        {
            bitString[i] = 0;
        }

        isValid = 1;
    }
    else{
        isValid = 0;
    }

}

Bitset::Bitset(const std::string &value)
{
    stringSize = value.size();
    bitString = new int[stringSize];

    isValid = 1;
    for (unsigned int i = 0; i < stringSize; i++)
    {
        bitString[i] = int(value[i] - 48);

        if((int(value[i] - 48) != 1) && (int(value[i] - 48) != 0)){
            isValid = 0;
        }
    }

}

Bitset::~Bitset()
{
    delete[] bitString; 
}

intmax_t Bitset::size() const
{
    return stringSize;
}

bool Bitset::good() const
{
    return isValid;
}

void Bitset::set(intmax_t index)
{
    if((index < stringSize) && (index >= 0)){
        bitString[index] = 1;
        isValid = 1;
    }
    else{
        isValid = 0;
    }    
}   

void Bitset::reset(intmax_t index)
{
    if((index < stringSize) && (index >= 0)){
        bitString[index] = 0;
        isValid = 1;
    }
    else{
        isValid = 0;
    } 
}

void Bitset::toggle(intmax_t index)
{
    if((index < stringSize) && (index >= 0)){
        if(bitString[index] == 1){
            bitString[index] = 0;
            isValid = 1;
        }
        else if(bitString[index] == 0){
            bitString[index] = 1;
            isValid = 1;
        }
        else{
            isValid = 0;
        }
    }
    else{
        isValid = 0;
    } 
}

bool Bitset::test(intmax_t index)
{
    if((index < stringSize) && (index >= 0)){
        if(bitString[index] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        isValid = 0;
        return 0;
    }
}

std::string Bitset::asString() const
{
    std::string bitAsString = "";

    for (unsigned i = 0; i < stringSize; i++){
        bitAsString += bitString[i] + 48;
    }

    return bitAsString;
}

#include "bitset.hpp"

Bitset::Bitset()
{
    stringSize = 8;
    bitString = new int[stringSize];

    for (unsigned int i = 0; i < stringSize; i++)
    {
        bitString[i] = 0;
    }

    isValid = good();
}

Bitset::Bitset(intmax_t size)
{
    stringSize = size;
    bitString = new int[stringSize];

    for (unsigned int i = 0; i < stringSize; i++)
    {
        bitString[i] = 0;
    }

    isValid = good();
}

Bitset::Bitset(const std::string &value)
{
    stringSize = value.size();
    bitString = new int[stringSize];

    for (unsigned int i = 0; i < stringSize; i++)
    {
        bitString[i] = value[i];
    }

    isValid = good();
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
    for (unsigned int i = 0; i < stringSize; i++)
    {
        if (bitString[i] != '0' || bitString[i] != '1'){
            return 0;
        }
    }

    return 1;
}

void Bitset::set(intmax_t index)
{
    if((index <= stringSize - 1) && (index >= 0)){
        bitString[index] = '1';
    }
    else{
        isValid = 0;
    }    
}   

void Bitset::reset(intmax_t index)
{
    if((index <= stringSize - 1) && (index >= 0)){
        bitString[index] = '0';
    }
    else{
        isValid = 0;
    } 
}

void Bitset::toggle(intmax_t index)
{
    if((index <= stringSize - 1) && (index >= 0)){
        if(bitString[index] = '1'){
            bitString[index] = '0';
        }
        else if(bitString[index] = '0'){
            bitString[index] = '1';
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
    if((index <= stringSize - 1) && (index >= 0)){
        if(bitString[index] = '1'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

std::string Bitset::asString() const
{
    std::string bitAsString;

    for (unsigned i = stringSize; i >= 0; i--){
        bitAsString[i] = static_cast<char>(bitString[i]);
    }

    return bitAsString;
}

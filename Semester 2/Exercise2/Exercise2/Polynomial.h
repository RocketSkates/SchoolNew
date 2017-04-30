#pragma once

#include <iostream>
#include "Monomial.h"

class Polynomial
{
public:
    Polynomial();
    ~Polynomial();
    
    friend std::ostream& operator << (std::ostream& out, const Polynomial& p);
    
    Polynomial& operator >> (const char* str);
    
    int maxExp() const;
    
    void sort();
    char* getStringRepresentation() const;
};

std::ostream& operator << (std::ostream& out, const Polynomial& p);
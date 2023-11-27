#include "fraction.h"
#include<iostream>

rightFraction::rightFraction(int a, int b)
{
    this->_nominator = a;
    this->_denominator = b;
}

rightFraction::rightFraction(rightFraction& p)
{
    this->_nominator = p._nominator;
    this->_denominator = p._denominator;

}


rightFraction rightFraction::operator+(const rightFraction& p2) {
    int new_nominator(0);
    int new_denominator(0);
   new_nominator = (this->getNominator() * p2._denominator) + (p2._nominator * this->getDenominator());
   new_denominator = (this->getDenominator() * p2._denominator);
   
   rightFraction fraction(new_nominator, new_denominator);
    reductFraction(fraction);
   
    return fraction;
}
rightFraction rightFraction::operator*(const rightFraction& p2) {
     int new_nominator(0);
     int new_denominator(0);
    new_nominator = (_nominator * p2._nominator);
    new_denominator = (_denominator * p2._denominator);
    rightFraction fraction(new_nominator, new_denominator);
    reductFraction(fraction);
    
    return fraction;
}
rightFraction rightFraction::operator/(const rightFraction& p2) {
    if (p2._nominator == 0) {
        std::cout << std::endl << "delenie na 0" << std::endl;
        throw std::invalid_argument("delenie na 0!");

    }
    else
    {
        int new_chisl(0);
        int new_znam(0);

        new_chisl = (_nominator * p2._denominator);
        new_znam = (_denominator * p2._nominator);
        rightFraction fraction(new_chisl, new_znam);

        reductFraction(fraction);

        return fraction;
    }
}

  int nod(int a, int b) {
      a = abs(a), b = abs(b);

      if (b == 0)  return a;
      else
          return nod(b, a % b);
  }

  rightFraction rightFraction::reductFraction(rightFraction& p1) {

      int sokr = nod(p1._nominator, p1._denominator);
      p1._nominator /= sokr;
      p1._denominator /= sokr;

      return p1;

  }

  int rightFraction::getNominator()
  {
      return _nominator;
  }

  int rightFraction::getDenominator()
  {
      return _denominator;
  }

  void rightFraction::printValues()
  {
      if (this->_nominator == 0) {
          std::cout << std::endl << 0 << std::endl;
      }
      else

          if (abs(this->_nominator) == this->_denominator) {
              if (this->_nominator < 0) {
                  std::cout << std::endl << -1 << std::endl;
              }
              else
              {
                  std::cout << std::endl << 1 << std::endl;
              }
          }
          else {
              if (this->_denominator < 0) {
                  this->_denominator = abs(this->_denominator);
                  this->_nominator = -this->_nominator;

              }
              rightFraction fraction(this->_nominator, this->_denominator);
              reductFraction(fraction);
              if (fraction._denominator == 0) {
                  throw std::invalid_argument("ZERO IN ZNAM");
              }
              else

                  if (fraction._nominator == 0) { std::cout << 0; }
                  else {
                      std::cout << std::endl << fraction._nominator << std::endl << "---" << std::endl << fraction._denominator << std::endl;
                  }
          }
  }
#pragma once
class rightFraction {

private:
    rightFraction() = delete;

    int _nominator = 0, _denominator = 0;

public:
    rightFraction(int a ,int b);
    rightFraction(rightFraction& p);

   
    rightFraction operator+(const rightFraction& p2);
    rightFraction operator*(const rightFraction& p2);
    rightFraction operator/(const rightFraction& p2);

    rightFraction reductFraction(rightFraction& p1);

    int getNominator();
    int getDenominator();

    void printValues();
};
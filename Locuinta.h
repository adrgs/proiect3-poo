//
// Created by adragos on 12/31/2019.
//

#ifndef PROIECT3_LOCUINTA_H
#define PROIECT3_LOCUINTA_H


#include <iostream>

class Locuinta
{
private:
    const static double MAXDISCOUNT;
protected:
    std::string numeClient;
    double suprafataUtila;
    double discount;
    double pretChirie;
public:
    Locuinta();
    Locuinta& operator=(const Locuinta& l)
    {
        if (&l == this)
            return *this;

        this->numeClient = l.numeClient;
        this->suprafataUtila = l.suprafataUtila;
        this->discount = l.discount;
        this->pretChirie = l.pretChirie;

        return *this;
    }
    Locuinta(const Locuinta&l)
    {
        *this = l;
    }
    virtual ~Locuinta();

    virtual void Afisare(std::ostream& out=std::cout);
    virtual double calculChirie() const = 0;

    static double CalculeazaChirie(double suprafataUtila, double discount, double pretMP);

    friend std::istream& operator>>(std::istream& in, Locuinta& locuinta);
    friend std::ostream& operator<<(std::ostream& out, Locuinta& locuinta);
};

#endif //PROIECT3_LOCUINTA_H

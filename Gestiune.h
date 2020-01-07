//
// Created by adragos on 12/31/2019.
//

#ifndef PROIECT3_GESTIUNE_H
#define PROIECT3_GESTIUNE_H

#include "Apartament.h"
#include "Casa.h"
#include <type_traits>

using std::pair;

template <typename T>
class Gestiune
{
private:
    size_t lungime;
    size_t index;
    T** vector;
public:
    Gestiune();

    Gestiune<T>& operator=(const Gestiune<T>& gestiune)
    {
        if (&gestiune == this)
            return *this;

        this->lungime = gestiune.lungime;
        this->index = gestiune.index;
        delete this->vector;

        this->vector = new T*[this->lungime];
        for (int i=0;i<=this->index;i++)
        {
            T* tmp = new T;
            *tmp = *gestiune.vector[i];
            this->vector = tmp;
        }

        return *this;
    }

    Gestiune(const Gestiune<T>& gestiune) {
        this->vector = NULL;
        *this = gestiune;
    }

    ~Gestiune();

    template <typename S>
    friend std::istream& operator>>(std::istream& in, Gestiune<S>& gestiune);
    template <typename S>
    friend std::ostream& operator<<(std::ostream& out, Gestiune<S>& gestiune);

    friend  class Gestiune<Casa>;

    Gestiune<T>& operator+=(const T& rhs);
    Gestiune<T>& operator+=(const Locuinta* locuinta);
    T& operator [] (int i);
};

template <>
class Gestiune<Casa>
{
private:
    size_t lungime;
    size_t index;
    pair<Casa, double>* vector;
public:
    double getChirieCase();
    size_t getNumarCase();

    Gestiune();

    Gestiune<Casa>& operator=(const Gestiune<Casa>& gestiune)
    {
        if (&gestiune == this)
            return *this;

        delete this->vector;
        this->lungime = gestiune.lungime;
        this->index = gestiune.lungime;
        this->vector = vector = new pair<Casa, double>[this->lungime];
        for (size_t i = 0; i < this->lungime; i++)
        {
            this->vector[i] = gestiune.vector[i];
        }

        return *this;
    }

    ~Gestiune();

    template <typename T>
    Gestiune(const Gestiune<T> &gestiune);
    Gestiune(const Gestiune<Casa> &gestiune);

    Gestiune<Casa>& operator+=(const Casa& rhs);
    Casa& operator [] (int i);

    friend std::istream& operator>>(std::istream& in, Gestiune<Casa>& locuinta);
    friend std::ostream& operator<<(std::ostream& out, Gestiune<Casa>& locuinta);
};

enum TipLocuinta {
    APARTAMENT,
    CASA
};

std::istream &operator>>(std::istream &in, TipLocuinta& tip)
{
    int tmp;
    in>>tmp;

    if (tmp==0) {
        tip = TipLocuinta::APARTAMENT;
    } else if (tmp==1) {
        tip = TipLocuinta::CASA;
    } else {
        throw "Mostenire neimplementata!";
    }

    return in;
}

#include "Gestiune.tpp"

#endif //PROIECT3_GESTIUNE_H

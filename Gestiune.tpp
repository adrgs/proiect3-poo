template<typename T>
Gestiune<T>::Gestiune()
{
    lungime = 100;
    index = -1;
    vector = new T*[lungime];
}

template<typename T>
Gestiune<T>::~Gestiune()
{
    for (size_t i = 0; i <= index; i++)
    {
        delete vector[i];
    }
    delete vector;
}

template<typename T>
Gestiune<T>& Gestiune<T>::operator+=(const T & rhs)
{
    this->index += 1;
    if (this->index >= this->lungime) {
        this->lungime = this->lungime * 2;
        T** tmp_vector = new T*[this->lungime];
        for (int i=0;i<this->index;i++)
        {
            tmp_vector[i] = this->vector[i];
        }
        delete vector;

        this->vector = tmp_vector;
    }
    T* pT = new T;
    pT = rhs;
    this->vector[this->index] = pT;

    return *this;
}

template<typename T>
Gestiune<T>& Gestiune<T>::operator+=(const Locuinta* locuinta)
{
    this->index += 1;
    if (this->index >= this->lungime) {
        this->lungime = this->lungime * 2;
        T** tmp_vector = new T*[this->lungime];
        for (int i=0;i<this->index;i++)
        {
            tmp_vector[i] = this->vector[i];
        }
        delete vector;

        this->vector = tmp_vector;
    }
    Locuinta* pLocuinta;
    Casa* pCasa = dynamic_cast<Casa*>(const_cast<Locuinta*>(locuinta));
    Apartament* pApartament = dynamic_cast<Apartament*>(const_cast<Locuinta*>(locuinta));
    if (pCasa)
    {
        Casa* ca = new Casa;
        *ca = *pCasa;
        pLocuinta = ca;
    } else if (pApartament){
        Apartament* ap = new Apartament;
        *ap = *pApartament;
        pLocuinta = pApartament;
    } else {
        throw "Mostenire neimplementata!";
    }
    this->vector[this->index] = pLocuinta;

    return *this;
}

template<typename T>
T & Gestiune<T>::operator[](int i)
{
    if (i<0 || i>this->index) throw "Array index out of bounds!";

    return this->vector[i];
}

template<typename T>
std::istream &operator>>(std::istream &in, Gestiune<T> &gestiune)
{
    int n;
    in>>n;

    if (n+gestiune.index-1>gestiune.lungime)
    {
        gestiune.lungime = (n + gestiune.lungime)*2;
        T** tmp_vector = new T*[gestiune.lungime];

        for (int i=0;i<=gestiune.lungime;i++)
        {
            tmp_vector[i] = gestiune.vector[i];
        }
        delete gestiune.vector;

        gestiune.vector = tmp_vector;
    }
    for (int i=0;i<n;i++)
    {
        gestiune.index++;
        if (std::is_same<T,Locuinta>::value)
        {
            int op;
            in>>op;
            Locuinta* locuinta;
            try {
                if (op == TipLocuinta::APARTAMENT) {
                    Apartament* ap = new Apartament;
                    in>> *ap;
                    locuinta = ap;
                } else if (op == TipLocuinta::CASA) {
                    Casa* ca = new Casa;
                    in >> *ca;
                    locuinta = ca;
                } else {
                    throw "Mostenire neimplementata!";
                }
                gestiune.vector[gestiune.index] = locuinta;
            } catch (...)
            {
                gestiune.index--;
            }
        } else {
            T* pT = new T;
            in>>*pT;
            gestiune.vector[gestiune.index] = pT;
        }
    }

    return in;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, Gestiune<T> &gestiune) {
    out<<"Gestiune: ";
    for (int i=0;i<=gestiune.index;i++)
    {
        out<<*gestiune.vector[i]<<" ";
    }
    out<<"\n";
    return out;
}

template<typename T>
Gestiune<Casa>::Gestiune(const Gestiune<T>& gestiune)
{
    this->lungime = (gestiune.lungime > 100 ? gestiune.lungime : 100);
    this->index = -1;

    vector = new pair<Casa,double>[this->lungime];

    for (size_t i = 0; i <= gestiune.index; i++)
    {
        Casa *c = dynamic_cast<Casa*>(gestiune.vector[i]);
        if (c)
        {
            this->index++;
            this->vector[this->index] = { *c, c->calculChirie() };

        }
    }
}

Gestiune<Casa>::Gestiune()
{
    lungime = 100;
    index = -1;
    vector = new pair<Casa, double>[lungime];
}

Gestiune<Casa>::~Gestiune()
{
    delete vector;
}

Gestiune<Casa>::Gestiune(const Gestiune<Casa>& gestiune)
{
    *this = gestiune;
}


double Gestiune<Casa>::getChirieCase()
{
    double suma = 0;
    for (size_t i = 0; i <= index; i++)
    {
        suma += vector[i].second;
    }
    return suma;
}

size_t Gestiune<Casa>::getNumarCase()
{
    return this->index + 1;
}

Gestiune<Casa>& Gestiune<Casa>::operator+=(const Casa & rhs)
{
    this->index += 1;
    if (this->index >= this->lungime) {
        this->lungime = this->lungime * 2;
        pair<Casa, double>* tmp = new pair<Casa, double>[this->lungime];
        for (int i=0;i<this->index;i++)
        {
            tmp[i] = this->vector[i];
        }
        delete vector;

        this->vector = tmp;
    }
    else {
        this->vector[this->index] = {rhs, rhs.calculChirie()};
    }

    return *this;
}

std::istream &operator>>(std::istream &in, Gestiune<Casa> &gestiune)
{
    int n;
    in>>n;

    if (n+gestiune.index-1>gestiune.lungime)
    {
        gestiune.lungime = (n + gestiune.lungime)*2;
        pair<Casa, double>* tmp_vector = new pair<Casa, double>[gestiune.lungime];

        for (int i=0;i<=gestiune.lungime;i++)
        {
            tmp_vector[i] = gestiune.vector[i];
        }
        delete gestiune.vector;

        gestiune.vector = tmp_vector;
    }
    for (int i=0;i<n;i++)
    {
        gestiune.index++;
        try {
            in>>gestiune.vector[gestiune.index].first;
            gestiune.vector[gestiune.index].second = gestiune.vector[gestiune.index].first.calculChirie();
        } catch (...)
        {
            gestiune.index--;
        }
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, Gestiune<Casa> &gestiune) {
    out<<"Agentia a obtinut " << gestiune.getChirieCase()<<" lei din chiria a "<<gestiune.getNumarCase()<<" case\n";
    return out;
}

Casa & Gestiune<Casa>::operator[](int i)
{
    if (i<0 || i>this->index) throw "Array index out of bounds!";

    return this->vector[i].first;
}
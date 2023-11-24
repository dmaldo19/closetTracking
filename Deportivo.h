//Maldonado Melendez Diego Alberto


//Definicion de la clase Deportivo
#ifndef DEPORTIVO_H_INCLUDED
#define DEPORTIVO_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Estaciones.h" 

class Deportivo : public Estaciones{
    private:
        string deporte;
    
    public:
        Deportivo (const Deportivo &rhs);
        Deportivo (int, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &);
        ~Deportivo();
        Deportivo(Deportivo &&rhs);
        Deportivo();
        Deportivo & operator=(const Deportivo & rhs);
        void setDeporte(const string &);
        string getDeporte() const;
        virtual bool operator==(const Deportivo& rhs) const;
};

#endif // DEPORTIVO_H_INCLUDED

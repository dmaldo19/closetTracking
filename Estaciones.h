//Maldonado Melendez Diego Alberto


//Definicion de la clase Estaciones
#ifndef ESTACIONES_H_INCLUDED
#define ESTACIONES_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Prendas.h" 

class Estaciones : public Prendas{
    protected:
        string estacion;
    
    public:
        Estaciones (const Estaciones &rhs);
        Estaciones (int, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &);
        ~Estaciones();
        Estaciones(Estaciones &&rhs);
        Estaciones();
        Estaciones & operator=(const Estaciones & rhs);
        void setEstacion(const string &);
        string getEstacion() const;
        virtual bool operator==(const Estaciones& rhs) const;
};

#endif // ESTACIONES_H_INCLUDED

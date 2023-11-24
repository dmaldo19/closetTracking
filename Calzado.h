//Maldonado Melendez Diego Alberto


//Definicion de la clase Calzado
#ifndef CALZADO_H_INCLUDED
#define CALZADO_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Estaciones.h" 

class Calzado : public Estaciones{
    private:
        string modelo;
    
    public:
        Calzado (const Calzado &rhs);
        //constructor con parametros
        Calzado (int, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &);
        ~Calzado();
        Calzado(Calzado &&rhs);
        Calzado();
        Calzado & operator=(const Calzado & rhs);
        void setModelo(const string &);
        string getModelo () const;
        virtual bool operator==(const Calzado& rhs) const;
};

#endif // CALZADO_H_INCLUDED

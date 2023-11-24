
//Maldonado Melendez Diego Alberto

//Definicion de la clase Accesorios
#ifndef ACCESORIOS_H_INCLUDED
#define ACCESORIOS_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Guardaropa.h" 

class Accesorios : public Guardaropa{
    protected:
        string material;
        string tipo;
    
    public:
        Accesorios (const Accesorios &rhs);
        //constructor con parametros
        Accesorios(int, const string &, const string &, const string &, const string &);
        ~Accesorios();
        Accesorios(Accesorios &&rhs);
        Accesorios();
        Accesorios & operator=(const Accesorios & rhs);
        void setMaterial(const string &);
        string getMaterial() const;
        void setTipo(const string &);
        string getTipo() const;
        virtual bool operator==(const Accesorios& rhs) const;
};

#endif // ACCESORIOS_H_INCLUDED

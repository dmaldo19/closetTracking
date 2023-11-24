//Maldonado Melendez Diego Alberto


//Definicion de la clase Prendas
#ifndef PRENDAS_H_INCLUDED
#define PRENDAS_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Guardaropa.h" 

class Prendas : public Guardaropa{
    protected:
        string corte;
        string color;
        string tipo;
        string tela;
        string talla;
    
    public:
        Prendas (const Prendas &rhs);
        Prendas (int f, const string &, const string &, const string &, const string &, const string &, const string &, const string &);
        ~Prendas();
        Prendas(Prendas &&rhs);
        Prendas();
        Prendas & operator=(const Prendas & rhs);
        void setCorte(const string &);
        string getCorte () const;
        void setColor(const string &);
        string getColor() const;
        void setTipo(const string &);
        string getTipo() const;
        void setTela(const string &);
        string getTela() const;
        void setTalla(const string &);
        string getTalla() const;
        virtual bool operator==(const Prendas& rhs) const;
};

#endif // PRENDAS_H_INCLUDED

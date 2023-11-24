//Maldonado Melendez Diego Alberto


//Definicion de la clase guardaropa que es la clase padre de todas
#ifndef GUARDAROPA_H_INCLUDED
#define GUARDAROPA_H_INCLUDED
#include <string> // clase string estándar de C++
#include <utility>
using std::string;
using std::move;

class Guardaropa{
    protected:
        int folio;
        string marca;
        string ocasion;
    
    public:
        Guardaropa(const Guardaropa &rhs);
        Guardaropa( int, const string &, const string &);
        ~Guardaropa();
        Guardaropa(Guardaropa &&rhs);
        Guardaropa();
        Guardaropa & operator=(const Guardaropa & rhs);
        void setMarca(const string &);
        string getMarca () const;
        void setOcasion(const string &);
        string getOcasion () const;
        void setFolio(int);
        int getFolio () const;
        virtual bool operator==(const Guardaropa& rhs) const;
};

#endif // GUARDAROPA_H_INCLUDED

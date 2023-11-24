//Maldonado Melendez Diego Alberto


//Definicion de la clase CuerpoCompleto
#ifndef CUERPOCOMPLETO_H_INCLUDED
#define CUERPOCOMPLETO_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Estaciones.h" 

class CuerpoCompleto : public Estaciones{
    private:
        string estampado;
        float longitud;
    
    public:
        CuerpoCompleto (const CuerpoCompleto &rhs);
        CuerpoCompleto (int, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, float = 0.0);
        ~CuerpoCompleto();
        CuerpoCompleto(CuerpoCompleto &&rhs);
        CuerpoCompleto();
        CuerpoCompleto & operator=(const CuerpoCompleto & rhs);
        void setEstampado(const string &);
        string getEstampado () const;
        void setLongitud(float);
        float getLongitud () const;
        virtual bool operator==(const CuerpoCompleto& rhs) const;
};

#endif // CUERPOCOMPLETO_H_INCLUDED

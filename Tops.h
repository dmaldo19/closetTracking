//Maldonado Melendez Diego Alberto


//Definicion de la clase Tops
#ifndef TOPS_H_INCLUDED
#define TOPS_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Estaciones.h" 

class Tops : public Estaciones{
    private:
        string estampado;
        float longitud;
    
    public:
        Tops (const Tops &rhs);
        Tops (int, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, float = 0.0);
        ~Tops();
        Tops(Tops &&rhs);
        Tops();
        Tops & operator=(const Tops & rhs);
        void setEstampado(const string &);
        string getEstampado () const;
        void setLongitud(float);
        float getLongitud () const;
        virtual bool operator==(const Tops& rhs) const;
};

#endif // TOPS_H_INCLUDED

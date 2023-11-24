
//Maldonado Melendez Diego Alberto


//Definicion de la clase guardaropa que es la clase padre de todas
#ifndef BOTTOMS_H_INCLUDED
#define BOTTOMS_H_INCLUDED
#include <string> // clase string estándar de C++
using std::string;

//Llamamos a la clase padre
#include "Estaciones.h" 

class Bottoms : public Estaciones{
    private:
        string estampado;
        float longitud;
    
    public:
        Bottoms (const Bottoms &rhs);
        //constructor con parametros
        Bottoms (int, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, float = 0.0);
        ~Bottoms();
        Bottoms(Bottoms &&rhs);
        Bottoms();
        Bottoms & operator=(const Bottoms & rhs);
        void setEstampado(const string &);
        string getEstampado () const;
        void setLongitud(float);
        float getLongitud () const;
        virtual bool operator==(const Bottoms& rhs) const;
};

#endif // BOTTOMS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LecturaDato {
public:
    int IdLectura;
    long timestamp;
    float valor;
    string unidad;

    bool esValida();
    string formatearSalida();
};

class ReglaControl {
public:
    float umbralTempMax;
    float umbralHumedadSueloMin;
    string estadoAlerta;

    void evaluarTemperatura(float t);
    void evaluarHumedad(float h);
    string obtenerEstado();
};



class Sensor {
public:
    int idPin;
    string nombre;
    bool activo;

   
    virtual void inicializar() = 0;
    virtual void obtenerLectura() = 0; 
};

class Actuador {
public:
    int idPin;
    bool estado;

    
    virtual void encender() = 0;
    virtual void apagar() = 0;
};


class SensorHumedad : public Sensor {
public:
    float humedad;

    void leerHumedadSuelo();
    float PorcentajeHumedad();

    void inicializar() override;
    void obtenerLectura() override;
};

class SensorDHT11 : public Sensor {
public:
    float temperatura;
    float humedadAire;

    void leerTemperatura();
    void LeerHumedadAire();

    void inicializar() override;
    void obtenerLectura() override;
};



class IndicadorLED : public Actuador {
public:
    string color;
    string Parpadeo;

    void cambiarEstado();
    void cambiarColor();

    void encender() override;
    void apagar() override;
};

class ServomotorEscotilla : public Actuador {
public:
    int anguloActual;
    int anguloAbierto;
    int anguloCerrado;

    void abrirEscobilla();
    void cerrarEscobilla();
    void fijarAngulo();

    void encender() override;
    void apagar() override;
};


class ControladorArduino {
public:
    int puertoSerie;
    int frecuenciaMuestreo;
    string estadoActual;


    vector<Sensor*> sensores;
    vector<Actuador*> actuadores;
    vector<ReglaControl*> reglas;

    void leerSensores();
    void ejecutarLogica();
    void enviarTelemetria();
};

class Invernadero {
public:
    string idInvernadero;
    string nombre;
    bool sistemaActivo;
    

    ControladorArduino* controlador;

    void iniciarSistema();
    void monitorear();
};
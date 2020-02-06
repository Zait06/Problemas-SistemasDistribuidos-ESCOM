#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura{
    private:
        double tempKelvin;     // Temperatura en grados Kelvin
    public:
        Temperatura(double=273.15);
        void setTempKelvin(double tk);
        void setTempFahrenheit(double tf);
        void setTempCelsius(double tc);
        void getTempKelvin();
        void getTempFahrenheit();
        void getTempCelsius();
};

#endif
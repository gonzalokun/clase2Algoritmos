//
// Created by gspringhart on 28/03/18.
//

#ifndef PERIODO_H
#define PERIODO_H

class Periodo {
public:
    Periodo(int anios, int meses, int dias);

    int anios() const;
    int meses() const;
    int dias() const;

private:
    int _anios;
    int _meses;
    int _dias;
};

#endif //SOLUCION_PERIODO_H

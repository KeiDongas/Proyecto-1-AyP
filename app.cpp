#include<iostream>
#include<cmath>
using namespace std;

// Definir variables
    char card1, card2, card3, card4, card5; // Cartas
    int palos; // Palos de cartas
    int comodin1, comodin2, comodin3; // Comodines
    int blind; // Blind (Ciega)
    int points; // Puntaje
    int mult; // Multiplicadores
    int fichas; // Total de fichas de la mano
    int valorCarta1, valorCarta2, valorCarta3, valorCarta4, valorCarta5; // Valores de las cartas
    int paloCarta1, paloCarta2, paloCarta3, paloCarta4, paloCarta5; // Palos de las cartas

    // Formula: Total de Puntos = (Valor de la mano + Total de puntos de cada carta) * Mult

// Funciones
int obtenerValorCarta(char carta) {
    if (carta == '2') return 2;
    else if (carta == '3') return 3;
    else if (carta == '4') return 4;
    else if (carta == '5') return 5;
    else if (carta == '6') return 6;
    else if (carta == '7') return 7;
    else if (carta == '8') return 8;
    else if (carta == '9') return 9;
    else if (carta == 'T') return 10;
    else if (carta == 'J') return 11;
    else if (carta == 'Q') return 12;
    else if (carta == 'K') return 13;
    else if (carta == 'A') return 15;
        
        return 0;
    }
int obtenerPaloCartas(int palos) {
    paloCarta1 = palos / 10000;
    paloCarta2 = (palos / 1000) % 10;
    paloCarta3 = (palos / 100) % 10;
    paloCarta4 = (palos / 10) % 10;
    paloCarta5 = palos % 10;
}

int main(){

    // Pedir datos al usuario
    cin >> card1 >> card2 >> card3 >> card4 >> card5; // Pedir mano de cartas
    cin >> palos; // Pedir palo de las cartas
    cin >> comodin1 >> comodin2 >> comodin3; // Pedir los comodines
    cin >> blind; // Pedir Blind

    // Obtener valores de las cartas
    valorCarta1 = obtenerValorCarta(card1);
    valorCarta2 = obtenerValorCarta(card2);
    valorCarta3 = obtenerValorCarta(card3);
    valorCarta4 = obtenerValorCarta(card4);
    valorCarta5 = obtenerValorCarta(card5);

    // Definir palos de las cartas
    obtenerPaloCartas(palos);

    return 0;
}

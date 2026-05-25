#include<iostream>
#include<cmath>
using namespace std;

// Definir variables
    char card1, card2, card3, card4, card5; // Cartas
    int palos; // Palos de cartas
    int comodin1, comodin2, comodin3; // Comodines
    int blind; // Blind (Ciega)

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

    return 0;
}

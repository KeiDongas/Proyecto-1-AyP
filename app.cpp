#include<iostream>
#include<cmath>
using namespace std;

int main(){

    // Definir variables
    char card1, card2, card3, card4, card5; // Cartas
    int palos; // Palos de cartas
    int comodin1, comodin2, comodin3; // Comodines
    int blind; // Blind (Ciega)
    int points; // Puntaje
    int mult; // Multiplicadores
    int fichas; // Total de fichas de la mano

    // Formula: (Valor de la mano + Total de puntos de cada carta) * Mult

    // Pedir datos al usuario
    cin >> card1 >> card2 >> card3 >> card4 >> card5; // Pedir mano de cartas
    cin >> palos; // Pedir palo de las cartas
    cin >> comodin1 >> comodin2 >> comodin3; // Pedir los comodines
    cin >> blind; // Pedir Blind

    return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

// Definir variables
    char card1, card2, card3, card4, card5; // Cartas
    int palos; // Palos de cartas
    int comodin1, comodin2, comodin3; // Comodines
    int blind; // Blind (Ciega)
    int valorCarta1, valorCarta2, valorCarta3, valorCarta4, valorCarta5; // Valores de las cartas
    int paloCarta1, paloCarta2, paloCarta3, paloCarta4, paloCarta5; // Palos de las cartas
    
    //jugadas (no recuerdo como se llamaban en balatro)
    bool esRoyalFlush = false;
    bool esStraightFlush = false;
    bool esFourOfAKind = false;
    bool esFullHouse = false;
    bool esFlush = false;
    bool esStraight = false;
    bool esThreeOfAkind = false;
    bool esTwoPair = false;
    bool esOnePair = false;
    bool esHightCard = false;
    
    //variables de calculo
    int valorTabla; //premio extra de la mano
    int mult; // Multiplicadores
    int valorCartasTotal;
    int fichas; // Total de fichas de la mano
    int total; // total, xd
    
    
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

    return 0;
}

int main(){

    // Pedir datos al usuario
    cin >> card1 >> card2 >> card3 >> card4 >> card5; // Pedir mano de cartas
    cin >> palos; // Pedir palo de las cartas
    /*cin >> comodin1 >> comodin2 >> comodin3; // Pedir los comodines
    cin >> blind; // Pedir Blind*/

    // Obtener valores de las cartas
    valorCarta1 = obtenerValorCarta(card1);
    valorCarta2 = obtenerValorCarta(card2);
    valorCarta3 = obtenerValorCarta(card3);
    valorCarta4 = obtenerValorCarta(card4);
    valorCarta5 = obtenerValorCarta(card5);

    //Ordenamiento de las cartas (me quiero morir saul :[ )
    int aux;
    //iba a hacerlo con un bucle while pero se me quedaba en loop chamo
    //chequeada 1 mueve el mas grande al final y asi
    if (valorCarta1 > valorCarta2) { aux = valorCarta1; valorCarta1 = valorCarta2; valorCarta2 = aux; }
    if (valorCarta2 > valorCarta3) { aux = valorCarta2; valorCarta2 = valorCarta3; valorCarta3 = aux; }
    if (valorCarta3 > valorCarta4) { aux = valorCarta3; valorCarta3 = valorCarta4; valorCarta4 = aux; }
    if (valorCarta4 > valorCarta5) { aux = valorCarta4; valorCarta4 = valorCarta5; valorCarta5 = aux; }

    //chequeada 2
    if (valorCarta1 > valorCarta2) { aux = valorCarta1; valorCarta1 = valorCarta2; valorCarta2 = aux; }
    if (valorCarta2 > valorCarta3) { aux = valorCarta2; valorCarta2 = valorCarta3; valorCarta3 = aux; }
    if (valorCarta3 > valorCarta4) { aux = valorCarta3; valorCarta3 = valorCarta4; valorCarta4 = aux; }

    //chequeada 3
    if (valorCarta1 > valorCarta2) { aux = valorCarta1; valorCarta1 = valorCarta2; valorCarta2 = aux; }
    if (valorCarta2 > valorCarta3) { aux = valorCarta2; valorCarta2 = valorCarta3; valorCarta3 = aux; }

    //chequeada 4
    if (valorCarta1 > valorCarta2) { aux = valorCarta1; valorCarta1 = valorCarta2; valorCarta2 = aux; }

    // Definir palos de las cartas
    obtenerPaloCartas(palos);

    //comprobacion de jugadas
    //Comprobacion de que es un FLUSH (normal)
    if (paloCarta1 == paloCarta2 && paloCarta2 == paloCarta3 && paloCarta3 == paloCarta4 && paloCarta4 == paloCarta5) {
        esFlush = true;
        if (esFlush == true){
            valorTabla = 50;
        }
    }
    //Royal Flush
    if (valorCarta1 && valorCarta2 &&  valorCarta3 &&  valorCarta4 && valorCarta5 > 9 && esFlush == true) {
        esRoyalFlush = true;
        esFlush = false; // por si le canta de sumar lo del flush normal
    }
    //one pair //FALTA TRABAJARLO MEJOR NO FUNCIONA DEL TODO
    if (valorCarta1 == valorCarta2 || valorCarta2 == valorCarta3 || valorCarta3 == valorCarta4 || valorCarta4 == valorCarta5){
        esOnePair = true;
        valorTabla = 10;
    }


    //aplicar jugadas
    if (esRoyalFlush){
        valorTabla = 100;
    } else if (esFlush){
        valorTabla = 50;
    } else if (esOnePair){
        valorTabla = 10;
    }
    
    //CALCULOS
    valorCartasTotal = valorCarta1 + valorCarta2  + valorCarta3 + valorCarta4 + valorCarta5; //valor total de las cartas
    fichas = valorCartasTotal + valorTabla;

    //SALIDA
    cout<<"total cartas: "<<fichas<<endl;
    cout<<esOnePair<<endl;
    cout<<"TEST! cartas en orden: "<<valorCarta1<< " "<<valorCarta2<<" "<<valorCarta3<<" "<<valorCarta4<<" "<<valorCarta5<<endl;

    
    return 0;
}

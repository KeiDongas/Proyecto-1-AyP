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

// Manos
bool esRoyalFlush = false;
bool esStraightFlush = false;
bool esFourOfAKind = false;
bool esFullHouse = false;
bool esFlush = false;
bool esStraight = false;
bool esThreeOfAkind = false;
bool esTwoPair = false;
bool esOnePair = false;

// Variables de calculo
int valorMano = 0;
int mult = 1;
int valorCartasTotal;
int total;
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
void intercambiar(char &card1, char &card2, int &valorCarta1, int &valorCarta2, int &paloCarta1, int &paloCarta2) {
    // Paso por referencia
    // Cartas
    char auxCard = card1;
    card1 = card2;
    card2 = auxCard;
    // Valor de carta
    int auxValor = valorCarta1;
    valorCarta1 = valorCarta2;
    valorCarta2 = auxValor;
    // Palos
    int auxPalo = paloCarta1;
    paloCarta1 = paloCarta2;
    paloCarta2 = auxPalo;
}
void aplicarComodin(int comodin) {
    switch (comodin) {
    case 1: // Joker
        mult += 4;
        break;
    case 2: // Joker Alegre
        if (esOnePair) {
            mult += 8;
        }
        break;
    case 3: // Joker Demente
        if (esTwoPair) {
            mult += 10;
        }
        break;
    case 4: // Joker Gracioso
        if (esFlush) {
            mult += 10;
        }
        break;
    case 5: // Joker Habilidoso
        if (esOnePair) {
            valorMano += 50;
        }
        break;
    case 6: // Joker Taimado
        if (esTwoPair) {
            valorMano += 100;
        }
        break;
    case 8: // Puño Elevado
        mult += valorCarta1;
        break;
    case 9: // Fibonacci
        if (card1 == 'A' || card1 == '2' || card1 == '3' || card1 == '5' || card1 == '8') mult += 2;
        if (card2 == 'A' || card2 == '2' || card2 == '3' || card2 == '5' || card2 == '8') mult += 2;
        if (card3 == 'A' || card3 == '2' || card3 == '3' || card3 == '5' || card3 == '8') mult += 2;
        if (card4 == 'A' || card4 == '2' || card4 == '3' || card4 == '5' || card4 == '8') mult += 2;
        if (card5 == 'A' || card5 == '2' || card5 == '3' || card5 == '5' || card5 == '8') mult += 2;
        break;
    default:
        break;
    }
}

int main() {

    // Pedir datos al usuario
    cin >> card1 >> card2 >> card3 >> card4 >> card5; // Pedir mano de cartas
    cin >> palos; // Pedir palo de las cartas
    cin >> comodin1 >> comodin2 >> comodin3; // Pedir los comodines
    cin >> blind; // Pedir Blind

    // Definir palos de las cartas
    obtenerPaloCartas(palos);

    // Obtener valores de las cartas
    valorCarta1 = obtenerValorCarta(card1);
    valorCarta2 = obtenerValorCarta(card2);
    valorCarta3 = obtenerValorCarta(card3);
    valorCarta4 = obtenerValorCarta(card4);
    valorCarta5 = obtenerValorCarta(card5);
    valorCartasTotal = valorCarta1 + valorCarta2  + valorCarta3 + valorCarta4 + valorCarta5; // Valor total de todas las cartas

    // Ordenamiento de las cartas
    while ((valorCarta1 > valorCarta2) || (valorCarta2 > valorCarta3) || (valorCarta3 > valorCarta4) || (valorCarta4 > valorCarta5)) {
        if (valorCarta1 > valorCarta2) intercambiar(card1, card2, valorCarta1, valorCarta2, paloCarta1, paloCarta2);
        if (valorCarta2 > valorCarta3) intercambiar(card2, card3, valorCarta2, valorCarta3, paloCarta2, paloCarta3);
        if (valorCarta3 > valorCarta4) intercambiar(card3, card4, valorCarta3, valorCarta4, paloCarta3, paloCarta4);
        if (valorCarta4 > valorCarta5) intercambiar(card4, card5, valorCarta4, valorCarta5, paloCarta4, paloCarta5);
    }

    // Comprueba si hay comodin cuatro dedos
    bool hayCuatroDedos = comodin1 == 7 || comodin2 == 7 || comodin3 == 7;

    // Comprobar manos
    // Royal Flush
    if (hayCuatroDedos) {
        bool tiene10 = (card1 == 'T' || card2 == 'T' || card3 == 'T' || card4 == 'T' || card5 == 'T');
        bool tieneJ  = (card1 == 'J' || card2 == 'J' || card3 == 'J' || card4 == 'J' || card5 == 'J');
        bool tieneQ  = (card1 == 'Q' || card2 == 'Q' || card3 == 'Q' || card4 == 'Q' || card5 == 'Q');
        bool tieneK  = (card1 == 'K' || card2 == 'K' || card3 == 'K' || card4 == 'K' || card5 == 'K');
        bool tieneA  = (card1 == 'A' || card2 == 'A' || card3 == 'A' || card4 == 'A' || card5 == 'A');
        int flushCaso1 = 1 + (paloCarta1 == paloCarta2) + (paloCarta1 == paloCarta3) + (paloCarta1 == paloCarta4) + (paloCarta1 == paloCarta5);
        int flushCaso2 = (paloCarta2 == paloCarta1) + 1 + (paloCarta2 == paloCarta3) + (paloCarta2 == paloCarta4) + (paloCarta2 == paloCarta5);
        bool mismoPalo4 = (flushCaso1 >= 4 || flushCaso2 >= 4);
        bool royalCaso1 = tiene10 && tieneJ && tieneQ && tieneK && mismoPalo4;
        bool royalCaso2 = tieneJ && tieneQ && tieneK && tieneA && mismoPalo4;
        if (royalCaso1 || royalCaso2) {
            esRoyalFlush = true;
        }
    } else {
        if ((card1 == 'T' && card2 == 'J' && card3 == 'Q' && card4 == 'K' && card5 == 'A') && (paloCarta1 == paloCarta2 && paloCarta2 == paloCarta3 && paloCarta3 == paloCarta4 && paloCarta4 == paloCarta5)) {
            esRoyalFlush = true;
        }
    }
    // Straight Flush (escalera color)
    if (hayCuatroDedos) {
        bool straightFlushCaso1 = ((valorCarta2 == valorCarta1 + 1) && (valorCarta3 == valorCarta2 + 1) && (valorCarta4 == valorCarta3 + 1 || valorCarta4 == valorCarta3 + 2)) &&
                                  ((paloCarta1 == paloCarta2) && (paloCarta2 == paloCarta3) && (paloCarta3 == paloCarta4));
        bool straightFlushCaso2 = ((valorCarta3 == valorCarta2 + 1) && (valorCarta4 == valorCarta3 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2)) &&
                                  ((paloCarta2 == paloCarta3) && (paloCarta3 == paloCarta4) && (paloCarta4 == paloCarta5));
        bool straightFlushCaso3 = ((valorCarta2 == valorCarta1 + 1) && (valorCarta4 == valorCarta2 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2)) &&
                                  ((paloCarta1 == paloCarta2) && (paloCarta2 == paloCarta4) && (paloCarta4 == paloCarta5));
        bool straightFlushCaso4 = ((valorCarta3 == valorCarta1 + 1) && (valorCarta4 == valorCarta3 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2)) &&
                                  ((paloCarta1 == paloCarta3) && (paloCarta3 == paloCarta4) && (paloCarta4 == paloCarta5));
        if (straightFlushCaso1 || straightFlushCaso2 || straightFlushCaso3 || straightFlushCaso4) {
            esStraightFlush = true;
        }
    } else {
        if ((valorCarta2 == valorCarta1 + 1) && (valorCarta3 == valorCarta2 + 1) && (valorCarta4 == valorCarta3 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2) && // Le añadi comparacion +2 pq recuerda q el As es la mas alta y vale dos puntos mas que la K
                (paloCarta1 == paloCarta2 && paloCarta2 == paloCarta3 && paloCarta3 == paloCarta4 && paloCarta4 == paloCarta5)) {
            esStraightFlush = true;
        }
    }
    // Four of a Kind (poker)
    if ((valorCarta1 == valorCarta2 && valorCarta2 == valorCarta3 && valorCarta3 == valorCarta4) || //[6,6,6,6,7]
            (valorCarta2 == valorCarta3 && valorCarta3 == valorCarta4 && valorCarta4 == valorCarta5)) { //[7,6,6,6,6]
        esFourOfAKind = true;
    }
    // Full House
    if ((valorCarta1 == valorCarta2 && valorCarta3 == valorCarta4 && valorCarta4 == valorCarta5) || //[2,2,3,3,3,]
            (valorCarta1 == valorCarta2 && valorCarta2 == valorCarta3 && valorCarta4 == valorCarta5)) { //[3,3,3,2,2]
        esFullHouse = true;
    }
    // Flush (color)
    if (hayCuatroDedos) {
        int flushCaso1 = 1 + (paloCarta1 == paloCarta2) + (paloCarta1 == paloCarta3) + (paloCarta1 == paloCarta4) + (paloCarta1 == paloCarta5);
        int flushCaso2 = (paloCarta2 == paloCarta1) + 1 + (paloCarta2 == paloCarta3) + (paloCarta2 == paloCarta4) + (paloCarta2 == paloCarta5);
        if ((flushCaso1 >= 4) || (flushCaso2 >= 4)) {
            esFlush = true;
        }
    } else {
        if (paloCarta1 == paloCarta2 && paloCarta2 == paloCarta3 && paloCarta3 == paloCarta4 && paloCarta4 == paloCarta5) {
            esFlush = true;
        }
    }
    // Straight (escalera)
    if (hayCuatroDedos) {
        bool straightCaso1 = (valorCarta2 == valorCarta1 + 1) && (valorCarta3 == valorCarta2 + 1) && (valorCarta4 == valorCarta3 + 1 || valorCarta4 == valorCarta3 + 2);
        bool straightCaso2 = (valorCarta3 == valorCarta2 + 1) && (valorCarta4 == valorCarta3 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2);
        bool straightCaso3 = (valorCarta2 == valorCarta1 + 1) && (valorCarta4 == valorCarta2 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2);
        bool straightCaso4 = (valorCarta3 == valorCarta1 + 1) && (valorCarta4 == valorCarta3 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2);
        if (straightCaso1 || straightCaso2 || straightCaso3 || straightCaso4) {
            esStraight = true;
        }
    } else {
        if ((valorCarta2 == valorCarta1 + 1) && (valorCarta3 == valorCarta2 + 1) && (valorCarta4 == valorCarta3 + 1) && (valorCarta5 == valorCarta4 + 1 || valorCarta5 == valorCarta4 + 2)) {
            esStraight = true;
        }
    }
    // Three of a Kind
    if ((valorCarta1 == valorCarta2 && valorCarta2 == valorCarta3) || (valorCarta2 == valorCarta3 && valorCarta3 ==  valorCarta4) || (valorCarta3 == valorCarta4 && valorCarta4 == valorCarta5)) {
        esThreeOfAkind = true;
    }
    // Two Pair
    if ((valorCarta1 == valorCarta2 && valorCarta3 == valorCarta4) || //[2,2,3,3,T]
            (valorCarta2 == valorCarta3 && valorCarta4 == valorCarta5) || //[T,2,2,3,3]
            (valorCarta1 == valorCarta2 && valorCarta4 == valorCarta5)) { //[2,2,T,3,3]
        esTwoPair = true;
    }
    // One Pair
    if (valorCarta1 == valorCarta2 || valorCarta2 == valorCarta3 || valorCarta3 == valorCarta4 || valorCarta4 == valorCarta5) {
        esOnePair = true;
    }

    // Aplicar mano
    if (esRoyalFlush) {
        valorMano += 100;
    } else if (esStraightFlush) {
        valorMano += 80;
    } else if (esFourOfAKind) {
        valorMano += 75;
    } else if (esFullHouse) {
        valorMano += 60;
    } else if (esFlush) {
        valorMano += 50;
    } else if (esStraight) {
        valorMano += 40;
    } else if (esThreeOfAkind) {
        valorMano += 30;
    } else if (esTwoPair) {
        valorMano += 20;
    } else if (esOnePair) {
        valorMano += 10;
    } else { // High Card
        valorMano += 0;
    }

    // Comodines
    aplicarComodin(comodin1);
    aplicarComodin(comodin2);
    aplicarComodin(comodin3);

    // Calculo
    total = (valorCartasTotal + valorMano) * mult;

    // Salida
    cout << total << endl;
    if (esRoyalFlush) {
        cout << "Royal Flush" << endl;
    } else if (esStraightFlush) {
        cout << "Straight Flush" << endl;
    } else if (esFourOfAKind) {
        cout << "Four of a Kind" << endl;
    } else if (esFullHouse) {
        cout << "Full House" << endl;
    } else if (esFlush) {
        cout << "Flush" << endl;
    } else if (esStraight) {
        cout << "Straight" << endl;
    } else if (esThreeOfAkind) {
        cout << "Three of a Kind" << endl;
    } else if (esTwoPair) {
        cout << "Two Pair" << endl;
    } else if (esOnePair) {
        cout << "One Pair" << endl;
    } else {
        cout << "High Card" << endl;
    }
    if (total >= blind) {
        cout << "The winner takes it all" << endl;
    } else {
        cout << "We folded like a..." << endl;
    }

    return 0;
}
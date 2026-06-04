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
char jugada; //determina la jugada en la salida

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
bool esHightCard = false;

// Variables de calculo
int valorMano; //premio extra de la mano
int mult = 1; // Multiplicadores
int valorCartasTotal;
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
void intercambiar(char &card1, char &card2, int &valorCarta1, int &valorCarta2, int &paloCarta1, int &paloCarta2) {
    //paso por referencia
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

int main() {

    // Pedir datos al usuario
    cin >> card1 >> card2 >> card3 >> card4 >> card5; // Pedir mano de cartas
    cin >> palos; // Pedir palo de las cartas
    cin >> comodin1; //>> comodin2 >> comodin3; // Pedir los comodines
    //cin >> blind; // Pedir Blind*/

    // Definir palos de las cartas
    obtenerPaloCartas(palos);

    // Obtener valores de las cartas
    valorCarta1 = obtenerValorCarta(card1);
    valorCarta2 = obtenerValorCarta(card2);
    valorCarta3 = obtenerValorCarta(card3);
    valorCarta4 = obtenerValorCarta(card4);
    valorCarta5 = obtenerValorCarta(card5);

    //Ordenamiento de las cartas
    while ((valorCarta1 > valorCarta2) || (valorCarta2 > valorCarta3) || (valorCarta3 > valorCarta4) || (valorCarta4 > valorCarta5)) {
        if (valorCarta1 > valorCarta2) intercambiar(card1, card2, valorCarta1, valorCarta2, paloCarta1, paloCarta2);
        if (valorCarta2 > valorCarta3) intercambiar(card2, card3, valorCarta2, valorCarta3, paloCarta2, paloCarta3);
        if (valorCarta3 > valorCarta4) intercambiar(card3, card4, valorCarta3, valorCarta4, paloCarta3, paloCarta4);
        if (valorCarta4 > valorCarta5) intercambiar(card4, card5, valorCarta4, valorCarta5, paloCarta4, paloCarta5);
    }

    //comprobacion de jugadas
    //Comprobacion de que es un FLUSH (normal)
    if (paloCarta1 == paloCarta2 && paloCarta2 == paloCarta3 && paloCarta3 == paloCarta4 && paloCarta4 == paloCarta5) {
        esFlush = true;
        if (esFlush == true) {
            valorMano = 50;
        }
    }
    //Royal Flush
    if (valorCarta1 > 9 && esFlush == true) {
        esRoyalFlush = true;
        esFlush = false; // por si le canta de sumar lo del flush normal
    }
    //one pair //FALTA TRABAJARLO MEJOR NO FUNCIONA DEL TODO
    if (valorCarta1 == valorCarta2 || valorCarta2 == valorCarta3 || valorCarta3 == valorCarta4 || valorCarta4 == valorCarta5) {
        esOnePair = true;
        valorMano = 10;
    }
    //trio
    if ((valorCarta1 == valorCarta2 && valorCarta2 == valorCarta3) || 
        (valorCarta2 == valorCarta3 && valorCarta3 ==  valorCarta4) ||
        (valorCarta3 == valorCarta4 && valorCarta4 == valorCarta5)){
        esThreeOfAkind = true;
    }
    //two pair
    if ((valorCarta1 == valorCarta2 && valorCarta3 == valorCarta4) || //[2,2,3,3,T]
        (valorCarta2 == valorCarta3 && valorCarta4 == valorCarta5) || //[T,2,2,3,3]
        (valorCarta1 == valorCarta2 && valorCarta4 == valorCarta5)) { //[2,2,T,3,3]
            esTwoPair = true;
    }
    //full house
    if ((valorCarta1 == valorCarta2 && valorCarta3 == valorCarta4 && valorCarta4 == valorCarta5) || //[2,2,3,3,3,]
        (valorCarta1 == valorCarta2 && valorCarta2 == valorCarta3 && valorCarta4 == valorCarta5)) { //[3,3,3,2,2]
            esFullHouse = true;
    }
    //Straight flush (escalera color)
    if ((valorCarta2 == valorCarta1+1) &&
        (valorCarta3 == valorCarta2+1) &&
        (valorCarta4 == valorCarta3+1) &&
        (valorCarta5 == valorCarta4+1) &&
        (paloCarta1 == paloCarta2 && paloCarta2 == paloCarta3 && paloCarta3 == paloCarta4 && paloCarta4 == paloCarta5)){
        esStraightFlush = true;
    }
    //Straight (escalera)
    if ((valorCarta2 == valorCarta1+1) &&
        (valorCarta3 == valorCarta2+1) &&
        (valorCarta4 == valorCarta3+1) &&
        (valorCarta5 == valorCarta4+1)){
        esStraight = true;
    }
    // four of a kind (poker)
    if ((valorCarta1 == valorCarta2 && valorCarta2 == valorCarta3 && valorCarta3 == valorCarta4) || //[6,6,6,6,7]
        (valorCarta2 == valorCarta3 && valorCarta3 == valorCarta4 && valorCarta4 == valorCarta5)){ //[7,6,6,6,6]
        esFourOfAKind = true;
    }

    //straightFlush
    //hight card


    //aplicar jugadas
    if (esRoyalFlush) {
        valorMano = 100;
    } else if (esStraightFlush) {
        valorMano = 80;
    } else if (esFourOfAKind) {
        valorMano = 75;
    } else if (esFullHouse) {
        valorMano = 60;
    } else if (esFlush) {
        valorMano = 50;
    } else if (esStraight) {
        valorMano = 40;
    } else if (esThreeOfAkind) {
        valorMano = 30;
    } else if (esTwoPair) {
        valorMano = 20;
    } else if (esOnePair) {
        valorMano = 10;
    } else {
        valorMano = 0;
    }

    //COMODINES

    //joker
    if (comodin1 == 1){
        mult += 4;
    } else if (comodin1 == 2){ //joker alegre
        if ((valorMano == 10)|| //hacer pruebas, de ser necesario se aplica como condicional de una vez (me da ladilla) 4/6/2026 2am
            (valorMano == 20)||
            (valorMano == 30)||
            (valorMano == 60)||
            (valorMano == 75)){
            mult += 8;
        }        
    } else if (comodin1 == 3){ //joker demente
        if (valorMano == 20 || valorMano == 60 || valorMano == 75){
            mult += 10;
        }
    } else if (comodin1 == 4){ //joker gracioso
        if (esFlush || esStraightFlush || esRoyalFlush){
            mult += 10;
        }
    } else if (comodin1 == 5){ //joker habilidoso
        if (valorMano == 10 || valorMano == 20 || valorMano == 30 || valorMano == 60 || valorMano == 75){
            valorMano += 50;
        }
    } else if (comodin1 == 6){ //joker taimado
        if (valorMano == 20 || valorMano == 60 || valorMano == 75){
            valorMano += 100;
        }
    } else if (comodin1 == 8){ //puño elevado
        mult += valorCarta1;
    } /*else if (comodin1 == 9){ //fibonacci
    
        
    }*/
    //CALCULOS
    valorCartasTotal = valorCarta1 + valorCarta2  + valorCarta3 + valorCarta4 + valorCarta5; //valor total de las cartas
    total = (valorCartasTotal + valorMano) * mult;

    //SALIDA
    cout << "total: " << total << endl;

    if (esRoyalFlush) {
        cout<<"Royal Flush"<<endl;
    } else if (esStraightFlush) {
        cout<<"Straight Flush"<<endl;
    } else if (esFourOfAKind) {
        cout<<"Four of a kind"<<endl;
    } else if (esFullHouse) {
        cout<<"Full House"<<endl;
    } else if (esFlush) {
        cout<<"Flush"<<endl;
    } else if (esStraight) {
        cout<<"Straight"<<endl;
    } else if (esThreeOfAkind) {
        cout<<"Three of a kind"<<endl;
    } else if (esTwoPair) {
        cout<<"Two Pair"<<endl;
    } else if (esOnePair) {
        cout<<"One Pair"<<endl;
    } else {
        cout<<"Hight Car"<<endl;
    }
    /*cout << "TEST! cartas en orden: " << card1 << " " << card2 << " " << card3 << " " << card4 << " " << card5 << endl;
    cout << "TEST! palos en orden: " << paloCarta1 << " " << paloCarta2 << " " << paloCarta3 << " " << paloCarta4 << " " << paloCarta5 << endl;
    cout << "TEST! valores en orden: " << valorCarta1 << " " << valorCarta2 << " " << valorCarta3 << " " << valorCarta4 << " " << valorCarta5 << endl;
    */

    return 0;
}
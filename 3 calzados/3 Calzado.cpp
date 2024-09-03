#include <iostream>
#include <cstdlib> // Para usar rand()
#include <ctime>   // Para srand(time(0))
using namespace std;

class Calzado {
private:
    int talla;
    char ladopie;
public:

    Calzado() {
        talla = 30;
        ladopie = 'D';
    }

    Calzado(int tam) {
        ladopie = 'D';
        talla = tam;
    }

    Calzado(int tam, char lado) {
        ladopie = lado;
        talla = tam;
    }

    bool esParde(Calzado cal) {
        return (talla == cal.talla && ladopie != cal.ladopie);
    }

    void verDatos() {
        cout << "La talla es: " << talla << "\n";
        cout << "El lado del pie es: " << ladopie << "\n";
    }

    void randomizar(int minTalla, int maxTalla) {
        talla = rand() % (maxTalla - minTalla + 1) + minTalla; // Generar talla entre minTalla y maxTalla
        ladopie = rand() % 2 == 0 ? 'I' : 'D';
    }
};

int main() {
    srand(time(0)); // Inicializar el generador de números aleatorios

    int aciertos = 0;

    while (true) {
        Calzado a, b, c;
        a.randomizar(40, 45); // Randomizar calzado 'a'
        b.randomizar(40, 45); // Randomizar calzado 'b'
        c.randomizar(40, 45); // Randomizar calzado 'c'

        // Mostrar los calzados
        cout << "\nCalzado 1:\n";
        a.verDatos();
        cout << "      |    |\n";
        cout << "      |    |\n";
        cout << "      |    ****\n";
        cout << "      |        |\n";
        cout << "      |        |\n";
        cout << "      ********* \n";

        cout << "Calzado 2:\n";
        b.verDatos();
        cout << "         |     |\n";
        cout << "         |     |\n";
        cout << "       ****    |\n";
        cout << "      |        |\n";
        cout << "      |        |\n";
        cout << "       ********* \n";

        cout << "Calzado 3:\n";
        c.verDatos();
        cout << "      |    |\n";
        cout << "      |    |\n";
        cout << "      |    ****\n";
        cout << "      |        |\n";
        cout << "      |        |\n";
        cout << "      ********* \n";

        cout << "Identifique los pares que se pueden formar con los calzados.\n";
        cout << "El calzado 1 y el calzado 2 forman un par (1 para si, 0 para no): ";
        int resp12;
        cin >> resp12;

        cout << "El calzado 1 y el calzado 3 forman un par (1 para si, 0 para no): ";
        int resp13;
        cin >> resp13;

        cout << "El calzado 2 y el calzado 3 forman un par (1 para si, 0 para no): ";
        int resp23;
        cin >> resp23;

        // Verificar si las respuestas del usuario son correctas
        bool correcto12 = (a.esParde(b) && resp12 == 1) || (!a.esParde(b) && resp12 == 0);
        bool correcto13 = (a.esParde(c) && resp13 == 1) || (!a.esParde(c) && resp13 == 0);
        bool correcto23 = (b.esParde(c) && resp23 == 1) || (!b.esParde(c) && resp23 == 0);

        if (correcto12 && correcto13 && correcto23) {
            cout << "¡Adivinaste todos los pares correctamente! :) \n";
            aciertos++;
        }
        else {
            cout << "Fallaste :( \n";
            break; 
        }

       
        cout << "Aciertos: " << aciertos << "\n";
    }

    return 0;
}
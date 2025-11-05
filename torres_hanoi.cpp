#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

stack<int> torreA;
stack<int> torreB;
stack<int> torreC;
string jugador1, jugador2;
int turno = 1;
int movimientos = 0;
int discos = 3;

// Prototipos.
void limpiarPantalla();
void InicializarTorres();
void MostrarTorres();
void MostrarTorresHorizontalmente();
string CentrarDisco(int tamaño);
bool ValidarEntrada(const string& desde, const string& hacia);
bool Mover(const string& desde, const string& hacia);
stack<int>* ObtenerTorre(const string& nombre);

int main() {
    cout << "TORRES DE HANÓI\n\n";

    cout << "Nombre del jugador 1: ";
    getline(cin, jugador1);
    if (jugador1.empty()) jugador1 = "Jugador 1";

    cout << "Nombre del jugador 2: ";
    getline(cin, jugador2);
    if (jugador2.empty()) jugador2 = "Jugador 2";

    InicializarTorres();

    limpiarPantalla();
    MostrarTorres();

    while (true) {
        cout << "\nTurno de " << (turno == 1 ? jugador1 : jugador2) << endl;
        cout << "Mover de torre (A, B, C): ";
        string desde;
        getline(cin, desde);
        transform(desde.begin(), desde.end(), desde.begin(), ::toupper);

        cout << "Mover a torre (A, B, C): ";
        string hacia;
        getline(cin, hacia);
        transform(hacia.begin(), hacia.end(), hacia.begin(), ::toupper);

        if (ValidarEntrada(desde, hacia) && Mover(desde, hacia)) {
            movimientos++;
            limpiarPantalla();
            MostrarTorres();

            if (torreC.size() == static_cast<size_t>(discos)) {
                cout << "\n¡" << (turno == 1 ? jugador1 : jugador2)
                     << " ha ganado en " << movimientos << " movimientos!" << endl;
                break;
            }

            turno = (turno == 1) ? 2 : 1;
        } else {
            cout << "\nMovimiento inválido. Intenta de nuevo." << endl;
            cout << "Reglas: Solo puedes mover el disco superior, "
                    "y no puedes colocar un disco sobre uno más pequeño." << endl;
        }
    }

    cout << "\nPresiona Enter para salir...";
    cin.get();
    return 0;
}

// Implementaciones.

void limpiarPantalla() {
    
    for (int i = 0; i < 30; i++) cout << "\n";
}

void InicializarTorres() {
    while (!torreA.empty()) torreA.pop();
    while (!torreB.empty()) torreB.pop();
    while (!torreC.empty()) torreC.pop();

    for (int i = discos; i >= 1; i--) {
        torreA.push(i);
    }
}

void MostrarTorres() {
    cout << "ESTADO ACTUAL\n\n";
    cout << "Movimientos realizados: " << movimientos << endl;
    cout << "Turno actual: " << (turno == 1 ? jugador1 : jugador2) << "\n\n";

    MostrarTorresHorizontalmente();
}

void MostrarTorresHorizontalmente() {
    vector<int> listaA, listaB, listaC;

    auto copiarTorre = [](stack<int> torre) {
        vector<int> lista;
        while (!torre.empty()) {
            lista.push_back(torre.top());
            torre.pop();
        }
        reverse(lista.begin(), lista.end());
        return lista;
    };

    listaA = copiarTorre(torreA);
    listaB = copiarTorre(torreB);
    listaC = copiarTorre(torreC);

    cout << "  A         B         C" << endl;
    cout << "-----     -----     -----" << endl;

    int maxAltura = max({ (int)listaA.size(), (int)listaB.size(), (int)listaC.size() });

    for (int i = maxAltura - 1; i >= 0; i--) {
        string linea = " ";

        // Torre A.
        if (i < (int)listaA.size())
            linea += CentrarDisco(listaA[i]) + "     ";
        else
            linea += "  |  " + string("     ");

        // Torre B.
        if (i < (int)listaB.size())
            linea += CentrarDisco(listaB[i]) + "     ";
        else
            linea += "  |  " + string("     ");

        // Torre C.
        if (i < (int)listaC.size())
            linea += CentrarDisco(listaC[i]);
        else
            linea += "  |  ";

        cout << linea << endl;
    }

    cout << "-----     -----     -----\n" << endl;
}

string CentrarDisco(int tamaño) {
    
    string disco(tamaño * 2 - 1, '#');
    string resultado = disco;
    if (resultado.size() < 5)
        resultado.insert(0, (5 - resultado.size()) / 2, ' ');
    return resultado;
}

bool ValidarEntrada(const string& desde, const string& hacia) {
    if (desde.empty() || hacia.empty()) return false;
    if (desde != "A" && desde != "B" && desde != "C") return false;
    if (hacia != "A" && hacia != "B" && hacia != "C") return false;
    return desde != hacia;
}

bool Mover(const string& desde, const string& hacia) {
    stack<int>* origen = ObtenerTorre(desde);
    stack<int>* destino = ObtenerTorre(hacia);

    if (!origen || !destino) return false;
    if (origen->empty()) return false;

    int discoOrigen = origen->top();

    if (!destino->empty() && destino->top() < discoOrigen)
        return false;

    origen->pop();
    destino->push(discoOrigen);
    return true;
}

stack<int>* ObtenerTorre(const string& nombre) {
    if (nombre == "A") return &torreA;
    if (nombre == "B") return &torreB;
    if (nombre == "C") return &torreC;
    return nullptr;
}
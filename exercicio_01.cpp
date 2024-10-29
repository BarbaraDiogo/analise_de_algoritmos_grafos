// Aluna: Barbara Diogo
// Código: 2063853

// 1) Leia os arquivos g1.txt, g2.txt e g3.txt e crie suas respectivas listas de adjacência na memória principal; (10 pontos)

#include "grafo.h"

int main() {
    grafo_g1 g1;
    grafo_g2 g2;
    grafo_g3 g3;

    ler_g1("../grafos/g1.txt", g1);
    ler_g2("../grafos/g2.txt", g2);
    ler_g3("../grafos/g3.txt", g3);

    cout << "Grafo g1:" << endl;
    imprimir_g1(g1);
    cout << endl;

    cout << "Grafo g2:" << endl;
    imprimir_g2(g2);
    cout << endl;

    cout << "Grafo g3:" << endl;
    imprimir_g3(g3);
    cout << endl;

    return 0;
}
// Aluna: Barbara Diogo
// Código: 2063853

// 2) Faça a busca em largura em G1 partindo do vértice b. Exiba na tela a ordem de visitação dos vértices. (30 pontos)

#include "grafo.h"

struct ResultadoBuscaLargura {
    vector<string> ordemVisita;
};

ResultadoBuscaLargura buscaEmLargura(const grafo_g1 &grafo, const string &inicio) {
    ResultadoBuscaLargura resultado;
    unordered_map<string, bool> visitado;
    queue<string> fila;

    fila.push(inicio);
    visitado[inicio] = true;

    unordered_map<string, vector<string>> listaAdjacenciaOrdenada = grafo.listaAdjacencia;

    while (!fila.empty()) {
        string u = fila.front();
        fila.pop();
        resultado.ordemVisita.push_back(u);

        sort(listaAdjacenciaOrdenada[u].begin(), listaAdjacenciaOrdenada[u].end());

        for (const string &v : listaAdjacenciaOrdenada[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                fila.push(v);
            }
        }
    }

    return resultado;
}

int main() {
    grafo_g1 g1;

    ler_g1("../grafos/g1.txt", g1);

    ResultadoBuscaLargura resultado = buscaEmLargura(g1, "b");

    cout << "Busca em Largura (BFS)" << endl;
    cout << "Iniciando no vertice b: ";
    for (const string &v : resultado.ordemVisita) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
// Aluna: Barbara Diogo
// Código: 2063853

// 3) Faça a busca em profundidade em G2 partindo do vértice a. Exiba na tela a ordem de visitação dos vértices. (30 pontos) 

#include "grafo.h"

struct ResultadoBuscaProfundidade {
    vector<string> ordemVisita;
};

ResultadoBuscaProfundidade buscaEmProfundidade(const grafo_g2 &grafo, const string &inicio) {
    ResultadoBuscaProfundidade resultado;
    unordered_map<string, bool> visitado;
    stack<string> pilha;

    pilha.push(inicio);

    while (!pilha.empty()) {
        string u = pilha.top();
        pilha.pop();

        if (!visitado[u]) {
            visitado[u] = true;
            resultado.ordemVisita.push_back(u);

            if (grafo.listaAdjacencia.find(u) != grafo.listaAdjacencia.end()) {
                vector<string> vizinhos = grafo.listaAdjacencia.at(u);
                sort(vizinhos.begin(), vizinhos.end());
                for (auto it = vizinhos.rbegin(); it != vizinhos.rend(); ++it) {
                    if (!visitado[*it]) {
                        pilha.push(*it);
                    }
                }
            }
        }
    }

    return resultado;
}

int main() {
    grafo_g2 g2;

    ler_g2("../grafos/g2.txt", g2);

    ResultadoBuscaProfundidade resultado = buscaEmProfundidade(g2, "a");

    cout << "Busca em Profundidade (DFS)" << endl;
    cout << "Iniciando no vertice " << "a" << ": ";
    for (const string &v : resultado.ordemVisita) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
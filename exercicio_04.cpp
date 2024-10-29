// Aluna: Barbara Diogo
// Código: 2063853

// 4) Execute o algoritmo do caminho mínimo em G3 e determine o custo do menor caminho entre os vértices x e t. Exiba na tela a lista de arestas correspondentes a este caminho. (30 pontos) 

#include "grafo.h"

struct ResultadoDijkstra {
    int custo;
    vector<pair<string, string>> caminho;
};

ResultadoDijkstra dijkstra(const grafo_g3 &grafo, const string &inicio, const string &fim) {
    ResultadoDijkstra resultado;
    unordered_map<string, int> dist;
    unordered_map<string, string> anterior;
    set<pair<int, string>> filaPrioridade;

    for (const auto &par : grafo.listaAdjacencia) {
        dist[par.first] = numeric_limits<int>::max();
        anterior[par.first] = "";
    }
    dist[inicio] = 0;
    filaPrioridade.insert({0, inicio});

    while (!filaPrioridade.empty()) {
        string u = filaPrioridade.begin()->second;
        filaPrioridade.erase(filaPrioridade.begin());

        if (u == fim) break;

        for (const auto &vizinho : grafo.listaAdjacencia.at(u)) {
            string v = vizinho.first;
            int peso = vizinho.second;
            int alt = dist[u] + peso;
            if (alt < dist[v]) {
                filaPrioridade.erase({dist[v], v});
                dist[v] = alt;
                anterior[v] = u;
                filaPrioridade.insert({alt, v});
            }
        }
    }

    vector<string> caminhoVertices;
    for (string at = fim; at != inicio; at = anterior[at]) {
        caminhoVertices.push_back(at);
    }
    caminhoVertices.push_back(inicio);
    reverse(caminhoVertices.begin(), caminhoVertices.end());

    resultado.custo = dist[fim];
    for (size_t i = 0; i < caminhoVertices.size() - 1; ++i) {
        resultado.caminho.push_back({caminhoVertices[i], caminhoVertices[i + 1]});
    }

    return resultado;
}

int main() {
    grafo_g3 g3;

    ler_g3("../grafos/g3.txt", g3);

    ResultadoDijkstra resultado = dijkstra(g3, "x", "t");

    cout << "Custo minimo de " << resultado.caminho.front().first << " a " << resultado.caminho.back().second << ": " << resultado.custo << endl;
    cout << "Caminho: ";
    for (const auto &aresta : resultado.caminho) {
        cout << "(" << aresta.first << ", " << aresta.second << ") ";
    }
    cout << endl;

    return 0;
}
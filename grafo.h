// Aluna: Barbara Diogo
// Código: 2063853

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <limits>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct grafo_g1 {
    unordered_map<string, vector<string>> listaAdjacencia;
};

struct grafo_g2 {
    unordered_map<string, vector<string>> listaAdjacencia;

    void adicionarAresta(const string& u, const string& v) {
        listaAdjacencia[u].push_back(v);
    }
};

struct grafo_g3 {
    unordered_map<string, vector<pair<string, int>>> listaAdjacencia;
};

bool abrirArquivo(ifstream &arquivo, const string &nomeArquivo) {
    arquivo.open(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return false;
    }
    return true;
}

void ler_g1(const string &nomeArquivo, grafo_g1 &grafo) {
    ifstream arquivo;
    if (!abrirArquivo(arquivo, nomeArquivo))
        return;
    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string u, v;
        getline(ss, u, ';');
        getline(ss, v, ';');
        grafo.listaAdjacencia[u].push_back(v);
        grafo.listaAdjacencia[v].push_back(u);
    }
    arquivo.close();
}

void ler_g2(const string &nomeArquivo, grafo_g2 &grafo) {
    ifstream arquivo;
    if (!abrirArquivo(arquivo, nomeArquivo))
        return;
    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string u, v;
        getline(ss, u, ';');
        getline(ss, v, ';');
        grafo.listaAdjacencia[u].push_back(v);
    }
    arquivo.close();
}

void ler_g3(const string &nomeArquivo, grafo_g3 &grafo) {
    ifstream arquivo;
    if (!abrirArquivo(arquivo, nomeArquivo))
        return;
    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string u, v;
        int peso;
        getline(ss, u, ';');
        getline(ss, v, ';');
        ss >> peso;
        grafo.listaAdjacencia[u].emplace_back(v, peso);
        grafo.listaAdjacencia[v].emplace_back(u, peso);
    }
    arquivo.close();
}

void imprimir_g1(const grafo_g1 &grafo) {
    set<string> vertices;
    for (const auto &par : grafo.listaAdjacencia) {
        vertices.insert(par.first);
    }

    for (const auto &vertice : vertices) {
        cout << vertice << ": ";
        for (const auto &v : grafo.listaAdjacencia.at(vertice)) {
            cout << v << " ";
        }
        cout << endl;
    }
}

void imprimir_g2(const grafo_g2 &grafo) {
    set<string> vertices;
    for (const auto &par : grafo.listaAdjacencia) {
        vertices.insert(par.first);
    }

    for (const auto &vertice : vertices) {
        cout << vertice << ": ";
        for (const auto &v : grafo.listaAdjacencia.at(vertice)) {
            cout << v << " ";
        }
        cout << endl;
    }
}

void imprimir_g3(const grafo_g3 &grafo) {
    set<string> vertices;
    for (const auto &par : grafo.listaAdjacencia) {
        vertices.insert(par.first);
    }

    for (const auto &vertice : vertices) {
        cout << vertice << ": ";
        for (const auto &p : grafo.listaAdjacencia.at(vertice)) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
}

#endif
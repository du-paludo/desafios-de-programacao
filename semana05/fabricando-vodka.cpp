#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int tempoTotalProducao, idadeInicial, idadeMaxima, precoDestilador;
vector<int> custosMan;
vector<int> valorVenda;
vector<vector<int>> mem(2001, vector<int>(2001, numeric_limits<int>::max()));
vector<vector<int>> anosTroca(2001, vector<int>(2001, 0));

int sol(int idade, int tempoProducao) {
    // cout << idade << ' ' << tempoProducao << ' ' << mem[idade][tempoProducao] << '\n';

    if (tempoProducao >= tempoTotalProducao) {
        return mem[tempoProducao][idade] = 0;
    }

    if (mem[tempoProducao][idade] != numeric_limits<int>::max()) {
        return mem[tempoProducao][idade];
    }

    if (idade >= idadeMaxima) {
        anosTroca[tempoProducao][idade] = 1;
        return mem[tempoProducao][idade] = precoDestilador - valorVenda[idade-1] + custosMan[0] + sol(1, tempoProducao + 1);
    }

    int substituir = precoDestilador - valorVenda[idade-1] + custosMan[0] + sol(1, tempoProducao + 1);
    int naoSubstituir = custosMan[idade] + sol(idade + 1, tempoProducao + 1);
    int minimo = naoSubstituir;
    anosTroca[tempoProducao][idade] = idade + 1;

    if (substituir <= naoSubstituir) {
        minimo = substituir;
        anosTroca[tempoProducao][idade] = 1;
    }

    return mem[tempoProducao][idade] = minimo;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> tempoTotalProducao >> idadeInicial >> idadeMaxima >> precoDestilador;
    int c, v;
    
    for (int i = 0; i < idadeMaxima; i++) {
        cin >> c;
        custosMan.push_back(c);
    }

    for (int i = 0; i < idadeMaxima; i++) {
        cin >> v;
        valorVenda.push_back(v);
    }

    cout << sol(idadeInicial, 0) << '\n';
    
    int idade = idadeInicial;
    bool trocou = false;
    for (int i = 0; i < tempoTotalProducao; i++) {
        if (anosTroca[i][idade] == 1) {
            cout << i+1 << ' ';
            trocou = true;
        }
        idade = anosTroca[i][idade];
    }
    if (!trocou) {
        cout << "0\n";
    } else {
        cout << '\n';
    }
}
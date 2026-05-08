#include <iostream>
#include <stack>

using namespace std;

stack<int> A, B, C;

void imprimirMovimento(char origem, char destino, int disco) {
    cout << "Moveu o disco " << disco << " da torre " << origem << " para a torre " << destino << "\n";
}

void moverDisco(stack<int>& origem, stack<int>& destino, char nomeOrigem, char nomeDestino) {
    int disco = origem.top();
    origem.pop();
    destino.push(disco);
    imprimirMovimento(nomeOrigem, nomeDestino, disco);
}

void hanoiRecursivo(int n, stack<int>& origem, stack<int>& destino, stack<int>& auxiliar, 
                    char nomeO, char nomeD, char nomeA) {
    if (n == 1) {
        moverDisco(origem, destino, nomeO, nomeD);
        return;
    }
    hanoiRecursivo(n - 1, origem, auxiliar, destino, nomeO, nomeA, nomeD);
    moverDisco(origem, destino, nomeO, nomeD);
    hanoiRecursivo(n - 1, auxiliar, destino, origem, nomeA, nomeD, nomeO);
}

int main() {
    int n = 3;
    
    for (int i = n; i >= 1; --i) {
        A.push(i);
    }

    cout << "--- Exercicio 4: Torre de Hanoi com Pilhas ---\n";
    cout << "Resolvendo para " << n << " discos:\n";
    hanoiRecursivo(n, A, C, B, 'A', 'C', 'B');

    return 0;
}

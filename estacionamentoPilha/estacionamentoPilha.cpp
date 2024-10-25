#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Estacionamento {
private:
    stack<string> estacionamento;  // Pilha principal (estacionamento)
    stack<string> patio;           // Pilha temporaria (patio)

public:
    // Adiciona um veiculo ao estacionamento
    void entradaVeiculo(const string& veiculo) {
        estacionamento.push(veiculo);
        cout << "Veiculo " << veiculo << " entrou no estacionamento.\n";
    }

    // Remove um veiculo especifico do estacionamento
    void saidaVeiculo(const string& veiculo) {
        bool encontrado = false;

        // Transfere os veiculos da pilha "estacionamento" para "patio" ate encontrar o veiculo desejado
        while (!estacionamento.empty()) {
            if (estacionamento.top() == veiculo) {
                encontrado = true;
                estacionamento.pop();  // Remove o veiculo desejado
                cout << "Veiculo " << veiculo << " saiu do estacionamento.\n";
                break;
            } else {
                patio.push(estacionamento.top());
                estacionamento.pop();
            }
        }

        // Se o veiculo foi encontrado, retornar os veiculos do patio ao estacionamento
        while (!patio.empty()) {
            estacionamento.push(patio.top());
            patio.pop();
        }

        if (!encontrado) {
            cout << "Veiculo " << veiculo << " nao esta no estacionamento.\n";
        }
    }

    // Mostra o estado atual das pilhas "estacionamento" e "patio"
    void mostrarEstado() {
        stack<string> temp = estacionamento;

        cout << "\nEstado atual do estacionamento: ";
        if (temp.empty()) {
            cout << "Vazio\n";
        } else {
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << "\n";
        }

        cout << "Estado atual do patio: ";
        temp = patio;  // Como o patio é temporario, geralmente estara vazio
        if (temp.empty()) {
            cout << "Vazio\n\n";
        } else {
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << "\n\n";
        }
    }
};

int main() {
    Estacionamento est;
    int opcao;
    string veiculo;

    do {
        cout << "1. Entrada de veiculo\n";
        cout << "2. Saida de veiculo\n";
        cout << "3. Mostrar estado atual\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite a placa do veiculo: ";
            cin >> veiculo;
            est.entradaVeiculo(veiculo);
            break;
        case 2:
            cout << "Digite a placa do veiculo a ser removido: ";
            cin >> veiculo;
            est.saidaVeiculo(veiculo);
            break;
        case 3:
            est.mostrarEstado();
            break;
        case 4:
            cout << "Encerrando programa.\n";
            break;
        default:
            cout << "Opcao invalida.\n";
        }
    } while (opcao != 4);

    return 0;
}

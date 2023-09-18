#include <iostream>
#include <vector>

using namespace std;

struct cliente {

    string cpf;
    string nome;
    string dtNascimento;
    string cnh;
};

void menu() {

    cout << "Gestão de clientes:\n\n";
    cout << "1. Incluir\n";
    cout << "2. Excluir cadastro\n";
    cout << "3. Listar clientes\n";
    cout << "4. Sair\n";
}

void lerCliente(cliente *novo_cliente) {

    cout << "Digite seu CPF: " << endl;
    getline(cin, novo_cliente->cpf);

    cout << "Digite seu nome: " << endl;
    getline(cin, novo_cliente->nome);

    cout << "Digite data de nascimento: " << endl;
    getline(cin, novo_cliente->dtNascimento);

    cout << "Digite o número da CNH: " << endl;
    getline(cin, novo_cliente->cnh);

}

void imprimirCliente(cliente pes_cliente){

    cout <<"------ Dados do Cliente ------" << endl;
    cout << "N° do CPF: " << pes_cliente.cpf << endl;
    cout << "Nome: " << pes_cliente.nome << endl;
    cout << "Data de Nascimento: " << pes_cliente.dtNascimento << endl;
    cout << "N° CNH: " << pes_cliente.cnh << endl;
    cout <<"------------------------------" << endl;
}

int main() {

    cliente cli;
    vector<cliente> clientes;

    menu();
    int op;
    cout << "Escolha uma nova Opção: ";
    cin >> op;
    cin.ignore(); 

    while (op != 4) {
        switch (op) {
            case 1:
                lerCliente(&cli);
                clientes.push_back(cli); 
                break;
            case 2:
                cout << "Excluir cadastro\n";
                break;
            case 3:
                cout << "Listagem de Clientes:\n\n";
                for (const cliente &c : clientes) {
                    imprimirCliente(c);
                }
                break;
            default:
                cout << "Entrada inválida\n";
                break;
        }

        menu();
        cin >> op;
        cin.ignore();
    }

    cout << "Encerrando..." << endl;
    return 0;
}
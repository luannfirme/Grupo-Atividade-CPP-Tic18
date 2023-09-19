#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cliente {
    string nome;
    string cpf;
    string dtNascimento;
    string cnh;
};

void incluirCliente(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, novoCliente.nome);

    cout << "Digite o CPF do cliente: ";
    getline(cin, novoCliente.cpf);

    cout << "Digite a data de nascimento: ";
    getline(cin, novoCliente.dtNascimento);

    cout << "Digite o número da CNH: ";
    getline(cin, novoCliente.cnh);

    clientes.push_back(novoCliente);
    cout << "Cliente incluído com sucesso!" << endl;
}

void excluirCliente(vector<Cliente>& clientes) {
    string cpfExcluir;
    cout << "Digite o CPF do cliente a ser excluído: ";
    cin >> cpfExcluir;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->cpf == cpfExcluir) {
            clientes.erase(it);
            cout << "Cliente excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

void alterarCliente(vector<Cliente>& clientes) {
    string cpfAlterar;
    cout << "Digite o CPF do cliente a ser alterado: ";
    cin >> cpfAlterar;

    for (auto& cliente : clientes) {
        if (cliente.cpf == cpfAlterar) {
            cout << "Digite o novo nome do cliente: ";
            cin.ignore();
            getline(cin, cliente.nome);

            cout << "Digite a nova data de nascimento: ";
            getline(cin, cliente.dtNascimento);

            cout << "Digite o novo número da CNH: ";
            getline(cin, cliente.cnh);

            cout << "Cliente alterado com sucesso!" << endl;
            cout << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

void listarClientes(const vector<Cliente>& clientes) {
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado." << endl;
    } else {
        cout << "Lista de Clientes:\n" << endl;
        for (const auto& cliente : clientes) {
            cout << "------ Dados do Cliente ------" << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "N° do CPF: " << cliente.cpf << endl;
            cout << "Data de Nascimento: " << cliente.dtNascimento << endl;
            cout << "N° do CNH: " << cliente.cnh << endl;
            cout << "------------------------------" << endl;
            cout << endl;
        }
    }
}

void localizarCliente(const vector<Cliente>& clientes) {
    string cpfLocalizar;
    cout << "Digite o CPF do cliente a ser localizado: ";
    cin >> cpfLocalizar;

    for (const auto& cliente : clientes) {
        if (cliente.cpf == cpfLocalizar) {
            cout << "------ Dados do Cliente ------" << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "N° do CPF: " << cliente.cpf << endl;
            cout << "Data de Nascimento: " << cliente.dtNascimento << endl;
            cout << "N° do CNH: " << cliente.cnh << endl;
            cout << "-----------------------------" << endl;
            cout << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
    cout << endl;
}

int main() {
    vector<Cliente> clientes;

    int opcao;
    do {
        cout << "Gestão Cadastro de Clientes:\n";
        cout << "Menu de Opções:\n" << endl;
        cout << "1. Incluir" << endl; 
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1:
                incluirCliente(clientes);
                break;
            case 2:
                excluirCliente(clientes);
                break;
            case 3:
                alterarCliente(clientes);
                break;
            case 4:
                listarClientes(clientes);
                break;
            case 5:
                localizarCliente(clientes);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}

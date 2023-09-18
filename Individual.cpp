#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Data {

    int dia, mes, ano;
};

struct Cliente {
    string nome;
    string cpf;
    Data dtNascimento;
    string cnh;
};

void LerDados(Cliente* lerdados) {
    cout << "-----Dados do Cliente-----" << endl;
    cout << "Digite Nome: ";
    cin.ignore(); // Limpar o buffer de entrada
    getline(cin, lerdados->nome);

    cout << "Digite CPF: ";
    getline(cin, lerdados->cpf);

    cout << "Digite sua Data de Nascimento no formato dia/mês/ano: ";
    cin >> lerdados->dtNascimento.dia >> lerdados->dtNascimento.mes >> lerdados->dtNascimento.ano;

    cout << "Digite CNH: ";
    getline(cin, lerdados->cnh);
}

void Menu() {
    cout << "---------- Menu -------------" << endl;
    cout << " Escolha uma opção abaixo" << endl;
    cout << " 1.Incluir " << endl;
    cout << " 2.Excluir " << endl;
    cout << " 3.Alterar " << endl;
    cout << " 4.Listar  " << endl;
    cout << " 5.Localizar " << endl;
    cout << " 0.Sair " << endl;
}

int main() {
    vector<Cliente> clientes; 
    Cliente novoCliente;
    
    int escolha;
    bool sair = false;

    while (!sair) {
        Menu();
        cout << "Escolha uma opção: ";
        cin >> escolha;

        if (escolha == 1) {
            LerDados(&novoCliente);
            clientes.push_back(novoCliente); 
            cout << "Cliente incluído com sucesso!" << endl;

        else if (escolha == 2) {
        
        }



        } else if (escolha == 0) {
            sair = true;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Data {

    int dia, mes, ano;
};

struct Cliente {
    string nome;
    string cpf;
    Data dtNascimento;
    string cnh;
};

void LerDados(Cliente* lerdados) {
    cout << "-----Dados do Cliente-----" << endl;
    cout << "Digite Nome: ";
    cin.ignore(); // Limpar o buffer de entrada
    getline(cin, lerdados->nome);

    cout << "Digite CPF: ";
    getline(cin, lerdados->cpf);

    cout << "Digite sua Data de Nascimento no formato dia/mês/ano: ";
    cin >> lerdados->dtNascimento.dia >> lerdados->dtNascimento.mes >> lerdados->dtNascimento.ano;

    cout << "Digite CNH: ";
    getline(cin, lerdados->cnh);
}

void Menu() {
    cout << "---------- Menu -------------" << endl;
    cout << " Escolha uma opção abaixo" << endl;
    cout << " 1.Incluir " << endl;
    cout << " 2.Excluir " << endl;
    cout << " 3.Alterar " << endl;
    cout << " 4.Listar  " << endl;
    cout << " 5.Localizar " << endl;
    cout << " 0.Sair " << endl;
}

int main() {
    vector<Cliente> clientes; 
    Cliente novoCliente;

    int escolha;
    bool sair = false;

    while (!sair) {
        Menu();
        cout << "Escolha uma opção: ";
        cin >> escolha;

        if (escolha == 1) {
            LerDados(&novoCliente);
            clientes.push_back(novoCliente); 
            cout << "Cliente incluído com sucesso!" << endl;

        else if (escolha == 2) {
        
        }



        } else if (escolha == 0) {
            sair = true;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
         }
    }

    return 0;
}

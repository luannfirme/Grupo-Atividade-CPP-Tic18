#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct cliente {

    string nome;
    string cpf;
    int dtNascimento;
    string cnh;
};

void Menu () {

    cout << "---------- Menu -------------" << endl << " Escolha uma opção abaixo" << endl;
    cout << " 1.Incluir " << endl;
    cout << " 2.Excluir " << endl;
    cout << " 3.Alterar " << endl;
    cout << " 4.Listar  " << endl;
    cout << " 5.Localizar " << endl;
    cout << " 0.Sair " << endl;
}

void LerDados(Cliente lerdados) {

        cout << endl;
        cout << "-----Dados de um Cliente-----" << endl;
        cout << "Digite Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Digite CPF: ";
        getline (cin, cpf;)
        cout << "Data de Nascimento entre com os dados:";
    
    }
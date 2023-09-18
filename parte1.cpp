#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct DataTratada
{
    int dia, mes, ano;
};

struct Cliente {
    string Cpf, Nome;
    DataTratada DtNascimento;
    string Cnh;

    void mostrarCliente(){
        cout << "Cliente: " << Nome << " - CPF: " << Cpf;
        cout << " - Data de Nascimento: " << DtNascimento.dia << "/" << DtNascimento.mes << "/" << DtNascimento.ano << " - CNH: " << Cnh<< endl;
    };

    void alterarCliente(Cliente *cliente){
        cliente->alterarCpf();
        cliente->alterarNome();
        cliente->alterarDtNascimento();
        cliente->alterarCnh();
        cout << "Cliente alterado com sucesso" << endl;
    };

    void alterarCpf(){
        char resp;
        do {
            cout << "Deseja Alterar o CPF do cliente?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe o novo CPF: ";
                cin >> Cpf;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    }

    void alterarNome(){
        char resp;
        do {
            cout << "Deseja Alterar o nome do cliente?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe o novo nome: ";
                cin >> Nome;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    }

    void alterarDtNascimento(){
        char resp;
        do {
            cout << "Deseja Alterar a data de nascimento do cliente?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe a nova data de nascimento: ";
                cin >> DtNascimento.dia >> DtNascimento.mes  >> DtNascimento.ano;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    };

    void alterarCnh(){
        char resp;
        do {
            cout << "Deseja Alterar a CNH do cliente?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe o novo CNH: ";
                cin >> Cnh;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    };
};

void lerDados(Cliente *cliente ){
    cout << "Digite o nome do cliente: ";
    cin >> cliente->Nome;

    cout << "Digite o CPF do cliente: ";
    cin >> cliente->Cpf;

    cout << "Digite a Data de Nascimento: ";
    cin >> cliente->DtNascimento.dia >> cliente->DtNascimento.mes  >> cliente->DtNascimento.ano;

    cout << "Digite a CNH do cliente: ";
    cin >> cliente->Cnh;
}

int buscarPosicao(vector<Cliente> clientes, string cpf){
    int n = -1;
    for (int i = 0; i < clientes.size(); ++i) {
        if(clientes[i].Cpf == cpf){
            n = i;
        }
    }
    return n;
}

int mostrarMenu(){
    int resp;
    do {
        cout << "#### GESTAO DE CLIENTES ####" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << "Resposta <enter>: ";
        cin >> resp;
    } while ((resp < 0 ) || (resp > 5));
};

int main (void){

    vector<Cliente> clientes;
    int selecionado;

    cout << endl << endl;

    do {
        selecionado = mostrarMenu();

        if(selecionado == 1){
            Cliente cliente;
            lerDados(&cliente);
            clientes.push_back(cliente);
        }

        if (selecionado >= 2 && selecionado <= 3 || selecionado == 5){
            string cpf;
            cout << "Informe o CPF do cliente: ";
            cin >> cpf;

            int posicao = buscarPosicao(clientes, cpf);

            if(posicao < 0 ){
                    cout << "Cliente nao localizado." << endl;
            } else {
                if (selecionado == 3)
                    clientes[posicao].alterarCliente(&clientes[posicao]);

                if(selecionado == 5)
                    clientes[posicao].mostrarCliente();

                if (selecionado == 2){
                    auto it = clientes.begin();
                    advance(it, posicao);
                    clientes.erase(it);
                    cout << "Cliente excluido com sucesso" << endl;
                }
            }
        }

        if (selecionado == 4){
            if (clientes.empty()) {
                cout << "Nenhum cliente cadastrado." << endl;
            } else {
                cout << endl;
                for (int i = 0; i < clientes.size(); ++i) {
                    clientes[i].mostrarCliente();
                }
                cout << endl << endl;
            }
        }

    } while (selecionado != 0);


    cout << "Programa encerrado..." << endl;

    return 0;
}
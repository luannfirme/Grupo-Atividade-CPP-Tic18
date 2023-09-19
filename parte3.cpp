#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct ApenasData
{
    int dia, mes, ano;
};

struct DataHora
{
    int dia, mes, ano, hora, minuto;
};

struct Veiculo {
    string Renavam, PlacaDoVeiculo;
    DataHora Retirada, Entrega;
    string LojaRetirada;

   vector<Veiculo> veiculos;

    int mostrarMenu(){
        int resp;
        do {
            cout << endl << endl;
            cout << "#### GESTAO DE VEICULOS ####" << endl;
            cout << "1. INCLUIR" << endl;
            cout << "2. EXCLUIR" << endl;
            cout << "3. ALTERAR" << endl;
            cout << "4. LISTAR" << endl;
            cout << "5. LOCALIZAR" << endl;
            cout << "0. VOLTAR" << endl;
            cout << "Resposta <enter>: ";
            cin >> resp;
        } while ((resp < 0 ) || (resp > 5));
    };

    int iniciar(){
    int selecionado;

    cout << endl << endl;   
    do {
        selecionado = mostrarMenu();

        if(selecionado == 1){
            Veiculo veiculo;
            lerDados(&veiculo);
            veiculos.push_back(veiculo);
        }

        if (selecionado >= 2 && selecionado <= 3 || selecionado == 5){
            string placa;
            cout << "Informe a placa do veiculo: ";
            cin >> placa;

            int posicao = buscarPosicao(placa);

            if(posicao < 0 ){
                    cout << "Veiculo não localizado." << endl;
            } else {
                if (selecionado == 3)
                    veiculos[posicao].alterarVeiculo(&veiculos[posicao]);

                if(selecionado == 5)
                    veiculos[posicao].mostrarVeiculo();

                if (selecionado == 2){
                    auto it = veiculos.begin();
                    advance(it, posicao);
                    veiculos.erase(it);
                    cout << "Veiculo excluido com sucesso" << endl;
                }
            }
        }

        if (selecionado == 4){
            if (veiculos.empty()) {
                cout << "Nenhum veiculo cadastrado." << endl;
            } else {
                cout << endl;
                for (int i = 0; i < veiculos.size(); ++i) {
                    veiculos[i].mostrarVeiculo();
                }
                cout << endl << endl;
            }
        }

    } while (selecionado != 0);

    return 0;
    }

    void lerDados(Veiculo *Veiculo ){
        cout << endl << endl;
        cout << "Digite o Renavam do veiculo: ";
        cin >> Veiculo->Renavam;

        cout << "Digite a placa do veiculo: ";
        cin >> Veiculo->PlacaDoVeiculo;

        cout << "Digite a data e hora de retirada do veiculo: ";
        cin >> Veiculo->Retirada.dia >> Veiculo->Retirada.mes  >> Veiculo->Retirada.ano >> Veiculo->Retirada.hora  >> Veiculo->Retirada.minuto;

        cout << "Digite a data e hora de entrega do veiculo: ";
        cin >> Veiculo->Entrega.dia >> Veiculo->Entrega.mes  >> Veiculo->Entrega.ano >> Veiculo->Entrega.hora  >> Veiculo->Entrega.minuto;

        cout << "Digite a loja onde o veiculo sera retirado: ";
        cin >> Veiculo->LojaRetirada;
    };

    void mostrarVeiculo(){
        cout << endl << endl;
        cout << "Renavam: " << Renavam << " - Placa: " << PlacaDoVeiculo;
        cout << " - Retirada: " << Retirada.dia << "/" << Retirada.mes << "/" << Retirada.ano << " as " << Retirada.hora << ":" << Retirada.minuto;
        cout << " - Entrega: " << Entrega.dia << "/" << Entrega.mes << "/" << Entrega.ano << " as " << Entrega.hora << ":" << Entrega.minuto;
        cout << " - Loja: "<< LojaRetirada << endl;
    };

    void alterarVeiculo(Veiculo *veiculo){
        veiculo->alterarRenavam();
        veiculo->alterarPlaca();
        veiculo->alterarRetirada();
        veiculo->alterarEntrega();
        veiculo->alterarLoja();
        cout << "Veiculo alterado com sucesso" << endl;
    };

    void alterarRenavam(){
        char resp;
        do {
            cout << "Deseja Alterar o Renavam do Veiculo?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe o novo Renavam: ";
                cin >> Renavam;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    }

    void alterarPlaca(){
        char resp;
        do {
            cout << "Deseja Alterar a placa do Veiculo?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe a nova placa: ";
                cin >> PlacaDoVeiculo;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    }

    void alterarRetirada(){
        char resp;
        do {
            cout << "Deseja Alterar a data de retirada do veiculo?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe a nova data de retirada: ";
                cin >> Retirada.dia >> Retirada.mes  >> Retirada.ano >> Retirada.hora  >> Retirada.minuto;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    };

    void alterarEntrega(){
        char resp;
        do {
            cout << "Deseja Alterar a data de entrega do veiculo?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe a nova data de entrega: ";
                cin >> Entrega.dia >> Entrega.mes  >> Entrega.ano >> Entrega.hora  >> Entrega.minuto;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    };

    void alterarLoja(){
        char resp;
        do {
            cout << "Deseja Alterar a loja de retirada do veiculo?" << endl;
            cout << "Resposta s/n <enter>: ";
            cin >> resp;

            if (resp == 's'  || resp == 'S' ){
                cout << "Informe a nova loja: ";
                cin >> LojaRetirada;
                break;
            } else if (resp == 'n'  || resp == 'n' ){
                break;
            }
        } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));
    };

    int buscarPosicao(string placa){
        int n = -1;
        for (int i = 0; i < veiculos.size(); ++i) {
            if(veiculos[i].PlacaDoVeiculo == placa){
                n = i;
            }
        }
        return n;
    }
};

struct Cliente {
    string Cpf, Nome;
    ApenasData DtNascimento;
    string Cnh;

    vector<Cliente> clientes;

    int mostrarMenu(){
        int resp;
        do {
            cout << endl << endl;
            cout << "#### GESTAO DE CLIENTES ####" << endl;
            cout << "1. INCLUIR" << endl;
            cout << "2. EXCLUIR" << endl;
            cout << "3. ALTERAR" << endl;
            cout << "4. LISTAR" << endl;
            cout << "5. LOCALIZAR" << endl;
            cout << "0. VOLTAR" << endl;
            cout << "Resposta <enter>: ";
            cin >> resp;
        } while ((resp < 0 ) || (resp > 5));
    };

    int iniciar(){
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

            int posicao = buscarPosicao(cpf);

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

    return 0;
    };

    void lerDados(Cliente *cliente ){
        cout << endl << endl;
        cout << "Digite o nome do cliente: ";
        cin >> cliente->Nome;

        cout << "Digite o CPF do cliente: ";
        cin >> cliente->Cpf;

        cout << "Digite a Data de Nascimento: ";
        cin >> cliente->DtNascimento.dia >> cliente->DtNascimento.mes  >> cliente->DtNascimento.ano;

        cout << "Digite a CNH do cliente: ";
        cin >> cliente->Cnh;
    };

    void mostrarCliente(){
        cout << "Cliente: " << Nome << " - CPF: " << Cpf;
        cout << " - Data de Nascimento: " << DtNascimento.dia << "/" << DtNascimento.mes << "/" << DtNascimento.ano << " - CNH: " << Cnh<< endl;
    };

    void alterarCliente(Cliente *cliente){
        cliente->alterarNome();
        cliente->alterarCpf();
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
    };

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

    int buscarPosicao(string cpf){
        int n = -1;
        for (int i = 0; i < clientes.size(); ++i) {
            if(clientes[i].Cpf == cpf){
                n = i;
            }
        }
        return n;
    };

    int buscarPosicaoPorCnh(string cnh){
        int n = -1;
        for (int i = 0; i < clientes.size(); ++i) {
            if(clientes[i].Cnh == cnh){
                n = i;
            }
        }
        return n;
    }
};


struct Locacao {
    bool Realizada;
    DataHora Retirada, Entrega;
    Cliente ClienteId;
    Veiculo VeiculoId;

    vector<Locacao> locacoes;

    int mostrarMenu(){
        int resp;
        do {
            cout << endl << endl;
            cout << "#### GESTAO DE LOCACAO ####" << endl;
            cout << "1. INCLUIR" << endl;
            cout << "2. EXCLUIR" << endl;
            cout << "3. ALTERAR" << endl;
            cout << "4. LISTAR" << endl;
            cout << "5. LOCALIZAR" << endl;
            cout << "0. VOLTAR" << endl;
            cout << "Resposta <enter>: ";
            cin >> resp;
        } while ((resp < 0 ) || (resp > 5));
    };

    int iniciar(){
        int selecionado;

        cout << endl << endl;

        do {
            selecionado = mostrarMenu();

            if(selecionado == 1){
                Locacao locacao;
                lerDados(&locacao);
                locacoes.push_back(locacao);
            }

            if (selecionado >= 2 && selecionado <= 3 || selecionado == 5){
                string placa;
                cout << "Informe a placa do veiculo: ";
                cin >> placa;

                // int posicao = buscarPosicao(clientes, cpf);

                // if(posicao < 0 ){
                //         cout << "Veiculo nao localizado." << endl;
                // } else {
                //     if (selecionado == 3)
                //         locacoes[posicao].alterarCliente(&clientes[posicao]);

                //     if(selecionado == 5)
                //         locacoes[posicao].mostrarCliente();

                //     if (selecionado == 2){
                //         auto it = clientes.begin();
                //         advance(it, posicao);
                //         clientes.erase(it);
                //         cout << "Cliente excluido com sucesso" << endl;
                //     }
                // }
            }

            if (selecionado == 4){
                if (locacoes.empty()) {
                    cout << "Nenhuma locacao cadastrada." << endl;
                } else {
                    cout << endl;
                    for (int i = 0; i < locacoes.size(); ++i) {
                        // locacoes[i].mostrarCliente();
                    }
                    cout << endl << endl;
                }
            }

        } while (selecionado != 0);

        return 0;
    }

        void lerDados(Locacao *locacao ){
        string cnh;
        Cliente cliente;
        string placa;
        Veiculo veiculo;

        cout << endl << endl;
        cout << "Informe a CNH do cliente: ";
        cin >> cnh;

        int c = cliente.buscarPosicaoPorCnh(cnh);

        if (c >= 0){
            locacao -> ClienteId = cliente.clientes[c];
            
            cout << "Informe a placa do veiculo: ";
            cin >> placa;

            int v = veiculo.buscarPosicao(placa);

            if (c >= 0){
                locacao -> VeiculoId = veiculo.veiculos[v];

                cout << "Informe a : ";
                cin >> placa;
            }
            else {
                cout << "Veiculo não encontrado" << endl;
            }
        } else {
            cout << "Cliente não encontrado" << endl;
        }

        // cout << "Digite o CPF do cliente: ";
        // cin >> cliente->Cpf;

        // cout << "Digite a Data de Nascimento: ";
        // cin >> cliente->DtNascimento.dia >> cliente->DtNascimento.mes  >> cliente->DtNascimento.ano;

        // cout << "Digite a CNH do cliente: ";
        // cin >> cliente->Cnh;
    };
};

int menuPrincipal(){
    int resp;
    do {
        cout << endl << endl;
        cout << "#### MENU PRINCIPAL ####" << endl;
        cout << "1. GESTAO DE CLIENTE" << endl;
        cout << "2. GESTAO DE VEICULOS" << endl;
        cout << "3. GESTAO DE LOCACAO" << endl;
        cout << "0. SAIR" << endl;
        cout << "Resposta <enter>: ";
        cin >> resp;
    } while ((resp < 0 ) || (resp > 3));
};

int main (void){
    Veiculo veiculo;
    Cliente cliente;
    Locacao locacao;
    int selecionado;

    cout << endl << endl;

    do {
        selecionado = menuPrincipal();

        if(selecionado == 1)
            cliente.iniciar();
        
        if (selecionado == 2)
            veiculo.iniciar();
            
        if (selecionado == 3)
            locacao.iniciar();

    } while (selecionado != 0);

    cout << endl << endl;
    cout << "Programa encerrado..." << endl;

    return 0;
}
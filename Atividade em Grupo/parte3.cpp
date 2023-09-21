#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


struct ApenasData
{
    int dia, mes, ano;

    bool validarData()
    {
        if (ano < 0)
            return false;

        if (mes < 1 || mes > 12)
            return false;

        if (dia < 1 || dia > diasNoMes(mes, ano))
            return false;

        return true;
    }

    int diasNoMes(int mes, int ano)
    {
        int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            diasNoMes[2] = 29; 

        return diasNoMes[mes];
    }
};

struct DataHora
{
    int dia, mes, ano, hora, minuto;

    bool validarDataHora()
    {
        ApenasData dataPart; 
        dataPart.dia = dia;
        dataPart.mes = mes;
        dataPart.ano = ano;

        if (!dataPart.validarData()) 
            return false;

        if (hora < 0 || hora > 23)
            return false;

        if (minuto < 0 || minuto > 59)
            return false;

        return true;
    }
};

struct Veiculo {
    string Renavam, PlacaDoVeiculo;
    DataHora Retirada, Entrega;
    string LojaRetirada;

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

    int iniciar(vector<Veiculo>* veiculos){
        int selecionado;

        cout << endl << endl;   
        do {
            selecionado = mostrarMenu();

            if(selecionado == 1){
                Veiculo veiculo;
                lerDados(&veiculo);
                veiculos->push_back(veiculo);
                cout << "Veiculo registrado com sucesso!" << endl;
            }

            if (selecionado >= 2 && selecionado <= 3 || selecionado == 5){
                string placa;
                cout << "Informe a placa do veiculo: ";
                cin >> placa;

                int posicao = buscarPosicao(placa, veiculos);

                if(posicao < 0 ){
                        cout << "Veiculo nao localizado." << endl;
                } else {
                    cout << endl << endl;
                    if (selecionado == 3)
                        alterarVeiculo(&(*veiculos)[posicao]);

                    if(selecionado == 5)
                        mostrarVeiculo(&(*veiculos)[posicao]);

                    if (selecionado == 2){
                        auto it = veiculos->begin();
                        advance(it, posicao);
                        veiculos->erase(it);
                    }
                }
            }

            if (selecionado == 4){
                if (veiculos->empty()) {
                    cout << "Nenhum veiculo cadastrado." << endl;
                } else {
                    cout << endl;
                    for (int i = 0; i < veiculos->size(); ++i) {
                        mostrarVeiculo(&(*veiculos)[i]);
                    }
                    cout << endl << endl;
                }
            }

        } while (selecionado != 0);

        return 0;
    }

    void lerDados(Veiculo *veiculo){
        cout << endl << endl;
        cout << "Digite o Renavam do veiculo: ";
        cin >> veiculo->Renavam;

        cout << "Digite a placa do veiculo: ";
        cin >> veiculo->PlacaDoVeiculo;

        cout << "Digite a data e hora de retirada do veiculo: ";
        cin >> veiculo->Retirada.dia >> veiculo->Retirada.mes  >> veiculo->Retirada.ano >> veiculo->Retirada.hora  >> veiculo->Retirada.minuto;

        cout << "Digite a data e hora de entrega do veiculo: ";
        cin >> veiculo->Entrega.dia >> veiculo->Entrega.mes  >> veiculo->Entrega.ano >> veiculo->Entrega.hora  >> veiculo->Entrega.minuto;

        cout << "Digite a loja onde o veiculo sera retirado: ";
        cin >> veiculo->LojaRetirada;

        cout << "Veiculo excluido com sucesso" << endl;
    };

    void mostrarVeiculo(Veiculo *veiculo){
        cout << "Renavam: " << veiculo->Renavam << " - Placa: " << veiculo->PlacaDoVeiculo;
        cout << " - Retirada: " << veiculo->Retirada.dia << "/" << veiculo->Retirada.mes << "/" << veiculo->Retirada.ano << " as " << veiculo->Retirada.hora << ":" << veiculo->Retirada.minuto;
        cout << " - Entrega: " << veiculo->Entrega.dia << "/" << veiculo->Entrega.mes << "/" << veiculo->Entrega.ano << " as " << veiculo->Entrega.hora << ":" << veiculo->Entrega.minuto;
        cout << " - Loja: "<< veiculo->LojaRetirada << endl;
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

    int buscarPosicao(string placa, vector<Veiculo>* veiculos){
        int n = -1;
        for (int i = 0; i < veiculos->size(); ++i) {
            if((*veiculos)[i].PlacaDoVeiculo == placa){
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

    int iniciar(vector<Cliente> *clientes){
        int selecionado;

        cout << endl << endl;

        do {
            selecionado = mostrarMenu();

            if(selecionado == 1){
                Cliente cliente;
                lerDados(&cliente);
                clientes->push_back(cliente);
            }

            if (selecionado >= 2 && selecionado <= 3 || selecionado == 5){
                string cpf;
                cout << "Informe o CPF do cliente: ";
                cin >> cpf;

                int posicao = buscarPosicao(cpf, clientes);

                if(posicao < 0 ){
                        cout << "Cliente nao localizado." << endl;
                } else {
                    cout << endl << endl;
                    if (selecionado == 3)
                        alterarCliente(&(*clientes)[posicao]);

                    if(selecionado == 5)
                        mostrarCliente(&(*clientes)[posicao]);

                    if (selecionado == 2){
                        auto it = clientes->begin();
                        advance(it, posicao);
                        clientes->erase(it);
                        cout << "Cliente excluido com sucesso" << endl;
                    }
                }
            }

            if (selecionado == 4){
                if (clientes->empty()) {
                    cout << "Nenhum cliente cadastrado." << endl;
                } else {
                    cout << endl;
                    for (int i = 0; i < clientes->size(); ++i) {
                        mostrarCliente(&(*clientes)[i]);
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

        cout << "Cliente registrado com sucesso!" << endl;
    };

    void mostrarCliente(Cliente *cliente){
        cout << "Cliente: " << cliente->Nome << " - CPF: " << cliente->Cpf;
        cout << " - Data de Nascimento: " << cliente->DtNascimento.dia << "/" << cliente->DtNascimento.mes << "/" << cliente->DtNascimento.ano << " - CNH: " << cliente->Cnh << endl;
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

    int buscarPosicao(string cpf, vector<Cliente>* clientes){
        int n = -1;
        for (int i = 0; i < clientes->size(); ++i) {
            if((*clientes)[i].Cpf == cpf){
                n = i;
            }
        }
        return n;
    };

    int buscarPosicaoPorCnh(string cnh, vector<Cliente>* clientes){
        int n = -1;
        for (int i = 0; i < clientes->size(); ++i) {
            if((*clientes)[i].Cnh == cnh){
                n = i;
            }
        }
        return n;
    };
};

struct Locacao {
    bool Realizada;
    DataHora Retirada, Entrega;
    Cliente ClienteId;
    Veiculo VeiculoId;

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

    int iniciar(vector<Locacao> *locacoes, vector<Cliente> *clientes, vector<Veiculo> *veiculos){
        int selecionado;

        cout << endl << endl;

        do {
            selecionado = mostrarMenu();

            if(selecionado == 1){
                Locacao locacao;
                locacao.lerDados((&locacao), clientes, veiculos);
                locacoes->push_back(locacao);
            }

            if (selecionado >= 2 && selecionado <= 3 || selecionado == 5){
                string placa, cpf;

                cout << "Informe a placa do veiculo: ";
                cin >> placa;

                for (int i = 0; i < locacoes->size(); ++i) {
                    if((*locacoes)[i].VeiculoId.PlacaDoVeiculo == placa){
                        mostrarLocacao(&(*locacoes)[i]);
                    }
                }

                cout << endl << endl;
                cout << "Informe o CPF do cliente que nao realizara a locacao: ";
                cin >> cpf;

                int posicao = buscarPosicao(cpf, placa, locacoes);;

                 if(posicao < 0 ){
                        cout << "Locacao nao localizada." << endl;
                } else {
                    cout << endl << endl;
                    if (selecionado == 3)
                        alterarLocacao(&(*locacoes)[posicao]);

                    if(selecionado == 5)
                        mostrarLocacao(&(*locacoes)[posicao]);

                    if (selecionado == 2){
                        auto it = locacoes->begin();
                        advance(it, posicao);
                        locacoes->erase(it);
                        cout << "Locacao excluida com sucesso" << endl;
                    }
                }
            }

            if (selecionado == 4){
                if (locacoes->empty()) {
                    cout << "Nenhum cliente cadastrado." << endl;
                } else {
                    cout << endl;
                    for (int i = 0; i < locacoes->size(); ++i) {
                        mostrarLocacao(&(*locacoes)[i]);
                    }
                    cout << endl << endl;
                }
            }

        } while (selecionado != 0);

        return 0;
    }

    void lerDados(Locacao *locacao, vector<Cliente>* clientes, vector<Veiculo>* veiculos){
        string cnh, placa;

        cout << endl << endl;
        cout << "Informe a CNH do cliente: ";
        cin >> cnh;
        
        int c = locacao->ClienteId.buscarPosicaoPorCnh(cnh, clientes);

        if (c >= 0) {
            cout << "Informe a placa do veiculo: ";
            cin >> placa;

            int v = locacao->VeiculoId.buscarPosicao(placa, veiculos);

            if (v >= 0) {

                locacao->ClienteId = (*clientes)[c];
                locacao->VeiculoId = (*veiculos)[v];

                cout << "Digite a data e hora real de retirada do veiculo: ";
                cin >> locacao->Retirada.dia >> locacao->Retirada.mes >> locacao->Retirada.ano >> locacao->Retirada.hora >> locacao->Retirada.minuto;

                locacao->Entrega.dia = 0;

                char resp;
                do {
                    cout << "A retirada ja aconteceu?" << endl;
                    cout << "Resposta s/n <enter>: ";
                    cin >> resp;

                    if(resp == 's' || resp == 'S'){
                        locacao->Realizada = true;
                        break;
                    } else if(resp == 'n' || resp == 'N'){
                        locacao->Realizada = false;
                        break;
                    }
                } while ((resp != 's' ) || (resp != 'S' ) || (resp != 'n' ) || (resp != 'N' ));                

                
                cout << "Locacao registrada com sucesso!" << endl;
            } else {
                cout << "Veiculo nao encontrado" << endl;
            }
        } else {
            cout << "Cliente nao encontrado" << endl;
        }
    };

    void mostrarLocacao(Locacao *locacao){
        cout << "Locacao " << (locacao->Realizada ? "realizada" : "nao realizada") << " - Veiculo: " << locacao->VeiculoId.PlacaDoVeiculo;
        cout << " - Cliente: " << locacao->ClienteId.Nome << " - Retirada: " << locacao->Retirada.dia << "/" << locacao->Retirada.mes << "/" << locacao->Retirada.ano << " " << locacao->Retirada.hora << ":" << locacao->Retirada.minuto;
        if(locacao->Entrega.dia != 0)
            cout << " - Entrega: " << locacao->Entrega.dia << "/" << locacao->Entrega.mes << "/" << locacao->Entrega.ano << " " << locacao->Entrega.hora << ":" << locacao->Entrega.minuto;
    };

    void alterarLocacao(Locacao *locacao){
        cout << "Digite a data e hora real de entrega do veiculo: ";
        cin >> locacao->Entrega.dia >> locacao->Entrega.mes >> locacao->Entrega.ano >> locacao->Entrega.hora >> locacao->Entrega.minuto;
        cout << "Locacao alterada com sucesso" << endl;
    };

    int buscarPosicao(string cpf, string placa, vector<Locacao>* locacoes){
        int n = -1;
        for (int i = 0; i < locacoes->size(); ++i) {
            if((*locacoes)[i].ClienteId.Cpf == cpf && (*locacoes)[i].VeiculoId.PlacaDoVeiculo == placa){
                n = i;
            }
        }
        return n;
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
    vector<Cliente> clientes;
    vector<Veiculo> veiculos;
    vector<Locacao> locacoes;
    Veiculo veiculo;
    Cliente cliente;
    Locacao locacao;
    int selecionado;

    cout << endl << endl;

    do {
        selecionado = menuPrincipal();

        if(selecionado == 1)
            cliente.iniciar(&clientes);
        
        if (selecionado == 2)
            veiculo.iniciar(&veiculos);
            
        if (selecionado == 3)
            locacao.iniciar(&locacoes, &clientes, &veiculos);

    } while (selecionado != 0);

    cout << endl << endl;
    cout << "Programa encerrado..." << endl;

    return 0;
}
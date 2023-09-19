#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct DataHora
{
    int dia, mes, ano, hora, minuto;
};

struct Veiculo {
    string Renavam, PlacaDoVeiculo;
    DataHora Retirada, Entrega;
    string LojaRetirada;

    void mostrarVeiculo(){
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
};

void lerDados(Veiculo *Veiculo ){
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
}

int buscarPosicao(vector<Veiculo> veiculos, string placa){
    int n = -1;
    for (int i = 0; i < veiculos.size(); ++i) {
        if(veiculos[i].PlacaDoVeiculo == placa){
            n = i;
        }
    }
    return n;
}

int mostrarMenu(){
    int resp;
    do {
        cout << "#### GESTAO DE VEICULOS ####" << endl;
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

    vector<Veiculo> veiculos;
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

            int posicao = buscarPosicao(veiculos, placa);

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


    cout << "Programa encerrado..." << endl;

    return 0;
}
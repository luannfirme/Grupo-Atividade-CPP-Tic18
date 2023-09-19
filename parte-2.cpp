#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct DataHora
{

    int dia, mes, ano;
    int hora,minuto;
};

struct Veiculo
{
    string renavan;
    string placa;
    DataHora retirada;
    DataHora entrega;
    string lojaretirada;
  
};

void LerDados(Veiculo *veiculo)
{
    cout << "----- Dados do Veículo -----" << endl;

    cout << "Digite o Renavam: ";
    cin.ignore();
    getline(cin, veiculo->renavan);

    cout << "Digite a Placa: ";
    getline(cin, veiculo->placa);

    cout << "Retirada  do veículo: ";
    cin >>veiculo->retirada.dia >> veiculo->retirada.mes >> veiculo->retirada.ano >> veiculo->retirada.hora >>veiculo->retirada.minuto;

    cout << "Local de entrega do veículo: ";
    cin >> veiculo->entrega.dia >> veiculo->entrega.mes >> veiculo->entrega.ano >> veiculo->entrega.hora >>veiculo->entrega.minuto;

    cout << " Digite a Loja de Retirada : ";
    getline (cin, veiculo->lojaretirada);



}


void MostrarVeiculo(Veiculo veiculo)
{
    cout << "Renavam: " << veiculo.renavan << endl;
    cout << "Placa: " << veiculo.placa << endl;
    cout << "Retirada: " << veiculo.retirada.dia << veiculo.retirada.mes << veiculo.retirada.ano << " no horário das : "<< veiculo.retirada.hora << ":" << veiculo.retirada.minuto << endl;
    cout << "Entrega :" << veiculo.entrega.dia << veiculo.entrega.mes <<veiculo.entrega.ano << " no horário das : " <<veiculo.entrega.hora <<veiculo.entrega.minuto <<endl;
    cout << "Loja Retirada: " << veiculo.lojaretirada << endl;
}


void ExcluirVeiculo(vector<Veiculo> &veiculos, const string &placa)
{
    for (auto buscar = veiculos.begin(); buscar != veiculos.end(); ++buscar)
    {
        if (buscar->placa == placa)
        {
            veiculos.erase(buscar);
            cout << "Veículo com Placa " << placa << " foi excluído." << endl;
            return;
        }
    }
    cout << "Veículo com Placa " << placa << " não foi encontrado." << endl;
}

void AlterarVeiculo(vector<Veiculo> &veiculos, const string &placa)
{
    for (size_t i = 0; i < veiculos.size(); ++i)
    {
        if (veiculos[i].placa == placa)
        {
            cout << "Dados atuais do veículo com Placa " << placa << ":" << endl;
            MostrarVeiculo(veiculos[i]);

            int opcao;
            cout << "Escolha o campo a ser alterado:" << endl;
            cout << "1. Renavan" << endl;
            cout << "2. Placa" << endl;
            cout << "3. Retirada" << endl;
            cout << "4. Entrega" << endl;
            cout << "5. Loja Retirada " << endl;
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                cout << "Digite a nova Placa: ";
                cin.ignore();
                getline(cin, veiculos[i].renavan);
                break;
            case 2:
                cout << "Digite a nova Placa: ";
                cin.ignore();
                getline(cin, veiculos[i].placa);
                break;
            case 3:
                cout << "Digite a nova data e hora de retirada : ";
                cin.ignore();
                veiculos[i].retirada;
                break;
            case 4:
                cout << "Digite a nova  a nova data e hora de entrega : ";
                cin.ignore();
                veiculos[i].entrega;
                break;
            case 5:
                cout << "Digite uma nova loja de retirada : ";
                cin >> veiculos[i].lojaretirada;
                break;
                cout << "Opção inválida." << endl;
                break;
            }

            cout << "Veículo com Placa " << placa << " foi alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Veículo com Placa " << placa << " não foi encontrado." << endl;
}

void ListarVeiculos(vector<Veiculo> listaveiculos)
{
    for (auto buscar = listaveiculos.begin(); buscar != listaveiculos.end(); buscar++)
    {
        cout << "Os dados do cliente são: " << endl;
        cout << "Renavan: " << buscar->renavan << endl;
        cout << "Placa: " << buscar->placa << endl;
        cout << "Retirada " << buscar->retirada .dia << buscar->retirada.mes << buscar->retirada.ano << buscar->retirada.hora <<buscar->retirada.minuto<< endl;
        cout << "Entrega: " << buscar->entrega.dia << "/" << buscar->entrega.mes << "/" << buscar->entrega.ano  << buscar->entrega.hora <<buscar->entrega.minuto<< endl;
    }
}


int LocalizarPlaca(const vector<Veiculo> &veiculos, const string &placa)
{
    for (size_t i = 0; i < veiculos.size(); ++i)
    {
        if (veiculos[i].placa == placa)
        {
            return i;
        }
    }
    return -1;
}

void Menu()
{
    cout << "---------- Menu de Veículos -------------" << endl;
    cout << " Escolha uma opção abaixo" << endl;
    cout << " 1. Incluir Veículos " << endl;
    cout << " 2. Excluir Veículos" << endl;
    cout << " 3. Alterar Veículos" << endl;
    cout << " 4. Listar Veículos" << endl;
    cout << " 5. Localizar Veículo por Placa" << endl;
    cout << " 0. Sair" << endl;
}

int main()
{
    vector<Veiculo> veiculos;
    Veiculo novoVeiculo;

    int escolha;
    bool sair = false;

    while (!sair)
    {
        Menu();
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            LerDados(&novoVeiculo);
            veiculos.push_back(novoVeiculo);
            cout << "Veículo incluído com sucesso!" << endl;
            break;

        case 2:
        {
            string placaExcluir;
            cout << "Digite a Placa do veículo a ser excluído: ";
            cin.ignore();
            getline(cin, placaExcluir);
            ExcluirVeiculo(veiculos, placaExcluir);
            break;
        }

        case 3:
        {
            string placaAlterar;
            cout << "Digite a Placa do veículo a ser alterado: ";
            cin.ignore();
            getline(cin, placaAlterar);
            AlterarVeiculo(veiculos, placaAlterar);
            break;
        }

        case 4:
            ListarVeiculos(veiculos);
            break;

        case 5:
        {
            string placaLocalizar;
            cout << "Digite a Placa do veículo: ";
            cin.ignore();
            getline(cin, placaLocalizar);
            int index = LocalizarPlaca(veiculos, placaLocalizar);
            if (index != -1)
            {
                cout << "Veículo encontrado. Dados do veículo:" << endl;
                MostrarVeiculo(veiculos[index]);
            }
            else
            {
                cout << "Veículo com Placa " << placaLocalizar << " não foi encontrado." << endl;
            }
            break;
        }

        case 0:
            sair = true;
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}
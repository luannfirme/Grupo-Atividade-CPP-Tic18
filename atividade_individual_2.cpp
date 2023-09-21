#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct veiculo {
    string renavan;
    string pl_veiculo;
    string dt_hora_ret;
    string dt_hora_entr;
    string lj_Retirada;
};

void incluirVeiculo(vector<veiculo>& veiculos) {
    veiculo novoVeiculo;
    cout << "Digite o renavan do veiculo: ";
    cin.ignore();
    getline(cin, novoVeiculo.renavan);

    cout << "Digite a Placa do Veículo: ";
    getline(cin, novoVeiculo.pl_veiculo);

    cout << "Digite data/hora da retirada: " << endl;
    getline(cin, novoVeiculo.dt_hora_ret);

    cout << "Digite data/hora da entrega:" << endl;
    getline(cin, novoVeiculo.dt_hora_entr);

    cout << "Digite a Loja da Retirada:" << endl;
    getline(cin, novoVeiculo.lj_Retirada);

    veiculos.push_back(novoVeiculo);
    cout << "veiculo incluído com sucesso!" << endl;
    cout << endl;

}

void excluirVeiculo(vector<veiculo>& veiculos) {
    string pl_veiculoExcluir;
    cout << "Digite a Placa do Veículo a ser excluído: ";
    cin >> pl_veiculoExcluir;

    for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
        if (it->pl_veiculo == pl_veiculoExcluir) {
            veiculos.erase(it);
            cout << "veiculo excluído com sucesso!" << endl;
            cout << endl;
            return;
        }
    }
    cout << "veiculo não encontrado." << endl;
}

void alterarVeiculo(vector<veiculo>& veiculos) {
    string pl_veiculoAlterar;
    cout << "Digite a Placa do Veículo a Ser Alterado: ";
    cin >> pl_veiculoAlterar;

    for (auto& veiculo : veiculos) {
        if (veiculo.pl_veiculo == pl_veiculoAlterar) {
            cout << "Digite a Placa do Veículo: ";
            cin.ignore();
            getline(cin, veiculo.pl_veiculo);
            
            cout << "Digite o renavan do veiculo: ";
            getline(cin, veiculo.renavan);

            cout << "Digite data/hora da retirada: " << endl;
            getline(cin, veiculo.dt_hora_ret);

            cout << "Digite data/hora da entrega:" << endl;
            getline(cin, veiculo.dt_hora_entr);

            cout << "Digite a Loja da Retirada:" << endl;
            getline(cin, veiculo.lj_Retirada);

            cout << "Veículo alterado com sucesso!" << endl;
            cout << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

void listarVeiculos(const vector<veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veiculo cadastrado." << endl;
    } else {
        cout << "Lista de veiculos:\n" << endl;
        for (const auto& veiculo : veiculos) {
            cout <<"------ Dados do veiculo ------" << endl;
            cout << "Renavan: " << veiculo.renavan << endl;
            cout << "Placa do Veículo: " << veiculo.pl_veiculo << endl;
            cout << "Data/Hora da Retrada: " << veiculo.dt_hora_ret << endl;
            cout << "Data/Hora da Entrega: " << veiculo.dt_hora_entr << endl;
            cout << "Digite a Loja da Retirada: " << veiculo.lj_Retirada << endl;
            cout << "------------------------------" << endl;
            cout << endl;
        }
    }
}

void localizarVeiculo(const vector<veiculo>& veiculos) {
    string pl_veiculoLocalizar;
    cout << "Digite a Placa do veiculo a ser localizado:\n ";
    cin >> pl_veiculoLocalizar;

    for (const auto& veiculo : veiculos) {
        if (veiculo.pl_veiculo == pl_veiculoLocalizar) {
            cout <<"------ Dados do veiculo ------" << endl;
            cout << "Renavan: " << veiculo.renavan << endl;
            cout << "Placa do Veículo: " << veiculo.pl_veiculo << endl;
            cout << "Data/Hora da Retrada: " << veiculo.dt_hora_ret << endl;
            cout << "Data/Hora da Entrega: " << veiculo.dt_hora_entr << endl;
            cout << "Digite a Loja da Retirada: " << veiculo.lj_Retirada << endl;
            cout << "------------------------------" << endl;
            cout << endl;
            return;
        }
    }
    cout << "veiculo não encontrado." << endl;
    cout << endl;
}

int main() {
    vector<veiculo> veiculos;

    int opcao;
    do {
        cout << "Gestão Veicular de Aluguel\n";
        cout << "===========================\n";
        cout << "Menu de Opções Veicular:\n" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << endl;
        cout << "Escolha uma opção:";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1:
                incluirVeiculo(veiculos);
                break;
            case 2:
                excluirVeiculo(veiculos);
                break;
            case 3:
                alterarVeiculo(veiculos);
                break;
            case 4:
                listarVeiculos(veiculos);
                break;
            case 5:
                localizarVeiculo(veiculos);
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

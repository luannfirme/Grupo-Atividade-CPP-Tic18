#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Data
{
    int dia, mes, ano;
};

struct Cliente
{
    string nome;
    string cpf;
    Data dtNascimento;
    string cnh;
};

void LerDados(Cliente *lerdados)
{
    cout << "-----Dados do Cliente-----" << endl;
    cout << "Digite Nome: ";
    cin.ignore();
    getline(cin, lerdados->nome);

    cout << "Digite CPF: ";
    getline(cin, lerdados->cpf);

    cout << "Digite sua Data de Nascimento no formato dia/mês/ano: ";
    cin >> lerdados->dtNascimento.dia >> lerdados->dtNascimento.mes >> lerdados->dtNascimento.ano;

    cout << "Digite CNH: ";
    cin.ignore();
    getline(cin, lerdados->cnh);
}

void MostrarCliente(Cliente mostrarcliente)
{
    cout << " Seu nome é : " << mostrarcliente.nome << endl;
    cout << " Seu CPF é : " << mostrarcliente.cpf << endl;
    cout << " Sua Data de Nascimento é : " << mostrarcliente.dtNascimento.dia << "/"
         << mostrarcliente.dtNascimento.mes << "/" << mostrarcliente.dtNascimento.ano << endl;
    cout << " Sua CNH é : " << mostrarcliente.cnh << endl;
}

void ExcluirCliente(vector<Cliente> &clientes, string cpf)
{
    for (size_t i = 0; i < clientes.size(); ++i)
    {
        if (clientes[i].cpf == cpf)
        {
            clientes.erase(clientes.begin() + i); // Remove o cliente do vetor
            cout << "Cliente com CPF " << cpf << " foi excluído." << endl;
            return; // Parar a busca, pois o cliente foi encontrado e excluído
        }
    }
    cout << "Cliente com CPF " << cpf << " não foi encontrado." << endl;
}

void AlterarCliente(vector<Cliente> &clientes, string cpf)
{
    for (size_t i = 0; i < clientes.size(); ++i)
    {
        if (clientes[i].cpf == cpf)
        {
            // Mostrar os dados atuais do cliente
            cout << "Dados atuais do cliente com CPF " << cpf << ":" << endl;
            MostrarCliente(clientes[i]);

            // Menu para escolher o campo a ser alterado
            int opcao;
            cout << "Escolha o campo a ser alterado:" << endl;
            cout << "1. Nome" << endl;
            cout << "2. CPF" << endl;
            cout << "3. Data de Nascimento" << endl;
            cout << "4. CNH" << endl;
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, clientes[i].nome);
                break;
            case 2:
                cout << "Digite o novo CPF: ";
                cin.ignore();
                getline(cin, clientes[i].cpf);
                break;
            case 3:
                cout << "Digite a nova Data de Nascimento no formato dia/mês/ano: ";
                cin >> clientes[i].dtNascimento.dia >> clientes[i].dtNascimento.mes >> clientes[i].dtNascimento.ano;
                break;
            case 4:
                cout << "Digite a nova CNH: ";
                cin.ignore();
                getline(cin, clientes[i].cnh);
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
            }

            cout << "Cliente com CPF " << cpf << " foi alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Cliente com CPF " << cpf << " não foi encontrado." << endl;
}

void ListarCliente(vector<Cliente> ListaClientes)
{
    for (auto buscar = ListaClientes.begin(); buscar != ListaClientes.end(); buscar++)
    {
        cout << "Os dados do cliente são: " << endl;
        cout << "Cliente: " << buscar->nome << endl;
        cout << "CPF: " << buscar->cpf << endl;
        cout << "CNH: " << buscar->cnh << endl;
        cout << "Data de nascimento: " << buscar->dtNascimento.dia << "/" << buscar->dtNascimento.mes << "/" << buscar->dtNascimento.ano << endl;
    }
}

int LocalizarCpf(vector<Cliente> clientes, string cpf)
{
    int buscar = -1;
    for (int i = 0; i < clientes.size(); ++i)
    {
        if (clientes[i].cpf == cpf)
        {
            buscar = i;
            break;
        }
    }
    return buscar;
}

void Menu()
{
    cout << "---------- Menu -------------" << endl;
    cout << " Escolha uma opção abaixo" << endl;
    cout << " 1.Incluir " << endl;
    cout << " 2.Excluir " << endl;
    cout << " 3.Alterar " << endl;
    cout << " 4.Listar  " << endl;
    cout << " 5.Localizar " << endl;
    cout << " 0.Sair " << endl;
}

int main()
{

    vector<Cliente> clientes;
    Cliente novoCliente;

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
            LerDados(&novoCliente);
            clientes.push_back(novoCliente);
            cout << "Cliente incluído com sucesso!" << endl;
            break;

        case 2:
        {
            string cpfExcluir;
            cout << "Digite o CPF do cliente a ser excluído: ";
            cin.ignore();
            getline(cin, cpfExcluir);
            if (cpfExcluir.size() == 11)
            {
                ExcluirCliente(clientes, cpfExcluir);
            }
            else
            {
                cout << "CPF inválido. Deve ter 11 dígitos." << endl;
            }
            break;
        }

        case 3:
        {
            string cpfAlterar;
            cout << "Digite o CPF do cliente a ser alterado: ";
            cin.ignore();
            getline(cin, cpfAlterar);
            if (cpfAlterar.size() == 11)
            {
                AlterarCliente(clientes, cpfAlterar);
            }
            else
            {
                cout << "CPF inválido. Deve ter 11 dígitos." << endl;
            }
            break;
        }
        case 4:
        {
            cout << "----- Lista de Clientes -----" << endl;
            ListarCliente(clientes);
            break;
        }

        case 5:
        {
            string cpfLocalizar;
            cout << "Digite o CPF com 11 dígitos: ";
            cin.ignore();
            getline(cin, cpfLocalizar);
            if (cpfLocalizar.size() == 11)
            {
                int index = LocalizarCpf(clientes, cpfLocalizar);
                if (index != -1)
                {
                    cout << "Cliente encontrado. Dados do cliente:" << endl;
                    MostrarCliente(clientes[index]);
                }
                else
                {
                    cout << "Cliente com CPF " << cpfLocalizar << " não foi encontrado." << endl;
                }
            }
            else
            {
                cout << "CPF inválido. Deve ter 11 dígitos." << endl;
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
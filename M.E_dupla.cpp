#include <iostream>
#include <vector>
#include <string>
#include <locale.h>

using namespace std;

// Exibe uma mensagem ao iniciar o programa
void msgInicio() {
    cout << "\nBem-vindo ao sistema de gerenciamento de dados!" << endl;
}

// Exibe uma mensagem ao finalizar o programa
void msgFinal() {
    cout << "\nObrigado por usar o sistema. At� logo!" << endl;
}

// Cadastra o usu�rio
void cadastrarUsuario(vector<string>& lista) {
    string nome;
    cout << "\nDigite o nome do usu�rio: ";
    cin.ignore(); // Cimpa o buffer do cin pra evitar problemas com o getline
    getline(cin, nome);
    lista.push_back(nome);
    cout << "\nUsu�rio cadastrado com sucesso!" << endl;
}

// Exibe a lista de usu�rios cadastrados
void exibirLista(const vector<string>& lista) {
    if (lista.empty()) {
        cout << "\nNenhum usu�rio cadastrado." << endl;
    } else {
        cout << "\nLista de usu�rios cadastrados:" << endl;
        for (size_t i = 0; i < lista.size(); ++i) {
            cout << i + 1 << ". " << lista[i] << endl;
        }
    }
}

// Remove um usu�rio da lista
void removerUsuario(vector<string>& lista) {
    if (lista.empty()) {
        cout << "\nA lista est� vazia, n�o tem usu�rios para serem removidos." << endl;
        return;
    }

    size_t num_usuarioDel;
    exibirLista(lista);
    cout << "\nDigite o n�mero do usu�rio a ser removido: ";
    cin >> num_usuarioDel;

    // Verifica se o n�mero do usu�rio � v�lido
    if (num_usuarioDel < 1 || num_usuarioDel > lista.size()) {
        cout << "\nUsu�rio inexistente." << endl;
    } else {
        lista.erase(lista.begin() + num_usuarioDel - 1);
        cout << "\nO usu�rio foi removido com sucesso!" << endl;
    }
}

// Edita o usu�rio, ou seja, reescreve outro no lugar
void editarUsuario(vector<string>& lista) {
    if (lista.empty()) {
        cout << "\nA lista est� vazia, n�o tem usu�rios para serem editados." << endl;
        return;
    }

    string usuarioEdit;
    size_t num_usuarioEdit;
    exibirLista(lista);
    cout << "\nDigite o n�mero do usu�rio a ser editado: ";
    cin >> num_usuarioEdit;

     // Verifica se o n�mero do usu�rio � v�lido
    if (num_usuarioEdit < 1 || num_usuarioEdit > lista.size()) {
        cout << "\nUsu�rio inexistente." << endl;
    } else {
        cin.ignore(); // Limpa o buffer do cin pra evitar problemas com o getline
        cout << "\nDigite o novo nome do usu�rio: ";
        getline(cin, usuarioEdit);
        lista[num_usuarioEdit - 1] = usuarioEdit; // Atualiza o usu�rio na lista
        cout << "\nO usu�rio foi editado com sucesso!" << endl;
    }
}

// Exibe o menu de escolhas
void exibirMenu() {
    cout << "\nMenu de op��es:" << endl;
    cout << "1. Cadastrar usu�rio" << endl;
    cout << "2. Exibir lista de usu�rios" << endl;
    cout << "3. Remover usu�rio" << endl;
    cout << "4. Editar usu�rio" << endl;
    cout << "5. Sair do sistema" << endl;
    cout << "Escolha uma op��o: ";
}

// Executa o sistema
void executarSistema() {
    vector<string> listaUsuarios;
    int opcao;

    msgInicio();

    // Executa infinitamente at� o usu�rio escolher a op��o de sair do programa
    while (true) {
        exibirMenu();
        cin >> opcao;

        // Executa de acordo com a escolha do usu�rio
        switch (opcao) {
            case 1:
                cadastrarUsuario(listaUsuarios);
                break;
            case 2:
                exibirLista(listaUsuarios);
                break;
            case 3:
                removerUsuario(listaUsuarios);
                break;
            case 4:
                editarUsuario(listaUsuarios);
                break;
            case 5:
                msgFinal();
                return; // Sai do loop e encerra o programa
            default:
                cout << "\nOp��o inv�lida! Por favor, escolha uma op��o v�lida." << endl;
                break;
        }
    }
}

// Chama a fun��o, executando todo o sistema
int main() {
    setlocale(LC_ALL, "portuguese");
    executarSistema();
    return 0;
}
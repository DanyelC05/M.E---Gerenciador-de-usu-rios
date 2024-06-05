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
    cout << "\nObrigado por usar o sistema. Até logo!" << endl;
}

// Cadastra o usuário
void cadastrarUsuario(vector<string>& lista) {
    string nome;
    cout << "\nDigite o nome do usuário: ";
    cin.ignore(); // Cimpa o buffer do cin pra evitar problemas com o getline
    getline(cin, nome);
    lista.push_back(nome);
    cout << "\nUsuário cadastrado com sucesso!" << endl;
}

// Exibe a lista de usuários cadastrados
void exibirLista(const vector<string>& lista) {
    if (lista.empty()) {
        cout << "\nNenhum usuário cadastrado." << endl;
    } else {
        cout << "\nLista de usuários cadastrados:" << endl;
        for (size_t i = 0; i < lista.size(); ++i) {
            cout << i + 1 << ". " << lista[i] << endl;
        }
    }
}

// Remove um usuário da lista
void removerUsuario(vector<string>& lista) {
    if (lista.empty()) {
        cout << "\nA lista está vazia, não tem usuários para serem removidos." << endl;
        return;
    }

    size_t num_usuarioDel;
    exibirLista(lista);
    cout << "\nDigite o número do usuário a ser removido: ";
    cin >> num_usuarioDel;

    // Verifica se o número do usuário é válido
    if (num_usuarioDel < 1 || num_usuarioDel > lista.size()) {
        cout << "\nUsuário inexistente." << endl;
    } else {
        lista.erase(lista.begin() + num_usuarioDel - 1);
        cout << "\nO usuário foi removido com sucesso!" << endl;
    }
}

// Edita o usuário, ou seja, reescreve outro no lugar
void editarUsuario(vector<string>& lista) {
    if (lista.empty()) {
        cout << "\nA lista está vazia, não tem usuários para serem editados." << endl;
        return;
    }

    string usuarioEdit;
    size_t num_usuarioEdit;
    exibirLista(lista);
    cout << "\nDigite o número do usuário a ser editado: ";
    cin >> num_usuarioEdit;

     // Verifica se o número do usuário é válido
    if (num_usuarioEdit < 1 || num_usuarioEdit > lista.size()) {
        cout << "\nUsuário inexistente." << endl;
    } else {
        cin.ignore(); // Limpa o buffer do cin pra evitar problemas com o getline
        cout << "\nDigite o novo nome do usuário: ";
        getline(cin, usuarioEdit);
        lista[num_usuarioEdit - 1] = usuarioEdit; // Atualiza o usuário na lista
        cout << "\nO usuário foi editado com sucesso!" << endl;
    }
}

// Exibe o menu de escolhas
void exibirMenu() {
    cout << "\nMenu de opções:" << endl;
    cout << "1. Cadastrar usuário" << endl;
    cout << "2. Exibir lista de usuários" << endl;
    cout << "3. Remover usuário" << endl;
    cout << "4. Editar usuário" << endl;
    cout << "5. Sair do sistema" << endl;
    cout << "Escolha uma opção: ";
}

// Executa o sistema
void executarSistema() {
    vector<string> listaUsuarios;
    int opcao;

    msgInicio();

    // Executa infinitamente até o usuário escolher a opção de sair do programa
    while (true) {
        exibirMenu();
        cin >> opcao;

        // Executa de acordo com a escolha do usuário
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
                cout << "\nOpção inválida! Por favor, escolha uma opção válida." << endl;
                break;
        }
    }
}

// Chama a função, executando todo o sistema
int main() {
    setlocale(LC_ALL, "portuguese");
    executarSistema();
    return 0;
}
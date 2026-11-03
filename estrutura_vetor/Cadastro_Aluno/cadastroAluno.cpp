#include <iostream>
#include <string>

using namespace std;

struct Turma{
    string nome, turma;
    char sexo;
    int idade;
};

int main(){
    int quantidadeAluno;
    Turma turma[quantidadeAluno];
    
    cout << "Digite a quantidade de aluno da turma: ";
    cin >> quantidadeAluno;

    cout << " -----  Cadastrar Aluno na Turma ------" << endl;

    for(int i = 0; i < quantidadeAluno; i++){
        cout << "Nome do aluno: ";
        cin >> turma[i].nome;

        cout << "Digite a idade do(a) aluno(a) " << turma[i].nome << ": ";
        cin >> turma[i].idade;

        cout << "Digite o sexo do(a) aluno(a) " << turma[i].nome << ": ";
        cin >> turma[i].sexo;

        cout << "Digite a turma: ";
        cin >> turma[i].turma;
    }

    for(int i = 0; i < quantidadeAluno; i++){
        cout << turma[i].nome << endl;
        cout << turma[i].idade << endl;
        cout << turma[i].sexo << endl;
        cout << turma[i].turma << endl;
    }

    return 0;

}
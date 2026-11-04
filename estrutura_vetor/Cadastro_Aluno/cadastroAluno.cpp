#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

struct Turma{
    string nome, turma, status;
    char sexo;
    int idade;
    float nota;
};

void cadastrarAlunO();

int main(){
    int quantidadeAluno;

    cout << "Digite a quantidade de aluno da turma: ";

    cin >> quantidadeAluno;

    Turma turma[quantidadeAluno];

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

        cout << "Digite a nota: ";
        cin >> turma[i].nota;

        if(turma[i].nota >= 7){
            turma[i].status = "Aprovado";
        }else{
            turma[i].status = "Reprovado";
        }
    }


    cout << left << setw(15) << "Nome" << 
    setw (8) << "Idade" << 
    setw(8) << "Idade" << 
    setw(8) << "Turma" << 
    setw(8) << "Nota" <<
    setw(15) << "Status" << endl;

    for(int i = 0; i < quantidadeAluno; i++){
        cout << left << setw (15) <<turma[i].nome <<
        setw(8) << turma[i].idade <<
        setw(8) << turma[i].sexo <<
        setw(8) << turma[i].turma << 
        setw(8) << turma[i].nota <<
        setw(15) << turma[i].status << endl;
    }

    return 0;

}
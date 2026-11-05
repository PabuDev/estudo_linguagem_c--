#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

struct Turma{
    string nome, turma, status;
    char sexo;
    int idade;
    float nota;
};

void cadastrarAluno(vector<Turma> &turme);
void exibirBoletim(const vector<Turma> &turma);

int main(){
    const int quantidadeAluno = 3;

    /*
    cout << "Digite a quantidade de aluno da turma: ";

    cin >> quantidadeAluno;
    */

    vector<Turma> turma(quantidadeAluno);

    //Chamando a função para cadastrar os alunos
    cadastrarAluno(turma);
    
    //Chamando a função para exibir o Boletim dos alunos
    exibirBoletim(turma);



    return 0;

}

//Função para Cadastrar os Alunos na Turma
void cadastrarAluno(vector<Turma> &turma){
    cout << " ------- CADASTRAR ALUNO NA TURMA ------- " << endl;
    for(size_t i = 0;  i < turma.size(); i++){
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
}

//Função para Exibir os dados dos Aluno em tabela
void exibirBoletim(const vector<Turma> &turma){
    cout << " ----- BOLETIM DOS ALUNOS -------" << endl;
    cout << left << setw(15) << "Nome" << 
    setw (8) << "Idade" << 
    setw(8) << "Sexo" << 
    setw(8) << "Turma" << 
    setw(8) << "Nota" <<
    setw(15) << "Status" << endl;

    for(size_t i = 0; i < turma.size(); i++){
        cout << left << setw (15) <<turma[i].nome <<
        setw(8) << turma[i].idade <<
        setw(8) << turma[i].sexo <<
        setw(8) << turma[i].turma << 
        setw(8) << turma[i].nota <<
        setw(15) << turma[i].status << endl;
    }
    
}
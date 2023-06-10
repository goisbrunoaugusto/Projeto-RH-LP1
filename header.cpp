#ifndef HEADER_CPP
#define HEADER_CPP

class Pessoa
{
private:
    string nome;
    string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    string estadoCivil;
    int qtdFilhos;
    public:
    Pessoa();
    Pessoa(string novoNome, string novoCpf, Data novaData, Endereco novoEndereco, string novoEstadoCivil, int novaQtdFilhos)
    {}
}

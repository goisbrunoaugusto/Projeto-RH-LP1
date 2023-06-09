#ifndef UTIL_HPP
#define UTIL_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct
{
    int ano;
    int mes;
    int dia;
} Data;

typedef struct
{
    string cidade;
    string bairo;
    string rua;
    string cep;
    int numero;
} Endereco;

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
    {
        this->nome = novoNome;
        this->cpf = novoCpf;
        this->dataNascimento = novaData;
        this->enderecoPessoal = novoEndereco;
        this->estadoCivil = novoEstadoCivil;
        this->qtdFilhos = novaQtdFilhos;
    };
    // Getters
    string getNome()
    {
        return this->nome;
    }

    string getCpf()
    {
        return this->cpf;
    }

    Data getDataNascimento()
    {
        return this->dataNascimento;
    }

    Endereco getEnderecoPessoal()
    {
        return this->enderecoPessoal;
    }

    string getEstadoCivil()
    {
        return this->estadoCivil;
    }

    int getQtdFilhos()
    {
        return this->qtdFilhos;
    }

    // Setters
    void setNome(string novoNome)
    {
        this->nome = novoNome;
    }

    void setCPF(string novoCPF)
    {
        this->cpf = novoCPF;
    }

    void setDataNascimento(Data novaData)
    {
        this->dataNascimento = novaData;
    }

    void setEnderecoPessoal(Endereco novoEndereco)
    {
        this->enderecoPessoal = novoEndereco;
    }

    void setEstadoCivil(string novoEstadoCivil)
    {
        this->estadoCivil = novoEstadoCivil;
    }

    void setQtdFilhos(int novaQtdFilhos)
    {
        this->qtdFilhos = novaQtdFilhos;
    }
};

class Funcionario
{
private:
    string salario;
    string matricula;
    Data ingressoEmpresa;

public:
    // getters
    string getSalario()
    {
        return this->salario;
    }
    string getMatricula()
    {
        return this->matricula;
    }
    Data getIngressoEmpresa()
    {
        return this->ingressoEmpresa;
    }
    // setters
    void setSalario(string novoSalario)
    {
        this->salario = novoSalario;
    }
    void setMatricula(string novaMatricula)
    {
        this->matricula = novaMatricula;
    }
    void setIngressoEmpresa(Data novoIngressoEmpresa)
    {
        this->ingressoEmpresa = novoIngressoEmpresa;
    }
    //
    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

class Asg : public Pessoa, public Funcionario
{
private:
    float adicionalInsalubridade;

public:
    Asg();
    Asg(float novoAdicionalInsalubridade)
    {
        this->adicionalInsalubridade = novoAdicionalInsalubridade;
    }
    // getters
    float getAdicionalInsalubridade()
    {
        return this->adicionalInsalubridade;
    }
    // setters
    void setAdicionalInsalubridade(float novoAdicionalInsalubridade)
    {
        this->adicionalInsalubridade = novoAdicionalInsalubridade;
    }
    //
    float calcularSalario(int diasFaltas)
    {
        // precisa implementar
        return 0;
    }
    float calcularRecisao(Data desligamento)
    {
        // precisa implementar
        return 0;
    }
};

class Vendedor : public Pessoa, public Funcionario
{

private:
    char tipoVendedor;

public:
    Vendedor();
    Vendedor(char novoTipoVendedor)
    {
        this->tipoVendedor = novoTipoVendedor;
    }
    // getters
    char getTipoVendedor()
    {
        return this->tipoVendedor;
    }
    // setters
    void setTipoVendedor(char novoTipoVendedor)
    {
        this->tipoVendedor = novoTipoVendedor;
    }
    //
    float calcularSalario(int diasFaltas)
    {
        // precisa implementar
        return 0;
    }
    float calcularRecisao(Data desligamento)
    {
        // precisa implementar
        return 0;
    }
};

class Gerente : public Pessoa, public Funcionario
{

private:
    float participacaoLucros;

public:
    Gerente();

    Gerente(float novaParticipacaoLucros)
    {
        this->participacaoLucros = novaParticipacaoLucros;
    }

    // getters
    float getParticipacaoLucros()
    {
        return this->participacaoLucros;
    }
    // setters
    void setParticipacaoLucros(float novaParticipacaoLucros)
    {
        this->participacaoLucros = novaParticipacaoLucros;
    }
    //
    float calcularSalario(int diasFaltas)
    {
        // precisa implementar
        return 0;
    }
    float calcularRecisao(Data desligamento)
    {
        // precisa implementar
        return 0;
    }
};

class Empresa
{

private:
    float faturamentoMensal;
    string nomeEmpresa;
    string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

public:
    Empresa();
    Empresa(string novoNomeEmpresa, string novoCnpj, float novoFaturamenteMensal)
    {
        this->nomeEmpresa = novoNomeEmpresa;
        this->cnpj = novoCnpj;
        this->faturamentoMensal = novoFaturamenteMensal;
    }

    // getters
    float getFaturamentoMensal()
    {
        return this->faturamentoMensal;
    }
    string getNomeEmpresa()
    {
        return this->nomeEmpresa;
    }
    string getCnpj()
    {
        return this->cnpj;
    }
    Pessoa getDono()
    {
        return this->dono;
    }
    vector<Asg> getAsgs()
    {
        return this->asgs;
    }
    vector<Vendedor> getVendedores()
    {
        return this->vendedores;
    }
    vector<Gerente> getGerentes()
    {
        return this->gerentes;
    }
    // setters
    void setFaturamentoMensal(float novoFaturamentoMensal)
    {
        this->faturamentoMensal = novoFaturamentoMensal;
    }
    void setNomeEmpresa(string novoNomeEmpresa)
    {
        this->nomeEmpresa = novoNomeEmpresa;
    }
    void setCnpj(string novoCnpj)
    {
        this->cnpj = novoCnpj;
    }
    //
    void carregaFuncoes()
    {
        ifstream funcoes;
        funcoes.open("funcoes.txt");
        string linha;

        while (!funcoes.eof())
        {
            getline(funcoes, linha);
            if (linha == "carregarEmpresa()")
            {
                cout << "carregou empresa" << endl;
            }
        }
        funcoes.close();
    }
};

#endif
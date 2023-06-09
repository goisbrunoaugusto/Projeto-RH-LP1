#include <iostream>
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
    string bairro;
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
    Pessoa(){};
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
    int diasDeFalta;

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
    void setDiasDeFalta(int novoDiasDeFalta)
    {
        this->diasDeFalta = novoDiasDeFalta;
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
    Asg(){};
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
    Vendedor(){};
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
    Gerente(){};

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
    Empresa(){};
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
    void carregarEmpresa()
    {
        ifstream empresa;
        empresa.open("empresa.txt");
        string linha;
        float faturamento;
        getline(empresa, linha);
        getline(empresa, linha);
        getline(empresa, linha);
        this->nomeEmpresa = linha;
        getline(empresa, linha);
        this->cnpj = linha;
        getline(empresa, linha);
        faturamento = stof(linha);
        this->faturamentoMensal = faturamento;
        empresa.close();
    };
    void carregarAsg()
    {
        ifstream file;
        file.open("asg.txt");
        string linha;
        Asg asg;
        Endereco endereco;
        Data data, dataIngresso;

        while (!file.eof())
        {
            getline(file, linha);
            getline(file, linha);
            getline(file, linha);
            getline(file, linha);
            asg.setNome(linha);
            getline(file, linha);
            asg.setCPF(linha);
            getline(file, linha);
            asg.setQtdFilhos(stoi(linha));
            getline(file, linha);
            asg.setEstadoCivil(linha);

            getline(file, linha);
            getline(file, linha);
            endereco.cidade = linha;
            getline(file, linha);
            endereco.cep = linha;
            getline(file, linha);
            endereco.bairro = linha;
            getline(file, linha);
            endereco.rua = linha;
            getline(file, linha);
            endereco.numero = stoi(linha);
            asg.setEnderecoPessoal(endereco);

            getline(file, linha);

            getline(file, linha);
            data.ano = (stoi(linha));
            getline(file, linha);
            data.mes = (stoi(linha));
            getline(file, linha);
            data.dia = (stoi(linha));
            asg.setDataNascimento(data);

            getline(file, linha);
            getline(file, linha);
            asg.setMatricula(linha);
            getline(file, linha);
            asg.setSalario(linha);
            getline(file, linha);
            asg.setAdicionalInsalubridade(stof(linha));
            getline(file, linha);
            asg.setDiasDeFalta(stoi(linha));

            getline(file, linha);
            getline(file, linha);
            dataIngresso.ano = (stoi(linha));
            getline(file, linha);
            dataIngresso.mes = (stoi(linha));
            getline(file, linha);
            dataIngresso.dia = (stoi(linha));
            asg.setIngressoEmpresa(dataIngresso);

            asgs.push_back(asg);
        }
        file.close();
    }
    void carregarVendedor()
    {
        ifstream file;
        file.open("vendedor.txt");
        string linha;
        Vendedor vendedor;
        Endereco endereco;
        Data data, dataIngresso;

        while (!file.eof())
        {
            getline(file, linha);
            getline(file, linha);
            getline(file, linha);
            getline(file, linha);
            vendedor.setNome(linha);
            getline(file, linha);
            vendedor.setCPF(linha);
            getline(file, linha);
            vendedor.setQtdFilhos(stoi(linha));
            getline(file, linha);
            vendedor.setEstadoCivil(linha);

            getline(file, linha);
            getline(file, linha);
            endereco.cidade = linha;
            getline(file, linha);
            endereco.cep = linha;
            getline(file, linha);
            endereco.bairro = linha;
            getline(file, linha);
            endereco.rua = linha;
            getline(file, linha);
            endereco.numero = stoi(linha);
            vendedor.setEnderecoPessoal(endereco);

            getline(file, linha);
            getline(file, linha);
            data.ano = (stoi(linha));
            getline(file, linha);
            data.mes = (stoi(linha));
            getline(file, linha);
            data.dia = (stoi(linha));
            vendedor.setDataNascimento(data);

            getline(file, linha);
            getline(file, linha);
            vendedor.setMatricula(linha);
            getline(file, linha);
            vendedor.setSalario(linha);
            getline(file, linha);
            vendedor.setTipoVendedor(linha[0]);
            getline(file, linha);
            vendedor.setDiasDeFalta(stoi(linha));

            getline(file, linha);
            getline(file, linha);
            dataIngresso.ano = (stoi(linha));
            getline(file, linha);
            dataIngresso.mes = (stoi(linha));
            getline(file, linha);
            dataIngresso.dia = (stoi(linha));
            vendedor.setIngressoEmpresa(dataIngresso);

            vendedores.push_back(vendedor);
        }
        file.close();
    }
    void carregarGerente()
    {
        ifstream file;
        file.open("gerente.txt");
        string linha;
        Gerente gerente;
        Endereco endereco;
        Data data, dataIngresso;

        while (!file.eof())
        {
            getline(file, linha);
            getline(file, linha);
            getline(file, linha);
            getline(file, linha);
            gerente.setNome(linha);
            getline(file, linha);
            gerente.setCPF(linha);
            getline(file, linha);
            gerente.setQtdFilhos(stoi(linha));
            getline(file, linha);
            gerente.setEstadoCivil(linha);

            getline(file, linha);
            getline(file, linha);
            endereco.cidade = linha;
            getline(file, linha);
            endereco.cep = linha;
            getline(file, linha);
            endereco.bairro = linha;
            getline(file, linha);
            endereco.rua = linha;
            getline(file, linha);
            endereco.numero = stoi(linha);
            gerente.setEnderecoPessoal(endereco);

            getline(file, linha);
            getline(file, linha);
            data.ano = (stoi(linha));
            getline(file, linha);
            data.mes = (stoi(linha));
            getline(file, linha);
            data.dia = (stoi(linha));
            gerente.setDataNascimento(data);

            getline(file, linha);
            getline(file, linha);
            gerente.setMatricula(linha);
            getline(file, linha);
            gerente.setSalario(linha);
            getline(file, linha);
            gerente.setParticipacaoLucros(stof(linha));
            getline(file, linha);
            gerente.setDiasDeFalta(stoi(linha));

            getline(file, linha);
            getline(file, linha);
            dataIngresso.ano = (stoi(linha));
            getline(file, linha);
            dataIngresso.mes = (stoi(linha));
            getline(file, linha);
            dataIngresso.dia = (stoi(linha));
            gerente.setIngressoEmpresa(dataIngresso);

            gerentes.push_back(gerente);
        }
        file.close();
    }
    void carregaDono()
    {
        ifstream file;
        file.open("dono.txt");
        string linha;
        Endereco endereco;
        Data data;

        getline(file, linha);
        getline(file, linha);
        getline(file, linha);

        getline(file, linha);
        dono.setNome(linha);
        getline(file, linha);
        dono.setCPF(linha);
        getline(file, linha);
        dono.setQtdFilhos(stoi(linha));
        getline(file, linha);
        dono.setEstadoCivil(linha);

        getline(file, linha);
        endereco.cidade = linha;
        getline(file, linha);
        endereco.cep = linha;
        getline(file, linha);
        endereco.bairro = linha;
        getline(file, linha);
        endereco.rua = linha;
        getline(file, linha);
        endereco.numero = stoi(linha);
        dono.setEnderecoPessoal(endereco);

        getline(file, linha);
        data.ano = stoi(linha);
        getline(file, linha);
        data.mes = stoi(linha);
        getline(file, linha);
        data.dia = stoi(linha);
        dono.setDataNascimento(data);

        file.close();
    }
    void imprimeAsgs()
    {
        cout << "Lista de auxiliares de serviços gerais:" << endl;
        for (auto i : asgs)
        {
            cout << "Nome: " << i.getNome() << endl;
            cout << "CPF: " << i.getCpf() << endl;
            cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
            cout << "Endereço: " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
            cout << "Estado civil: " << i.getEstadoCivil() << endl;
            cout << "Número de filhos: " << i.getQtdFilhos() << endl;
            cout << "Salário: " << i.getSalario() << endl;
            cout << "Matrícula: " << i.getMatricula() << endl;
            cout << "Data de ingresso: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }

    void imprimeVendedores()
    {
        cout << "Lista de vendedores:" << endl;
        for (auto i : asgs)
        {
            cout << "Nome: " << i.getNome() << endl;
            cout << "CPF: " << i.getCpf() << endl;
            cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
            cout << "Endereço: " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
            cout << "Estado civil: " << i.getEstadoCivil() << endl;
            cout << "Número de filhos: " << i.getQtdFilhos() << endl;
            cout << "Salário: " << i.getSalario() << endl;
            cout << "Matrícula: " << i.getMatricula() << endl;
            cout << "Data de ingresso: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }
    void imprimeGerentes()
    {
        cout << "Lista de gerentes:" << endl;
        for (auto i : asgs)
        {
            cout << "Nome: " << i.getNome() << endl;
            cout << "CPF: " << i.getCpf() << endl;
            cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
            cout << "Endereço: " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
            cout << "Estado civil: " << i.getEstadoCivil() << endl;
            cout << "Número de filhos: " << i.getQtdFilhos() << endl;
            cout << "Salário: " << i.getSalario() << endl;
            cout << "Matrícula: " << i.getMatricula() << endl;
            cout << "Data de ingresso: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }
    void imprimeDono()
    {
        cout << "Lista de auxiliares de serviços gerais:" << endl;
        for (auto i : asgs)
        {
            cout << "Nome: " << i.getNome() << endl;
            cout << "CPF: " << i.getCpf() << endl;
            cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
            cout << "Endereço: " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
            cout << "Estado civil: " << i.getEstadoCivil() << endl;
            cout << "Número de filhos: " << i.getQtdFilhos() << endl;
            cout << "Salário: " << i.getSalario() << endl;
            cout << "Matrícula: " << i.getMatricula() << endl;
            cout << "Data de ingresso: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }
    void buscaFuncionario();
    void calculaSalarioFuncionario();
    void calculaTodoOsSalarios();
    void calcularRecisao();

    void carregaFuncoes()
    {
        ifstream funcoes;
        funcoes.open("funcoes.txt");
        string linha;

        while (!funcoes.eof())
        {
            getline(funcoes, linha);
            if (linha == "carregarEmpresa()")
                carregarEmpresa();
            else if (linha == "carregarAsg()")
                carregarAsg();
            else if (linha == "carregarVendedor()")
                carregarVendedor();
            else if (linha == "carregarGerente()")
                carregarGerente();
            else if (linha == "carregaDono()")
                carregaDono();
            else if (linha == "imprimeAsgs()")
                imprimeAsgs();
            else if (linha == "imprimeVendedores()")
                imprimeVendedores();
            else if (linha == "imprimeGerentes()")
                imprimeGerentes();
            else if (linha == "imprimeDono()")
                imprimeDono();
            else if (linha == "buscaFuncionario()")
                buscaFuncionario();
            else if (linha == "calculaSalarioFuncionario()")
                calculaSalarioFuncionario();
            else if (linha == "calculaTodoOsSalarios()")
                calculaTodoOsSalarios();
            else if (linha == "calcularRecisao()")
                calcularRecisao();
        }
        funcoes.close();
    }
};

int main()
{
    Empresa empresa;

    empresa.carregaFuncoes();

    return 0;
}
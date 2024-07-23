# Polimorfismo em Orientação a Objetos com C++

## 1. Conceito de Polimorfismo

**Definição**: Capacidade de uma função ou método de processar dados de diferentes tipos.

### Tipos de Polimorfismo:

- **Polimorfismo em Tempo de Compilação (Sobrecarga)**: Overloading e templates.
- **Polimorfismo em Tempo de Execução (Dinâmico)**: Herança e funções virtuais.

## 2. Polimorfismo em Tempo de Compilação

### Sobrecarga de Funções (Function Overloading):

- Definição de múltiplas funções com o mesmo nome, mas diferentes assinaturas.

### Sobrecarga de Operadores (Operator Overloading):

- Definição de novos comportamentos para operadores existentes.

### Templates:

- **Function Templates**: Funções genéricas que funcionam com qualquer tipo de dados.
- **Class Templates**: Classes genéricas que podem ser usadas com qualquer tipo de dados.

## 3. Polimorfismo em Tempo de Execução

### Herança:

- **Classe Base e Classe Derivada**: Relação entre classes através da herança.
- **Herança Múltipla**: Herança de múltiplas classes base.

### Funções Virtuais:

- **Definição**: Funções que podem ser sobrescritas em classes derivadas.
- **VTable**: Tabela de ponteiros para funções virtuais.

### Classe Abstrata e Funções Virtuais Puras:

- **Classe Abstrata**: Classe que não pode ser instanciada, contém pelo menos uma função virtual pura.
- **Função Virtual Pura**: Função que não tem implementação na classe base (`virtual void func() = 0;`).

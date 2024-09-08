#  Exercício 01: Reverse Polish Notation (RPN)

**Regras específicas do módulo**:
* Uso de container padrao é obrigatorio.
* Cada container utilizado em um exercicio não pode ser reutilizado nos exercicios seguintes.
* O uso de dois containers é obrigatório no exercício 02

**Objetivo**: Criar um programa que interprete expressões matemáticas na notação polonesa reversa.

##### Requisitos:
- [ ] O nome do programa deve ser RPN
- [ ] O programa deve aceitar uma expressao RPN como argumento.
- [ ] Operadores permitidos: `+ - / *`
- [ ] Em caso de erro, a mensagem deve ser direcionada para a saída de erro padrão.
- [ ] Os números usados serão sempre menores que 10.
>Você não precisa gerenciar os colchetes ou números decimais.

##### Dicas de Estudo:
* Estude o conceito de RPN e como ele é resolvido utilizando uma pilha (stack).
* Reforce o conhecimento sobre manipulação de strings e cálculos aritméticos.

##### Formas de resolução:
* Utilize uma `stack` para processar os operadores
* Implemente o tratamento de erros para entradas malformadas.

**Aqui está um exemplo do uso do programa:**

    $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
    42
    $> ./RPN "7 7 * 7 -"
    42
    $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
    0
    $> ./RPN "(1 + 1)"
    Error
    $>

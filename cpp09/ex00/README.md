# Exercício 00: Bitcoin Exchange

**Regras específicas do módulo**:
* Uso de container padrao é obrigatorio.
* Cada container utilizado em um exercicio não pode ser reutilizado nos exercicios seguintes.
* O uso de dois containers é obrigatório no exercício 02

**Objetivo**: Criar um programa que calcula o valor do Bitcoin em uma data específica.

##### Requisitos:
- [x] O nome do programa deve ser `btc`.
- [X] O programa deve ler um arquivo CSV contendo os preços do Bitcoin.
- [x] Deve calcular o valor de Bitcoin de acordo com a data especificada no arquivo de entrada.
- [x] Data válida estará sempre no formato: Ano-Mês-Dia.
- [x] O arquivo de entrada segue o formato `data | valor`.
- [x] Gerar uma mensagem de erro para entradas invalidas ou valores fora do intervalo (0 a 1000).
>O valor válido deve ser um float ou um inteiro positivo, entre 0 e 1000.

##### Dicas de Estudo:
* Revise como manipular arquivos e containers em C++.
* Pratique com a leitura e manipulação de arquivos CSV.

##### Formas de resolução:
* Utilize um container como `map` ou `unordered map` para armazenar os preços do Bitcoin e suas datas.
* Lide com a correspondencia de datas usando algoritmos de busca.

**Aqui temos um exemplo de um arquivo input.txt**:

    > head input.txt
    date | value
    2011-01-03 | 3
    2011-01-03 | 2
    2011-01-03 | 1
    2011-01-03 | 1.2
    2011-01-09 | 1
    2012-01-11 | -1
    2001-42-42
    2012-01-11 | 1
    2012-01-11 | 2147483648
    $>

- [ ] Seu programa deve exibir na saída padrão o resultado do valor multiplicado pela taxa de câmbio de acordo com a data indicada em seu banco de dados.
> Se a data usada na entrada não existir no seu BD, então você deve usar a data mais próxima contida no seu BD. Tenha cuidado para usar a data mais baixa e não a mais alta.

A seguir, um exemplo de uso do programa:

    $> ./btc
    Error: could not open file.
    $> ./btc input.txt
    2011-01-03 => 3 = 0.9
    2011-01-03 => 2 = 0.6
    2011-01-03 => 1 = 0.3
    2011-01-03 => 1.2 = 0.36
    2011-01-09 => 1 = 0.32
    Error: not a positive number.
    Error: bad input => 2001-42-42
    2012-01-11 => 1 = 7.1
    Error: too large a number.
    $>

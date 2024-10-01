#  Exercício 02: PmergeMe

**Regras específicas do módulo**:
* Uso de container padrao é obrigatorio.
* Cada container utilizado em um exercicio não pode ser reutilizado nos exercicios seguintes.
* O uso de dois containers é obrigatório no exercício 02

**Objetivo**: Implementar o algoritmo Ford-Johnson para ordenar uma sequência de inteiros usando a técnica merge-insert sort.

#### Requisitos:
- [x] O programa deve ter o nome de PmergeMe
- [ ] O programa deve ordenar uma sequência de inteiros positivos fornecida como argumento.
- [ ] Seu programa deve usar o algoritmo merge-insert sort para ordenar os inteiros em sequência.
- [ ] Erros devem ser encaminhados para a saida de erro padrão.
- [ ] Deve utilizar dois containers diferentes e ser capaz de lidar com até 3000 números.
- [ ] exibir o tempo de execução de cada container.

#### Dicas de Estudo:
* Pesquise sobre o algoritmo Ford-Johnson e a implementação de merge sort.
* Pratique o uso de containers como vector e deque.

#### Formas de resolução:
* Implemente a lógica de ordenação para cada container separadamente.
* Meça o tempo de execução usando a biblioteca <chrono\>

**Aqui estão algumas diretrizes adicionais sobre as informações que você deve exibir linha por linha na saída padrão:**
* Na primeira linha, você deve exibir um texto explícito seguido pela sequência de inteiros positivos não classificados.
* Na segunda linha, você deve exibir um texto explícito seguido pela sequência de inteiros positivos classificados.
* Na terceira linha, você deve exibir um texto explícito indicando o tempo usado pelo seu algoritmo, especificando o primeiro contêiner usado para classificar a sequência de inteiros positivos.
* Na última linha, você deve exibir um texto explícito indicando o tempo usado pelo seu algoritmo, especificando o segundo contêiner usado para classificar a sequência de inteiros positivos.

>O formato de exibição do tempo utilizado para realizar sua triagem é livre, mas a precisão escolhida deve permitir ver claramente a diferença entre os dois recipientes utilizados.

#### Implementaçao:
    1. [] Determine se o array é par ou ímpar em comprimento. Se for ímpar, remova o último número, designe-o como um "straggler" e insira-o mais tarde no array ordenado.
    2. [] Divida arbitrariamente a sequencia para classifica-la em pares de dois valores
    3. [] Classifique os pares, para que a ordem seja sempre [menor, maior]
    4. [] Classifique a sequencia resursivamente pelo valor do seu maior par.
    5. [] Crie uma nova sequencia "S", retirando o valor [mais alto] de cada par e inserindo-o em "S".
    6. [] Os valores restantes formam uma matriz temporaria "pend"
    7. [] Com base no comprimento de "pend", construa a sequencia de inserçao ideal usando numeros de jacobsthal relevantes.
    8. [] Percorra os elementos em "pend" e, usando a sequencia de inserçao criada na etapa anterior, use a pequesquisa binaria para inserir cada elemento "pend" em "S".
    9. [] Se um "straggler" for encontrado, faça um loop de sobras e uma insercao para completar a lista

**Aqui está um exemplo de uso padrão:**

    $> ./PmergeMe 3 5 9 7 4
    Before: 3 5 9 7 4
    After: 3 4 5 7 9
    Time to process a range of 5 elements with std::[..] : 0.00031 us
    Time to process a range of 5 elements with std::[..] : 0.00014 us
    $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
    Before: 141 79 526 321 [...]
    After: 79 141 321 526 [...]
    Time to process a range of 3000 elements with std::[..] : 62.14389 us
    Time to process a range of 3000 elements with std::[..] : 69.27212 us
    $> ./PmergeMe "-1" "2"
    Error
    $> # For OSX USER:
    $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
    [...]
    $>

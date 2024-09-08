# Exercício 00: Bitcoin Exchange

**Regras específicas do módulo**:
* Uso de container padrao é obrigatorio.
* Cada container utilizado em um exercicio não pode ser reutilizado nos exercicios seguintes.
* O uso de dois containers é obrigatório no exercício 02

**Objetivo**: Criar um programa que calcula o valor do Bitcoin em uma data específica.

##### Requisitos:
- [ ] O programa deve ler um arquivo CSV contendo os preços do Bitcoin.
- [ ] Deve calcular o valor de Bitcoin de acordo com a data especificada no arquivo de entrada.
- [ ] O arquivo de entrada segue o formato `data | valor`.
- [ ] Gerar uma mensagem de erro para entradas invalidas ou valores fora do intervalo (0 a 1000).

##### Dicas de Estudo:
* Revise como manipular arquivos e containers em C++.
* Pratique com a leitura e manipulação de arquivos CSV.

##### Formas de resolução:
* Utilize um container como `map` ou `unordered map` para armazenar os preços do Bitcoin e suas datas.
* Lide com a correspondencia de datas usando algoritmos de busca.

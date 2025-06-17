Programa 1
O programa lê um arquivo de texto que contém registros de leituras de sensores, onde cada linha tem um timestamp, um identificador do sensor e o valor medido. Ele armazena essas leituras em um array, depois ordena todas elas em ordem decrescente de timestamp (do mais recente para o mais antigo). Em seguida, para cada leitura, o programa grava os dados em arquivos separados, criando um arquivo para cada sensor com o nome do identificador do sensor, e escreve as leituras ordenadas dentro desses arquivos. Isso permite organizar os dados por sensor e com as leituras mais recentes no topo.
Para executar o programa, basta compilar o código em C e rodar no terminal passando como argumento o arquivo de entrada com as leituras, por exemplo:
./programa leituras.txt

Programa 2 
Ele lê um arquivo de texto que contém diversas leituras de sensores. Cada linha do arquivo tem três informações:
timestamp (um número grande que representa o momento da leitura),
id_sensor (nome do sensor),
valor (o valor da leitura).
O programa armazena todas essas leituras em uma lista na memória.
Depois, ele ordena essa lista de leituras pela data e hora (timestamp) em ordem decrescente — ou seja, do registro mais recente para o mais antigo.
Em seguida, o programa cria arquivos separados para cada sensor (com o nome do sensor + ".txt") e grava dentro deles todas as leituras desse sensor, na ordem decrescente.
Compile o código com um compilador C, por exemplo:
gcc seu_codigo.c -o programa
Execute o programa passando como argumento o nome do arquivo que contém as leituras:
./programa arquivo_entrada.txt

Programa 3 
Ele gera um arquivo chamado dados.txt contendo leituras simuladas de vários sensores entre duas datas que você escolher.
Cada linha do arquivo terá:
Um timestamp (que é a data e hora da leitura, em formato numérico),
O nome do sensor,
O valor da leitura (que pode ser número inteiro, número decimal, valor booleano ou texto, dependendo do tipo do sensor).
Como o programa funciona
Você passa para o programa, na linha de comando:
A data e hora de início (exemplo: 2025-06-01T00:00:00),
A data e hora de fim (exemplo: 2025-06-05T23:59:59),
Depois, vários sensores com seus tipos, no formato: nome_sensor:tipo.
O programa converte as datas para números que representam o tempo.
Para cada sensor, ele gera 2000 leituras com datas aleatórias entre o início e o fim.
Os valores das leituras são criados aleatoriamente de acordo com o tipo que você escolheu para cada sensor.
Como executar
Compile o programa:
gcc seu_codigo.c -o gerar_dados
Execute passando as datas e sensores. Exemplo:
./gerar_dados 2025-06-01T00:00:00 2025-06-05T23:59:59 temperatura:CONJ_Q porta:BINARIO umidade:CONJ_Z status:TEXTO
Isso vai criar o arquivo dados.txt com as leituras simuladas para esses sensores.





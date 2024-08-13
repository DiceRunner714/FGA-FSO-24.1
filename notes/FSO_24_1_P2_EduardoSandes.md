# FUNDAMENTOS DE SISTEMAS OPERACIONAIS

Bibliografias:
- SISTEMAS OPERACIONAIS MODERNOS 4ª EDIÇÃO
    - Autor: TANENBAUM, A.S. Obra: Sistemas Operacionais Modernos Editor: Pearson Edição: 3ª Ano:
2010
- Slides do professor
    - Módulo 07 - Gerência de Memória, Prof. Daniel Sundfeld

Capítulos (Tanenbaum):

Slides:
7. Gerência de Memória

## #7 GERÊNCIA DE MEMÓRIA

- A **memória RAM** precisa ser cuidadosamente gerenciada.
- não existe memória rápida e não volátil.
- **memória não volátil**: não perde os dados ao se desligar o computador (permanentemente).

### Hierarquia de memória

![Imagem6](6.png)

- Os registradores são a **memória mais rápida**. Eles são manipulados diretamente por programas ou usados pelo hardware.
- A memória cache é completamente gerenciada pelo hardware.
- O foco da gerência de memória é da **memória principal** (RAM).

### Funções básicas

- Os programas são armazenados em memória secundária, logo, para executarem devem ser carregados (pelo SO) para a memória principal.
- 

---

# JOAO ENTEDIMENTO

### Geren Memoria

#### nao tem memoria suficiente pra tudo

* Memória princial

toda vez q execut um programa vc precissa carregar ele na mem secundaria para mem principal e isso em si ja é uma operaçao custosa pois tem entrada e saida o idea é que todos os programas ja estejam na cache do processador mas como nao tem espaço...

mem Principal precisa de uma parte para o SO, pois o kernel prceisa ta sempre rodando e o restantee para o programa de usuario

RODANDO O PROGRAMA A

S0 -BARREIRA- A 

S0 TEM UMA BARREIRA PRA IMPEDIR QUE PROGRAMAS DE USUARIO ACESSEM Ele

### Alocaçao continua simples

guarda o sistema operacional e guarda todos os outros programas continuamente na memória principal

Toda vez que um programa tenta acessar alguma parte do S0 ele recebe uma violação de acesso.

#### OVERLAY - Alocaçao continua

Dado um programa A pode dividir em modulos independentes

nao precisa que o porgrama inteiro esteja na memoria, precisa que um modulo principal esteja na memoria, no caso o mod 1:

> modulo 1
LIBT
PROGRAM
VAR 1 2 3

> modulo 2
SOMA

> modulo 3
IMPRIME 

o usuario escolhe a area de overlay, precisa do tam do maior modulo que vai precisar


### ALOCAÇÃO PARTICIONADA

Desde o inicio da memoria cria as partiçoes para os programas q vao executar

Todo programa roda na menor memoria que cabe ele.
Se essa memoria (particao) está ocupada ele simplesmente enfileira

NÃO SEPARA MEMORIA MAIOR DO Q O NECESSARIO

Garante que o maior programa se encaixe em alguma partição

#### Estática Realocavel - ALOCAÇÃO PARTICIONALDA

Se a partição ta ocupada vai pro proximo.

Impede que uma partição acesse um endereço que ta fora dele


#### Dinamica - ALOCAÇÃO  PARTICIONADA

Não existe partição de tamanho fixo.






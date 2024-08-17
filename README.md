# Implementação usando a linguagem C do problema </br> "Jantar Dos Filosofos"

### Essa atividade foi proposta na disciplina de sistemas operacionais, com base no aprendizado em gerenciamento de tarefas.

Para implementar o problema do Jantar dos Filósofos foi utilizado semáforos, através de funções já existentes na linguagem.
Primeiramente na função o filósofo entra na região protegida pelo mutex antes de tentar pegar os hashis. Após isso, o filósofo poderá pegar o hashi da esquerda e da direita, sendo esses semáforos decrementados em seguida, indicando que os grafos estão ocupados. 
Com isso, o filósofo pode comer por um determinado tempo. Para finalizar é feita a devolução dos hashis.

Foi usado também o mutex para garantir que apenas um filósofo possa tentar pegar os hashis por vez. Isso reduz a chance de deadlock, pois evita que múltiplos filósofos entrem na seção crítica ao mesmo tempo.

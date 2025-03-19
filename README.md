# Sistema de Fila de Chamadas

Este é um sistema simples em C para gerenciar uma fila de chamadas. Ele permite adicionar chamadas à fila, finalizar o atendimento de chamadas e calcular o tempo médio de espera.

### Funcionalidades
- Adicionar Chamadas: Gera um número de telefone aleatório e registra a chamada na fila de espera.
- Finalizar Chamadas: Move a primeira chamada da fila de espera para a lista de atendidas e calcula o tempo de espera.
- Cálculo de Tempo Médio de Espera: Calcula o tempo médio de espera das chamadas atendidas.
- Exibição das Filas: Mostra as chamadas na fila de espera e as chamadas finalizadas.

Exemplo de Saída

```foi a adicionado à lista de espera o cliente número 1, telefone +55 (69)9xxxxxxx
A chamada referente ao telefone +55 (69)9xxxxxxx foi finalizada após aguardar 1.00 segundos

Chamadas na fila de espera:
n 1 - telefone: +55 (69)9yyyyyyy, entrada: Tue Mar 19 10:52:32 2025

Chamadas finalizadas:
n 1 - telefone: +55 (69)9xxxxxxx, entrada: Tue Mar 19 10:52:32 2025, espera: 1.00s

Tempo médio de espera: 1.00s```

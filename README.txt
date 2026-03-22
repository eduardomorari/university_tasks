Funções implementadas:

 - Inserção no Final: 
 Fiz uma condicão se o L.tamanho é menor que o MAX, o valor é inserido na posição "L.tamanho" e, em seguida o L.tamanho
 é incrementado.

 - Inserção em Posição Arbitrária:
 Fiz uma condicional para se o L.tamanho for menor que o MAX-1, eu incremento o L.tamanho para liberar uma posição
 no final e, em seguida implementei um for para "varrer" a lista do fim até a posição selecionada "empurrando" os
 elementos para a direita. E caso o L.tamanho fosse exatamente igual a MAX-1, eu simplismente reutilizo a função
 de inserção, para evitar o acesso de memória indevida.

 - Remoção por Posição:
 Fiz uma verificação se o L.tamanho é maior ou igual a 0 para garantir que a lista não está vazia. Depois, usei 
 um for começando da posição escolhida até o final da lista para sobrescrever os elementos, "puxando" todo mundo 
 uma casa para a esquerda, e no fim decremento o L.tamanho.

 - Busca de Valor:
 Implementei um for que percorre a lista inteira comparando cada elemento com o valor que eu quero encontrar. Se
 ele achar o valor, a função já retorna o índice (i) na hora; se o laço terminar e não encontrar nada, ela retorna -1.

 - Remoção por Valor:
 Criei uma lógica que percorre a lista procurando o valor desejado. Assim que ele é encontrado, eu reaproveito a 
 função de "Remoção por Posição" passando o índice atual e uso um break para interromper o laço, garantindo que apenas
 a primeira ocorrência do valor seja removida. Se encontrar e remover, retorna true, caso contrário, retorna false.

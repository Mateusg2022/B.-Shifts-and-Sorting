Questão do codeforces 1969/problem/B
Esse código leva 'Time limit exceeded', pois a resolução correta é calcular o custo pra ordenar a sequência, sem necessáriamente fazer a ordenação. Porém, achei interessante fazer a ordenação e calcular o numero de shifts feitos, ou seja,
quantas vezes o algoritmo selecionou uma substring e fez a rotação dela durante a ordenação. O custo que a questão pede seria, para cada substring selecionada para o shift, calcular 'Right - Left + 1' e adicionar ao somatório.
Um shift significa selecionar uma substring da minha sequência original e 'rotaciona-lo'. O elemento na posição i vai para a posição i+1 e o elemento em N vai para a posição 0. 
Exemplo:
  original: 1001 - shiftado: 1100.

Input: 
  quantidade de testes t (1≤t≤10^4)
  binary string s (2≤|s|≤2⋅105; si∈ {0, 1})

Compilação:
  g++ shift.cpp -o main
  ./main

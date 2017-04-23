## Trace

1- Utilizando a seguinte base de fatos e regras:
   ```prolog
   pai(roberto,joao).
   pai(joao, jose).
   pai(roberto,julio).
   pai(julio,marcos).
   pai(julio,mario).
   avo(X,Z) :- pai(X,Y), pai(Y,Z).
   ```
Para a seguinte chama: 
   ```
   ?- avo(joao,Y).
   false.
   ```
 temos o quadro abaixo:
 
   Prolog dialog/trace output  | Comentarios
   :------------- | -------------
   ?- [t3parte1]. | "Include" do arquivo t3parte1.pl
   true. |
   ?- trace. | Ligando tracing
   true. | 
   [trace]  ?- avo(joao, Y). | Chamada da regra avo
   Call: (7) avo(joao, _G2290) ? creep | Trace faz consulta, substituindo Y por um valor unico
   Call: (8) pai(joao, _G2366) ? creep | Chamada da regra pai, buscando um valor para Y, quando X = joao
   Exit: (8) pai(joao, jose) ? creep | Sucesso(pai). Encontrou Y = jose, quando X = joao
   Call: (8) pai(jose, _G2290) ? creep | Chamada da regra pai, buscando um valor para Y, quando X = jose
   Fail: (8) pai(jose, _G2290) ? creep | Falha(pai). Não encontrou um valor para Y, quando X = jose
   Fail: (7) avo(joao, _G2290) ? creep | Falha(avo). Não encontrou um valor para Y, quando X = joao
   false. | Falha da Chama da regra avo
   
   ```prolog
   ?- avo(roberto,Y).
   Y = jose ;
   Y = marcos ;
   Y = mario.
   ```
   Prolog | Comentário
   :---------|---------------
   [trace]  ?- avo(roberto, Y). | Chamada da regra avo
   Call: (7) avo(roberto, _G2290) ? creep | Buscando um possível valor para Y quando X = roberto
   Call: (8) pai(roberto, _G2366) ? creep | Chamada da regra pai. Buscando um valor para Y quando X = roberto
   Exit: (8) pai(roberto, joao) ? creep | Sucesso(pai). Encontrou Y = joao quando X = roberto
   Call: (8) pai(joao, _G2290) ? creep | Chamada da regra pai. Buscando um valor para Y quando X = joao
   Exit: (8) pai(joao, jose) ? creep | Sucesso(pai). Encontrou Y = jose quando X = joao
   *Exit: (7) avo(roberto, jose) ? creep |Sucesso(avo). Como as duas chamadas da regra pai resultaram true, o valor encotrado foi Y = jose quando X = roberto
   Y = jose . | primeiro resultado da primeira chamada da regra avo
   Redo: (8) pai(roberto, _G3476) ? creep | Buscando outro possivel valor para Y quando X = roberto
   Exit: (8) pai(roberto, julio) ? creep | Sucesso(pai). Encontrou Y = julio quando X = roberto
   Call: (8) pai(julio, _G3400) ? creep | Chamada da regra pai. Buscando valor de Y quando X = julio
   Exit: (8) pai(julio, marcos) ? creep | Sucesso(pai). Encontrou Y = marcos quando X = julio
 *Exit: (7) avo(roberto, marcos) ? creep | Sucesso(avo). Como as duas chamadas da regra pai resultaram true, o valor encotrado foi Y = marcos quando X = roberto
Y = marcos ; | Segundo resultado da primeira chamada da regra avo
   Redo: (8) pai(julio, _G3400) ? creep | Buscando um segundo possivel valor para Y quando X = julio
   Exit: (8) pai(julio, mario) ? creep | Sucesso(pai). Encontrou Y = mario quando X = julio
 *Exit: (7) avo(roberto, mario) ? creep | Sucesso(avo). Como para X = julio a o fato pai possui duas ocorrências, quando a regra avo é chamada com X = roberto é encontrado dois valores para Y
Y = mario. | Terceira resultado da primeira chamada da regra avo 


2- Utilizando a seguinte base de regra e fato:
   ```prolog
   azulejos(0,0).
   azulejos(Na,Nq) :-
      Na > 0,
      Q is floor(sqrt(Na)),
      R is Na - Q*Q,
      azulejos(R,C),
      Nq is 1 + C.
   ```
Para a chamada:
   ```
   ?- azulejos(120,A).
   ```
   Temos o quadro abaixo:
   
   Prolog | Comentário
   :---------|---------------
[trace]  ?- azulejos(120, A). | Chamada da regra azulejos
   Call: (7) azulejos(120, _G2290) ? creep | Irá buscar um possivel valor para A quando Na = 120
   Call: (8) 120>0 ? creep | Teste se 120 maior que 0
   Exit: (8) 120>0 ? creep | Sucesso no teste
   Call: (8) _G2369 is floor(sqrt(120)) ? creep | Calculo do valor
   Exit: (8) 10 is floor(sqrt(120)) ? creep | Atribuição do valor calculado. Q = 10
   Call: (8) _G2375 is 120-10*10 ? creep | Calculo do valor
   Exit: (8) 20 is 120-10*10 ? creep | Atribuição do valor calculado. R = 20
   Call: (8) azulejos(20, _G2376) ? creep | chamada recursiva, com Na = 20
   Call: (9) 20>0 ? creep | Teste se 20 maior que 0
   Exit: (9) 20>0 ? creep | Sucesso no teste
   Call: (9) _G2379 is floor(sqrt(20)) ? creep | Calculo do Valor
   Exit: (9) 4 is floor(sqrt(20)) ? creep | Atribuição do valor calculado. Q = 4
   Call: (9) _G2385 is 20-4*4 ? creep | Calculo do Valor
   Exit: (9) 4 is 20-4*4 ? creep | Atribuição do valor calculado. Q = 4
   Call: (9) azulejos(4, _G2386) ? creep | Chamada recursiva, com Na = 4
   Call: (10) 4>0 ? creep | Teste se 4 maior que 0
   Exit: (10) 4>0 ? creep | Sucesso no teste
   Call: (10) _G2389 is floor(sqrt(4)) ? creep | Calculo do Valor
   Exit: (10) 2 is floor(sqrt(4)) ? creep | Atribuição do valor calculado. Q = 2
   Call: (10) _G2395 is 4-2*2 ? creep | Calculo do Valor
   Exit: (10) 0 is 4-2*2 ? creep | Atribuição do valor calculado. Nq = 0
   Call: (10) azulejos(0, _G2396) ? creep | Chamada recursiva com Na = 0
   Exit: (10) azulejos(0, 0) ? creep | Sucesso(azulejos). Quando Na = 0, Nq = 0
   Call: (10) _G2398 is 1+0 ? creep | Calculo do Valor
   Exit: (10) 1 is 1+0 ? creep | Atribuição do valor calculado. Nq = 1
   Exit: (9) azulejos(4, 1) ? creep | Sucesso. Quando Nq = 4, A = 1
   Call: (9) _G2401 is 1+1 ? creep | Calculo do Valor
   Exit: (9) 2 is 1+1 ? creep | Atribuição do valor calculado no passo anterior
   Exit: (8) azulejos(20, 2) ? creep | Sucesso. Quando Nq = 20, A = 2
   Call: (8) _G2290 is 1+2 ? creep | Calculo do Valor
   Exit: (8) 3 is 1+2 ? creep | Atribuição do valor calculado no passo anterior
   Exit: (7) azulejos(120, 3) ? creep | Sucesso. Quando Nq = 120, A = 3
A = 3 . | Resultado. Quando Na = 120, Nq = 3




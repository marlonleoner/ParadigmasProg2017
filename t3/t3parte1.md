## 1.

Utilizando a seguinte base de fatos e regras:
   ```prolog
   pai(roberto,joao).
   pai(joao, jose).
   pai(roberto,julio).
   pai(julio,marcos).
   pai(julio,mario).
   avo(X,Z) :- pai(X,Y), pai(Y,Z).
   ```

   ```
   ?- avo(joao,Y).
   false.
   ```
|                                                                                                                                                Prolog dialog/trace output                                                                                                                                               | Comentários |
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|-------------|
| ?- [t3parte1]. 
	true.
	
?- trace. true.  [trace]    ?- avo(joao, Y).     Call: (7) avo(joao, _G2290) ? creep     Call: (8) pai(joao, _G2366) ? creep     Exit: (8) pai(joao, jose) ? creep     Call: (8) pai(jose, _G2290) ? creep     Fail: (8) pai(jose, _G2290) ? creep     Fail: (7) avo(joao, _G2290) ? creep false. |             |




   Prolog dialog/trace output  | Comentarios
   ------------- | -------------
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
   Content Cell  | Content Cell
   Content Cell  | Content Cell

   ```
   ?- avo(roberto,Y).
   Y = jose ;
   Y = marcos ;
   Y = mario.
   ```



   ```prolog
   azulejos(0,0).
   azulejos(Na,Nq) :-
      Na > 0,
      Q is floor(sqrt(Na)),
      R is Na - Q*Q,
      azulejos(R,C),
      Nq is 1 + C.
   ```

   ```
   ?- azulejos(120,A).
   ```


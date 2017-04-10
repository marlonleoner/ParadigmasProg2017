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
   First Header  | Second Header
   ------------- | -------------
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


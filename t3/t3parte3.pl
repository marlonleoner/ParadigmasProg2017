/*******************************************************
Questão 4.
Uma nova sala de aula foi inaugurada, para estudo e exercícios em grupo. A sala de aula
tem mesas para seis estudantes.  Quando as mesas são colocadas juntas, numa única fila de mesas,
elas podem ser usadas pelo número de estudantes mostrado na figura abaixo.

	[IMAGEM]

Quantos estudantes podem usar quatro mesas colocadas juntas como mostrado?
(A) 15
(B) 16
(C) 18
(D) 20
(E) 24

?- questao4(4, 15).
false.

?- questao4(4, 16).
false.

?- questao4(4, 18).
true.

?- questao4(4, 20).
false.

?- questao4(4, 24).
false.

?- questao4(4, M).
M = 18.
*******************************************************/

questao4(0, 0).
questao4(M, A) :-
	A is 6 + ((M - 1) * 4),
	M > 0.

/*******************************************************
Questão 5.
Para que 42 estudantes usem mesas colocadas juntas como mostrado, quantas mesas são
necessárias?
(A) 6
(B) 7
(C) 8
(D) 9
(E) 10

?- questao5(6, 42).
false.

?- questao5(7, 42).
false.

?- questao5(8, 42).
false.

?- questao5(9, 42).
false.

?- questao5(10, 42).
true.

?- questao5(M, 42).
M = 10.
*******************************************************/

questao5(0, 0).
questao5(M, A) :-
	M is ((A - 6) / 4) + 1,
	A > 0.

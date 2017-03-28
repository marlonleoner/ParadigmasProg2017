# Eliza

## Fatos `rules`

O código da Eliza identifica a palavra-chave da frase que o usuário digitou e retorna alguma resposta, dentre as possiveis, relacionada com a palavra-chave. Segue abaixo o modelo:
```prolog
% rules([[keyword, importance of keyword],[
%         [pattern #, [the pattern], last response used,
%             [response 1],
%             [response 2],
%             ...
%             [response n]]]]).
```
Exemplo com a palavra-chave "dream":
```prolog
rules([[dream,3],[
	[1,[_],0,
		[what,does,that,dream,suggest,to,you,?],
		[do,you,dream,often,?],
		[what,persons,appear,in,your,dreams,?],
		[do,you,believe,that,dreaming,has,something,to,do,with,your,problem,?],
		[newkey]]]]).
``` 

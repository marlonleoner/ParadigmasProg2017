#1 - Adiciona "Sr. " no início de cada nome da lista 
def addSr(l):
	return list(map(lambda s:"Sr. "+s, l))

#2 - Calcula a função para cada valor de 'n' da lista
def calcFunc(l):
	return list(map(lambda n:(3*(n**2))+(2/n)+1,l))

#3 - Retorna uma lista com as Strings terminadas em 'a'
def endA(l):
	return list(filter(lambda s:s[-1]=='a',l))

#4 - Retorna uma lista com a idade das pessoas que nasceram após 1970
def age70(l):
	return list(filter(lambda i:2017-i>1970,l))

#5 - Multiplica cada valor 'n' da lista por 2, retorna uma lista com tais valores
def mult2(l):
	return list(map(lambda n:n*2,l))

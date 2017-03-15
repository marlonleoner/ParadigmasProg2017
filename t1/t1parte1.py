#1 - Calcula a soma dos quadrados de dois números x e y.
def somaQuad(x,y):
	return x**2+y**2

#2 - Verifica se o primeiro elemento das listas são iguais
def hasEqHeads(l1,l2):
	return l1[0]==l2[0]

#3 - Adiciona "Sr. " no início de cada nome da lista
def putSr(l):
	return list(map(auxPutSr,l))

def auxPutSr(nome):
	return "Sr. "+nome

#4 - Retorna o numero de espaços que a String contém
def countSpc(s):
	return len(list(filter(auxCountSpc,s)))

def auxCountSpc(c):
	return c==' '

#5 - Calcula a função para cada valor de 'n' da lista
def calcFunc(l):
	return list(map(auxCalcFunc,l))

def auxCalcFunc(n):
	return (3*n**2)+(2/n)+1

#6 - Retorna uma lista com os numeros negativos
def neg(l):
        return list(filter(auxNeg,l))

def auxNeg(n):
        return n<0

#7 - Retorna uma lista contendo números entre 0 e 100, inclusive
def btw0n100(l):
	return list(filter(auxBtw0n100,l))

def auxBtw0n100(n):
	return n>=0 and n<=100

#8 - Retorna uma lista contendo somente números pares
def isEven(l):
	return list(filter(auxIsEven,l))

def auxIsEven(n):
	return n%2==0

#9 - Verifica se o caracter 'c' esta contido na String 's'
def charFound(c,s):
	return s.count(c)>0

def cFound(c,s):
	def g(x):
		return c==x
	
	return len(list(filter(g,s)))>0

#10 - Retorna uma lista com marcações HTML adicionada para cada String da lista
def addHTML(l):
	return list(map(auxAddHTML,l))

def auxAddHTML(s):
	return "<p>"+s+"</p>"

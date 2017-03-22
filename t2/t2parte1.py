#1
def addSufix(suf, nomes):
	return [nome+suf for nome in nomes]

#2
def countShorts(words):
	return len([w for w in words if len(w)<5])

#3
def stripVowels(s):
	return ''.join([c for c in s if c not in 'AaEeIiOoUu'])

#4
def hideChars(s):
	return ''.join(['-' if c != ' ' else ' ' for c in s])

#5
def genTables(n):
	return [(x,x**2) for x in range(1,n+1)]

#6
def genCode(l):
	return ''.join([w[0]+w[-1] for w in l])

#7
def myZip(l1,l2):
	return [(l1[x],l2[x]) for x in range(len(l1 if (len(l1)<len(l2)) else l2))]

#8
def enumerate(words):
	return [(x+1,words[x]) for x in range(len(words))]

#9
def isBin(s):
	return len([n for n in s if n not in ['1','0']])==0

#10
def bin2dec(digits):
	return sum([2**(len(digits)-1-y) if digits[y]==1 else 0 for y in range(0, len(digits))])
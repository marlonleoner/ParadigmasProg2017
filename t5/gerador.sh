nomes=("João" "Lucas" "Ana" "Carol" "Pedro" "Matheus" "Gabriela" "Camila")

for i in `seq 1 10`
do
	for j in `seq 0 7`
	do
		NOME=${nomes[$j]}
		ATIVIDADE=Atividade$i
		PONTO=$(($RANDOM%10))
		echo "$NOME,$ATIVIDADE,$PONTO"
	done
done > pontos.csv
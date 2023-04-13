./philo 5 800 200 200 7 > check

a=1

while [ $a -lt 6 ]
do
	cat check | grep "$a\tis eating" | wc -l
	a=`expr $a + 1`
done
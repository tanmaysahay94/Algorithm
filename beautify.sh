for i in *
do
	indent i -o temp.c -bad -bap -bbb
	mv temp.c i
done

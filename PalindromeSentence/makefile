
palindromes: palindromes.o palindromesMODS.o
	gcc -o palindromes palindromes.o palindromesMODS.o

palindromes.o: palindromes.c
	gcc -c palindromes.c

palindromesMODS.o: palindromesMODS.c
	gcc -c palindromesMODS.c

clean:
	rm *.o palindromes

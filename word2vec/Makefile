all:
	g++ main.cpp Word2Vec.cpp -oword2vec -I. -std=c++11 -Ofast -march=native -funroll-loops -fopenmp

so:
	g++ -shared -o libWord2Vec.so -fPIC Interop.cpp Word2Vec.cpp -I. -std=c++11 -Ofast -march=native -funroll-loops -fopenmp


clean:
	rm -f *.o *.so word2vec

#pragma once
#include <cstdlib>

#ifdef WIN32
#define DLL_ENTRY __declspec(dllexport)
#else
#define DLL_ENTRY
#endif

#ifdef __cplusplus
extern "C" {
#endif

	struct MostSimilarPair
	{
		char* item;
		float score;
	};

	DLL_ENTRY void* InitWord2Vec(int iter, int window, int min_count, int table_size, int word_dim,
		int negative, float subsample_threshold, float init_alpha, float min_alpha,
		bool cbow_mean, int num_threads, const char* train_method, const char* model);

	DLL_ENTRY bool ReleaseWord2Vec(void* word2vec);

	DLL_ENTRY void* LoadDocs(const char* filename);
	DLL_ENTRY bool ReleaseDocs(void* docs);

	DLL_ENTRY void InitWeights(void* word2vec, size_t vocab_size);
	DLL_ENTRY void BuildVocab(void* word2vec, void* docs);
	DLL_ENTRY void Train(void* word2vec, void* docs);

	DLL_ENTRY void SaveVocab(void* word2vec, const char* vocab_filename);
	DLL_ENTRY void LoadVocab(void* word2vec, const char* vocab_filename);
	DLL_ENTRY void SaveWord2Vec(void* word2vec, const char* word2vec_filename, int data_type, bool binary);
	DLL_ENTRY void LoadWord2Vec(void* word2vec, const char* word2vec_filename, bool binary);

#if 0
	DLL_ENTRY bool most_similar(void* word2vec, const char* pos, int N, MostSimilarPair** result);
	DLL_ENTRY bool most_similar(void* word2vec, const vector<string>& posWordList, const vector<string>& negWordList, int N, MostSimilarPair** result);
#endif

#ifdef __cplusplus
}
#endif

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) void* InitWord2Vec(int iter, int window, int min_count, int table_size, int word_dim,
		int negative, float subsample_threshold, float init_alpha, float min_alpha,
		bool cbow_mean, int num_threads, const char* train_method, const char* model);

	__declspec(dllexport) bool ReleaseWord2Vec(void* word2vec);

	__declspec(dllexport) void* LoadDocs(const char* filename);
	__declspec(dllexport) bool ReleaseDocs(void* docs);

	__declspec(dllexport) void InitWeights(void* word2vec, size_t vocab_size);
	__declspec(dllexport) void BuildVocab(void* word2vec, void* docs);
	__declspec(dllexport) void Train(void* word2vec, void* docs);

	__declspec(dllexport) void SaveVocab(void* word2vec, const char* vocab_filename);
	__declspec(dllexport) void LoadVocab(void* word2vec, const char* vocab_filename);
	__declspec(dllexport) void SaveWord2Vec(void* word2vec, const char* word2vec_filename, int data_type, bool binary);
	__declspec(dllexport) void LoadWord2Vec(void* word2vec, const char* word2vec_filename, bool binary);

#ifdef __cplusplus
}
#endif
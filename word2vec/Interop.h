#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) void* CreateWord2Vec(int iter, int window, int min_count, int table_size, int word_dim,
		int negative, float subsample_threshold, float init_alpha, float min_alpha,
		bool cbow_mean, int num_threads, const char* train_method, const char* model);

	__declspec(dllexport) bool DeleteWord2Vec(void* word2vec);

#ifdef __cplusplus
}
#endif
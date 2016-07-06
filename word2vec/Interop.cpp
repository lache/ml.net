#include "Interop.h"
#include "Word2Vec.h"

#define W2B(ptr) (reinterpret_cast<Word2Vec*>(ptr))
#define DOCS(ptr) (reinterpret_cast<Docs*>(ptr))

typedef vector<vector<string>> Docs;

void* InitWord2Vec(int iter, int window, int min_count, int table_size, int word_dim,
	int negative, float subsample_threshold, float init_alpha, float min_alpha,
	bool cbow_mean, int num_threads, const char* train_method, const char* model)
{
	Word2Vec* w2v = new Word2Vec(iter, window, min_count, table_size, word_dim, negative, subsample_threshold,
		init_alpha, min_alpha, cbow_mean, num_threads, train_method, model);
	return w2v;
}

bool ReleaseWord2Vec(void* word2vec)
{
	delete W2B(word2vec);
	return true;
}

void* LoadDocs(const char* filename)
{
	Docs* docs = new Docs;
	vector<vector<string>>& sentences = (*docs);
	ifstream in(filename);
	string s;
	while (std::getline(in, s))
	{
		istringstream iss(s);
		sentences.emplace_back(istream_iterator<string>{iss}, istream_iterator<string>{});
	}
	return docs;
}

bool ReleaseDocs(void* docs)
{
	delete DOCS(docs);
	return true;
}

void InitWeights(void* word2vec, size_t vocab_size)
{
	W2B(word2vec)->init_weights(vocab_size);
}

void BuildVocab(void* word2vec, void* docs)
{
	W2B(word2vec)->build_vocab(*DOCS(docs));
}

void Train(void* word2vec, void* docs)
{
	W2B(word2vec)->train(*DOCS(docs));
}

void SaveVocab(void* word2vec, const char* vocab_filename)
{
	W2B(word2vec)->save_vocab(vocab_filename);
}

void LoadVocab(void* word2vec, const char* vocab_filename)
{
	W2B(word2vec)->read_vocab(vocab_filename);
}

void SaveWord2Vec(void* word2vec, const char* word2vec_filename, int data_type, bool binary)
{
	W2B(word2vec)->save_word2vec(word2vec_filename, data_type == 1 ? W2B(word2vec)->C : W2B(word2vec)->WEmbedding, binary);
}

void LoadWord2Vec(void* word2vec, const char* word2vec_filename, bool binary)
{
	W2B(word2vec)->load_word2vec(word2vec_filename, binary);
}

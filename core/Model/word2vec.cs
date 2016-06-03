using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpML.Core.Model.Word2Vec
{
    public class Parameter
    {
        public enum type
        {
            CBOW,
            SkipGram,
        }

        public type Type { get; set; }
        public int Negative { get; set; }
        public bool UseHierarchicalSoftmax { get; set; }

        public double Alpha { get; set; }
        public double MinAlpha { get; set; }
        public int Iteration { get; set; }
        public int HiddenDimension { get; set; }

        public double SampleHighFrequencyWord { get; set; }
        public int WindowSize { get; set; }
        public int MinCount { get; set; }
        public int MaxVocabularySize { get; set; }

        public int NumberOfThreads { get; set; }
    }

    public class Word2Vec
    {
        private DataSet _dataset;
        private Parameter _parameter;
        
        public Word2Vec(DataSet dataset, Parameter parametr)
        {
            _dataset = dataset;
            _parameter = parametr;
        }

        protected void BuildBinaryTree()
        {
        }

        protected void Score()
        {
        }

        protected void BuildVocabulary()
        {
        }

        public void Train()
        {
        }

        public void Load()
        {
        }

        public void Save()
        {
        }

        public dynamic MostSimilar(dynamic positives, dynamic negatives, int N)
        {
            return null;
        }
    }
}

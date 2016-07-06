using System;
using System.Runtime.InteropServices;

namespace core
{
    public static class Word2Vec
    {
        [DllImport("word2vec.dll", EntryPoint = "InitWord2Vec")]
        public static extern IntPtr InitWord2Vec(int iter, int window, int minCount, int tableSize, int wordDim,
            int negative, float subsampleThreshold, float initAlpha, float minAlpha,
            [MarshalAs(UnmanagedType.I1)] bool cbowMean, int numThreads,
            [In] [MarshalAs(UnmanagedType.LPStr)] string trainMethod,
            [In] [MarshalAs(UnmanagedType.LPStr)] string model);

        [DllImport("word2vec.dll", EntryPoint = "ReleaseWord2Vec")]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool ReleaseWord2Vec(IntPtr word2Vec);

        [DllImport("word2vec.dll", EntryPoint = "LoadDocs")]
        public static extern IntPtr LoadDocs([In] [MarshalAs(UnmanagedType.LPStr)] string filename);

        [DllImport("word2vec.dll", EntryPoint = "ReleaseDocs")]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool ReleaseDocs(IntPtr docs);

        [DllImport("word2vec.dll", EntryPoint = "InitWeights")]
        public static extern void InitWeights(IntPtr word2Vec, [MarshalAs(UnmanagedType.SysUInt)] uint vocabSize);

        [DllImport("word2vec.dll", EntryPoint = "BuildVocab")]
        public static extern void BuildVocab(IntPtr word2Vec, IntPtr docs);

        [DllImport("word2vec.dll", EntryPoint = "Train")]
        public static extern void Train(IntPtr word2Vec, IntPtr docs);

        [DllImport("word2vec.dll", EntryPoint = "SaveVocab")]
        public static extern void SaveVocab(IntPtr word2Vec, [In] [MarshalAs(UnmanagedType.LPStr)] string vocabFilename);

        [DllImport("word2vec.dll", EntryPoint = "LoadVocab")]
        public static extern void LoadVocab(IntPtr word2Vec, [In] [MarshalAs(UnmanagedType.LPStr)] string vocabFilename);

        [DllImport("word2vec.dll", EntryPoint = "SaveWord2Vec")]
        public static extern void SaveWord2Vec(IntPtr word2Vec,
            [In] [MarshalAs(UnmanagedType.LPStr)] string word2VecFilename, int dataType,
            [MarshalAs(UnmanagedType.I1)] bool binary);

        [DllImport("word2vec.dll", EntryPoint = "LoadWord2Vec")]
        public static extern void LoadWord2Vec(IntPtr word2Vec,
            [In] [MarshalAs(UnmanagedType.LPStr)] string word2VecFilename, [MarshalAs(UnmanagedType.I1)] bool binary);
    }
}
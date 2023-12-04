using System;

namespace NamespacePlaceholder{
    class Program{

        static bool ex3(string sentence){
            const string MAJ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            bool checker = true;
            if(!(MAJ.Contains(sentence[0]) && sentence[sentence.Length-1] == '.')){
                checker = false;
            }

            for (int i = 0; i < sentence.Length-2 && checker; i++){

                if (sentence[i] == ' ' && sentence[i+1] == ' '){
                    checker = false;
                }

                if (sentence[i] == '.' && sentence[i+1] != ' '){
                    checker = false;
                }

                if (sentence[i] == ',' && sentence[i+1] != ' '){
                    checker = false;
                }

                if (i <= sentence.Length-3){
                    if (sentence[i] != ' ' && sentence[i+1] == ';' && sentence[i+2] == ' '){
                        checker = false;
                    }

                    if (sentence[i] != ' ' && sentence[i+1] == ':' && sentence[i+2] == ' '){
                        checker = false;
                    }
                }
            }

            return checker;
        }
        private static void Main(string[] args){
            Console.WriteLine(ex3("Bonj our j'aime les haricots."));         
        }
    }
}
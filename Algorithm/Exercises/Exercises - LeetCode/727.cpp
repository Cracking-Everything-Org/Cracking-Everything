class Solution {
public:
    string minWindow(string S, string T) {
        // O(n+m)
        int sIndex = 0;
        int tIndex = 0;
        string res = "";
        int minSize = INT_MAX;

        while (sIndex < S.size()) {
            if (S[sIndex] == T[tIndex]) {
                tIndex++;
                if (tIndex == T.size()) { // si llego al final busco hacia el otro lado
                    int end = sIndex;
                    tIndex--;
                    while (tIndex >= 0) { // busco la menor window de derecha a izquierda
                        if (T[tIndex] == S[sIndex]) {
                            tIndex--;
                        }
                        sIndex--;
                    }

                    //Restore tIndex - la seteo en 0 para volver a comparar
                    tIndex = 0;
                    sIndex++; // le hago ++ para que quede posicionado en el primer char en común
                    int size = end - sIndex + 1;

                    // me quedo con el menor tamaño encontrado y seteo al string result
                    if (size < minSize) {
                        minSize = size;
                        res = S.substr(sIndex, size);
                    }
                }
            }

            sIndex++; // paso al siguiente char, así sigo buscando nuevos subsequences y no me quedo siempre en el mismo
        }

        return res;
    }
};

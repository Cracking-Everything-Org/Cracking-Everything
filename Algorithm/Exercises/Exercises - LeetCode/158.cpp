int read(char *buf, int n) {
        char buf4[4];
        int tmpPtr = 0; // para saber donde estoy en el buffer nuestro
        int tmpCnt = 0; // para saber cuantos leí de la API
        int total = 0; // para saber cuando leí todo
        while (total < n) {
            if (tmpPtr == 0) { // leo si estoy en el principio
                tmpCnt = read4(buf4);
            }
            
            if (tmpCnt == 0) { // leí todo
                break;   
            }
            
            while (total < n && tmpPtr < tmpCnt) { // escribo lo que leí
                buf[total++] = buf4[tmpPtr++];
            }
            
            if (tmpPtr == tmpCnt) { // reseteo el puntero
                tmpPtr = 0;
            }
            
            if (tmpCnt < 4) break;
        }
        
        return total;
    }
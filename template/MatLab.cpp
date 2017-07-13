template<class T>
struct Matrix {
    int row, col;
    vector<vector<T> > data;
    Matrix(int r, int c, bool id = false){
        row = r;
        col = c;
        data.resize(row);
        for(int i=0; i<row; i++)
            data[i].resize(col);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                data[i][j] = ((i==j) & id);
            }
        }
    }
    Matrix multiply(const Matrix &ot, long long mod = 0){
		long long reducer = mod*mod;
        assert(col == ot.row);
        Matrix c(row, ot.col);
        for(int i=0; i<c.row; i++){
            for(int j=0; j<c.col; j++){
                c.data[i][j] = 0;
                for(int k=0; k<col; k++){
                    //change here when use double number
                    c.data[i][j] += data[i][k]*(long long)ot.data[k][j];
					if(mod && c.data[i][j] >= reducer) c.data[i][j] -= reducer;
                }
                if(mod) c.data[i][j] %= mod;
            }
        }
        return c;
    }
    Matrix exp(int n, long long mod = 0){
        assert(row == col);
        Matrix temp = *this;
        Matrix res(col, row, true);
        while(n){
            if(n&1){
                res = res.multiply(temp, mod);
                n--;
            } else {
                temp = temp.multiply(temp, mod);
                n /= 2;
            }
        }
        return res;
    }
    void dump(){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout << data[i][j] << " \n"[j==col-1];
            }
        }
    }
};

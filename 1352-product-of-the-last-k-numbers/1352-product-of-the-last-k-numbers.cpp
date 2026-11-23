class ProductOfNumbers {
private:
    vector<int> prefixProd;
    int i=0;

public:
    ProductOfNumbers() {
        prefixProd.push_back(1);
        i = 0;
    }
    
    void add(int num) {
        if(num==0) {
            prefixProd = {1};
            i = 0;
        } else {
            prefixProd.push_back(prefixProd[i]*num);
            i++;
        }
    }
    
    int getProduct(int k) {
        if(k>i) return 0;
        return prefixProd[i]/prefixProd[i-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
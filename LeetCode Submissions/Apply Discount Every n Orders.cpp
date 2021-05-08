class Cashier {
private:
    int customer;
    int discount;
    int n;
    unordered_map<int, int> um;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
    {
        customer=0;
        this->n=n;
        this->discount=discount;
        for(int i=0; i<products.size(); i++)
            um[products[i]]=prices[i];
    }

    double getBill(vector<int> product, vector<int> amount)
    {
        customer++;

        int total=0;
        for(int i=0; i<product.size(); i++)
            total+=(um[product[i]]*amount[i]);

        if(customer==n)
        {
            customer=0;
            return ((1.0)*(total) - (((1.0*discount)*(1.0*total))/100.0));
        }

        return 1.0*total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

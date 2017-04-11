
namespace invnorm {
    template<class Type>
    Type dinvnorm(Type x, Type mu, Type shape, int give_log=0) {
        Type out = 0.5 * log(shape/(2 * M_PI)) - 1.5 * log(x) -
                0.5 * shape * pow(x - mu, 2)/(x * pow(mu, 2)); 
        if (!give_log) 
            return exp(out);
        return out;
    }
    VECTORIZE4_ttti(dinvnorm)

    template<class Type>
    Type dinvnorm_inv(Type x, Type mu, Type sigma, int give_log=0) {
        Type out = 0.5 * log(1/(sigma * 2 * M_PI)) - 1.5 * log(x) -
                   (1/(2 * sigma)) * pow(x - mu, 2)/(x * pow(mu, 2));
        if (!give_log)
            return exp(out);
        return out;
    }
    VECTORIZE4_ttti(dinvnorm_inv)

    template<class Type>
    Type rinvnorm(Type mu, Type shape) {
        Type y = pow(rnorm(Type(0), Type(1)), 2);
        Type z = runif(Type(0), Type(1));
        Type x = mu + (pow(mu, 2) * y)/(Type(2) * shape) - (mu/(Type(2) * shape)) * 
                 sqrt(Type(4)*mu*shape*y + pow(mu, 2) * pow(y, 2));
        
        return CppAD::CondExpLe(z, mu/(mu + x), x, pow(mu, 2)/x);
    }
    VECTORIZE2_n(rinvnorm)
}

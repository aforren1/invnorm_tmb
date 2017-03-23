
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

    // unlikely to work, need to simulate in R instead
    // template<class Type>
    // Type rinvnorm(Type mu, Type shape) {
    //     Type y = pow(rnorm(0, 1), 2);
    //     Type z = runif(0, 1);
    //     Type x = mu + (pow(mu, 2) * y)/(2 * shape) - (mu/(2 * shape)) * sqrt(4*mu*shape*y + pow(mu, 2) * pow(y, 2));
    //     if (z <= mu/(mu + x))
    //        return x;
    //     return pow(mu, 2)/x; 
    // }
    // VECTORIZE2_n(rinvnorm)
}

#include <TMB.hpp>
#include "invnorm.hpp"

template<class Type>
Type objective_function<Type>::operator() ()
{
    DATA_VECTOR(y);
    PARAMETER(mu);
    PARAMETER(sigma);

    Type nll = 0;
    nll -= invnorm::dinvnorm(y, mu, sigma, true).sum();
    SIMULATE {
        y = invnorm::rinvnorm(y.size(), mu, sigma);
        REPORT(y);
    }
    return nll;
}

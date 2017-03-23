#include <TMB.hpp>
#include "invnorm.hpp"

template<class Type>
Type objective_function<Type>::operator() ()
{
    DATA_VECTOR(y);
    PARAMETER(mu);
    PARAMETER(shape);

    Type nll = 0;
    nll -= invnorm::dinvnorm(y, mu, shape, true).sum();
    // SIMULATE {
    //     y = invnorm::rinvnorm(y.size(), mu, shape);
    //     REPORT(y);
    // }
    return nll;
}

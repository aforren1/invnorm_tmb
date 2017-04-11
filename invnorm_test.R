library(TMB)
library(ggplot2)

n <- 500
params <- list(mu = .5, sigma = 20)
data_list <- list(y = statmod::rinvgauss(500, 0.5, 20))

compile('invnorm_test.cpp')
dyn.load(dynlib('invnorm_test'))

obj <- MakeADFun(data = data_list,
                 params, 
                 DLL = 'invnorm_test')

opt <- nlminb(obj$par, obj$fn, obj$gr)

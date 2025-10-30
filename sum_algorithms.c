//
// Created by Adnan Hajro on 29. 10. 2025..
//

#include <stdlib.h>
#include <math.h>
#include "sum_algorithms.h"

// standard double precision sum
double do_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   for (long i = 0; i < ncells; i++){
      sum += var[i];
   }
   return sum;
}

// long double data type sum
double do_ldsum(double* restrict var, long ncells)
{
    long double ldsum = 0.0;
    for (long i = 0; i < ncells; i++) {
        ldsum += (long double)var[i];
    }
    double dsum = ldsum;
    return dsum;
}


// pairwise summation 
double do_pair_sum(double* restrict var, long ncells)
{
   // Pair-wise sum
   double *pwsum = (double *)malloc(ncells/2*sizeof(double));

   long nmax = ncells/2;
   for (long i = 0; i<nmax; i++){
      pwsum[i] = var[i*2]+var[i*2+1];
   }

   for (long j = 1; j<log2(ncells); j++){
      nmax /= 2;
      for (long i = 0; i<nmax; i++){
         pwsum[i] = pwsum[i*2]+pwsum[i*2+1];
      }
   }
   double sum = pwsum[0];

   free(pwsum);
   return(sum);
}

// kahan summation 
double do_kahan_sum(double* restrict var, long ncells)
{
    struct esum_type {
        double sum;
        double correction;
    } local;
    
    double corrected_next_term, new_sum;
    local.sum = 0.0;
    local.correction = 0.0;
    
    for (long i = 0; i < ncells; i++) {
        corrected_next_term = var[i] + local.correction;
        new_sum = local.sum + corrected_next_term;
        local.correction = corrected_next_term - (new_sum - local.sum);
        local.sum = new_sum;
    }
    
    return local.sum + local.correction;
}

// knuth summation 
double do_knuth_sum(double* restrict var, long ncells)
{
    struct esum_type {
        double sum;
        double correction;
    } local;
    
    double u, v, upt, up, vpp;
    local.sum = 0.0;
    local.correction = 0.0;
    
    for (long i = 0; i < ncells; i++) {
        u = local.sum;
        v = var[i] + local.correction;
        upt = u + v;
        up = upt - v;
        vpp = upt - up;
        local.sum = upt;
        local.correction = (u - up) + (v - vpp);
    }
    
    return local.sum + local.correction;
}
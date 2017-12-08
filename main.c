
// Created by sujana on 12/8/2017.

#include <stdio.h>
#include <omp.h>

// The Monte carlo pi program

#include "random.h"

static long trials_no = 10000;

int main ()
{
    long i;  long Num = 0;
    double pi, x, y, test;
    double r = 1.0;

    seed(-r, r);
#pragma omp parallel for private(x,y,test) reduction(+:Num)
    for(i=0;i<trials_no; i++)
    {
        x = random();
        y = random();

        test = x*x + y*y;

        if (test <= r*r) Num++;
    }

    pi = 4.0 * ((double)Num/(double)trials_no);

    printf("\n %d number of trials, pi value is %f \n",trials_no, pi);

    return 0;
}


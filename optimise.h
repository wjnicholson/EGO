#include <vector>
#include <random>
#include "ego.h"

#pragma once

using namespace std;

class Particle
{
  public:
    vector<double> p;
    vector<double> speed;
    vector<double> best;
    double best_fitness;
};

class opt 
{
  public:
    int dimension;
    vector<double> upper;
    vector<double> lower;
    EGO *ego;
    Particle *best_part;
    vector<Particle *> particles;

    vector<uniform_real_distribution<>> *space_generator;
    vector<uniform_real_distribution<>> *speed_generator;
    vector<double> speed_max;

    opt(int d, vector<double> u, vector<double> l, EGO *e);
    void update_particles(int generation, int max_iter);
    void filter();
    void generate(int pop);
    vector<double> optimise(int max_gen, int pop = 100);
};


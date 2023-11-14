#include <random>
#include "celero/Celero.h"

constexpr size_t nmbsmpl = 0;
constexpr size_t nmbiter = 0;


auto rd = std::default_random_engine();
auto udist_float =
  std::uniform_real_distribution<float> (-10000.,10000.);
auto udist_double =
  std::uniform_real_distribution<double> (-10000.,10000.);

CELERO_MAIN


BASELINE(types_sqrt_float_rand, nullop, nmbsmpl, nmbiter)
{
  celero::DoNotOptimizeAway(udist_float(rd));
}

BENCHMARK(types_sqrt_float_rand, double, nmbsmpl, nmbiter)
{
  auto a = udist_double(rd);
  celero::DoNotOptimizeAway(sqrt(a));
}

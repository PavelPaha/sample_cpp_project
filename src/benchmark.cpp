#include <benchmark/benchmark.h>
#include "../include/my_add.hpp"

static void Bench(benchmark::State& state) {
    for (auto _ : state) {
        slow_add(10000, 10000);
    }
}

BENCHMARK(Bench);
BENCHMARK_MAIN();
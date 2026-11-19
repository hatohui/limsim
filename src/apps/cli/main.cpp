#include <chrono>
#include <iostream>
#include <thread>

using duration = std::chrono::milliseconds;

struct EngineState {
    int tick;
    bool running;
    double delta_time;
};

static void simulate(EngineState& state) {
    auto start = std::chrono::steady_clock::now();
    state.tick++;
    auto end = std::chrono::steady_clock::now();
    state.delta_time = std::chrono::duration<double>(end - start).count();

    std::cout << "Simulating tick " << state.tick << " with delta " << state.delta_time <<
        '\n';
}

static void update(EngineState& state) {
    simulate(state);
}

static void start() {
    EngineState state = {.tick = 0, .running = true, .delta_time = 0};

    while (state.running) {
        if (state.tick == 10) {
            state.running = false;
            continue;
        }

        update(state);

        std::this_thread::sleep_for(duration(1000));
    }
}


int main() {
    start();
    return 0;
}
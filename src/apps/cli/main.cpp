#include <chrono>
#include <iostream>
#include <thread>

using duration = std::chrono::milliseconds;

struct EngineState
{
    int tick;
    bool running;
    double delta_time;
    double elapsed_time;
};

static void simulate(EngineState& state)
{
    state.tick++;
    std::cout << "Simulating tick " << state.tick << " with delta " << state.delta_time << " for " << state.elapsed_time
        << std::endl;
}

static void update(EngineState& state)
{
    simulate(state);
}

static void start()
{
    EngineState state = {.tick = 0, .running = true, .delta_time = 0, .elapsed_time = 0};
    auto previous = std::chrono::steady_clock::now();

    while (state.running)
    {
        auto timestamp = std::chrono::steady_clock::now();
        state.delta_time = std::chrono::duration<double>(timestamp - previous).count();
        state.elapsed_time += state.delta_time;
        previous = timestamp;

        if (state.tick == 10)
        {
            state.running = false;
            continue;
        }

        update(state);
        std::this_thread::sleep_for(duration(1000));
    }
}


int main()
{
    start();
    return 0;
}

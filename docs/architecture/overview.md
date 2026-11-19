# Architecture overview

The game core, hatogin, is a set of C++ libraries under `src/libs/`, wrapped by a C API in `src/api/`.

| Library | Role | Depends on |
|---|---|---|
| core | Seeded RNG, typed IDs, event bus, ticks, logging, result types | none |
| sim | Game rules: lab, samples, chemistry, business, missions | core |
| save | Versioned serialization | core, sim |
| net | Optional co-op command sync | core, sim |
| api | `extern "C"` surface for engines | core, sim, save |

The engine owns presentation and platform services. It sends commands through the API and reads state back.

## core

Each header in `src/libs/core/include/hatogin/core/` holds one concern:

| Header | Provides |
|---|---|
| `rng.h` | `rng`: seeded, portable xoshiro256** with `below`, `between`, `unit` and saveable state |
| `id.h` | `id<Tag>`: strongly typed ids (0 is "no id"), and `id_generator` |
| `event_bus.h` | `event_bus<Events...>`: queued, ordered delivery of typed events |
| `tick.h` | `tick`: a point in simulation time |
| `fixed_step.h` | `fixed_step`: turns elapsed real time into whole simulation steps |
| `log.h` | `logger` with a host-provided sink, and `default_logger()` |
| `result.h` | `result<T>` (`std::expected`), `error`, `errc` and `fail()` |

Why these are built this way: [0002-deterministic-core](../decisions/0002-deterministic-core.md).

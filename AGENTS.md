# Agent and contributor guide

Read this before changing code. It applies to humans and AI coding agents.

## Principles

- Clean, extendable, scalable code. Prefer clear library boundaries over convenience.
- The core is engine-agnostic. No rendering, input, audio or platform SDKs (Steam etc.) in `src/`.
- Simulation is deterministic: all randomness goes through the seeded RNG in `libs/core`.

## Library dependencies (one-way only)

```
core  <-  sim  <-  save
              <-  net
api   ->  core, sim, save
```

- `core` must never include anything from `sim`, `save` or `net`.
- `sim` must never include `save` or `net`.
- Engines only see `src/api/include/limsim/limsim.h`. No C++ types cross that boundary.

## Conventions

- C++23, CMake 3.25+.
- Public headers live in `src/libs/<lib>/include/limsim/<lib>/`; include them as `<limsim/<lib>/...>`.
- Private code lives in `src/libs/<lib>/src/`.
- Unit tests sit next to each library in `tests/`; cross-library tests go in `src/tests/`.
- Game data belongs in `content/data/`, not in code.

## Workflow

- Build: `cmake --preset debug && cmake --build --preset debug`.
- Keep changes small and focused; one concern per PR.
- Record notable design choices as a short ADR in `docs/decisions/`.
- Update `docs/` when you change architecture or a library boundary.

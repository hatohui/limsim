# limsim

An engine-agnostic C++ game core for a laboratory management simulator. The player runs a testing lab: takes customer samples, runs tests, investigates chemical properties and delivers results, growing from commercial testing into research and strange experimental projects.

The core holds game rules and state only. A game engine (Unity first) drives it through a plain `extern "C"` API and owns rendering, input, audio and platform services such as Steam.

## Layout

```
.github/        CI workflows and issue/PR templates
docs/           Architecture, design notes and decision records
src/
  libs/core/    Utils, seeded RNG, events, IDs (no game knowledge)
  libs/sim/     Game rules: lab, samples, chemistry, business, missions
  libs/save/    Versioned serialization of sim state
  libs/net/     Optional co-op command sync
  api/          extern "C" API consumed by engines
  apps/         cli (dev harness) and server (headless/co-op host)
  tests/        Integration tests across libraries
content/data/   Game data (tests, reagents, missions)
tools/          Dev scripts and content tooling
external/       Third-party deps (gitignored)
```

## Build

```
cmake --workflow --preset <preset>
```

This configures, builds and runs the tests. Presets are split per platform and compiler, and only the ones for your OS show up:

| Platform | Presets |
|---|---|
| Windows | `windows-msvc-debug`, `windows-msvc-release`, `windows-mingw-debug`, `windows-mingw-release` |
| Linux | `linux-gcc-debug`, `linux-gcc-release`, `linux-clang-debug`, `linux-clang-release` |

MSVC presets need a Developer Command Prompt (or CLion's Visual Studio toolchain).

In CLion, the presets for your OS show up as CMake profiles; pick the one that matches your toolchain, then use Build, or Run with the `limsim_cli` target.

Pass `-DLIMSIM_BUILD_NET=ON` to build the co-op library.

## Contributing

See [AGENTS.md](AGENTS.md) for conventions, which apply to people and AI agents alike, and [docs/](docs/README.md) for architecture.

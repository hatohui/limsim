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

- Build and test in one command: `cmake --workflow --preset <os>-<compiler>-<debug|release>`, e.g. `windows-msvc-debug` or `linux-gcc-debug`. CI runs on Linux only, since the server target is Linux. It compiles with Clang (Release) and GCC, and runs the tests once on the GCC build, which also produces coverage for SonarQube. Windows presets are for local work.
- Add a new platform or compiler as a hidden preset in `CMakePresets.json` that inherits `windows` or `linux`, then add debug/release presets on top.
- Add tests with `limsim_add_test(<name> SOURCES ... LIBS ...)` (doctest).
- Keep changes small and focused; one concern per PR.
- Record notable design choices as a short ADR in `docs/decisions/`.
- Update `docs/` when you change architecture or a library boundary.

## MCP servers

`.mcp.json` configures them. Credentials come from your environment, never from the repo. Use them whenever the task calls for them, before falling back to the shell:

| Server | Use it to | Needs |
|---|---|---|
| `sonarqube` | Read the quality gate and issues of a branch or pull request, and fix what it reports. | Docker, `SONARQUBE_TOKEN` |
| `context7` | Read current documentation of C++, CMake and libraries before relying on an API. | Node; `CONTEXT7_API_KEY` optional |
| `filesystem` | Read, write and search files of the worktree. | Node |

When a server is not connected, say so, then continue with the shell.

## Linting

- Formatting follows `.clang-format`; CLion applies it on Reformat Code. CI fails on any unformatted file.
- `.clang-tidy` enables bugprone, cert, core guidelines, modernize, performance and readability checks as errors. Names are `lower_case` (members of classes end in `_`), template parameters `CamelCase`, macros `UPPER_CASE`.
- Each `tests/` folder has a `.clang-tidy` that relaxes the checks doctest's macros trip.
- Run locally: `clang-format -i <files>` and `run-clang-tidy -p build/<preset>`.

## Quality gate

CI analyzes every pull request and `main` with SonarQube Cloud, using coverage from the `linux-gcc-coverage` preset. Run it locally with `cmake --workflow --preset linux-gcc-coverage`.

## Hard rules

- **Read first.** Read the current state of the files before changing anything; they may have changed since you last saw them.
- **Keep docs current.** When a change makes a document outdated, update the document in the same change.
- **No guessing.** Ask the owner when a requirement is unknown.
- **No silent changes.** State any design choice the owner did not give, in your reply or PR.
- **No leftovers.** Replace old code instead of commenting it out. Git history explains changes.
- **Comment sparingly.** Comment at the start of a block, function or class only when the code doesn't make it obvious.

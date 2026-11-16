# Architecture overview

The game core is a set of C++ libraries under `src/libs/`, wrapped by a C API in `src/api/`.

| Library | Role | Depends on |
|---|---|---|
| core | Utils, seeded RNG, events, IDs | none |
| sim | Game rules: lab, samples, chemistry, business, missions | core |
| save | Versioned serialization | core, sim |
| net | Optional co-op command sync | core, sim |
| api | `extern "C"` surface for engines | core, sim, save |

The engine owns presentation and platform services. It sends commands through the API and reads state back.

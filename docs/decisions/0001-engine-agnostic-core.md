# 0001: Engine-agnostic C++ core

Status: accepted (2026-11-16)

## Context

The game should be driven by Unity first but stay portable to other engines.

## Decision

Game rules live in C++ libraries with no rendering or platform code. Engines call a plain `extern "C"` API. Steam and other platform SDKs are owned by the engine.

## Consequences

- The sim can run headless (CLI, server, tests).
- All data crossing the API must be C types.

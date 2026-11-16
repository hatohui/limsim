#ifndef LIMSIM_H
#define LIMSIM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#  define LIMSIM_API __declspec(dllexport)
#else
#  define LIMSIM_API __attribute__((visibility("default")))
#endif

typedef struct world world;

#ifdef __cplusplus
}
#endif

#endif /* LIMSIM_H */

#ifndef HATOGIN_H
#define HATOGIN_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#  define HATOGIN_API __declspec(dllexport)
#else
#  define HATOGIN_API __attribute__((visibility("default")))
#endif

typedef struct world world;

#ifdef __cplusplus
}
#endif

#endif /* HATOGIN_H */

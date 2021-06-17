#pragma once

#ifdef _WIN32
#if defined(EXPORTS)
#define SAMPLE_API __declspec(dllexport)
#else
#define SAMPLE_API __declspec(dllimport)
#endif
#else
#define SAMPLE_API
#endif

#if (defined __cpp_inline_variables) || __cplusplus >= 201703L
#define SAMPLE_API_INLINE_VARIABLE inline
#else
#ifdef _MSC_VER
#define SAMPLE_API_INLINE_VARIABLE __declspec(selectany)
#define HINT_MSVC_LINKER_INCLUDE_SYMBOL
#else
#define SAMPLE_API_INLINE_VARIABLE __attribute__((weak))
#endif
#endif
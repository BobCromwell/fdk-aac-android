#include <jni.h>
#include <stdlib.h>
#include "aacenc.h"

static aacenc_t *enc;

// Macro for native functions that can be found by way of jni-auto discovery.
// Note extern "C" is needed for "discovery" of native methods to work.
#define JOWW(rettype, name)                                             \
  extern "C" rettype JNIEXPORT JNICALL Java_com_github_bobcromwell_aacencoder_NativeAACEncoder_##name



JOWW(jboolean, init)(
    JNIEnv *env,
    jobject thiz,
    jint sampleRate,
    jint channels,
    jint bitsPerSample,
    jint bitRate)
{
  enc = aacenc_init(sampleRate, channels, bitRate);
  return enc != NULL;
}

JOWW(void, release)(
    JNIEnv *env,
    jobject thiz)
{
  aacenc_free(enc);
  enc = NULL;
}
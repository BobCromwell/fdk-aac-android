#ifndef __AACENC_H__
#define __AACENC_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct aacenc aacenc_t;

aacenc_t *aacenc_init(int samplerate, int channels, int bitrate);

void aacenc_free(aacenc_t *enc);

#ifdef __cplusplus
}
#endif

#endif  /*__AACENC_H__*/

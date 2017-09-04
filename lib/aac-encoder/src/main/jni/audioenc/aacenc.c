#include <stdlib.h>
#include <stdio.h>

#include "aacenc_lib.h"

typedef struct aacenc {
  HANDLE_AACENCODER handle;
  AACENC_InfoStruct info;
  int channels;
} aacenc_t;

aacenc_t *aacenc_init(int samplerate, int channels, int bitrate)
{
  CHANNEL_MODE mode;
  aacenc_t *enc;

  switch (channels) {
    case 1: mode = MODE_1; break;
    case 2: mode = MODE_2; break;
    default: return NULL;
  }

  enc = (aacenc_t *) malloc(sizeof(aacenc_t));
  if( !enc )
    return NULL;

  enc->handle = NULL;
  enc->channels = channels;

  if (aacEncOpen(&enc->handle, 0, channels) != AACENC_OK) {
    fprintf(stderr, "Unable to open encoder\n");
    goto fail;
  }

  // AAC-LC
  if (aacEncoder_SetParam(enc->handle, AACENC_AOT, AOT_AAC_LC) != AACENC_OK) {
    fprintf(stderr, "Unable to set the AOT\n");
    goto fail;
  }

  if (aacEncoder_SetParam(enc->handle, AACENC_SAMPLERATE, samplerate) != AACENC_OK) {
    fprintf(stderr, "Unable to set the sample rate\n");
    goto fail;
  }

  if (aacEncoder_SetParam(enc->handle, AACENC_CHANNELMODE, mode) != AACENC_OK) {
    fprintf(stderr, "Unable to set the channel mode\n");
    goto fail;
  }

  if (aacEncoder_SetParam(enc->handle, AACENC_BITRATE, bitrate) != AACENC_OK) {
    fprintf(stderr, "Unable to set the bitrate\n");
    goto fail;
  }

  if (aacEncoder_SetParam(enc->handle, AACENC_TRANSMUX, TT_MP4_ADTS) != AACENC_OK) {
    fprintf(stderr, "Unable to set the ADTS transmux\n");
    goto fail;
  }

  if (aacEncEncode(enc->handle, NULL, NULL, NULL, NULL) != AACENC_OK) {
    fprintf(stderr, "Unable to initialize the encoder\n");
    goto fail;
  }

  if (aacEncInfo(enc->handle, &enc->info) != AACENC_OK) {
    fprintf(stderr, "Unable to get the encoder info\n");
    goto fail;
  }

  return enc;

fail:
  free(enc);
  return NULL;
}

void aacenc_free(aacenc_t *enc)
{
  if (enc->handle)
  {
    aacEncClose(&enc->handle);
  }
  free(enc);
}
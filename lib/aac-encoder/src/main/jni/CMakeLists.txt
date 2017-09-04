cmake_minimum_required(VERSION 3.4.1)

set(target_so_file_name aac_encoder_jni)
set(fdk_aac_path fdk-aac)

aux_source_directory(${fdk_aac_path}/libAACdec/src fdk_aac_dec_src)
aux_source_directory(${fdk_aac_path}/libAACenc/src fdk_aac_enc_src)
aux_source_directory(${fdk_aac_path}/libPCMutils/src fdk_aac_pcm_utils_src)
aux_source_directory(${fdk_aac_path}/libFDK/src fdk_aac_fdk_src)
aux_source_directory(${fdk_aac_path}/libSYS/src fdk_aac_sys_src)
aux_source_directory(${fdk_aac_path}/libMpegTPDec/src fdk_aac_mpeg_tp_dec_src)
aux_source_directory(${fdk_aac_path}/libMpegTPEnc/src fdk_aac_mpeg_tp_enc_src)
aux_source_directory(${fdk_aac_path}/libSBRdec/src fdk_aac_sbr_dec_src)
aux_source_directory(${fdk_aac_path}/libSBRenc/src fdk_aac_sbr_enc_src)

add_library(fdk_aac_lib
  STATIC
  ${fdk_aac_dec_src}
  ${fdk_aac_enc_src}
  ${fdk_aac_pcm_utils_src}
  ${fdk_aac_fdk_src}
  ${fdk_aac_sys_src}
  ${fdk_aac_mpeg_tp_dec_src}
  ${fdk_aac_mpeg_tp_enc_src}
  ${fdk_aac_sbr_dec_src}
  ${fdk_aac_sbr_enc_src}
  )

target_include_directories(fdk_aac_lib
  PRIVATE
  ${fdk_aac_path}/libAACdec/include
  ${fdk_aac_path}/libAACenc/include
  ${fdk_aac_path}/libPCMutils/include
  ${fdk_aac_path}/libFDK/include
  ${fdk_aac_path}/libSYS/include
  ${fdk_aac_path}/libMpegTPDec/include
  ${fdk_aac_path}/libMpegTPEnc/include
  ${fdk_aac_path}/libSBRdec/include
  ${fdk_aac_path}/libSBRenc/include
  )

add_library(${target_so_file_name}
  SHARED
  audioenc/aacenc.c
  audioenc/audioenc_jni.cpp)

target_include_directories(${target_so_file_name}
  PRIVATE
  ${fdk_aac_path}/libAACenc/include
  ${fdk_aac_path}/libSYS/include
  )

target_link_libraries(${target_so_file_name} fdk_aac_lib)

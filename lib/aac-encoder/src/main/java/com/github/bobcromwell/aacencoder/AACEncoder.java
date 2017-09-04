package com.github.bobcromwell.aacencoder;

public interface AACEncoder {

    boolean init(int sampleRate, int channels, int bitsPerSample, int bitRate);

    void release();
}

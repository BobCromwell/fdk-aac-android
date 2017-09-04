package com.github.bobcromwell.aacencoder;

public class NativeAACEncoder implements AACEncoder {

    @Override
    public native boolean init(int sampleRate, int channels, int bitsPerSample, int bitRate);

    @Override
    public native void release();
}

package com.github.bobcromwell.androidaacencodesample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.github.bobcromwell.aacencoder.AACEncoder;
import com.github.bobcromwell.aacencoder.NativeAACEncoder;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        AACEncoder encoder = new NativeAACEncoder();
        //encoder.init();

    }
}

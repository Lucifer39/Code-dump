package com.libhub.libhub

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.libhub.libhub.models.CurrentAffairs

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val  c = CurrentAffairs("","","","")
        c.getId()
    }
}
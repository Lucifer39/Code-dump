package com.libhub.libhub

import android.app.Application
import android.app.Dialog

class MyApplication : Application() {
    private val EXPIRY_CHECK = "LIBHUB_EXPIRY_SUBSCRIPTION"
    private val SUBSCRIPTION_TOPIC = "LIBHUB_NOTIFICATION_SYSTEM"
    var DEVICE_ID: String? = null
    private val dialog: Dialog? = null

    override fun onCreate() {
        super.onCreate()
    }

}
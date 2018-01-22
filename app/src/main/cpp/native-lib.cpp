#include <string.h>
#include <stdio.h>
#include <jni.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_ar_yue_examples_androidtestjni_MainActivity_stringFromJNI(JNIEnv* env, jobject obj) {

// Construct a String
jstring jstr = env->NewStringUTF("This string comes from JNI");
// First get the class that contains the method you need to call
jclass clazz = env->FindClass("ar/yue/examples/androidtestjni/MainActivity");
// Get the method that you want to call
jmethodID messageMe = env->GetMethodID(clazz, "messageMe", "(Ljava/lang/String;)V");
// Call the method on the object
 env->CallVoidMethod(obj, messageMe, jstr);

return env->NewStringUTF("Hello from JNI!");
}



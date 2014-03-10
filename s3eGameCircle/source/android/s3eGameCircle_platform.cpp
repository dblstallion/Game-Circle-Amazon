/*
 * android-specific implementation of the s3eGameCircle extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eGameCircle_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eGameCircleInitialize;
static jmethodID g_s3eGameCircleIsInitialized;
static jmethodID g_s3eGameCircleShowAchievementsOverlay;
static jmethodID g_s3eGameCircleUpdateAchievement;
static jmethodID g_s3eGameCircleShowLeaderboardOverlay;
static jmethodID g_s3eGameCircleShowLeaderboardsOverlay;
static jmethodID g_s3eGameCircleSubmitScore;

s3eResult s3eGameCircleInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eGameCircle");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eGameCircleInitialize = env->GetMethodID(cls, "s3eGameCircleInitialize", "(ZZ)V");
    if (!g_s3eGameCircleInitialize)
        goto fail;

    g_s3eGameCircleIsInitialized = env->GetMethodID(cls, "s3eGameCircleIsInitialized", "()Z");
    if (!g_s3eGameCircleIsInitialized)
        goto fail;

    g_s3eGameCircleShowAchievementsOverlay = env->GetMethodID(cls, "s3eGameCircleShowAchievementsOverlay", "()V");
    if (!g_s3eGameCircleShowAchievementsOverlay)
        goto fail;

    g_s3eGameCircleUpdateAchievement = env->GetMethodID(cls, "s3eGameCircleUpdateAchievement", "(Ljava/lang/String;FLjava/lang/String;)V");
    if (!g_s3eGameCircleUpdateAchievement)
        goto fail;

    g_s3eGameCircleShowLeaderboardOverlay = env->GetMethodID(cls, "s3eGameCircleShowLeaderboardOverlay", "(Ljava/lang/String;)V");
    if (!g_s3eGameCircleShowLeaderboardOverlay)
        goto fail;

    g_s3eGameCircleShowLeaderboardsOverlay = env->GetMethodID(cls, "s3eGameCircleShowLeaderboardsOverlay", "()V");
    if (!g_s3eGameCircleShowLeaderboardsOverlay)
        goto fail;

    g_s3eGameCircleSubmitScore = env->GetMethodID(cls, "s3eGameCircleSubmitScore", "(Ljava/lang/String;JLjava/lang/String;)V");
    if (!g_s3eGameCircleSubmitScore)
        goto fail;



    IwTrace(GAMECIRCLE, ("GAMECIRCLE init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eGameCircle, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void s3eGameCircleTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eGameCircleInitialize_platform(bool useAchievements, bool useLeaderboards)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eGameCircleInitialize, useAchievements, useLeaderboards);
}

bool s3eGameCircleIsInitialized_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eGameCircleIsInitialized);
}

void s3eGameCircleShowAchievementsOverlay_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eGameCircleShowAchievementsOverlay);
}

void s3eGameCircleUpdateAchievement_platform(const char* achievementId, float percentComplete, const char* developerPayload)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring achievementId_jstr = env->NewStringUTF(achievementId);
    jstring developerPayload_jstr = env->NewStringUTF(developerPayload);
    env->CallVoidMethod(g_Obj, g_s3eGameCircleUpdateAchievement, achievementId_jstr, percentComplete, developerPayload_jstr);
    env->DeleteLocalRef(achievementId_jstr);
    env->DeleteLocalRef(developerPayload_jstr);
}

void s3eGameCircleShowLeaderboardOverlay_platform(const char* leaderboardId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring leaderboardId_jstr = env->NewStringUTF(leaderboardId);
    env->CallVoidMethod(g_Obj, g_s3eGameCircleShowLeaderboardOverlay, leaderboardId_jstr);
}

void s3eGameCircleShowLeaderboardsOverlay_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eGameCircleShowLeaderboardsOverlay);
}

void s3eGameCircleSubmitScore_platform(const char* leaderboardId, int64_t score, const char* developerPayload)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring leaderboardId_jstr = env->NewStringUTF(leaderboardId);
    jstring developerPayload_jstr = env->NewStringUTF(developerPayload);
    env->CallVoidMethod(g_Obj, g_s3eGameCircleSubmitScore, leaderboardId_jstr, score, developerPayload_jstr);
    env->DeleteLocalRef(leaderboardId_jstr);
    env->DeleteLocalRef(developerPayload_jstr);
}

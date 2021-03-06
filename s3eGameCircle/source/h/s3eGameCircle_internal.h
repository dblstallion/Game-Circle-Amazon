/*
 * Internal header for the s3eGameCircle extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EGAMECIRCLE_INTERNAL_H
#define S3EGAMECIRCLE_INTERNAL_H

#include "s3eTypes.h"
#include "s3eGameCircle.h"
#include "s3eGameCircle_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eGameCircleInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eGameCircleInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eGameCircleTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eGameCircleTerminate_platform();
void s3eGameCircleInitialize_platform(bool useAchievements, bool useLeaderboards);

bool s3eGameCircleIsInitialized_platform();

void s3eGameCircleShowAchievementsOverlay_platform();

void s3eGameCircleUpdateAchievement_platform(const char* achievementId, float percentComplete, const char* developerPayload);

void s3eGameCircleShowLeaderboardOverlay_platform(const char* leaderboardId);

void s3eGameCircleShowLeaderboardsOverlay_platform();

void s3eGameCircleSubmitScore_platform(const char* leaderboardId, int64_t score, const char* developerPayload);


#endif /* !S3EGAMECIRCLE_INTERNAL_H */
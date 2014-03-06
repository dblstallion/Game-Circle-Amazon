/*
Generic implementation of the s3eGameCircle extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eGameCircle_internal.h"
s3eResult s3eGameCircleInit()
{
    //Add any generic initialisation code here
    return s3eGameCircleInit_platform();
}

void s3eGameCircleTerminate()
{
    //Add any generic termination code here
    s3eGameCircleTerminate_platform();
}

void s3eGameCircleInitialize(bool useAchievements, bool useLeaderboards)
{
	s3eGameCircleInitialize_platform(useAchievements, useLeaderboards);
}

bool s3eGameCircleIsInitialized()
{
	return s3eGameCircleIsInitialized_platform();
}

void s3eGameCircleShowAchievementsOverlay()
{
	s3eGameCircleShowAchievementsOverlay_platform();
}

void s3eGameCircleUpdateAchievement(const char* achievementId, float percentComplete, const char* developerPayload)
{
	s3eGameCircleUpdateAchievement_platform(achievementId, percentComplete, developerPayload);
}

void s3eGameCircleShowLeaderboardOverlay(const char* leaderboardId)
{
	s3eGameCircleShowLeaderboardOverlay_platform(leaderboardId);
}

void s3eGameCircleShowLeaderboardsOverlay()
{
	s3eGameCircleShowLeaderboardsOverlay_platform();
}

void s3eGameCircleSubmitScore(const char* leaderboardId, int64_t score, const char* developerPayload)
{
	s3eGameCircleSubmitScore_platform(leaderboardId, score, developerPayload);
}

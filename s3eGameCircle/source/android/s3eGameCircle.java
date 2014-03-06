/*
java implementation of the s3eGameCircle extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.amazon.ags.api.*;
import com.amazon.ags.constants.*;
import com.amazon.ags.constants.whispersync.*;
import com.amazon.ags.api.whispersync.*;
import com.amazon.ags.api.leaderboards.SubmitScoreResponse;

import android.util.Log;
import java.util.EnumSet;

class s3eGameCircle
{
    private static final String TAG = "Amazon-GameCircle";
    
    private static AmazonGamesCallback s3eGameCircleInitializeCallback = new AmazonGamesCallback()
    {
        @Override
        public void onServiceReady(AmazonGamesClient amazonGamesClient)
        {
            Log.v(TAG, "s3eGameCircleInitializeCallback Service READY");
            
            agcClient = amazonGamesClient;
        }
        @Override
        public void onServiceNotReady(AmazonGamesStatus amazonGamesStatus)
        {
            Log.v(TAG, "s3eGameCircleInitializeCallback Service NOT READY");
        }
    };
 
    private static AmazonGamesClient agcClient;
 
    public void s3eGameCircleInitialize(boolean useAchievements, boolean useLeaderboards)
    {
        Log.v(TAG, "s3eGameCircleInitialize");
        
        EnumSet<AmazonGamesFeature> myGameFeatures = EnumSet.noneOf(AmazonGamesFeature.class);
        
        if (useAchievements) 
        {
            myGameFeatures.add(AmazonGamesFeature.Achievements);
        }
        
        if (useLeaderboards)
        {
            myGameFeatures.add(AmazonGamesFeature.Leaderboards);
        }
        
        AmazonGamesClient.initialize(LoaderActivity.m_Activity, s3eGameCircleInitializeCallback, myGameFeatures); 
    }
    
    public boolean s3eGameCircleIsInitialized()
    {
        Log.v(TAG, "s3eGameCircleIsInitialized");
        
        if (agcClient == null)
        {
            return false;
        }
        else
        {
            return agcClient.isInitialized();
        }
    }
    
    public void s3eGameCircleShowAchievementsOverlay()
    {
        Log.v(TAG, "s3eGameCircleShowAchievementsOverlay");
        
        if (s3eGameCircleIsInitialized())
        {
            agcClient.getAchievementsClient().showAchievementsOverlay();
        }
        else
        {
            Log.v(TAG, "ERROR: Amazon GameCircle is not initialized.");
        }
    }
    
    public void s3eGameCircleUpdateAchievement(String achievementId, float percentComplete, String developerPayload)
    {
        Log.v(TAG, "s3eGameCircleUpdateAchievement " + achievementId + " " + percentComplete);
        
        if (s3eGameCircleIsInitialized())
        {
            agcClient.getAchievementsClient().updateProgress(achievementId, percentComplete, developerPayload);
        }
        else
        {
            Log.v(TAG, "ERROR: Amazon GameCircle is not initialized.");
        }
    }
    
    public void s3eGameCircleShowLeaderboardOverlay(String leaderboardId)
    {
        Log.v(TAG, "s3eGameCircleShowLeaderboardOverlay " + leaderboardId);
        
        if (s3eGameCircleIsInitialized())
        {
            agcClient.getLeaderboardsClient().showLeaderboardsOverlay(leaderboardId);
        }
        else
        {
            Log.v(TAG, "ERROR: Amazon GameCircle is not initialized.");
        }
    }
    
    public void s3eGameCircleShowLeaderboardsOverlay()
    {
        Log.v(TAG, "s3eGameCircleShowLeaderboardsOverlay");
        
        if (s3eGameCircleIsInitialized())
        {
            agcClient.getLeaderboardsClient().showLeaderboardsOverlay();
        }
        else
        {
            Log.v(TAG, "ERROR: Amazon GameCircle is not initialized.");
        }
    }
    
    public void s3eGameCircleSubmitScore(String leaderboardId, long score, String developerPayload)
    {
        Log.v(TAG, "s3eGameCircleSubmitScore " + leaderboardId + " " + score);
        
        if (s3eGameCircleIsInitialized())
        {
            agcClient.getLeaderboardsClient().submitScore(leaderboardId, score, developerPayload);
        }
        else
        {
            Log.v(TAG, "ERROR: Amazon GameCircle is not initialized.");
        }
    }
}

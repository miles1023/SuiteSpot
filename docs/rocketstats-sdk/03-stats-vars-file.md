# Stats, Vars & File Management

_Source: RocketStats BakkesMod plugin — extracted via repomix_

## File: Managements/StatsManagement.cpp
```cpp
#include "../RocketStats.h"

bool RocketStats::isPrimaryPlayer(PriWrapper PRI)
{
    if (PRI.IsNull())
        return (false);

    ServerWrapper server = (is_online_game ? gameWrapper->GetOnlineGame() : gameWrapper->GetGameEventAsServer());
    if (server.IsNull())
        return (false);

    PlayerControllerWrapper player = server.GetLocalPrimaryPlayer();
    if (player.IsNull())
        return (false);

    PriWrapper playerPRI = player.GetPRI();
    if (playerPRI.IsNull())
        return (false);

    return (PRI.GetUniqueIdWrapper().GetUID() == playerPRI.GetUniqueIdWrapper().GetUID());
}

void RocketStats::onStatEvent(ServerWrapper caller, void* params)
{
    StatEventParams* pstats = (StatEventParams*)params;
    StatEventWrapper event = StatEventWrapper(pstats->StatEvent);

    std::string name = event.GetEventName();
    if (name == "Shot")
        name = "ShotOnGoal";

    SocketSend(name, {
        { "Points", event.GetPoints() }
    }, "StatEvent");

    if (!is_online_game)
        return;

    bool refresh = true;
    if (name == "Clear")
    {
        cvarManager->log(" --> " + name);

        ++always.Clear;
        ++current.stats.Clear;
        ++session.Clear;
        ++stats[current.playlist].Clear;
        ++always_gm[current.playlist].Clear;

        ++always.ClearCumul;
        ++current.stats.ClearCumul;
        ++session.ClearCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].ClearCumul;
            ++always_gm[it->first].ClearCumul;
        }

        AllShotsClear(true);
    }
    else if (name == "Center")
    {
        cvarManager->log(" --> " + name);

        ++always.Center;
        ++current.stats.Center;
        ++session.Center;
        ++stats[current.playlist].Center;
        ++always_gm[current.playlist].Center;

        ++always.CenterCumul;
        ++current.stats.CenterCumul;
        ++session.CenterCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].CenterCumul;
            ++always_gm[it->first].CenterCumul;
        }

        AllShotsCenter(true);
    }
    else if (name == "AerialHit")
    {
        cvarManager->log(" --> " + name);

        ++always.AerialHit;
        ++current.stats.AerialHit;
        ++session.AerialHit;
        ++stats[current.playlist].AerialHit;
        ++always_gm[current.playlist].AerialHit;

        ++always.AerialHitCumul;
        ++current.stats.AerialHitCumul;
        ++session.AerialHitCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].AerialHitCumul;
            ++always_gm[it->first].AerialHitCumul;
        }

        AllShotsAerialHit(true);
    }
    else if (name == "FirstTouch")
    {
        cvarManager->log(" --> " + name);

        ++always.FirstTouch;
        ++current.stats.FirstTouch;
        ++session.FirstTouch;
        ++stats[current.playlist].FirstTouch;
        ++always_gm[current.playlist].FirstTouch;

        ++always.FirstTouchCumul;
        ++current.stats.FirstTouchCumul;
        ++session.FirstTouchCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FirstTouchCumul;
            ++always_gm[it->first].FirstTouchCumul;
        }

        AllMiscsFirstTouch(true);
    }
    else if (name == "OwnGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.OwnGoal;
        ++current.stats.OwnGoal;
        ++session.OwnGoal;
        ++stats[current.playlist].OwnGoal;
        ++always_gm[current.playlist].OwnGoal;

        ++always.OwnGoalCumul;
        ++current.stats.OwnGoalCumul;
        ++session.OwnGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].OwnGoalCumul;
            ++always_gm[it->first].OwnGoalCumul;
        }

        AllGoalsOwnGoal(true);
    }
    else if (name == "KO_Thrown")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutThrown;
        ++current.stats.KnockoutThrown;
        ++session.KnockoutThrown;
        ++stats[current.playlist].KnockoutThrown;
        ++always_gm[current.playlist].KnockoutThrown;

        ++always.KnockoutThrownCumul;
        ++current.stats.KnockoutThrownCumul;
        ++session.KnockoutThrownCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutThrownCumul;
            ++always_gm[it->first].KnockoutThrownCumul;
        }

        AllKnockoutThrown(true);
    }
    else if (name == "KO_Grabbed")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutGrabbed;
        ++current.stats.KnockoutGrabbed;
        ++session.KnockoutGrabbed;
        ++stats[current.playlist].KnockoutGrabbed;
        ++always_gm[current.playlist].KnockoutGrabbed;

        ++always.KnockoutGrabbedCumul;
        ++current.stats.KnockoutGrabbedCumul;
        ++session.KnockoutGrabbedCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutGrabbedCumul;
            ++always_gm[it->first].KnockoutGrabbedCumul;
        }

        AllKnockoutGrabbed(true);
    }
    else if (name == "KO_HitTaken")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutHitTaken;
        ++current.stats.KnockoutHitTaken;
        ++session.KnockoutHitTaken;
        ++stats[current.playlist].KnockoutHitTaken;
        ++always_gm[current.playlist].KnockoutHitTaken;

        ++always.KnockoutHitTakenCumul;
        ++current.stats.KnockoutHitTakenCumul;
        ++session.KnockoutHitTakenCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutHitTakenCumul;
            ++always_gm[it->first].KnockoutHitTakenCumul;
        }

        AllKnockoutHitTaken(true);
    }
    else if (name == "KO_LightHit")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutLightHit;
        ++current.stats.KnockoutLightHit;
        ++session.KnockoutLightHit;
        ++stats[current.playlist].KnockoutLightHit;
        ++always_gm[current.playlist].KnockoutLightHit;

        ++always.KnockoutLightHitCumul;
        ++current.stats.KnockoutLightHitCumul;
        ++session.KnockoutLightHitCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutLightHitCumul;
            ++always_gm[it->first].KnockoutLightHitCumul;
        }

        AllKnockoutLightHit(true);
    }
    else if (name == "KO_BlockTaken")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutBlockTaken;
        ++current.stats.KnockoutBlockTaken;
        ++session.KnockoutBlockTaken;
        ++stats[current.playlist].KnockoutBlockTaken;
        ++always_gm[current.playlist].KnockoutBlockTaken;

        ++always.KnockoutBlockTakenCumul;
        ++current.stats.KnockoutBlockTakenCumul;
        ++session.KnockoutBlockTakenCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutBlockTakenCumul;
            ++always_gm[it->first].KnockoutBlockTakenCumul;
        }

        AllKnockoutBlockTaken(true);
    }
    else if (name == "KO_LightBlock")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutLightBlock;
        ++current.stats.KnockoutLightBlock;
        ++session.KnockoutLightBlock;
        ++stats[current.playlist].KnockoutLightBlock;
        ++always_gm[current.playlist].KnockoutLightBlock;

        ++always.KnockoutLightBlockCumul;
        ++current.stats.KnockoutLightBlockCumul;
        ++session.KnockoutLightBlockCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutLightBlockCumul;
            ++always_gm[it->first].KnockoutLightBlockCumul;
        }

        AllKnockoutLightBlock(true);
    }
    else if (name == "KO_PlayerThrown")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutPlayerThrown;
        ++current.stats.KnockoutPlayerThrown;
        ++session.KnockoutPlayerThrown;
        ++stats[current.playlist].KnockoutPlayerThrown;
        ++always_gm[current.playlist].KnockoutPlayerThrown;

        ++always.KnockoutPlayerThrownCumul;
        ++current.stats.KnockoutPlayerThrownCumul;
        ++session.KnockoutPlayerThrownCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutPlayerThrownCumul;
            ++always_gm[it->first].KnockoutPlayerThrownCumul;
        }

        AllKnockoutPlayerThrown(true);
    }
    else if (name == "KO_PlayerGrabbed")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutPlayerGrabbed;
        ++current.stats.KnockoutPlayerGrabbed;
        ++session.KnockoutPlayerGrabbed;
        ++stats[current.playlist].KnockoutPlayerGrabbed;
        ++always_gm[current.playlist].KnockoutPlayerGrabbed;

        ++always.KnockoutPlayerGrabbedCumul;
        ++current.stats.KnockoutPlayerGrabbedCumul;
        ++session.KnockoutPlayerGrabbedCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutPlayerGrabbedCumul;
            ++always_gm[it->first].KnockoutPlayerGrabbedCumul;
        }

        AllKnockoutPlayerGrabbed(true);
    }
    else if (name == "CarTouches")
    {
        cvarManager->log(" --> " + name);

        ++always.CarTouches;
        ++current.stats.CarTouches;
        ++session.CarTouches;
        ++stats[current.playlist].CarTouches;
        ++always_gm[current.playlist].CarTouches;

        ++always.CarTouchesCumul;
        ++current.stats.CarTouchesCumul;
        ++session.CarTouchesCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].CarTouchesCumul;
            ++always_gm[it->first].CarTouchesCumul;
        }

        AllAccoladesCarTouches(true);
    }
    else if (name == "FastestGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.FastestGoal;
        ++current.stats.FastestGoal;
        ++session.FastestGoal;
        ++stats[current.playlist].FastestGoal;
        ++always_gm[current.playlist].FastestGoal;

        ++always.FastestGoalCumul;
        ++current.stats.FastestGoalCumul;
        ++session.FastestGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FastestGoalCumul;
            ++always_gm[it->first].FastestGoalCumul;
        }

        AllAccoladesFastestGoal(true);
    }
    else if (name == "SlowestGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.SlowestGoal;
        ++current.stats.SlowestGoal;
        ++session.SlowestGoal;
        ++stats[current.playlist].SlowestGoal;
        ++always_gm[current.playlist].SlowestGoal;

        ++always.SlowestGoalCumul;
        ++current.stats.SlowestGoalCumul;
        ++session.SlowestGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].SlowestGoalCumul;
            ++always_gm[it->first].SlowestGoalCumul;
        }

        AllAccoladesSlowestGoal(true);
    }
    else if (name == "BoostPickups")
    {
        cvarManager->log(" --> " + name);

        ++always.BoostPickups;
        ++current.stats.BoostPickups;
        ++session.BoostPickups;
        ++stats[current.playlist].BoostPickups;
        ++always_gm[current.playlist].BoostPickups;

        ++always.BoostPickupsCumul;
        ++current.stats.BoostPickupsCumul;
        ++session.BoostPickupsCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].BoostPickupsCumul;
            ++always_gm[it->first].BoostPickupsCumul;
        }

        AllAccoladesBoostPickups(true);
    }
    else if (name == "FurthestGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.FurthestGoal;
        ++current.stats.FurthestGoal;
        ++session.FurthestGoal;
        ++stats[current.playlist].FurthestGoal;
        ++always_gm[current.playlist].FurthestGoal;

        ++always.FurthestGoalCumul;
        ++current.stats.FurthestGoalCumul;
        ++session.FurthestGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FurthestGoalCumul;
            ++always_gm[it->first].FurthestGoalCumul;
        }

        AllAccoladesFurthestGoal(true);
    }
    else if (name == "MostBallTouches")
    {
        cvarManager->log(" --> " + name);

        ++always.MostBallTouches;
        ++current.stats.MostBallTouches;
        ++session.MostBallTouches;
        ++stats[current.playlist].MostBallTouches;
        ++always_gm[current.playlist].MostBallTouches;

        ++always.MostBallTouchesCumul;
        ++current.stats.MostBallTouchesCumul;
        ++session.MostBallTouchesCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].MostBallTouchesCumul;
            ++always_gm[it->first].MostBallTouchesCumul;
        }

        AllAccoladesMostBallTouches(true);
    }
    else if (name == "MostBoostPickups")
    {
        cvarManager->log(" --> " + name);

        ++always.MostBoostPickups;
        ++current.stats.MostBoostPickups;
        ++session.MostBoostPickups;
        ++stats[current.playlist].MostBoostPickups;
        ++always_gm[current.playlist].MostBoostPickups;

        ++always.MostBoostPickupsCumul;
        ++current.stats.MostBoostPickupsCumul;
        ++session.MostBoostPickupsCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].MostBoostPickupsCumul;
            ++always_gm[it->first].MostBoostPickupsCumul;
        }

        AllAccoladesMostBoostPickups(true);
    }
    else if (name == "FewestBallTouches")
    {
        cvarManager->log(" --> " + name);

        ++always.FewestBallTouches;
        ++current.stats.FewestBallTouches;
        ++session.FewestBallTouches;
        ++stats[current.playlist].FewestBallTouches;
        ++always_gm[current.playlist].FewestBallTouches;

        ++always.FewestBallTouchesCumul;
        ++current.stats.FewestBallTouchesCumul;
        ++session.FewestBallTouchesCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FewestBallTouchesCumul;
            ++always_gm[it->first].FewestBallTouchesCumul;
        }

        AllAccoladesFewestBallTouches(true);
    }
    else
    {
        if (name == "Win" || name == "Loss" || name == "TimePlayed" || name == "BicycleHit" || name == "Shot" || name == "Assist" || name == "Save" || name == "EpicSave" || name == "Goal" || name == "AerialGoal" || name == "BackwardsGoal" || name == "BicycleGoal" || name == "LongGoal" || name == "TurtleGoal" || name == "OvertimeGoal" || name == "HoopsSwishGoal" || name == "PoolShot" || name == "FirstTouch" || name == "Savior" || name == "LowFive" || name == "HatTrick" || name == "HighFive" || name == "Playmaker" || name == "Demolish" || name == "BreakoutDamage" || name == "BreakoutDamageLarge" || name == "KO_Knockout" || name == "KO_KnockoutAssist" || name == "KO_DoubleKO" || name == "KO_HeavyHit" || name == "KO_TripleKO" || name == "KO_HeavyBlock" || name == "KO_AerialHeavyHit" || name == "KO_AerialLightHit" || name == "MVP")
            return;

        refresh = false;
        cvarManager->log("onStatEvent " + name + "[" + std::to_string(event.GetPoints()) + "]");
    }

    if (refresh)
        SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::onStatTickerMessage(ServerWrapper caller, void* params)
{
    StatTickerParams* pstats = (StatTickerParams*)params;

    CarWrapper me = gameWrapper->GetLocalCar();
    PriWrapper receiver = PriWrapper(pstats->Receiver);
    PriWrapper victim = PriWrapper(pstats->Victim);
    StatEventWrapper event = StatEventWrapper(pstats->StatEvent);

    std::string name = event.GetEventName();
    if (name == "Shot")
        name = "ShotOnGoal";

    bool iam_receiver = (!receiver.IsNull() && isPrimaryPlayer(receiver));
    bool iam_victim = (!victim.IsNull() && isPrimaryPlayer(victim));
    bool team_receiver = (!me.IsNull() && !receiver.IsNull() && me.GetTeamNum2() == receiver.GetTeamNum2());
    bool team_victim = (!me.IsNull() && !victim.IsNull() && me.GetTeamNum2() == victim.GetTeamNum2());

    SocketSend(name, {
        { "Points", event.GetPoints() },
        { "Receiver", (iam_receiver ? "me" : (team_receiver ? "team" : "no")) },
        { "Victim", (iam_victim ? "me" : (team_victim ? "team" : "no")) }
    }, "TickerMessage");

    if (!is_online_game)
        return;

    bool refresh = true;
    if (!iam_receiver && !team_receiver && !iam_victim && !team_victim) // Opponent statistics
    {
        refresh = false;
    }
    else // Self and team statistics
    {
        if (name == "BicycleHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBicycleHit;
            ++current.stats.TotalBicycleHit;
            ++session.TotalBicycleHit;
            ++stats[current.playlist].TotalBicycleHit;
            ++always_gm[current.playlist].TotalBicycleHit;

            ++(iam_receiver ? always.BicycleHit : always.TeamBicycleHit);
            ++(iam_receiver ? current.stats.BicycleHit : current.stats.TeamBicycleHit);
            ++(iam_receiver ? session.BicycleHit : session.TeamBicycleHit);
            ++(iam_receiver ? stats[current.playlist].BicycleHit : stats[current.playlist].TeamBicycleHit);
            ++(iam_receiver ? always_gm[current.playlist].BicycleHit : always_gm[current.playlist].TeamBicycleHit);

            ++always.TotalBicycleHitCumul;
            ++current.stats.TotalBicycleHitCumul;
            ++session.TotalBicycleHitCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBicycleHitCumul;
                ++always_gm[it->first].TotalBicycleHitCumul;

                ++(iam_receiver ? stats[it->first].BicycleHitCumul : stats[it->first].TeamBicycleHitCumul);
                ++(iam_receiver ? always_gm[it->first].BicycleHitCumul : always_gm[it->first].TeamBicycleHitCumul);
            }

            AllShotsBicycleHit(true);
        }
        else if (name == "ShotOnGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalShotOnGoal;
            ++current.stats.TotalShotOnGoal;
            ++session.TotalShotOnGoal;
            ++stats[current.playlist].TotalShotOnGoal;
            ++always_gm[current.playlist].TotalShotOnGoal;

            ++(iam_receiver ? always.ShotOnGoal : always.TeamShotOnGoal);
            ++(iam_receiver ? current.stats.ShotOnGoal : current.stats.TeamShotOnGoal);
            ++(iam_receiver ? session.ShotOnGoal : session.TeamShotOnGoal);
            ++(iam_receiver ? stats[current.playlist].ShotOnGoal : stats[current.playlist].TeamShotOnGoal);
            ++(iam_receiver ? always_gm[current.playlist].ShotOnGoal : always_gm[current.playlist].TeamShotOnGoal);

            ++always.TotalShotOnGoalCumul;
            ++current.stats.TotalShotOnGoalCumul;
            ++session.TotalShotOnGoalCumul;

            if (always.ShotOnGoal > 0)
                always.ShootingPercentage = static_cast<int>(static_cast<float>(always.Goal) / always.ShotOnGoal * 100);
            if (current.stats.ShotOnGoal > 0)
                current.stats.ShootingPercentage = static_cast<int>(static_cast<float>(current.stats.Goal) / current.stats.ShotOnGoal * 100);
            if (session.ShotOnGoal > 0)
                session.ShootingPercentage = static_cast<int>(static_cast<float>(session.Goal) / session.ShotOnGoal * 100);
            
            if (always.TeamShotOnGoal > 0)
                always.TeamShootingPercentage = static_cast<int>(static_cast<float>(always.TeamGoal) / always.TeamShotOnGoal * 100);
            if (current.stats.TeamShotOnGoal > 0)
                current.stats.TeamShootingPercentage = static_cast<int>(static_cast<float>(current.stats.TeamGoal) / current.stats.TeamShotOnGoal * 100);
            if (session.TeamShotOnGoal > 0)
                session.TeamShootingPercentage = static_cast<int>(static_cast<float>(session.TeamGoal) / session.TeamShotOnGoal * 100);

            if (stats[current.playlist].ShotOnGoal > 0)
                stats[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].Goal) / stats[current.playlist].ShotOnGoal * 100);
            if (stats[current.playlist].TeamShotOnGoal > 0)
                stats[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].TeamGoal) / stats[current.playlist].TeamShotOnGoal * 100);

            if (always_gm[current.playlist].ShotOnGoal > 0)
                always_gm[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].Goal) / always_gm[current.playlist].ShotOnGoal * 100);
            if (always_gm[current.playlist].TeamShotOnGoal > 0)
                always_gm[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].TeamGoal) / always_gm[current.playlist].TeamShotOnGoal * 100);

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalShotOnGoalCumul;
                ++always_gm[it->first].TotalShotOnGoalCumul;

                if (stats[it->first].TotalShotOnGoalCumul > 0)
                    stats[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TotalGoalCumul) / stats[it->first].TotalShotOnGoalCumul * 100);
                if (always_gm[it->first].TotalShotOnGoalCumul > 0)
                    always_gm[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TotalGoalCumul) / always_gm[it->first].TotalShotOnGoalCumul * 100);

                ++(iam_receiver ? stats[it->first].ShotOnGoalCumul : stats[it->first].TeamShotOnGoalCumul);
                ++(iam_receiver ? always_gm[it->first].ShotOnGoalCumul : always_gm[it->first].TeamShotOnGoalCumul);

                if (stats[it->first].ShotOnGoalCumul > 0)
                    stats[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].GoalCumul) / stats[it->first].ShotOnGoalCumul * 100);
                if (stats[it->first].TeamShotOnGoalCumul > 0)
                    stats[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TeamGoalCumul) / stats[it->first].TeamShotOnGoalCumul * 100);

                if (always_gm[it->first].ShotOnGoalCumul > 0)
                    always_gm[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].GoalCumul) / always_gm[it->first].ShotOnGoalCumul * 100);
                if (always_gm[it->first].TeamShotOnGoalCumul > 0)
                    always_gm[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TeamGoalCumul) / always_gm[it->first].TeamShotOnGoalCumul * 100);
            }

            AllShotsShotOnGoal(true);
        }
        else if (name == "Assist")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalAssist;
            ++current.stats.TotalAssist;
            ++session.TotalAssist;
            ++stats[current.playlist].TotalAssist;
            ++always_gm[current.playlist].TotalAssist;

            ++(iam_receiver ? always.Assist : always.TeamAssist);
            ++(iam_receiver ? current.stats.Assist : current.stats.TeamAssist);
            ++(iam_receiver ? session.Assist : session.TeamAssist);
            ++(iam_receiver ? stats[current.playlist].Assist : stats[current.playlist].TeamAssist);
            ++(iam_receiver ? always_gm[current.playlist].Assist : always_gm[current.playlist].TeamAssist);

            ++always.TotalAssistCumul;
            ++current.stats.TotalAssistCumul;
            ++session.TotalAssistCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalAssistCumul;
                ++always_gm[it->first].TotalAssistCumul;

                ++(iam_receiver ? stats[it->first].AssistCumul : stats[it->first].TeamAssistCumul);
                ++(iam_receiver ? always_gm[it->first].AssistCumul : always_gm[it->first].TeamAssistCumul);
            }

            AllShotsAssist(true);
        }
        else if (name == "Save")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalSave;
            ++current.stats.TotalSave;
            ++session.TotalSave;
            ++stats[current.playlist].TotalSave;
            ++always_gm[current.playlist].TotalSave;

            ++(iam_receiver ? always.Save : always.TeamSave);
            ++(iam_receiver ? current.stats.Save : current.stats.TeamSave);
            ++(iam_receiver ? session.Save : session.TeamSave);
            ++(iam_receiver ? stats[current.playlist].Save : stats[current.playlist].TeamSave);
            ++(iam_receiver ? always_gm[current.playlist].Save : always_gm[current.playlist].TeamSave);

            ++always.TotalSaveCumul;
            ++current.stats.TotalSaveCumul;
            ++session.TotalSaveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalSaveCumul;
                ++always_gm[it->first].TotalSaveCumul;

                ++(iam_receiver ? stats[it->first].SaveCumul : stats[it->first].TeamSaveCumul);
                ++(iam_receiver ? always_gm[it->first].SaveCumul : always_gm[it->first].TeamSaveCumul);
            }

            AllSavesSave(true);
        }
        else if (name == "EpicSave")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalEpicSave;
            ++current.stats.TotalEpicSave;
            ++session.TotalEpicSave;
            ++stats[current.playlist].TotalEpicSave;
            ++always_gm[current.playlist].TotalEpicSave;

            ++(iam_receiver ? always.EpicSave : always.TeamEpicSave);
            ++(iam_receiver ? current.stats.EpicSave : current.stats.TeamEpicSave);
            ++(iam_receiver ? session.EpicSave : session.TeamEpicSave);
            ++(iam_receiver ? stats[current.playlist].EpicSave : stats[current.playlist].TeamEpicSave);
            ++(iam_receiver ? always_gm[current.playlist].EpicSave : always_gm[current.playlist].TeamEpicSave);

            ++always.TotalEpicSaveCumul;
            ++current.stats.TotalEpicSaveCumul;
            ++session.TotalEpicSaveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalEpicSaveCumul;
                ++always_gm[it->first].TotalEpicSaveCumul;

                ++(iam_receiver ? stats[it->first].EpicSaveCumul : stats[it->first].TeamEpicSaveCumul);
                ++(iam_receiver ? always_gm[it->first].EpicSaveCumul : always_gm[it->first].TeamEpicSaveCumul);
            }

            AllSavesEpicSave(true);
        }
        else if (name == "Goal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalGoal;
            ++current.stats.TotalGoal;
            ++session.TotalGoal;
            ++stats[current.playlist].TotalGoal;
            ++always_gm[current.playlist].TotalGoal;

            ++(iam_receiver ? always.Goal : always.TeamGoal);
            ++(iam_receiver ? current.stats.Goal : current.stats.TeamGoal);
            ++(iam_receiver ? session.Goal : session.TeamGoal);
            ++(iam_receiver ? stats[current.playlist].Goal : stats[current.playlist].TeamGoal);
            ++(iam_receiver ? always_gm[current.playlist].Goal : always_gm[current.playlist].TeamGoal);

            ++always.TotalGoalCumul;
            ++current.stats.TotalGoalCumul;
            ++session.TotalGoalCumul;

            if (always.ShotOnGoal > 0)
                always.ShootingPercentage = static_cast<int>(static_cast<float>(always.Goal) / always.ShotOnGoal * 100);
            if (current.stats.ShotOnGoal > 0)
                current.stats.ShootingPercentage = static_cast<int>(static_cast<float>(current.stats.Goal) / current.stats.ShotOnGoal * 100);
            if (session.ShotOnGoal > 0)
                session.ShootingPercentage = static_cast<int>(static_cast<float>(session.Goal) / session.ShotOnGoal * 100);

            if (always.TeamShotOnGoal > 0)
                always.TeamShootingPercentage = static_cast<int>(static_cast<float>(always.TeamGoal) / always.TeamShotOnGoal * 100);
            if (current.stats.TeamShotOnGoal > 0)
                current.stats.TeamShootingPercentage = static_cast<int>(static_cast<float>(current.stats.TeamGoal) / current.stats.TeamShotOnGoal * 100);
            if (session.TeamShotOnGoal > 0)
                session.TeamShootingPercentage = static_cast<int>(static_cast<float>(session.TeamGoal) / session.TeamShotOnGoal * 100);

            if (stats[current.playlist].ShotOnGoal > 0)
                stats[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].Goal) / stats[current.playlist].ShotOnGoal * 100);
            if (stats[current.playlist].TeamShotOnGoal > 0)
                stats[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].TeamGoal) / stats[current.playlist].TeamShotOnGoal * 100);

            if (always_gm[current.playlist].ShotOnGoal > 0)
                always_gm[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].Goal) / always_gm[current.playlist].ShotOnGoal * 100);
            if (always_gm[current.playlist].TeamShotOnGoal > 0)
                always_gm[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].TeamGoal) / always_gm[current.playlist].TeamShotOnGoal * 100);

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalGoalCumul;
                ++always_gm[it->first].TotalGoalCumul;

                if (stats[it->first].TotalShotOnGoalCumul > 0)
                    stats[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TotalGoalCumul) / stats[it->first].TotalShotOnGoalCumul * 100);
                if (always_gm[it->first].TotalShotOnGoalCumul > 0)
                    always_gm[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TotalGoalCumul) / always_gm[it->first].TotalShotOnGoalCumul * 100);

                ++(iam_receiver ? stats[it->first].GoalCumul : stats[it->first].TeamGoalCumul);
                ++(iam_receiver ? always_gm[it->first].GoalCumul : always_gm[it->first].TeamGoalCumul);

                if (stats[it->first].ShotOnGoalCumul > 0)
                    stats[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].GoalCumul) / stats[it->first].ShotOnGoalCumul * 100);
                if (stats[it->first].TeamShotOnGoalCumul > 0)
                    stats[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TeamGoalCumul) / stats[it->first].TeamShotOnGoalCumul * 100);

                if (always_gm[it->first].ShotOnGoalCumul > 0)
                    always_gm[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].GoalCumul) / always_gm[it->first].ShotOnGoalCumul * 100);
                if (always_gm[it->first].TeamShotOnGoalCumul > 0)
                    always_gm[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TeamGoalCumul) / always_gm[it->first].TeamShotOnGoalCumul * 100);
            }

            AllGoalsGoal(true);
        }
        else if (name == "AerialGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalAerialGoal;
            ++current.stats.TotalAerialGoal;
            ++session.TotalAerialGoal;
            ++stats[current.playlist].TotalAerialGoal;
            ++always_gm[current.playlist].TotalAerialGoal;

            ++(iam_receiver ? always.AerialGoal : always.TeamAerialGoal);
            ++(iam_receiver ? current.stats.AerialGoal : current.stats.TeamAerialGoal);
            ++(iam_receiver ? session.AerialGoal : session.TeamAerialGoal);
            ++(iam_receiver ? stats[current.playlist].AerialGoal : stats[current.playlist].TeamAerialGoal);
            ++(iam_receiver ? always_gm[current.playlist].AerialGoal : always_gm[current.playlist].TeamAerialGoal);

            ++always.TotalAerialGoalCumul;
            ++current.stats.TotalAerialGoalCumul;
            ++session.TotalAerialGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalAerialGoalCumul;
                ++always_gm[it->first].TotalAerialGoalCumul;

                ++(iam_receiver ? stats[it->first].AerialGoalCumul : stats[it->first].TeamAerialGoalCumul);
                ++(iam_receiver ? always_gm[it->first].AerialGoalCumul : always_gm[it->first].TeamAerialGoalCumul);
            }

            AllGoalsAerialGoal(true);
        }
        else if (name == "BackwardsGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBackwardsGoal;
            ++current.stats.TotalBackwardsGoal;
            ++session.TotalBackwardsGoal;
            ++stats[current.playlist].TotalBackwardsGoal;
            ++always_gm[current.playlist].TotalBackwardsGoal;

            ++(iam_receiver ? always.BackwardsGoal : always.TeamBackwardsGoal);
            ++(iam_receiver ? current.stats.BackwardsGoal : current.stats.TeamBackwardsGoal);
            ++(iam_receiver ? session.BackwardsGoal : session.TeamBackwardsGoal);
            ++(iam_receiver ? stats[current.playlist].BackwardsGoal : stats[current.playlist].TeamBackwardsGoal);
            ++(iam_receiver ? always_gm[current.playlist].BackwardsGoal : always_gm[current.playlist].TeamBackwardsGoal);

            ++always.TotalBackwardsGoalCumul;
            ++current.stats.TotalBackwardsGoalCumul;
            ++session.TotalBackwardsGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBackwardsGoalCumul;
                ++always_gm[it->first].TotalBackwardsGoalCumul;

                ++(iam_receiver ? stats[it->first].BackwardsGoalCumul : stats[it->first].TeamBackwardsGoalCumul);
                ++(iam_receiver ? always_gm[it->first].BackwardsGoalCumul : always_gm[it->first].TeamBackwardsGoalCumul);
            }

            AllGoalsBackwardsGoal(true);
        }
        else if (name == "BicycleGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBicycleGoal;
            ++current.stats.TotalBicycleGoal;
            ++session.TotalBicycleGoal;
            ++stats[current.playlist].TotalBicycleGoal;
            ++always_gm[current.playlist].TotalBicycleGoal;

            ++(iam_receiver ? always.BicycleGoal : always.TeamBicycleGoal);
            ++(iam_receiver ? current.stats.BicycleGoal : current.stats.TeamBicycleGoal);
            ++(iam_receiver ? session.BicycleGoal : session.TeamBicycleGoal);
            ++(iam_receiver ? stats[current.playlist].BicycleGoal : stats[current.playlist].TeamBicycleGoal);
            ++(iam_receiver ? always_gm[current.playlist].BicycleGoal : always_gm[current.playlist].TeamBicycleGoal);

            ++always.TotalBicycleGoalCumul;
            ++current.stats.TotalBicycleGoalCumul;
            ++session.TotalBicycleGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBicycleGoalCumul;
                ++always_gm[it->first].TotalBicycleGoalCumul;

                ++(iam_receiver ? stats[it->first].BicycleGoalCumul : stats[it->first].TeamBicycleGoalCumul);
                ++(iam_receiver ? always_gm[it->first].BicycleGoalCumul : always_gm[it->first].TeamBicycleGoalCumul);
            }

            AllGoalsBicycleGoal(true);
        }
        else if (name == "LongGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalLongGoal;
            ++current.stats.TotalLongGoal;
            ++session.TotalLongGoal;
            ++stats[current.playlist].TotalLongGoal;
            ++always_gm[current.playlist].TotalLongGoal;

            ++(iam_receiver ? always.LongGoal : always.TeamLongGoal);
            ++(iam_receiver ? current.stats.LongGoal : current.stats.TeamLongGoal);
            ++(iam_receiver ? session.LongGoal : session.TeamLongGoal);
            ++(iam_receiver ? stats[current.playlist].LongGoal : stats[current.playlist].TeamLongGoal);
            ++(iam_receiver ? always_gm[current.playlist].LongGoal : always_gm[current.playlist].TeamLongGoal);

            ++always.TotalLongGoalCumul;
            ++current.stats.TotalLongGoalCumul;
            ++session.TotalLongGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalLongGoalCumul;
                ++always_gm[it->first].TotalLongGoalCumul;

                ++(iam_receiver ? stats[it->first].LongGoalCumul : stats[it->first].TeamLongGoalCumul);
                ++(iam_receiver ? always_gm[it->first].LongGoalCumul : always_gm[it->first].TeamLongGoalCumul);
            }

            AllGoalsLongGoal(true);
        }
        else if (name == "TurtleGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalTurtleGoal;
            ++current.stats.TotalTurtleGoal;
            ++session.TotalTurtleGoal;
            ++stats[current.playlist].TotalTurtleGoal;
            ++always_gm[current.playlist].TotalTurtleGoal;

            ++(iam_receiver ? always.TurtleGoal : always.TeamTurtleGoal);
            ++(iam_receiver ? current.stats.TurtleGoal : current.stats.TeamTurtleGoal);
            ++(iam_receiver ? session.TurtleGoal : session.TeamTurtleGoal);
            ++(iam_receiver ? stats[current.playlist].TurtleGoal : stats[current.playlist].TeamTurtleGoal);
            ++(iam_receiver ? always_gm[current.playlist].TurtleGoal : always_gm[current.playlist].TeamTurtleGoal);

            ++always.TotalTurtleGoalCumul;
            ++current.stats.TotalTurtleGoalCumul;
            ++session.TotalTurtleGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalTurtleGoalCumul;
                ++always_gm[it->first].TotalTurtleGoalCumul;

                ++(iam_receiver ? stats[it->first].TurtleGoalCumul : stats[it->first].TeamTurtleGoalCumul);
                ++(iam_receiver ? always_gm[it->first].TurtleGoalCumul : always_gm[it->first].TeamTurtleGoalCumul);
            }

            AllGoalsTurtleGoal(true);
        }
        else if (name == "OvertimeGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalOvertimeGoal;
            ++current.stats.TotalOvertimeGoal;
            ++session.TotalOvertimeGoal;
            ++stats[current.playlist].TotalOvertimeGoal;
            ++always_gm[current.playlist].TotalOvertimeGoal;

            ++(iam_receiver ? always.OvertimeGoal : always.TeamOvertimeGoal);
            ++(iam_receiver ? current.stats.OvertimeGoal : current.stats.TeamOvertimeGoal);
            ++(iam_receiver ? session.OvertimeGoal : session.TeamOvertimeGoal);
            ++(iam_receiver ? stats[current.playlist].OvertimeGoal : stats[current.playlist].TeamOvertimeGoal);
            ++(iam_receiver ? always_gm[current.playlist].OvertimeGoal : always_gm[current.playlist].TeamOvertimeGoal);

            ++always.TotalOvertimeGoalCumul;
            ++current.stats.TotalOvertimeGoalCumul;
            ++session.TotalOvertimeGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalOvertimeGoalCumul;
                ++always_gm[it->first].TotalOvertimeGoalCumul;

                ++(iam_receiver ? stats[it->first].OvertimeGoalCumul : stats[it->first].TeamOvertimeGoalCumul);
                ++(iam_receiver ? always_gm[it->first].OvertimeGoalCumul : always_gm[it->first].TeamOvertimeGoalCumul);
            }

            AllGoalsOvertimeGoal(true);
        }
        else if (name == "HoopsSwishGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalHoopsSwishGoal;
            ++current.stats.TotalHoopsSwishGoal;
            ++session.TotalHoopsSwishGoal;
            ++stats[current.playlist].TotalHoopsSwishGoal;
            ++always_gm[current.playlist].TotalHoopsSwishGoal;

            ++(iam_receiver ? always.HoopsSwishGoal : always.TeamHoopsSwishGoal);
            ++(iam_receiver ? current.stats.HoopsSwishGoal : current.stats.TeamHoopsSwishGoal);
            ++(iam_receiver ? session.HoopsSwishGoal : session.TeamHoopsSwishGoal);
            ++(iam_receiver ? stats[current.playlist].HoopsSwishGoal : stats[current.playlist].TeamHoopsSwishGoal);
            ++(iam_receiver ? always_gm[current.playlist].HoopsSwishGoal : always_gm[current.playlist].TeamHoopsSwishGoal);

            ++always.TotalHoopsSwishGoalCumul;
            ++current.stats.TotalHoopsSwishGoalCumul;
            ++session.TotalHoopsSwishGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalHoopsSwishGoalCumul;
                ++always_gm[it->first].TotalHoopsSwishGoalCumul;

                ++(iam_receiver ? stats[it->first].HoopsSwishGoalCumul : stats[it->first].TeamHoopsSwishGoalCumul);
                ++(iam_receiver ? always_gm[it->first].HoopsSwishGoalCumul : always_gm[it->first].TeamHoopsSwishGoalCumul);
            }

            AllGoalsHoopsSwishGoal(true);
        }
        else if (name == "PoolShot")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalPoolShot;
            ++current.stats.TotalPoolShot;
            ++session.TotalPoolShot;
            ++stats[current.playlist].TotalPoolShot;
            ++always_gm[current.playlist].TotalPoolShot;

            ++(iam_receiver ? always.PoolShot : always.TeamPoolShot);
            ++(iam_receiver ? current.stats.PoolShot : current.stats.TeamPoolShot);
            ++(iam_receiver ? session.PoolShot : session.TeamPoolShot);
            ++(iam_receiver ? stats[current.playlist].PoolShot : stats[current.playlist].TeamPoolShot);
            ++(iam_receiver ? always_gm[current.playlist].PoolShot : always_gm[current.playlist].TeamPoolShot);

            ++always.TotalPoolShotCumul;
            ++current.stats.TotalPoolShotCumul;
            ++session.TotalPoolShotCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalPoolShotCumul;
                ++always_gm[it->first].TotalPoolShotCumul;

                ++(iam_receiver ? stats[it->first].PoolShotCumul : stats[it->first].TeamPoolShotCumul);
                ++(iam_receiver ? always_gm[it->first].PoolShotCumul : always_gm[it->first].TeamPoolShotCumul);
            }

            AllGoalsPoolShot(true);
        }
        else if (name == "FirstTouch")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.FirstTouch;
            ++current.stats.FirstTouch;
            ++session.FirstTouch;
            ++stats[current.playlist].FirstTouch;
            ++always_gm[current.playlist].FirstTouch;

            ++always.FirstTouchCumul;
            ++current.stats.FirstTouchCumul;
            ++session.FirstTouchCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].FirstTouchCumul;
                ++always_gm[it->first].FirstTouchCumul;
            }

            AllMiscsFirstTouch(true);
        }
        else if (name == "Savior")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalSavior;
            ++current.stats.TotalSavior;
            ++session.TotalSavior;
            ++stats[current.playlist].TotalSavior;
            ++always_gm[current.playlist].TotalSavior;

            ++(iam_receiver ? always.Savior : always.TeamSavior);
            ++(iam_receiver ? current.stats.Savior : current.stats.TeamSavior);
            ++(iam_receiver ? session.Savior : session.TeamSavior);
            ++(iam_receiver ? stats[current.playlist].Savior : stats[current.playlist].TeamSavior);
            ++(iam_receiver ? always_gm[current.playlist].Savior : always_gm[current.playlist].TeamSavior);

            ++always.TotalSaviorCumul;
            ++current.stats.TotalSaviorCumul;
            ++session.TotalSaviorCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalSaviorCumul;
                ++always_gm[it->first].TotalSaviorCumul;

                ++(iam_receiver ? stats[it->first].SaviorCumul : stats[it->first].TeamSaviorCumul);
                ++(iam_receiver ? always_gm[it->first].SaviorCumul : always_gm[it->first].TeamSaviorCumul);
            }

            AllMiscsSavior(true);
        }
        else if (name == "LowFive")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalLowFive;
            ++current.stats.TotalLowFive;
            ++session.TotalLowFive;
            ++stats[current.playlist].TotalLowFive;
            ++always_gm[current.playlist].TotalLowFive;

            ++(iam_receiver ? always.LowFive : always.TeamLowFive);
            ++(iam_receiver ? current.stats.LowFive : current.stats.TeamLowFive);
            ++(iam_receiver ? session.LowFive : session.TeamLowFive);
            ++(iam_receiver ? stats[current.playlist].LowFive : stats[current.playlist].TeamLowFive);
            ++(iam_receiver ? always_gm[current.playlist].LowFive : always_gm[current.playlist].TeamLowFive);

            ++always.TotalLowFiveCumul;
            ++current.stats.TotalLowFiveCumul;
            ++session.TotalLowFiveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalLowFiveCumul;
                ++always_gm[it->first].TotalLowFiveCumul;

                ++(iam_receiver ? stats[it->first].LowFiveCumul : stats[it->first].TeamLowFiveCumul);
                ++(iam_receiver ? always_gm[it->first].LowFiveCumul : always_gm[it->first].TeamLowFiveCumul);
            }

            AllMiscsLowFive(true);
        }
        else if (name == "HatTrick")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalHatTrick;
            ++current.stats.TotalHatTrick;
            ++session.TotalHatTrick;
            ++stats[current.playlist].TotalHatTrick;
            ++always_gm[current.playlist].TotalHatTrick;

            ++(iam_receiver ? always.HatTrick : always.TeamHatTrick);
            ++(iam_receiver ? current.stats.HatTrick : current.stats.TeamHatTrick);
            ++(iam_receiver ? session.HatTrick : session.TeamHatTrick);
            ++(iam_receiver ? stats[current.playlist].HatTrick : stats[current.playlist].TeamHatTrick);
            ++(iam_receiver ? always_gm[current.playlist].HatTrick : always_gm[current.playlist].TeamHatTrick);

            ++always.TotalHatTrickCumul;
            ++current.stats.TotalHatTrickCumul;
            ++session.TotalHatTrickCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalHatTrickCumul;
                ++always_gm[it->first].TotalHatTrickCumul;

                ++(iam_receiver ? stats[it->first].HatTrickCumul : stats[it->first].TeamHatTrickCumul);
                ++(iam_receiver ? always_gm[it->first].HatTrickCumul : always_gm[it->first].TeamHatTrickCumul);
            }

            AllMiscsHatTrick(true);
        }
        else if (name == "HighFive")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalHighFive;
            ++current.stats.TotalHighFive;
            ++session.TotalHighFive;
            ++stats[current.playlist].TotalHighFive;
            ++always_gm[current.playlist].TotalHighFive;

            ++(iam_receiver ? always.HighFive : always.TeamHighFive);
            ++(iam_receiver ? current.stats.HighFive : current.stats.TeamHighFive);
            ++(iam_receiver ? session.HighFive : session.TeamHighFive);
            ++(iam_receiver ? stats[current.playlist].HighFive : stats[current.playlist].TeamHighFive);
            ++(iam_receiver ? always_gm[current.playlist].HighFive : always_gm[current.playlist].TeamHighFive);

            ++always.TotalHighFiveCumul;
            ++current.stats.TotalHighFiveCumul;
            ++session.TotalHighFiveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalHighFiveCumul;
                ++always_gm[it->first].TotalHighFiveCumul;

                ++(iam_receiver ? stats[it->first].HighFiveCumul : stats[it->first].TeamHighFiveCumul);
                ++(iam_receiver ? always_gm[it->first].HighFiveCumul : always_gm[it->first].TeamHighFiveCumul);
            }

            AllMiscsHighFive(true);
        }
        else if (name == "Playmaker")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalPlaymaker;
            ++current.stats.TotalPlaymaker;
            ++session.TotalPlaymaker;
            ++stats[current.playlist].TotalPlaymaker;
            ++always_gm[current.playlist].TotalPlaymaker;

            ++(iam_receiver ? always.Playmaker : always.TeamPlaymaker);
            ++(iam_receiver ? current.stats.Playmaker : current.stats.TeamPlaymaker);
            ++(iam_receiver ? session.Playmaker : session.TeamPlaymaker);
            ++(iam_receiver ? stats[current.playlist].Playmaker : stats[current.playlist].TeamPlaymaker);
            ++(iam_receiver ? always_gm[current.playlist].Playmaker : always_gm[current.playlist].TeamPlaymaker);

            ++always.TotalPlaymakerCumul;
            ++current.stats.TotalPlaymakerCumul;
            ++session.TotalPlaymakerCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalPlaymakerCumul;
                ++always_gm[it->first].TotalPlaymakerCumul;

                ++(iam_receiver ? stats[it->first].PlaymakerCumul : stats[it->first].TeamPlaymakerCumul);
                ++(iam_receiver ? always_gm[it->first].PlaymakerCumul : always_gm[it->first].TeamPlaymakerCumul);
            }

            AllMiscsPlaymaker(true);
        }
        else if (name == "Demolish")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            if (iam_receiver || iam_victim || team_receiver || team_victim)
            {
                ++((iam_receiver || team_receiver) ? always.TotalDemolitions : always.TotalDeath);
                ++((iam_receiver || team_receiver) ? current.stats.TotalDemolitions : current.stats.TotalDeath);
                ++((iam_receiver || team_receiver) ? session.TotalDemolitions : session.TotalDeath);
                ++((iam_receiver || team_receiver) ? stats[current.playlist].TotalDemolitions : stats[current.playlist].TotalDeath);
                ++((iam_receiver || team_receiver) ? always_gm[current.playlist].TotalDemolitions : always_gm[current.playlist].TotalDeath);

                ++((iam_receiver || team_receiver) ? always.TotalDemolitionsCumul : always.TotalDeathCumul);
                ++((iam_receiver || team_receiver) ? current.stats.TotalDemolitionsCumul : current.stats.TotalDeathCumul);
                ++((iam_receiver || team_receiver) ? session.TotalDemolitionsCumul : session.TotalDeathCumul);

                for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
                {
                    ++((iam_receiver || team_receiver) ? stats[it->first].TotalDemolitionsCumul : stats[it->first].TotalDeathCumul);
                    ++((iam_receiver || team_receiver) ? always_gm[it->first].TotalDemolitionsCumul : always_gm[it->first].TotalDeathCumul);
                }
            }

            if (iam_receiver || iam_victim)
            {
                ++(iam_receiver ? always.Demolitions : always.Death);
                ++(iam_receiver ? current.stats.Demolitions : current.stats.Death);
                ++(iam_receiver ? session.Demolitions : session.Death);
                ++(iam_receiver ? stats[current.playlist].Demolitions : stats[current.playlist].Death);
                ++(iam_receiver ? always_gm[current.playlist].Demolitions : always_gm[current.playlist].Death);

                ++(iam_receiver ? always.DemolitionsCumul : always.DeathCumul);
                ++(iam_receiver ? current.stats.DemolitionsCumul : current.stats.DeathCumul);
                ++(iam_receiver ? session.DemolitionsCumul : session.DeathCumul);

                for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
                {
                    ++(iam_receiver ? stats[it->first].DemolitionsCumul : stats[it->first].DeathCumul);
                    ++(iam_receiver ? always_gm[it->first].DemolitionsCumul : always_gm[it->first].DeathCumul);
                }

                if (iam_receiver)
                    AllMiscsDemolitions(true);
                else
                    AllMiscsDeath(true);
            }
            else if (team_receiver || team_victim)
            {
                ++(team_receiver ? always.TeamDemolitions : always.TeamDeath);
                ++(team_receiver ? current.stats.TeamDemolitions : current.stats.TeamDeath);
                ++(team_receiver ? session.TeamDemolitions : session.TeamDeath);
                ++(team_receiver ? stats[current.playlist].TeamDemolitions : stats[current.playlist].TeamDeath);
                ++(team_receiver ? always_gm[current.playlist].TeamDemolitions : always_gm[current.playlist].TeamDeath);

                ++(team_receiver ? always.TeamDemolitionsCumul : always.TeamDeathCumul);
                ++(team_receiver ? current.stats.TeamDemolitionsCumul : current.stats.TeamDeathCumul);
                ++(team_receiver ? session.TeamDemolitionsCumul : session.TeamDeathCumul);

                for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
                {
                    ++(team_receiver ? stats[it->first].TeamDemolitionsCumul : stats[it->first].TeamDeathCumul);
                    ++(team_receiver ? always_gm[it->first].TeamDemolitionsCumul : always_gm[it->first].TeamDeathCumul);
                }

                if (team_receiver)
                    AllMiscsDemolitions(true);
                else
                    AllMiscsDeath(true);
            }
        }
        else if (name == "BreakoutDamage")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBreakoutDamage;
            ++current.stats.TotalBreakoutDamage;
            ++session.TotalBreakoutDamage;
            ++stats[current.playlist].TotalBreakoutDamage;
            ++always_gm[current.playlist].TotalBreakoutDamage;

            ++(iam_receiver ? always.BreakoutDamage : always.TeamBreakoutDamage);
            ++(iam_receiver ? current.stats.BreakoutDamage : current.stats.TeamBreakoutDamage);
            ++(iam_receiver ? session.BreakoutDamage : session.TeamBreakoutDamage);
            ++(iam_receiver ? stats[current.playlist].BreakoutDamage : stats[current.playlist].TeamBreakoutDamage);
            ++(iam_receiver ? always_gm[current.playlist].BreakoutDamage : always_gm[current.playlist].TeamBreakoutDamage);

            ++always.TotalBreakoutDamageCumul;
            ++current.stats.TotalBreakoutDamageCumul;
            ++session.TotalBreakoutDamageCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBreakoutDamageCumul;
                ++always_gm[it->first].TotalBreakoutDamageCumul;

                ++(iam_receiver ? stats[it->first].BreakoutDamageCumul : stats[it->first].TeamBreakoutDamageCumul);
                ++(iam_receiver ? always_gm[it->first].BreakoutDamageCumul : always_gm[it->first].TeamBreakoutDamageCumul);
            }

            AllDropshotBreakoutDamage(true);
        }
        else if (name == "BreakoutDamageLarge")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBreakoutDamageLarge;
            ++current.stats.TotalBreakoutDamageLarge;
            ++session.TotalBreakoutDamageLarge;
            ++stats[current.playlist].TotalBreakoutDamageLarge;
            ++always_gm[current.playlist].TotalBreakoutDamageLarge;

            ++(iam_receiver ? always.BreakoutDamageLarge : always.TeamBreakoutDamageLarge);
            ++(iam_receiver ? current.stats.BreakoutDamageLarge : current.stats.TeamBreakoutDamageLarge);
            ++(iam_receiver ? session.BreakoutDamageLarge : session.TeamBreakoutDamageLarge);
            ++(iam_receiver ? stats[current.playlist].BreakoutDamageLarge : stats[current.playlist].TeamBreakoutDamageLarge);
            ++(iam_receiver ? always_gm[current.playlist].BreakoutDamageLarge : always_gm[current.playlist].TeamBreakoutDamageLarge);

            ++always.TotalBreakoutDamageLargeCumul;
            ++current.stats.TotalBreakoutDamageLargeCumul;
            ++session.TotalBreakoutDamageLargeCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBreakoutDamageLargeCumul;
                ++always_gm[it->first].TotalBreakoutDamageLargeCumul;

                ++(iam_receiver ? stats[it->first].BreakoutDamageLargeCumul : stats[it->first].TeamBreakoutDamageLargeCumul);
                ++(iam_receiver ? always_gm[it->first].BreakoutDamageLargeCumul : always_gm[it->first].TeamBreakoutDamageLargeCumul);
            }

            AllDropshotBreakoutDamageLarge(true);
        }
        else if (name == "KO_Knockout" && (iam_receiver || iam_victim))
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++(iam_receiver ? always.KnockoutKO : always.Death);
            ++(iam_receiver ? current.stats.KnockoutKO : current.stats.Death);
            ++(iam_receiver ? session.KnockoutKO : session.Death);
            ++(iam_receiver ? stats[current.playlist].KnockoutKO : stats[current.playlist].Death);
            ++(iam_receiver ? always_gm[current.playlist].KnockoutKO : always_gm[current.playlist].Death);

            ++(iam_receiver ? always.KnockoutKOCumul : always.DeathCumul);
            ++(iam_receiver ? current.stats.KnockoutKOCumul : current.stats.DeathCumul);
            ++(iam_receiver ? session.KnockoutKOCumul : session.DeathCumul);

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++(iam_receiver ? stats[it->first].KnockoutKOCumul : stats[it->first].DeathCumul);
                ++(iam_receiver ? always_gm[it->first].KnockoutKOCumul : always_gm[it->first].DeathCumul);
            }

            if (iam_receiver)
                AllKnockoutKO(true);
            else
                AllKnockoutDeath(true);
        }
        else if (name == "KO_KnockoutAssist")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutAssist;
            ++current.stats.KnockoutAssist;
            ++session.KnockoutAssist;
            ++stats[current.playlist].KnockoutAssist;
            ++always_gm[current.playlist].KnockoutAssist;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutAssistCumul;
                ++always_gm[it->first].KnockoutAssistCumul;
            }

            AllKnockoutAssist(true);
        }
        else if (name == "KO_DoubleKO" && iam_receiver)
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutDoubleKO;
            ++current.stats.KnockoutDoubleKO;
            ++session.KnockoutDoubleKO;
            ++stats[current.playlist].KnockoutDoubleKO;
            ++always_gm[current.playlist].KnockoutDoubleKO;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutDoubleKOCumul;
                ++always_gm[it->first].KnockoutDoubleKOCumul;
            }

            AllKnockoutDoubleKO(true);
        }
        else if (name == "KO_HeavyHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutHeavyHit;
            ++current.stats.KnockoutHeavyHit;
            ++session.KnockoutHeavyHit;
            ++stats[current.playlist].KnockoutHeavyHit;
            ++always_gm[current.playlist].KnockoutHeavyHit;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutHeavyHitCumul;
                ++always_gm[it->first].KnockoutHeavyHitCumul;
            }

            AllKnockoutHeavyHit(true);
        }
        else if (name == "KO_TripleKO")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutTripleKO;
            ++current.stats.KnockoutTripleKO;
            ++session.KnockoutTripleKO;
            ++stats[current.playlist].KnockoutTripleKO;
            ++always_gm[current.playlist].KnockoutTripleKO;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutTripleKOCumul;
                ++always_gm[it->first].KnockoutTripleKOCumul;
            }

            AllKnockoutTripleKO(true);
        }
        else if (name == "KO_HeavyBlock")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutHeavyBlock;
            ++current.stats.KnockoutHeavyBlock;
            ++session.KnockoutHeavyBlock;
            ++stats[current.playlist].KnockoutHeavyBlock;
            ++always_gm[current.playlist].KnockoutHeavyBlock;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutHeavyBlockCumul;
                ++always_gm[it->first].KnockoutHeavyBlockCumul;
            }

            AllKnockoutHeavyBlock(true);
        }
        else if (name == "KO_AerialHeavyHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutAerialHeavyHit;
            ++current.stats.KnockoutAerialHeavyHit;
            ++session.KnockoutAerialHeavyHit;
            ++stats[current.playlist].KnockoutAerialHeavyHit;
            ++always_gm[current.playlist].KnockoutAerialHeavyHit;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutAerialHeavyHitCumul;
                ++always_gm[it->first].KnockoutAerialHeavyHitCumul;
            }

            AllKnockoutAerialHeavyHit(true);
        }
        else if (name == "KO_AerialLightHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutAerialLightHit;
            ++current.stats.KnockoutAerialLightHit;
            ++session.KnockoutAerialLightHit;
            ++stats[current.playlist].KnockoutAerialLightHit;
            ++always_gm[current.playlist].KnockoutAerialLightHit;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutAerialLightHitCumul;
                ++always_gm[it->first].KnockoutAerialLightHitCumul;
            }

            AllKnockoutAerialLightHit(true);
        }
        else if (name == "MVP")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalMVP;
            ++current.stats.TotalMVP;
            ++session.TotalMVP;
            ++stats[current.playlist].TotalMVP;
            ++always_gm[current.playlist].TotalMVP;

            ++(iam_receiver ? always.MVP : always.TeamMVP);
            ++(iam_receiver ? current.stats.MVP : current.stats.TeamMVP);
            ++(iam_receiver ? session.MVP : session.TeamMVP);
            ++(iam_receiver ? stats[current.playlist].MVP : stats[current.playlist].TeamMVP);
            ++(iam_receiver ? always_gm[current.playlist].MVP : always_gm[current.playlist].TeamMVP);

            ++always.TotalMVPCumul;
            ++current.stats.TotalMVPCumul;
            ++session.TotalMVPCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalMVPCumul;
                ++always_gm[it->first].TotalMVPCumul;

                ++(iam_receiver ? stats[it->first].MVPCumul : stats[it->first].TeamMVPCumul);
                ++(iam_receiver ? always_gm[it->first].MVPCumul : always_gm[it->first].TeamMVPCumul);
            }

            AllAccoladesMVP(true);
        }
        else
        {
            if (name == "Win" || name == "Loss")
                return;

            refresh = false;
            cvarManager->log("onStatTickerMessage " + name + "[" + std::to_string(event.GetPoints()) + "] receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));
        }
    }

    if (refresh)
        SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::onGoalScore(std::string eventName)
{
    TeamWrapper player = GetTeam(false);
    TeamWrapper opposite = GetTeam(true);

    int score_player = current.score_player;
    if (!player.IsNull())
        current.score_player = player.GetScore();

    int score_opposite = current.score_opposite;
    if (!opposite.IsNull())
        current.score_opposite = opposite.GetScore();

    if (current.score_player != score_player || current.score_opposite != score_opposite)
    {
        SendGameState("GoalScore");
        VarScorePlayer(true);
        VarScoreOpposite(true);
    }
}

void RocketStats::InitRank()
{
    int tier = current.tier;
    bool ranked = current.ranked;
    int playlist = current.playlist;

    last_rank = "";
    last_division = "";
    current = t_current();

    current.tier = tier;
    current.ranked = ranked;
    current.playlist = playlist;
}

void RocketStats::MajRank(bool isRanked, float _currentMMR, SkillRank playerRank)
{
    current.tier = playerRank.Tier;
    current.ranked = isRanked;

    if (isRanked)
    {
        current.preview_rank = GetRankName(playerRank.Tier, current.preview_rank_number);
        if (current.preview_rank_number)
            current.preview_rank += " {{Number}}";

        current.preview_division = "Div. {{Number}}";
        current.preview_division_number = (playerRank.Division + 1);

        if (current.playlist != 34 && playerRank.MatchesPlayed < 10)
        {
            current.rank = "Placement: " + std::to_string(playerRank.MatchesPlayed) + "/10";
            current.rank_number = 0;
            current.division = "";
            current.division_number = 0;
        }
        else
        {
            current.rank = current.preview_rank;
            current.rank_number = current.preview_rank_number;
            current.division = current.preview_division;
            current.division_number = current.preview_division_number;
        }
    }
    else
    {
        current.rank = GetPlaylistName(current.playlist);
        current.rank_number = 0;
        current.division = "";
        current.division_number = 0;

        current.preview_rank = current.rank;
        current.preview_rank_number = current.rank_number;
        current.preview_division = current.division;
        current.preview_division_number = current.division_number;
    }

    VarRank(true);
    VarDiv(true);

    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::UpdateMMR(UniqueIDWrapper id)
{
    cvarManager->log("===== UpdateMMR =====");
    /*
    if (id.GetIdString() != gameWrapper->GetUniqueID().GetIdString()) {
        cvarManager->log("Not the user");
        return;
    }
    cvarManager->log("User match");
    */

    if (current.playlist == 0)
    {
        cvarManager->log("Invalid playlist id. Have you just opened the game ?");
        return;
    }

    MMRWrapper mmrw = gameWrapper->GetMMRWrapper();
    float mmr = mmrw.GetPlayerMMR(id, current.playlist);
    SkillRank playerRank = mmrw.GetPlayerRank(id, current.playlist);

    if (stats[current.playlist].isInit)
    {
        float MMRChange = (mmr - stats[current.playlist].myMMR);

        always.MMRChange = MMRChange;
        session.MMRChange = MMRChange;
        stats[current.playlist].MMRChange = MMRChange;
        always_gm[current.playlist].MMRChange = MMRChange;

        always.MMRCumulChange += MMRChange;
        session.MMRCumulChange += MMRChange;
        stats[current.playlist].MMRCumulChange += MMRChange;
        always_gm[current.playlist].MMRCumulChange += MMRChange;
    }
    else
        stats[current.playlist].isInit = true;

    always.myMMR = mmr;
    session.myMMR = mmr;
    stats[current.playlist].myMMR = mmr;
    always_gm[current.playlist].myMMR = mmr;

    MajRank(mmrw.IsRanked(current.playlist), stats[current.playlist].myMMR, playerRank);
    SessionStats();
    VarMMR(true);
    VarMMRChange(true);

    SetRefresh(RefreshFlags_Refresh);
    cvarManager->log("===== !UpdateMMR =====");
}

void RocketStats::InitStats()
{
    session = Stats();
    for (auto& kv : stats)
        kv.second = Stats();

    always = Stats();
    always.isInit = true;
    for (auto& kv : always_gm)
    {
        kv.second = Stats();
        kv.second.isInit = true;
    }
}

void RocketStats::SessionStats()
{
    Stats tmp;

    for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        VarsSession(tmp, it->first, true);

    VarsSession(tmp);
    session.isInit = true;

    always.myMMR = session.myMMR;
    always.MMRChange = session.MMRChange;
    always.isInit = true;

    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::ResetStats()
{
    InitStats();

    WriteConfig();
    ResetFiles();

    InitRank();
    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::ResetBasicStats()
{
    current.stats = Stats();
    current.score_player = 0;
    current.score_opposite = 0;
}
```

## File: Managements/VarsManagement.cpp
```cpp
#include "../RocketStats.h"

void RocketStats::VarsReplace(std::map<std::string, std::string>& vars)
{
    ReplaceOther(vars);
    ReplaceShots(vars);
    ReplaceSaves(vars);
    ReplaceGoals(vars);
    ReplaceDropshot(vars);
    ReplaceKnockout(vars);
    ReplaceMiscs(vars);
    ReplaceAccolades(vars);
}

void RocketStats::VarsSession(Stats& stat, int index, bool playlists)
{
    SessionOther(stat, index, playlists);
    SessionShots(stat, index, playlists);
    SessionSaves(stat, index, playlists);
    SessionGoals(stat, index, playlists);
    SessionDropshot(stat, index, playlists);
    SessionKnockout(stat, index, playlists);
    SessionMiscs(stat, index, playlists);
    SessionAccolades(stat, index, playlists);
}

void RocketStats::VarsRead(Stats& stat, json& config)
{
    ReadOther(stat, config);
    ReadShots(stat, config);
    ReadSaves(stat, config);
    ReadGoals(stat, config);
    ReadDropshot(stat, config);
    ReadKnockout(stat, config);
    ReadMiscs(stat, config);
    ReadAccolades(stat, config);
}

void RocketStats::VarsWrite(Stats& stat, json& config, bool more)
{
    WriteOther(stat, config, more);
    WriteShots(stat, config, more);
    WriteSaves(stat, config, more);
    WriteGoals(stat, config, more);
    WriteDropshot(stat, config, more);
    WriteKnockout(stat, config, more);
    WriteMiscs(stat, config, more);
    WriteAccolades(stat, config, more);
}

#pragma region Other
void RocketStats::AllOther(bool force, bool default_value)
{
    VarGames(true, force, default_value);
    VarGameMode(true, force, default_value);
    VarRank(true, force, default_value);
    VarDiv(true, force, default_value);
    VarMMR(true, force, default_value);
    VarMMRChange(true, force, default_value);
    VarMMRCumulChange(true, force, default_value);
    VarWin(true, force, default_value);
    VarLoss(true, force, default_value);
    VarStreak(true, force, default_value);
    VarWinRatio(true, force, default_value);
    VarWinPercentage(true, force, default_value);
    VarScorePlayer(true, force, default_value);
    VarScoreOpposite(true, force, default_value);
    VarBoost(true, force, (!is_game_started || is_game_ended), false);
}
#pragma endregion

#pragma region Shots
void RocketStats::AllShots(bool force, bool default_value)
{
    AllShotsClear(force, default_value);
    AllShotsAssist(force, default_value);
    AllShotsCenter(force, default_value);
    AllShotsAerialHit(force, default_value);
    AllShotsBicycleHit(force, default_value);
    AllShotsShotOnGoal(force, default_value);
}

void RocketStats::AllShotsClear(bool force, bool default_value)
{
    VarShotsClear(true, force, default_value);
    VarShotsClearMatch(true, force, default_value);
    VarShotsClearCumul(true, force, default_value);
}

void RocketStats::AllShotsAssist(bool force, bool default_value)
{
    VarShotsAssist(true, force, default_value);
    VarShotsTeamAssist(true, force, default_value);
    VarShotsTotalAssist(true, force, default_value);

    VarShotsAssistMatch(true, force, default_value);
    VarShotsTeamAssistMatch(true, force, default_value);
    VarShotsTotalAssistMatch(true, force, default_value);

    VarShotsAssistCumul(true, force, default_value);
    VarShotsTeamAssistCumul(true, force, default_value);
    VarShotsTotalAssistCumul(true, force, default_value);
}

void RocketStats::AllShotsCenter(bool force, bool default_value)
{
    VarShotsCenter(true, force, default_value);
    VarShotsCenterMatch(true, force, default_value);
    VarShotsCenterCumul(true, force, default_value);
}

void RocketStats::AllShotsAerialHit(bool force, bool default_value)
{
    VarShotsAerialHit(true, force, default_value);
    VarShotsAerialHitMatch(true, force, default_value);
    VarShotsAerialHitCumul(true, force, default_value);
}

void RocketStats::AllShotsBicycleHit(bool force, bool default_value)
{
    VarShotsBicycleHit(true, force, default_value);
    VarShotsTeamBicycleHit(true, force, default_value);
    VarShotsTotalBicycleHit(true, force, default_value);

    VarShotsBicycleHitMatch(true, force, default_value);
    VarShotsTeamBicycleHitMatch(true, force, default_value);
    VarShotsTotalBicycleHitMatch(true, force, default_value);

    VarShotsBicycleHitCumul(true, force, default_value);
    VarShotsTeamBicycleHitCumul(true, force, default_value);
    VarShotsTotalBicycleHitCumul(true, force, default_value);
}

void RocketStats::AllShotsShotOnGoal(bool force, bool default_value)
{
    VarShotsShotOnGoal(true, force, default_value);
    VarShotsTeamShotOnGoal(true, force, default_value);
    VarShotsTotalShotOnGoal(true, force, default_value);

    VarShotsShotOnGoalMatch(true, force, default_value);
    VarShotsTeamShotOnGoalMatch(true, force, default_value);
    VarShotsTotalShotOnGoalMatch(true, force, default_value);

    VarShotsShotOnGoalCumul(true, force, default_value);
    VarShotsTeamShotOnGoalCumul(true, force, default_value);
    VarShotsTotalShotOnGoalCumul(true, force, default_value);

    VarShotsShootingPercentage(true, force, default_value);
    VarShotsTeamShootingPercentage(true, force, default_value);
    VarShotsTotalShootingPercentage(true, force, default_value);

    VarShotsShootingPercentageMatch(true, force, default_value);
    VarShotsTeamShootingPercentageMatch(true, force, default_value);
    VarShotsTotalShootingPercentageMatch(true, force, default_value);

    VarShotsShootingPercentageCumul(true, force, default_value);
    VarShotsTeamShootingPercentageCumul(true, force, default_value);
    VarShotsTotalShootingPercentageCumul(true, force, default_value);
}
#pragma endregion

#pragma region Saves
void RocketStats::AllSaves(bool force, bool default_value)
{
    AllSavesSave(force, default_value);
    AllSavesEpicSave(force, default_value);
}

void RocketStats::AllSavesSave(bool force, bool default_value)
{
    VarSavesSave(true, force, default_value);
    VarSavesTeamSave(true, force, default_value);
    VarSavesTotalSave(true, force, default_value);

    VarSavesSaveMatch(true, force, default_value);
    VarSavesTeamSaveMatch(true, force, default_value);
    VarSavesTotalSaveMatch(true, force, default_value);

    VarSavesSaveCumul(true, force, default_value);
    VarSavesTeamSaveCumul(true, force, default_value);
    VarSavesTotalSaveCumul(true, force, default_value);
}

void RocketStats::AllSavesEpicSave(bool force, bool default_value)
{
    VarSavesEpicSave(true, force, default_value);
    VarSavesTeamEpicSave(true, force, default_value);
    VarSavesTotalEpicSave(true, force, default_value);

    VarSavesEpicSaveMatch(true, force, default_value);
    VarSavesTeamEpicSaveMatch(true, force, default_value);
    VarSavesTotalEpicSaveMatch(true, force, default_value);

    VarSavesEpicSaveCumul(true, force, default_value);
    VarSavesTeamEpicSaveCumul(true, force, default_value);
    VarSavesTotalEpicSaveCumul(true, force, default_value);
}
#pragma endregion

#pragma region Goals
void RocketStats::AllGoals(bool force, bool default_value)
{
    AllGoalsGoal(force, default_value);
    AllGoalsOwnGoal(force, default_value);
    AllGoalsLongGoal(force, default_value);
    AllGoalsPoolShot(force, default_value);
    AllGoalsAerialGoal(force, default_value);
    AllGoalsTurtleGoal(force, default_value);
    AllGoalsBicycleGoal(force, default_value);
    AllGoalsOvertimeGoal(force, default_value);
    AllGoalsBackwardsGoal(force, default_value);
    AllGoalsHoopsSwishGoal(force, default_value);
}

void RocketStats::AllGoalsGoal(bool force, bool default_value)
{
    VarGoalsGoal(true, force, default_value);
    VarGoalsTeamGoal(true, force, default_value);
    VarGoalsTotalGoal(true, force, default_value);

    VarGoalsGoalMatch(true, force, default_value);
    VarGoalsTeamGoalMatch(true, force, default_value);
    VarGoalsTotalGoalMatch(true, force, default_value);

    VarGoalsGoalCumul(true, force, default_value);
    VarGoalsTeamGoalCumul(true, force, default_value);
    VarGoalsTotalGoalCumul(true, force, default_value);

    VarShotsShootingPercentage(true, force, default_value);
    VarShotsTeamShootingPercentage(true, force, default_value);
    VarShotsTotalShootingPercentage(true, force, default_value);

    VarShotsShootingPercentageMatch(true, force, default_value);
    VarShotsTeamShootingPercentageMatch(true, force, default_value);
    VarShotsTotalShootingPercentageMatch(true, force, default_value);

    VarShotsShootingPercentageCumul(true, force, default_value);
    VarShotsTeamShootingPercentageCumul(true, force, default_value);
    VarShotsTotalShootingPercentageCumul(true, force, default_value);
}

void RocketStats::AllGoalsOwnGoal(bool force, bool default_value)
{
    VarGoalsOwnGoal(true, force, default_value);
    VarGoalsOwnGoalMatch(true, force, default_value);
    VarGoalsOwnGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsLongGoal(bool force, bool default_value)
{
    VarGoalsLongGoal(true, force, default_value);
    VarGoalsTeamLongGoal(true, force, default_value);
    VarGoalsTotalLongGoal(true, force, default_value);

    VarGoalsLongGoalMatch(true, force, default_value);
    VarGoalsTeamLongGoalMatch(true, force, default_value);
    VarGoalsTotalLongGoalMatch(true, force, default_value);

    VarGoalsLongGoalCumul(true, force, default_value);
    VarGoalsTeamLongGoalCumul(true, force, default_value);
    VarGoalsTotalLongGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsPoolShot(bool force, bool default_value)
{
    VarGoalsPoolShot(true, force, default_value);
    VarGoalsTeamPoolShot(true, force, default_value);
    VarGoalsTotalPoolShot(true, force, default_value);

    VarGoalsPoolShotMatch(true, force, default_value);
    VarGoalsTeamPoolShotMatch(true, force, default_value);
    VarGoalsTotalPoolShotMatch(true, force, default_value);

    VarGoalsPoolShotCumul(true, force, default_value);
    VarGoalsTeamPoolShotCumul(true, force, default_value);
    VarGoalsTotalPoolShotCumul(true, force, default_value);
}

void RocketStats::AllGoalsAerialGoal(bool force, bool default_value)
{
    VarGoalsAerialGoal(true, force, default_value);
    VarGoalsTeamAerialGoal(true, force, default_value);
    VarGoalsTotalAerialGoal(true, force, default_value);

    VarGoalsAerialGoalMatch(true, force, default_value);
    VarGoalsTeamAerialGoalMatch(true, force, default_value);
    VarGoalsTotalAerialGoalMatch(true, force, default_value);

    VarGoalsAerialGoalCumul(true, force, default_value);
    VarGoalsTeamAerialGoalCumul(true, force, default_value);
    VarGoalsTotalAerialGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsTurtleGoal(bool force, bool default_value)
{
    VarGoalsTurtleGoal(true, force, default_value);
    VarGoalsTeamTurtleGoal(true, force, default_value);
    VarGoalsTotalTurtleGoal(true, force, default_value);

    VarGoalsTurtleGoalMatch(true, force, default_value);
    VarGoalsTeamTurtleGoalMatch(true, force, default_value);
    VarGoalsTotalTurtleGoalMatch(true, force, default_value);

    VarGoalsTurtleGoalCumul(true, force, default_value);
    VarGoalsTeamTurtleGoalCumul(true, force, default_value);
    VarGoalsTotalTurtleGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsBicycleGoal(bool force, bool default_value)
{
    VarGoalsBicycleGoal(true, force, default_value);
    VarGoalsTeamBicycleGoal(true, force, default_value);
    VarGoalsTotalBicycleGoal(true, force, default_value);

    VarGoalsBicycleGoalMatch(true, force, default_value);
    VarGoalsTeamBicycleGoalMatch(true, force, default_value);
    VarGoalsTotalBicycleGoalMatch(true, force, default_value);

    VarGoalsBicycleGoalCumul(true, force, default_value);
    VarGoalsTeamBicycleGoalCumul(true, force, default_value);
    VarGoalsTotalBicycleGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsOvertimeGoal(bool force, bool default_value)
{
    VarGoalsOvertimeGoal(true, force, default_value);
    VarGoalsTeamOvertimeGoal(true, force, default_value);
    VarGoalsTotalOvertimeGoal(true, force, default_value);

    VarGoalsOvertimeGoalMatch(true, force, default_value);
    VarGoalsTeamOvertimeGoalMatch(true, force, default_value);
    VarGoalsTotalOvertimeGoalMatch(true, force, default_value);

    VarGoalsOvertimeGoalCumul(true, force, default_value);
    VarGoalsTeamOvertimeGoalCumul(true, force, default_value);
    VarGoalsTotalOvertimeGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsBackwardsGoal(bool force, bool default_value)
{
    VarGoalsBackwardsGoal(true, force, default_value);
    VarGoalsTeamBackwardsGoal(true, force, default_value);
    VarGoalsTotalBackwardsGoal(true, force, default_value);

    VarGoalsBackwardsGoalMatch(true, force, default_value);
    VarGoalsTeamBackwardsGoalMatch(true, force, default_value);
    VarGoalsTotalBackwardsGoalMatch(true, force, default_value);

    VarGoalsBackwardsGoalCumul(true, force, default_value);
    VarGoalsTeamBackwardsGoalCumul(true, force, default_value);
    VarGoalsTotalBackwardsGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsHoopsSwishGoal(bool force, bool default_value)
{
    VarGoalsHoopsSwishGoal(true, force, default_value);
    VarGoalsTeamHoopsSwishGoal(true, force, default_value);
    VarGoalsTotalHoopsSwishGoal(true, force, default_value);

    VarGoalsHoopsSwishGoalMatch(true, force, default_value);
    VarGoalsTeamHoopsSwishGoalMatch(true, force, default_value);
    VarGoalsTotalHoopsSwishGoalMatch(true, force, default_value);

    VarGoalsHoopsSwishGoalCumul(true, force, default_value);
    VarGoalsTeamHoopsSwishGoalCumul(true, force, default_value);
    VarGoalsTotalHoopsSwishGoalCumul(true, force, default_value);
}
#pragma endregion

#pragma region Dropshot
void RocketStats::AllDropshot(bool force, bool default_value)
{
    AllDropshotBreakoutDamage(force, default_value);
    AllDropshotBreakoutDamageLarge(force, default_value);
}

void RocketStats::AllDropshotBreakoutDamage(bool force, bool default_value)
{
    VarDropshotBreakoutDamage(true, force, default_value);
    VarDropshotTeamBreakoutDamage(true, force, default_value);
    VarDropshotTotalBreakoutDamage(true, force, default_value);

    VarDropshotBreakoutDamageMatch(true, force, default_value);
    VarDropshotTeamBreakoutDamageMatch(true, force, default_value);
    VarDropshotTotalBreakoutDamageMatch(true, force, default_value);

    VarDropshotBreakoutDamageCumul(true, force, default_value);
    VarDropshotTeamBreakoutDamageCumul(true, force, default_value);
    VarDropshotTotalBreakoutDamageCumul(true, force, default_value);
}

void RocketStats::AllDropshotBreakoutDamageLarge(bool force, bool default_value)
{
    VarDropshotBreakoutDamageLarge(true, force, default_value);
    VarDropshotTeamBreakoutDamageLarge(true, force, default_value);
    VarDropshotTotalBreakoutDamageLarge(true, force, default_value);

    VarDropshotBreakoutDamageLargeMatch(true, force, default_value);
    VarDropshotTeamBreakoutDamageLargeMatch(true, force, default_value);
    VarDropshotTotalBreakoutDamageLargeMatch(true, force, default_value);

    VarDropshotBreakoutDamageLargeCumul(true, force, default_value);
    VarDropshotTeamBreakoutDamageLargeCumul(true, force, default_value);
    VarDropshotTotalBreakoutDamageLargeCumul(true, force, default_value);
}
#pragma endregion

#pragma region Knockout
void RocketStats::AllKnockout(bool force, bool default_value)
{
    AllKnockoutKO(force, default_value);
    AllKnockoutDeath(force, default_value);
    AllKnockoutAssist(force, default_value);
    AllKnockoutThrown(force, default_value);
    AllKnockoutWinner(force, default_value);
    AllKnockoutGrabbed(force, default_value);
    AllKnockoutDoubleKO(force, default_value);
    AllKnockoutHeavyHit(force, default_value);
    AllKnockoutHitTaken(force, default_value);
    AllKnockoutLightHit(force, default_value);
    AllKnockoutTripleKO(force, default_value);
    AllKnockoutBlockTaken(force, default_value);
    AllKnockoutHeavyBlock(force, default_value);
    AllKnockoutLightBlock(force, default_value);
    AllKnockoutPlayerThrown(force, default_value);
    AllKnockoutPlayerGrabbed(force, default_value);
    AllKnockoutAerialHeavyHit(force, default_value);
    AllKnockoutAerialLightHit(force, default_value);
}

void RocketStats::AllKnockoutKO(bool force, bool default_value)
{
    VarKnockoutKO(true, force, default_value);
    VarKnockoutKOMatch(true, force, default_value);
    VarKnockoutKOCumul(true, force, default_value);
}

void RocketStats::AllKnockoutDeath(bool force, bool default_value)
{
    VarKnockoutDeath(true, force, default_value);
    VarKnockoutDeathMatch(true, force, default_value);
    VarKnockoutDeathCumul(true, force, default_value);
}

void RocketStats::AllKnockoutAssist(bool force, bool default_value)
{
    VarKnockoutAssist(true, force, default_value);
    VarKnockoutAssistMatch(true, force, default_value);
    VarKnockoutAssistCumul(true, force, default_value);
}

void RocketStats::AllKnockoutThrown(bool force, bool default_value)
{
    VarKnockoutThrown(true, force, default_value);
    VarKnockoutThrownMatch(true, force, default_value);
    VarKnockoutThrownCumul(true, force, default_value);
}

void RocketStats::AllKnockoutWinner(bool force, bool default_value)
{
    VarKnockoutWinner(true, force, default_value);
    VarKnockoutWinnerMatch(true, force, default_value);
    VarKnockoutWinnerCumul(true, force, default_value);
}

void RocketStats::AllKnockoutGrabbed(bool force, bool default_value)
{
    VarKnockoutGrabbed(true, force, default_value);
    VarKnockoutGrabbedMatch(true, force, default_value);
    VarKnockoutGrabbedCumul(true, force, default_value);
}

void RocketStats::AllKnockoutDoubleKO(bool force, bool default_value)
{
    VarKnockoutDoubleKO(true, force, default_value);
    VarKnockoutDoubleKOMatch(true, force, default_value);
    VarKnockoutDoubleKOCumul(true, force, default_value);
}

void RocketStats::AllKnockoutHeavyHit(bool force, bool default_value)
{
    VarKnockoutHeavyHit(true, force, default_value);
    VarKnockoutHeavyHitMatch(true, force, default_value);
    VarKnockoutHeavyHitCumul(true, force, default_value);
}

void RocketStats::AllKnockoutHitTaken(bool force, bool default_value)
{
    VarKnockoutHitTaken(true, force, default_value);
    VarKnockoutHitTakenMatch(true, force, default_value);
    VarKnockoutHitTakenCumul(true, force, default_value);
}

void RocketStats::AllKnockoutLightHit(bool force, bool default_value)
{
    VarKnockoutLightHit(true, force, default_value);
    VarKnockoutLightHitMatch(true, force, default_value);
    VarKnockoutLightHitCumul(true, force, default_value);
}

void RocketStats::AllKnockoutTripleKO(bool force, bool default_value)
{
    VarKnockoutTripleKO(true, force, default_value);
    VarKnockoutTripleKOMatch(true, force, default_value);
    VarKnockoutTripleKOCumul(true, force, default_value);
}

void RocketStats::AllKnockoutBlockTaken(bool force, bool default_value)
{
    VarKnockoutBlockTaken(true, force, default_value);
    VarKnockoutBlockTakenMatch(true, force, default_value);
    VarKnockoutBlockTakenCumul(true, force, default_value);
}

void RocketStats::AllKnockoutHeavyBlock(bool force, bool default_value)
{
    VarKnockoutHeavyBlock(true, force, default_value);
    VarKnockoutHeavyBlockMatch(true, force, default_value);
    VarKnockoutHeavyBlockCumul(true, force, default_value);
}

void RocketStats::AllKnockoutLightBlock(bool force, bool default_value)
{
    VarKnockoutLightBlock(true, force, default_value);
    VarKnockoutLightBlockMatch(true, force, default_value);
    VarKnockoutLightBlockCumul(true, force, default_value);
}

void RocketStats::AllKnockoutPlayerThrown(bool force, bool default_value)
{
    VarKnockoutPlayerThrown(true, force, default_value);
    VarKnockoutPlayerThrownMatch(true, force, default_value);
    VarKnockoutPlayerThrownCumul(true, force, default_value);
}

void RocketStats::AllKnockoutPlayerGrabbed(bool force, bool default_value)
{
    VarKnockoutPlayerGrabbed(true, force, default_value);
    VarKnockoutPlayerGrabbedMatch(true, force, default_value);
    VarKnockoutPlayerGrabbedCumul(true, force, default_value);
}

void RocketStats::AllKnockoutAerialHeavyHit(bool force, bool default_value)
{
    VarKnockoutAerialHeavyHit(true, force, default_value);
    VarKnockoutAerialHeavyHitMatch(true, force, default_value);
    VarKnockoutAerialHeavyHitCumul(true, force, default_value);
}

void RocketStats::AllKnockoutAerialLightHit(bool force, bool default_value)
{
    VarKnockoutAerialLightHit(true, force, default_value);
    VarKnockoutAerialLightHitMatch(true, force, default_value);
    VarKnockoutAerialLightHitCumul(true, force, default_value);
}
#pragma endregion

#pragma region Miscs
void RocketStats::AllMiscs(bool force, bool default_value)
{
    AllMiscsDeath(force, default_value);
    AllMiscsSavior(force, default_value);
    AllMiscsLowFive(force, default_value);
    AllMiscsHatTrick(force, default_value);
    AllMiscsHighFive(force, default_value);
    AllMiscsPlaymaker(force, default_value);
    AllMiscsFirstTouch(force, default_value);
    AllMiscsDemolitions(force, default_value);
}

void RocketStats::AllMiscsDeath(bool force, bool default_value)
{
    VarMiscsDeath(true, force, default_value);
    VarMiscsTeamDeath(true, force, default_value);
    VarMiscsTotalDeath(true, force, default_value);

    VarMiscsDeathMatch(true, force, default_value);
    VarMiscsTeamDeathMatch(true, force, default_value);
    VarMiscsTotalDeathMatch(true, force, default_value);

    VarMiscsDeathCumul(true, force, default_value);
    VarMiscsTeamDeathCumul(true, force, default_value);
    VarMiscsTotalDeathCumul(true, force, default_value);
}

void RocketStats::AllMiscsSavior(bool force, bool default_value)
{
    VarMiscsSavior(true, force, default_value);
    VarMiscsTeamSavior(true, force, default_value);
    VarMiscsTotalSavior(true, force, default_value);

    VarMiscsSaviorMatch(true, force, default_value);
    VarMiscsTeamSaviorMatch(true, force, default_value);
    VarMiscsTotalSaviorMatch(true, force, default_value);

    VarMiscsSaviorCumul(true, force, default_value);
    VarMiscsTeamSaviorCumul(true, force, default_value);
    VarMiscsTotalSaviorCumul(true, force, default_value);
}

void RocketStats::AllMiscsLowFive(bool force, bool default_value)
{
    VarMiscsLowFive(true, force, default_value);
    VarMiscsTeamLowFive(true, force, default_value);
    VarMiscsTotalLowFive(true, force, default_value);

    VarMiscsLowFiveMatch(true, force, default_value);
    VarMiscsTeamLowFiveMatch(true, force, default_value);
    VarMiscsTotalLowFiveMatch(true, force, default_value);

    VarMiscsLowFiveCumul(true, force, default_value);
    VarMiscsTeamLowFiveCumul(true, force, default_value);
    VarMiscsTotalLowFiveCumul(true, force, default_value);
}

void RocketStats::AllMiscsHatTrick(bool force, bool default_value)
{
    VarMiscsHatTrick(true, force, default_value);
    VarMiscsTeamHatTrick(true, force, default_value);
    VarMiscsTotalHatTrick(true, force, default_value);

    VarMiscsHatTrickMatch(true, force, default_value);
    VarMiscsTeamHatTrickMatch(true, force, default_value);
    VarMiscsTotalHatTrickMatch(true, force, default_value);

    VarMiscsHatTrickCumul(true, force, default_value);
    VarMiscsTeamHatTrickCumul(true, force, default_value);
    VarMiscsTotalHatTrickCumul(true, force, default_value);
}

void RocketStats::AllMiscsHighFive(bool force, bool default_value)
{
    VarMiscsHighFive(true, force, default_value);
    VarMiscsTeamHighFive(true, force, default_value);
    VarMiscsTotalHighFive(true, force, default_value);

    VarMiscsHighFiveMatch(true, force, default_value);
    VarMiscsTeamHighFiveMatch(true, force, default_value);
    VarMiscsTotalHighFiveMatch(true, force, default_value);

    VarMiscsHighFiveCumul(true, force, default_value);
    VarMiscsTeamHighFiveCumul(true, force, default_value);
    VarMiscsTotalHighFiveCumul(true, force, default_value);
}

void RocketStats::AllMiscsPlaymaker(bool force, bool default_value)
{
    VarMiscsPlaymaker(true, force, default_value);
    VarMiscsTeamPlaymaker(true, force, default_value);
    VarMiscsTotalPlaymaker(true, force, default_value);

    VarMiscsPlaymakerMatch(true, force, default_value);
    VarMiscsTeamPlaymakerMatch(true, force, default_value);
    VarMiscsTotalPlaymakerMatch(true, force, default_value);

    VarMiscsPlaymakerCumul(true, force, default_value);
    VarMiscsTeamPlaymakerCumul(true, force, default_value);
    VarMiscsTotalPlaymakerCumul(true, force, default_value);
}

void RocketStats::AllMiscsFirstTouch(bool force, bool default_value)
{
    VarMiscsFirstTouch(true, force, default_value);
    VarMiscsFirstTouchMatch(true, force, default_value);
    VarMiscsFirstTouchCumul(true, force, default_value);
}

void RocketStats::AllMiscsDemolitions(bool force, bool default_value)
{
    VarMiscsDemolitions(true, force, default_value);
    VarMiscsTeamDemolitions(true, force, default_value);
    VarMiscsTotalDemolitions(true, force, default_value);

    VarMiscsDemolitionsMatch(true, force, default_value);
    VarMiscsTeamDemolitionsMatch(true, force, default_value);
    VarMiscsTotalDemolitionsMatch(true, force, default_value);

    VarMiscsDemolitionsCumul(true, force, default_value);
    VarMiscsTeamDemolitionsCumul(true, force, default_value);
    VarMiscsTotalDemolitionsCumul(true, force, default_value);
}
#pragma endregion

#pragma region Accolades
void RocketStats::AllAccolades(bool force, bool default_value)
{
    AllAccoladesMVP(force, default_value);
    AllAccoladesCarTouches(force, default_value);
    AllAccoladesFastestGoal(force, default_value);
    AllAccoladesSlowestGoal(force, default_value);
    AllAccoladesBoostPickups(force, default_value);
    AllAccoladesFurthestGoal(force, default_value);
    AllAccoladesMostBallTouches(force, default_value);
    AllAccoladesMostBoostPickups(force, default_value);
    AllAccoladesFewestBallTouches(force, default_value);
}

void RocketStats::AllAccoladesMVP(bool force, bool default_value)
{
    VarAccoladesMVP(true, force, default_value);
    VarAccoladesTeamMVP(true, force, default_value);
    VarAccoladesTotalMVP(true, force, default_value);

    VarAccoladesMVPMatch(true, force, default_value);
    VarAccoladesTeamMVPMatch(true, force, default_value);
    VarAccoladesTotalMVPMatch(true, force, default_value);

    VarAccoladesMVPCumul(true, force, default_value);
    VarAccoladesTeamMVPCumul(true, force, default_value);
    VarAccoladesTotalMVPCumul(true, force, default_value);
}

void RocketStats::AllAccoladesCarTouches(bool force, bool default_value)
{
    VarAccoladesCarTouches(true, force, default_value);
    VarAccoladesCarTouchesMatch(true, force, default_value);
    VarAccoladesCarTouchesCumul(true, force, default_value);
}

void RocketStats::AllAccoladesFastestGoal(bool force, bool default_value)
{
    VarAccoladesFastestGoal(true, force, default_value);
    VarAccoladesFastestGoalMatch(true, force, default_value);
    VarAccoladesFastestGoalCumul(true, force, default_value);
}

void RocketStats::AllAccoladesSlowestGoal(bool force, bool default_value)
{
    VarAccoladesSlowestGoal(true, force, default_value);
    VarAccoladesSlowestGoalMatch(true, force, default_value);
    VarAccoladesSlowestGoalCumul(true, force, default_value);
}

void RocketStats::AllAccoladesBoostPickups(bool force, bool default_value)
{
    VarAccoladesBoostPickups(true, force, default_value);
    VarAccoladesBoostPickupsMatch(true, force, default_value);
    VarAccoladesBoostPickupsCumul(true, force, default_value);
}

void RocketStats::AllAccoladesFurthestGoal(bool force, bool default_value)
{
    VarAccoladesFurthestGoal(true, force, default_value);
    VarAccoladesFurthestGoalMatch(true, force, default_value);
    VarAccoladesFurthestGoalCumul(true, force, default_value);
}

void RocketStats::AllAccoladesMostBallTouches(bool force, bool default_value)
{
    VarAccoladesMostBallTouches(true, force, default_value);
    VarAccoladesMostBallTouchesMatch(true, force, default_value);
    VarAccoladesMostBallTouchesCumul(true, force, default_value);
}

void RocketStats::AllAccoladesMostBoostPickups(bool force, bool default_value)
{
    VarAccoladesMostBoostPickups(true, force, default_value);
    VarAccoladesMostBoostPickupsMatch(true, force, default_value);
    VarAccoladesMostBoostPickupsCumul(true, force, default_value);
}

void RocketStats::AllAccoladesFewestBallTouches(bool force, bool default_value)
{
    VarAccoladesFewestBallTouches(true, force, default_value);
    VarAccoladesFewestBallTouchesMatch(true, force, default_value);
    VarAccoladesFewestBallTouchesCumul(true, force, default_value);
}
#pragma endregion
```

## File: Managements/FileManagement.cpp
```cpp
#include "../RocketStats.h"

std::string RocketStats::GetPath(std::string _path, bool root)
{
    std::string _return = gameWrapper->GetBakkesModPath().string() + "/";

    if (root)
        _return += _path;
    else
        _return += "data/RocketStats/" + _path;

    return _return;
}

bool RocketStats::ExistsPath(std::string _filename, bool root)
{
    return fs::exists(GetPath(_filename, root));
}

bool RocketStats::RemoveFile(std::string _filename, bool root)
{
    if (!ExistsPath(_filename, root))
        return true;

    try
    {
        return fs::remove(GetPath(_filename, root));
    }
    catch (const std::exception&) {}

    return false;
}

std::string RocketStats::ReadFile(std::string _filename, bool root)
{
    std::string _value = "";
    std::string _path = GetPath(_filename, root);
    if (fs::exists(_path) && fs::is_regular_file(_path) && (fs::status(_path).permissions() & fs::perms::owner_read) == fs::perms::owner_read)
    {
        std::ifstream stream(_path, std::ios::in | std::ios::binary);

        if (stream.is_open())
        {
            std::ostringstream os;
            os << stream.rdbuf();
            _value = os.str();
            stream.close();
        }
        else
            cvarManager->log("Can't read this file: " + _filename);
    }
    else
        cvarManager->log("Bad path: " + _filename);

    return _value;
}

json RocketStats::ReadJSON(std::string _filename, bool root)
{
    cvarManager->log("Read JSON: " + _filename);
    return json::parse(ReadFile(_filename, root));
}

void RocketStats::WriteInFile(std::string _filename, std::string _value, bool root)
{
    std::string _path = GetPath(_filename, root);
    if (!fs::exists(_path) || fs::is_regular_file(_path))
    {
        std::ofstream stream(_path, std::ios::out | std::ios::trunc);

        if (stream.is_open())
        {
            stream << _value;
            stream.close();
        }
        else
        {
            cvarManager->log("Can't write to file: " + _filename);
            cvarManager->log("Value to write was: " + _value);
        }
    }
}

bool RocketStats::WriteResInFile(std::string _filename, int id, const char* type, bool root)
{
    std::string _path = GetPath(_filename, root);
    if (!fs::exists(_path) || fs::is_regular_file(_path))
    {
        Resource res = Resource(id, type, GetModuleHandle("RocketStats"));
        std::span<const char> obj = res.GetResource();

        if (obj.data())
        {
            std::ofstream stream(_path, std::ios::out | std::ios::trunc | std::ios::binary);

            if (stream.is_open())
            {
                stream.write(obj.data(), obj.size());
                stream.close();
                return true;
            }
            else
                cvarManager->log("Can't write to file: " + _filename);
        }
    }

    return false;
}

void RocketStats::MigrateFolder()
{
    // If the old folder exist, copy everything to the new path
    if (ExistsPath("RocketStats", true))
    {
        std::string old_path = GetPath("RocketStats", true);
        fs::copy(old_path, GetPath(), (fs::copy_options::recursive | fs::copy_options::update_existing));
        MigrateRemove();
    }
}

void RocketStats::MigrateRemove()
{
    if (ExistsPath("RocketStats", true))
        fs::remove_all(GetPath("RocketStats", true));

    RemoveFile("RocketStats_Loose.txt"); // Delete the old file
    RemoveFile("RocketStats_images/BoostState.txt"); // Delete the old file
}

void RocketStats::UpdateFiles(bool force)
{
    AllOther(force);
    AllShots(force);
    AllSaves(force);
    AllGoals(force);
    AllDropshot(force);
    AllKnockout(force);
    AllMiscs(force);
    AllAccolades(force);
}

void RocketStats::ResetFiles()
{
    last_rank = "";
    last_division = "";

    AllOther(true, true);
    AllShots(true, true);
    AllSaves(true, true);
    AllGoals(true, true);
    AllDropshot(true, true);
    AllKnockout(true, true);
    AllMiscs(true, true);
    AllAccolades(true, true);
}

bool RocketStats::ReadConfig()
{
    cvarManager->log("===== ReadConfig =====");

    std::string file = "data/rocketstats.json";
    bool exists = ExistsPath(file, true);
    if (exists)
    {
        try
        {
            // Read the plugin settings JSON file
            json config = ReadJSON(file, true);

            if (config.is_object())
            {
                if (config["settings"].is_object() && !config["settings"].is_null())
                {
                    if (config["settings"]["mode"].is_number_unsigned())
                        rs_mode = config["settings"]["mode"];

                    if (config["settings"]["theme"].is_string())
                       SetTheme(config["settings"]["theme"]);

                    if (config["settings"]["overlay"].is_boolean())
                        rs_disp_overlay = config["settings"]["overlay"];

                    if (config["settings"]["GameTheme"].is_string()) {
                        SetGameTheme(config["settings"]["GameTheme"]);
                    }

                    if (config["settings"]["themes"].is_object() && !config["settings"]["themes"].is_null() && config["settings"]["themes"].size())
                    {
                        json tmp = json::object();
                        for (auto it = config["settings"]["themes"].begin(); it != config["settings"]["themes"].end(); ++it)
                        {
                            if (!it.value().is_null())
                            {
                                json ctmp = json::object();
                                for (auto cit = it.value().begin(); cit != it.value().end(); ++cit)
                                {
                                    if (!cit.value().is_null())
                                        ctmp[cit.key()] = cit.value();
                                }

                                if (ctmp.size())
                                    tmp[it.key()] = ctmp;
                            }
                        }

                        if (tmp.size())
                            themes_values = tmp;
                    }

                    if (config["settings"]["inmenu"].is_boolean())
                        rs_enable_inmenu = config["settings"]["inmenu"];
                    if (config["settings"]["enableDualTheme"].is_boolean())
                        dualtheme = config["settings"]["enableDualTheme"];
                    if (config["settings"]["ingame"].is_boolean())
                        rs_enable_ingame = config["settings"]["ingame"];
                    if (config["settings"]["inscoreboard"].is_boolean())
                        rs_enable_inscoreboard = config["settings"]["inscoreboard"];
                    if (config["settings"]["float"].is_boolean())
                        rs_enable_float = config["settings"]["float"];
                    if (config["settings"]["preview"].is_boolean())
                        rs_preview_rank = config["settings"]["preview"];
                    if (config["settings"]["roman"].is_boolean())
                        rs_roman_numbers = config["settings"]["roman"];

                    if (config["settings"]["replace_mmr"].is_boolean())
                        rs_replace_mmr = config["settings"]["replace_mmr"];
                    if (config["settings"]["replace_mmr_cc"].is_boolean())
                        rs_replace_mmr_cc = config["settings"]["replace_mmr_cc"];
                    if (config["settings"]["replace_mmrc"].is_boolean())
                        rs_replace_mmrc = config["settings"]["replace_mmrc"];
                    if (config["settings"]["replace_mmrc_cc"].is_boolean())
                        rs_replace_mmrc_cc = config["settings"]["replace_mmrc_cc"];
                    if (config["settings"]["replace_mmrcc"].is_boolean())
                        rs_replace_mmrcc = config["settings"]["replace_mmrcc"];
                    if (config["settings"]["replace_mmrcc_c"].is_boolean())
                        rs_replace_mmrcc_c = config["settings"]["replace_mmrcc_c"];

                    if (config["settings"]["files"].is_object() && !config["settings"]["files"].is_null())
                    {
                        if (config["settings"]["files"]["on"].is_boolean())
                            rs_in_file = config["settings"]["files"]["on"];
                        if (config["settings"]["files"]["games"].is_boolean())
                            rs_file_games = config["settings"]["files"]["games"];
                        if (config["settings"]["files"]["gm"].is_boolean())
                            rs_file_gm = config["settings"]["files"]["gm"];
                        if (config["settings"]["files"]["rank"].is_boolean())
                            rs_file_rank = config["settings"]["files"]["rank"];
                        if (config["settings"]["files"]["div"].is_boolean())
                            rs_file_div = config["settings"]["files"]["div"];
                        if (config["settings"]["files"]["mmr"].is_boolean())
                            rs_file_mmr = config["settings"]["files"]["mmr"];
                        if (config["settings"]["files"]["mmrc"].is_boolean())
                            rs_file_mmrc = config["settings"]["files"]["mmrc"];
                        if (config["settings"]["files"]["mmrcc"].is_boolean())
                            rs_file_mmrcc = config["settings"]["files"]["mmrcc"];
                        if (config["settings"]["files"]["win"].is_boolean())
                            rs_file_win = config["settings"]["files"]["win"];
                        if (config["settings"]["files"]["loss"].is_boolean())
                            rs_file_loss = config["settings"]["files"]["loss"];
                        if (config["settings"]["files"]["streak"].is_boolean())
                            rs_file_streak = config["settings"]["files"]["streak"];
                        if (config["settings"]["files"]["winratio"].is_boolean())
                            rs_file_winratio = config["settings"]["files"]["winratio"];
                        if (config["settings"]["files"]["winpercentage"].is_boolean())
                            rs_file_winpercentage = config["settings"]["files"]["winpercentage"];
                        if (config["settings"]["files"]["score"].is_boolean())
                            rs_file_score = config["settings"]["files"]["score"];
                        if (config["settings"]["files"]["demo"].is_boolean())
                            rs_file_demolitions = config["settings"]["files"]["demo"];
                        if (config["settings"]["files"]["demom"].is_boolean())
                            rs_file_demolitionsm = config["settings"]["files"]["demom"];
                        if (config["settings"]["files"]["democ"].is_boolean())
                            rs_file_demolitionsc = config["settings"]["files"]["democ"];
                        if (config["settings"]["files"]["death"].is_boolean())
                            rs_file_death = config["settings"]["files"]["death"];
                        if (config["settings"]["files"]["deathm"].is_boolean())
                            rs_file_deathm = config["settings"]["files"]["deathm"];
                        if (config["settings"]["files"]["deathc"].is_boolean())
                            rs_file_deathc = config["settings"]["files"]["deathc"];
                        if (config["settings"]["files"]["shots"].is_boolean())
                            rs_file_shots = config["settings"]["files"]["shots"];
                        if (config["settings"]["files"]["saves"].is_boolean())
                            rs_file_saves = config["settings"]["files"]["saves"];
                        if (config["settings"]["files"]["goals"].is_boolean())
                            rs_file_goals = config["settings"]["files"]["goals"];
                        if (config["settings"]["files"]["dropshot"].is_boolean())
                            rs_file_dropshot = config["settings"]["files"]["dropshot"];
                        if (config["settings"]["files"]["knockout"].is_boolean())
                            rs_file_knockout = config["settings"]["files"]["knockout"];
                        if (config["settings"]["files"]["boost"].is_boolean())
                            rs_file_boost = config["settings"]["files"]["boost"];
                        if (config["settings"]["files"]["miscs"].is_boolean())
                            rs_file_miscs = config["settings"]["files"]["miscs"];
                        if (config["settings"]["files"]["accolades"].is_boolean())
                            rs_file_accolades = config["settings"]["files"]["accolades"];
                    }

                    if (config["settings"]["hides"].is_object() && !config["settings"]["hides"].is_null())
                    {
                        if (config["settings"]["hides"]["games"].is_boolean())
                            rs_hide_games = config["settings"]["hides"]["games"];
                        if (config["settings"]["hides"]["gm"].is_boolean())
                            rs_hide_gm = config["settings"]["hides"]["gm"];
                        if (config["settings"]["hides"]["rank"].is_boolean())
                            rs_hide_rank = config["settings"]["hides"]["rank"];
                        if (config["settings"]["hides"]["div"].is_boolean())
                            rs_hide_div = config["settings"]["hides"]["div"];
                        if (config["settings"]["hides"]["mmr"].is_boolean())
                            rs_hide_mmr = config["settings"]["hides"]["mmr"];
                        if (config["settings"]["hides"]["mmrc"].is_boolean())
                            rs_hide_mmrc = config["settings"]["hides"]["mmrc"];
                        if (config["settings"]["hides"]["mmrcc"].is_boolean())
                            rs_hide_mmrcc = config["settings"]["hides"]["mmrcc"];
                        if (config["settings"]["hides"]["win"].is_boolean())
                            rs_hide_win = config["settings"]["hides"]["win"];
                        if (config["settings"]["hides"]["loss"].is_boolean())
                            rs_hide_loss = config["settings"]["hides"]["loss"];
                        if (config["settings"]["hides"]["streak"].is_boolean())
                            rs_hide_streak = config["settings"]["hides"]["streak"];
                        if (config["settings"]["hides"]["winratio"].is_boolean())
                            rs_hide_winratio = config["settings"]["hides"]["winratio"];
                        if (config["settings"]["hides"]["winpercentage"].is_boolean())
                            rs_hide_winpercentage = config["settings"]["hides"]["winpercentage"];
                        if (config["settings"]["hides"]["score"].is_boolean())
                            rs_hide_score = config["settings"]["hides"]["score"];
                        if (config["settings"]["hides"]["demo"].is_boolean())
                            rs_hide_demolitions = config["settings"]["hides"]["demo"];
                        if (config["settings"]["hides"]["demom"].is_boolean())
                            rs_hide_demolitionsm = config["settings"]["hides"]["demom"];
                        if (config["settings"]["hides"]["democ"].is_boolean())
                            rs_hide_demolitionsc = config["settings"]["hides"]["democ"];
                        if (config["settings"]["hides"]["death"].is_boolean())
                            rs_hide_death = config["settings"]["hides"]["death"];
                        if (config["settings"]["hides"]["deathm"].is_boolean())
                            rs_hide_deathm = config["settings"]["hides"]["deathm"];
                        if (config["settings"]["hides"]["deathc"].is_boolean())
                            rs_hide_deathc = config["settings"]["hides"]["deathc"];
                        if (config["settings"]["hides"]["shots"].is_boolean())
                            rs_hide_shots = config["settings"]["hides"]["shots"];
                        if (config["settings"]["hides"]["saves"].is_boolean())
                            rs_hide_saves = config["settings"]["hides"]["saves"];
                        if (config["settings"]["hides"]["goals"].is_boolean())
                            rs_hide_goals = config["settings"]["hides"]["goals"];
                        if (config["settings"]["hides"]["dropshot"].is_boolean())
                            rs_hide_dropshot = config["settings"]["hides"]["dropshot"];
                        if (config["settings"]["hides"]["knockout"].is_boolean())
                            rs_hide_knockout = config["settings"]["hides"]["knockout"];
                        if (config["settings"]["hides"]["miscs"].is_boolean())
                            rs_hide_miscs = config["settings"]["hides"]["miscs"];
                        if (config["settings"]["hides"]["accolades"].is_boolean())
                            rs_hide_accolades = config["settings"]["hides"]["accolades"];

                        cvarManager->log("Config: hides loaded");
                    }

                    cvarManager->log("Config: settings loaded");
                }

                if (config["always"].is_object() && !config["always"].is_null())
                {
                    VarsRead(always, config["always"]);
                    always.isInit = true;

                    cvarManager->log("Config: stats loaded");
                }

                if (config["always_gm_idx"].is_number_unsigned() && int(config["always_gm_idx"]) < playlist_name.size())
                    current.playlist = config["always_gm_idx"];

                if (config["always_gm"].is_array())
                {
                    for (int i = 0; i < config["always_gm"].size() && i < playlist_name.size(); ++i)
                    {
                        if (config["always_gm"][i].is_object() && !config["always_gm"][i].is_null())
                        {
                            VarsRead(always_gm[i], config["always_gm"][i]);
                            always_gm[i].isInit = true;
                        }
                    }

                    cvarManager->log("Config: stats loaded");
                }

                SetRefresh(RefreshFlags_Refresh);
            }
            else
                cvarManager->log("Config: bad JSON");
        }
        catch (json::parse_error& e)
        {
            cvarManager->log("Config: bad JSON -> " + std::string(e.what()));
        }
    }

    cvarManager->log("===== !ReadConfig =====");
    return exists;
}

void RocketStats::WriteConfig()
{
    cvarManager->log("===== WriteConfig =====");

    json tmp = json::object();

    tmp["settings"] = json::object();
    tmp["settings"]["mode"] = rs_mode;
    tmp["settings"]["theme"] = themes.at(rs_theme).name.c_str();
    tmp["settings"]["GameTheme"] = themes.at(rs_gameTheme).name.c_str();
    tmp["settings"]["enableDualTheme"] = dualtheme;
    tmp["settings"]["overlay"] = rs_disp_overlay;
    tmp["settings"]["inmenu"] = rs_enable_inmenu;
    tmp["settings"]["ingame"] = rs_enable_ingame;
    tmp["settings"]["inscoreboard"] = rs_enable_inscoreboard;
    tmp["settings"]["float"] = rs_enable_float;
    tmp["settings"]["preview"] = rs_preview_rank;
    tmp["settings"]["roman"] = rs_roman_numbers;

    tmp["settings"]["replace_mmr"] = rs_replace_mmr;
    tmp["settings"]["replace_mmr_cc"] = rs_replace_mmr_cc;
    tmp["settings"]["replace_mmrc"] = rs_replace_mmrc;
    tmp["settings"]["replace_mmrc_cc"] = rs_replace_mmrc_cc;
    tmp["settings"]["replace_mmrcc"] = rs_replace_mmrcc;
    tmp["settings"]["replace_mmrcc_c"] = rs_replace_mmrcc_c;

    // Save only existing themes
    tmp["settings"]["themes"] = json::object();
    for (int i = 0; i < themes.size(); ++i)
    {
        std::string name = themes.at(i).name;
        if (themes_values[name].is_object() && !themes_values[name].is_null() && themes_values[name].size())
            tmp["settings"]["themes"][name] = themes_values[name];
    }

    tmp["settings"]["files"] = json::object();
    tmp["settings"]["files"]["on"] = rs_in_file;
    tmp["settings"]["files"]["games"] = rs_file_games;
    tmp["settings"]["files"]["gm"] = rs_file_gm;
    tmp["settings"]["files"]["rank"] = rs_file_rank;
    tmp["settings"]["files"]["div"] = rs_file_div;
    tmp["settings"]["files"]["mmr"] = rs_file_mmr;
    tmp["settings"]["files"]["mmr"] = rs_file_mmr;
    tmp["settings"]["files"]["mmrc"] = rs_file_mmrc;
    tmp["settings"]["files"]["mmrcc"] = rs_file_mmrcc;
    tmp["settings"]["files"]["win"] = rs_file_win;
    tmp["settings"]["files"]["loss"] = rs_file_loss;
    tmp["settings"]["files"]["streak"] = rs_file_streak;
    tmp["settings"]["files"]["winratio"] = rs_file_winratio;
    tmp["settings"]["files"]["winpercentage"] = rs_file_winpercentage;
    tmp["settings"]["files"]["score"] = rs_file_score;
    tmp["settings"]["files"]["demo"] = rs_file_demolitions;
    tmp["settings"]["files"]["demom"] = rs_file_demolitionsm;
    tmp["settings"]["files"]["democ"] = rs_file_demolitionsc;
    tmp["settings"]["files"]["death"] = rs_file_death;
    tmp["settings"]["files"]["deathm"] = rs_file_deathm;
    tmp["settings"]["files"]["deathc"] = rs_file_deathc;
    tmp["settings"]["files"]["shots"] = rs_file_shots;
    tmp["settings"]["files"]["saves"] = rs_file_saves;
    tmp["settings"]["files"]["goals"] = rs_file_goals;
    tmp["settings"]["files"]["dropshot"] = rs_file_dropshot;
    tmp["settings"]["files"]["knockout"] = rs_file_knockout;
    tmp["settings"]["files"]["miscs"] = rs_file_miscs;
    tmp["settings"]["files"]["accolades"] = rs_file_accolades;
    tmp["settings"]["files"]["boost"] = rs_file_boost;

    tmp["settings"]["hides"] = json::object();
    tmp["settings"]["hides"]["games"] = rs_hide_games;
    tmp["settings"]["hides"]["gm"] = rs_hide_gm;
    tmp["settings"]["hides"]["rank"] = rs_hide_rank;
    tmp["settings"]["hides"]["div"] = rs_hide_div;
    tmp["settings"]["hides"]["mmr"] = rs_hide_mmr;
    tmp["settings"]["hides"]["mmrc"] = rs_hide_mmrc;
    tmp["settings"]["hides"]["mmrcc"] = rs_hide_mmrcc;
    tmp["settings"]["hides"]["win"] = rs_hide_win;
    tmp["settings"]["hides"]["loss"] = rs_hide_loss;
    tmp["settings"]["hides"]["streak"] = rs_hide_streak;
    tmp["settings"]["hides"]["winratio"] = rs_hide_winratio;
    tmp["settings"]["hides"]["winpercentage"] = rs_hide_winpercentage;
    tmp["settings"]["hides"]["score"] = rs_hide_score;
    tmp["settings"]["hides"]["demo"] = rs_hide_demolitions;
    tmp["settings"]["hides"]["demom"] = rs_hide_demolitionsm;
    tmp["settings"]["hides"]["democ"] = rs_hide_demolitionsc;
    tmp["settings"]["hides"]["death"] = rs_hide_death;
    tmp["settings"]["hides"]["deathm"] = rs_hide_deathm;
    tmp["settings"]["hides"]["deathc"] = rs_hide_deathc;
    tmp["settings"]["hides"]["shots"] = rs_hide_shots;
    tmp["settings"]["hides"]["saves"] = rs_hide_saves;
    tmp["settings"]["hides"]["goals"] = rs_hide_goals;
    tmp["settings"]["hides"]["dropshot"] = rs_hide_dropshot;
    tmp["settings"]["hides"]["knockout"] = rs_hide_knockout;
    tmp["settings"]["hides"]["miscs"] = rs_hide_miscs;
    tmp["settings"]["hides"]["accolades"] = rs_hide_accolades;

    tmp["always"] = json::object();
    VarsWrite(always, tmp["always"]);

    tmp["always_gm_idx"] = current.playlist;
    tmp["always_gm"] = json::array();
    for (int i = 0; i < always_gm.size(); ++i)
    {
        tmp["always_gm"][i] = json::object();
        VarsWrite(always_gm[i], tmp["always_gm"][i]);
    }

    WriteInFile("data/rocketstats.json", tmp.dump(2), true); // Save plugin settings in JSON format

    cvarManager->log("===== !WriteConfig =====");
}
```


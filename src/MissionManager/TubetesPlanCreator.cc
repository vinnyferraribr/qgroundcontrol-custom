/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "TubetesPlanCreator.h"
#include "PlanMasterController.h"
#include "TubetesComplexItem.h"

TubetesPlanCreator::TubetesPlanCreator(PlanMasterController* planMasterController, QObject* parent)
    : PlanCreator(
          planMasterController,
          TubetesComplexItem::name,
          //QStringLiteral("/qmlimages/PlanCreator/TubetesPlanCreator.png"),
          QStringLiteral("/qmlimages/PlanCreator/CorridorScanPlanCreator.png"),
          parent)
{
}

void TubetesPlanCreator::createPlan(const QGeoCoordinate& mapCenterCoord)
{
    _planMasterController->removeAll();
    VisualMissionItem* takeoffItem = _missionController->insertTakeoffItem(mapCenterCoord, -1);
    _missionController->insertComplexMissionItem(TubetesComplexItem::name, mapCenterCoord, -1);
    _missionController->insertLandItem(mapCenterCoord, -1);
    _missionController->setCurrentPlanViewSeqNum(takeoffItem->sequenceNumber(), true);
}

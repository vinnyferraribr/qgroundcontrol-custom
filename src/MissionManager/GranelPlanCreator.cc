/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "GranelPlanCreator.h"
#include "PlanMasterController.h"
#include "GranelComplexItem.h"

GranelPlanCreator::GranelPlanCreator(PlanMasterController* planMasterController, QObject* parent)
    : PlanCreator(
          planMasterController,
          GranelComplexItem::name,
          //QStringLiteral("/qmlimages/PlanCreator/GranelPlanCreator.png"),
          QStringLiteral("/qmlimages/PlanCreator/StructureScanPlanCreator.png"),
          parent)
{
}

void GranelPlanCreator::createPlan(const QGeoCoordinate& mapCenterCoord)
{
    _planMasterController->removeAll();
    VisualMissionItem* takeoffItem = _missionController->insertTakeoffItem(mapCenterCoord, -1);
    _missionController->insertComplexMissionItem(GranelComplexItem::name, mapCenterCoord, -1);
    _missionController->insertLandItem(mapCenterCoord, -1);
    _missionController->setCurrentPlanViewSeqNum(takeoffItem->sequenceNumber(), true);
}

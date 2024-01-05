/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "CorridorScanPlanCreator.h"
#include "PlanMasterController.h"
#include "CorridorScanComplexItem.h"

CorridorScanPlanCreator::CorridorScanPlanCreator(PlanMasterController* planMasterController, QObject* parent)
    : PlanCreator(planMasterController, CorridorScanComplexItem::name, QStringLiteral("/qmlimages/PlanCreator/CorridorScanPlanCreator.png"), parent)
{

}

void CorridorScanPlanCreator::createPlan(QVariantList coordList)
{
    PlanCreator::createPlan(coordList);

    auto mapCenterCoord = _coordRectCenter(_convertCoordList(coordList));

    VisualMissionItem* takeoffItem = _missionController->insertTakeoffItem(mapCenterCoord, -1);
    _missionController->insertComplexMissionItem(CorridorScanComplexItem::name, mapCenterCoord, -1);
    _missionController->insertLandItem(mapCenterCoord, -1);
    _missionController->setCurrentPlanViewSeqNum(takeoffItem->sequenceNumber(), true);
}

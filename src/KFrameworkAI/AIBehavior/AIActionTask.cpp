#include "AIActionTask.h"

ActionTask::ActionTask()
{
    SetStatus(BHSuccess);
}

BehaviorBase* ActionTask::AddChild(BehaviorBase* child)
{
    //TODO: Cant add a node to the action/leaf node. 
    //TODO: Later replace the base class from composite to some node class identifying the difference between CompositeNodes and SingleNodes.
    return nullptr;
}

void ActionTask::OnInitialize()
{
    SetStatus(BHSuccess);
}

BehaviorStatus ActionTask::OnUpdate()
{
    return GetStatus();
}
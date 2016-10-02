#pragma once

#include "IBehavior.h"

class Behavior : public IBehavior
{
public:
	Behavior();
	virtual ~Behavior();
	virtual BehaviorStatus Tick(float dt) override;

	virtual BehaviorStatus	GetStatus() override { return m_behaviorStatus; }

	virtual void			SetStatus(BehaviorStatus status) override { m_behaviorStatus = status; }
	virtual void			SetOnInitialize(ActionBind<BehaviorStatus>* actionBind) override { m_ActionInitialize = actionBind; }
	virtual void			SetOnUpdate(ActionBind<BehaviorStatus>* actionBind) override { m_ActionTick = actionBind; }
	virtual void			SetOnTerminate(ActionBind<BehaviorStatus>* actionBind) override { m_ActionTerminate = actionBind; }

protected:
	virtual BehaviorStatus			OnInitialize() override;
	virtual BehaviorStatus			OnUpdate() override;
	virtual BehaviorStatus			OnTerminate() override;
	virtual bool			GetInitializeBind() override { return (m_ActionInitialize != nullptr) ? true : false; }

private:
	ActionBind<BehaviorStatus>* m_ActionInitialize;
	ActionBind<BehaviorStatus>* m_ActionTick;
	ActionBind<BehaviorStatus>* m_ActionTerminate;

	BehaviorStatus		m_behaviorStatus;
};



//(*m_ActionInitialize)(); //TODO: This call binding can be there for ActionBehavior;

// 
// BehaviorStatus Behavior::Initialize()
// {
// 	BehaviorStatus status = BehaviorStatus_Success;
// 	status = m_ActionInitialize(); //TODO: Move this from normal behavior to Node behavior i.e ActionsBehavior;
// 	return status;
// }



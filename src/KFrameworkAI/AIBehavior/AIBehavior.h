#pragma once

#include "AIBehavior/IBehavior.h"

class Behavior : public IBehavior
{
public:
	Behavior();
	virtual ~Behavior();
	virtual BehaviorStatus Tick(float dt) override;

	virtual BehaviorStatus	GetStatus() override { return m_behaviorStatus; }

	virtual void			SetStatus(BehaviorStatus status) override { m_behaviorStatus = status; }

	virtual void			SetOnInitialize(ActionBind<InitFunc>* callback) override { m_OnInitialize = callback; }
	virtual void			SetOnUpdate(ActionBind<UpdateFunc>* callback) override { m_OnUpdate = callback; }
	virtual void			SetOnTerminate(ActionBind<TermFunc>* callback) override { m_OnTerminate = callback; }

protected:
	virtual void			OnInitialize() override;
	virtual BehaviorStatus	OnUpdate() override;
	virtual void			OnTerminate(BehaviorStatus status) override;
	virtual bool			GetInitializeBind() override { return (m_OnInitialize != nullptr) ?  true :  false; }

	ActionBind<InitFunc>* m_OnInitialize;
	ActionBind<UpdateFunc>* m_OnUpdate;
	ActionBind<TermFunc>* m_OnTerminate;

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



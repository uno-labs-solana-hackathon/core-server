#pragma once

#include "TestApp_global.hpp"

namespace Sol::Loyalty::Test {

class TestTask: public GpTaskFiberBase
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(TestTask)
	CLASS_DECLARE_DEFAULTS(TestTask)

public:
							TestTask					(void) noexcept;
	virtual					~TestTask					(void) noexcept override final;

protected:
	virtual void			OnStart						(void) override final;
	virtual GpTask::ResT	OnStep						(EventOptRefT aEvent) override final;
	virtual void			OnStop						(void) noexcept override final;

private:
	void					FindClient1					(Sol::Loyalty::API::RPC::ApiClient& aApiClient);
	void					MakeBuyTx1					(Sol::Loyalty::API::RPC::ApiClient& aApiClient);
	void					MakeBuyTx2					(Sol::Loyalty::API::RPC::ApiClient& aApiClient);
	void					FillBuyTxItems				(Sol::Loyalty::DataModel::BuyTxItemDesc::C::Vec::SP& aItemsOut);

	void					TestLoy2Sol					(void);
	void					TestSolWallet				(void);
	void					SendTx						(Sol::Core::API::RPC::ApiClient&			aSolApiCli,
														 const Sol::Core::LightWallet::Transaction&	aTx);
};

}//namespace Sol::Loyalty::Test

#include "ApiServerApp_global.hpp"

int main (int aArgc, char** aArgv)
{
	Sol::Core::LightWallet::LightWalletCore::SInit();

	try
	{
		return GpService::SRun
		(
			aArgc,
			aArgv,
			MakeSP<Sol::Loyalty::API::RPC::ServiceFactory>(),
			{MakeSP<Sol::Loyalty::API::RPC::HttpStartServerTaskFactory>()}
		);
	} catch (const std::exception& e)
	{
		GpExceptionsSink::SSink(e);
	} catch (...)
	{
		GpExceptionsSink::SSinkUnknown();
	}

	Sol::Core::LightWallet::LightWalletCore::SClear();

	return EXIT_FAILURE;
}

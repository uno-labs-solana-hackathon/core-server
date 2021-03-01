#include "StartTestTaskFactory.hpp"

int main (int aArgc, char** aArgv)
{
	try
	{
		return GpService::SRun
		(
			aArgc,
			aArgv,
			MakeSP<Sol::Loyalty::API::RPC::ServiceFactory>(),
			{
				MakeSP<Sol::Loyalty::API::RPC::HttpStartServerTaskFactory>(),
				MakeSP<Sol::Loyalty::Test::StartTestTaskFactory>()
			}
		);
	} catch (const std::exception& e)
	{
		GpExceptionsSink::SSink(e);
	} catch (...)
	{
		GpExceptionsSink::SSinkUnknown();
	}

	return EXIT_FAILURE;
}

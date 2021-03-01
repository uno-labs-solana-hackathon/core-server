#include "TestTask.hpp"
#include <iostream>

using namespace Sol::Core;

namespace Sol::Loyalty::Test {

TestTask::TestTask (void) noexcept
{
}

TestTask::~TestTask (void) noexcept
{
}

void	TestTask::OnStart (void)
{
	//wait for server start
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	Sol::Core::LightWallet::LightWalletCore::SInit();
}

GpTask::ResT	TestTask::OnStep (EventOptRefT /*aEvent*/)
{
	//Sol::Loyalty::API::RPC::ApiClient apiClient("https://api.gplatform.org/sol/api"_sv);
	Sol::Loyalty::API::RPC::ApiClient apiClient("http://127.0.0.1:8081/"_sv);

	//TestLoy2Sol();
	//TestSolWallet();
	//FindClient1(apiClient);
	//MakeBuyTx1(apiClient);
	MakeBuyTx2(apiClient);

	return GpTask::ResT::DONE;
}

void	TestTask::OnStop (void) noexcept
{
	Sol::Core::LightWallet::LightWalletCore::SClear();
}

void	TestTask::FindClient1 (Sol::Loyalty::API::RPC::ApiClient& aApiClient)
{
	Sol::Loyalty::DataModel::ClientDesc::SP clientDesc = aApiClient.find_client("test_id_1234"_sv, true);
}

void	TestTask::MakeBuyTx1 (Sol::Loyalty::API::RPC::ApiClient& aApiClient)
{
	Sol::Loyalty::DataModel::BuyTxItemDesc::C::Vec::SP items;
	FillBuyTxItems(items);

	const monetary_t	spend = 0_monetary;
	GpBytesArray		spendSign;
	GpBytesArray		spendRawTx;
	GpBytesArray		newAccountSign;
	GpBytesArray		newAccountRawTx;

	//Sol::Core::LightWallet::Wallet		buyerWallet;
	//Sol::Core::LightWallet::Address::SP	addressBuyerNew	= buyerWallet.GenRndAddr();

	Sol::Core::LightWallet::Wallet		buyerWallet;
	const count_t hdGroupId	= buyerWallet.AddHDGroup("spin error reward way loan use struggle weapon mango park relax tip"_sv, ""_sv);
	Sol::Core::LightWallet::Address::SP	addressBuyerNew	= buyerWallet.GenNextHDAddr(hdGroupId);

	Sol::Loyalty::DataModel::BuyTxDesc::SP buyTx = aApiClient.make_buy_tx
	(
		addressBuyerNew->Name(),
		items,
		spend,
		spendSign,
		spendRawTx,
		newAccountSign,
		newAccountRawTx,
		false
	);

	//Sign TX by buyer
	spendRawTx		= buyTx->spend_raw_tx;
	spendSign		= buyTx->spend_sign;
	newAccountRawTx	= buyTx->new_account_raw_tx;
	newAccountSign	= addressBuyerNew->SignData(newAccountRawTx);

	aApiClient.make_buy_tx
	(
		addressBuyerNew->Name(),
		items,
		spend,
		spendSign,
		spendRawTx,
		newAccountSign,
		newAccountRawTx,
		true
	);
}

void	TestTask::MakeBuyTx2 (Sol::Loyalty::API::RPC::ApiClient& aApiClient)
{
	Sol::Loyalty::DataModel::BuyTxItemDesc::C::Vec::SP items;
	FillBuyTxItems(items);

	const monetary_t	spend = 10_monetary;
	GpBytesArray		spendSign;
	GpBytesArray		spendRawTx;
	GpBytesArray		newAccountSign;
	GpBytesArray		newAccountRawTx;

	Sol::Core::LightWallet::Wallet		buyerWallet;
	const count_t hdGroupId	= buyerWallet.AddHDGroup("spin error reward way loan use struggle weapon mango park relax tip"_sv, ""_sv);
	Sol::Core::LightWallet::Address::SP	addressBuyerNew	= buyerWallet.GenNextHDAddr(hdGroupId);

	Sol::Loyalty::DataModel::BuyTxDesc::SP buyTx = aApiClient.make_buy_tx
	(
		addressBuyerNew->Name(),
		items,
		spend,
		spendSign,
		spendRawTx,
		newAccountSign,
		newAccountRawTx,
		false
	);

	//Sign TX by buyer
	spendRawTx		= buyTx->spend_raw_tx;
	spendSign		= addressBuyerNew->SignData(spendRawTx);
	newAccountRawTx	= buyTx->new_account_raw_tx;
	newAccountSign	= buyTx->new_account_sign;

	aApiClient.make_buy_tx
	(
		addressBuyerNew->Name(),
		items,
		spend,
		spendSign,
		spendRawTx,
		newAccountSign,
		newAccountRawTx,
		true
	);
}

void	TestTask::FillBuyTxItems (Sol::Loyalty::DataModel::BuyTxItemDesc::C::Vec::SP& aItemsOut)
{
	const size_t count = GpSRandom::S().SI64(1_s_int_64, 5_s_int_64).As<size_t>();

	for (size_t id = 0; id < count; id++)
	{
		aItemsOut.emplace_back(MakeSP<Sol::Loyalty::DataModel::BuyTxItemDesc>
		(
			SInt64::SMake(id),
			GpSRandom::S().String(GpRandomStrMode::ALPHA_NUM, 8_cnt),
			"Test"_sv,
			GpSRandom::S().SI64(100_s_int_64, 10000_s_int_64).As<monetary_t>(),
			GpSRandom::S().SI64(1_s_int_64, 5_s_int_64).As<count_t>()
		));
	}
}

void	TestTask::TestLoy2Sol (void)
{
	Sol::Loyalty::SolanaGateway::Loyalty2Solana loyalty2Solana("https://testnet.solana.com"_sv);
	Sol::Core::LightWallet::Wallet				buyerWallet;

	static const GpArray<u_int_8, 32>	privateKeyStore		= {12,105,194,80,78,228,241,238,31,105,219,69,228,23,193,143,87,80,30,179,60,99,54,88,5,126,134,185,180,165,176,247};
	static const GpArray<u_int_8, 32>	privateKeyProgram	= {25,250,30,109,229,24,183,141,170,235,127,24,242,14,143,231,231,70,122,228,4,64,94,14,125,134,199,140,182,215,89,59};

	Sol::Core::LightWallet::Address::SP	addressStore		= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(privateKeyStore);
	Sol::Core::LightWallet::Address::SP	addressBuyerNew		= buyerWallet.GenRndAddr();
	Sol::Core::LightWallet::Address::SP	addressProgram		= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(privateKeyProgram);

	//------------------------------------------------------------------------------------
	{
		//Prepare TX
		const GpBytesArray txSerializedDataNoSign = loyalty2Solana.NewAccountPrepareTx
		(
			addressStore->KeyPair().PublicBytes(),
			addressBuyerNew->KeyPair().PublicBytes(),
			addressProgram->KeyPair().PublicBytes()
		);

		//Sign TX by buyer
		const GpBytesArray buyerTxSign = addressBuyerNew->SignData(txSerializedDataNoSign);

		//Make TX
		loyalty2Solana.NewAccountMakeTx
		(
			txSerializedDataNoSign,
			addressStore.VC(),
			buyerTxSign
		);

		std::this_thread::sleep_for(std::chrono::seconds(35));
	}

	//------------------------------------------------------------------------------------
	{
		loyalty2Solana.EmitMakeTx
		(
			addressStore.VC(),
			addressBuyerNew->KeyPair().PublicBytes(),
			addressProgram->KeyPair().PublicBytes(),
			100_monetary
		);

		std::this_thread::sleep_for(std::chrono::seconds(35));
	}

	//------------------------------------------------------------------------------------
	{
		//Prepare TX
		const GpBytesArray txSerializedDataNoSign = loyalty2Solana.SpendPrepareTx
		(
			addressStore->KeyPair().PublicBytes(),
			addressBuyerNew->KeyPair().PublicBytes(),
			addressProgram->KeyPair().PublicBytes(),
			100_monetary
		);

		//Sign TX by buyer
		const GpBytesArray buyerTxSign = addressBuyerNew->SignData(txSerializedDataNoSign);

		//Make TX
		loyalty2Solana.SpendMakeTx
		(
			txSerializedDataNoSign,
			addressStore.VC(),
			buyerTxSign
		);
	}

	std::cout << "Done!" << std::endl;
}

void	TestTask::TestSolWallet (void)
{
	//https://docs.solana.com/developing/builtins/programs
	//KeccakSecp256k11111111111111111111111111111    04c6fc20f050ccf05584d7211c9f8cf59ec14785bb166a1e2830e81220000000
	//BPFLoader1111111111111111111111111111111111    02a8f6914e88a16bbd2395855f6404d9b4f456b7821bb0145749428c00000000
	//Vote111111111111111111111111111111111111111    0761481d357474bb7c4d7624ebd3bdb3d8355e73d11043fc0da3538000000000
	//Stake11111111111111111111111111111111111111    06a1d8179137542a983437bdfe2a7ab2557f535c8a78722b68a49dc000000000
	//Config1111111111111111111111111111111111111    03064aa3002f74dcc86e43310f0c052af8c5da27f6104019a323efa000000000
	//           11111111111111111111111111111111    0000000000000000000000000000000000000000000000000000000000000000

	Sol::Core::LightWallet::Wallet buyerWallet;


	static const GpArray<u_int_8, 32>		privateKeyStore		= {12,105,194,80,78,228,241,238,31,105,219,69,228,23,193,143,87,80,30,179,60,99,54,88,5,126,134,185,180,165,176,247};
	static const GpArray<u_int_8, 32>		privateKeyProgram	= {25,250,30,109,229,24,183,141,170,235,127,24,242,14,143,231,231,70,122,228,4,64,94,14,125,134,199,140,182,215,89,59};
	static const GpBytesArray				privateKeyBuyer1	= StrOps::SToBytesHex("fdef36460313dcc552a7633cdd4343d5a1565aa96035c5db3e12cf1ee15939c3"_sv);


	Sol::Core::LightWallet::Address::SP		addressStore		= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(privateKeyStore);
	Sol::Core::LightWallet::Address::SP		addressBuyerNew		= buyerWallet.GenRndAddr();
	//Sol::Core::LightWallet::Address::SP	addressBuyer1		= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(privateKeyBuyer1);
	Sol::Core::LightWallet::Address::SP		addressProgram		= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(privateKeyProgram);

	std::cout << "Store address:   "_sv << addressStore->Name() << std::endl;
	std::cout << "Buyer address:   "_sv << addressBuyerNew->Name() << std::endl;
	std::cout << "Program address: "_sv << addressProgram->Name() << std::endl;

	Sol::Core::LightWallet::Transaction::SP transaction;

	//Create new account
	{
		std::cout << "---------------------------------************************ Create new account ***********************---------------------------------*"_sv << std::endl;

		Sol::Core::API::RPC::ApiClient solApiClient("https://testnet.solana.com"_sv);
		Sol::Core::API::RPC::GetRecentBlockhashRsData::SP	getRecentBlockhashRs = solApiClient.getRecentBlockhash();
		const GpBytesArray									recentBlockhash = GpBase58::SDecodeToByteArray(getRecentBlockhashRs->value.blockhash, GpBase58Alphabet::NAKAMOTO);

		const GpBytesArray programData = Sol::Core::LightWallet::ProgramBuilder::SCreateAccount(89784_lamport, 4_byte, addressProgram->KeyPair().PublicBytes());

		std::cout << "Program data hex: " << StrOps::SFromBytesHex(programData) << std::endl;

		transaction = Sol::Core::LightWallet::TransactionBuilder::SNew()
			.MessageHeader(2_cnt, 0_cnt, 1_cnt)
			.AddAccountKey(addressStore->KeyPair().PublicBytes())
			.AddAccountKey(addressBuyerNew->KeyPair().PublicBytes())
			.AddAccountKey(Sol::Core::LightWallet::ProgramBuilder::SBuiltinProgramId(Sol::Core::DataModel::BuiltinProgramId::SYSTEM))
			.RecentBlockhash(recentBlockhash)
			.InstructionBegin()
				.ProgramIdIndex(2_cnt)
				.AddAccountIdIndex(0_cnt)
				.AddAccountIdIndex(1_cnt)
				.Data(programData)
			.InstructionEnd()
			.AddSign(addressStore.VC())
			.AddSign(addressBuyerNew.VC())
			.Build();

		SendTx(solApiClient, transaction.VC());

		std::cout << "NEW Buyer private key:   "_sv << StrOps::SFromBytesHex(addressBuyerNew->KeyPair().PrivateBytes().ViewR().R()) << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}

	//EMIT
	{
		std::cout << "---------------------------------************************ EMIT ************************---------------------------------"_sv << std::endl;

		Sol::Core::API::RPC::ApiClient solApiClient("https://testnet.solana.com"_sv);
		Sol::Core::API::RPC::GetRecentBlockhashRsData::SP	getRecentBlockhashRs = solApiClient.getRecentBlockhash();
		const GpBytesArray									recentBlockhash = GpBase58::SDecodeToByteArray(getRecentBlockhashRs->value.blockhash, GpBase58Alphabet::NAKAMOTO);

		u_int_32 programDataVal = BitOps::H2N(u_int_32(0b00) | NumOps::SConvert<u_int_32>(100 << 2));

		GpBytesArray					programData;
		GpByteWriterStorageByteArray	programDataStorage(programData);
		GpByteWriter					programDataWriter(programDataStorage);

		programDataWriter.UInt32(programDataVal);

		std::cout << "Program data hex: " << StrOps::SFromBytesHex(programData) << std::endl;

		transaction = Sol::Core::LightWallet::TransactionBuilder::SNew()
			.MessageHeader(1_cnt, 0_cnt, 1_cnt)
			.AddAccountKey(addressStore->KeyPair().PublicBytes())
			.AddAccountKey(addressBuyerNew->KeyPair().PublicBytes())
			//.AddAccountKey(addressBuyer1->KeyPair().PublicBytes())
			.AddAccountKey(addressProgram->KeyPair().PublicBytes())
			.RecentBlockhash(recentBlockhash)
			.InstructionBegin()
				.ProgramIdIndex(2_cnt)
				.AddAccountIdIndex(1_cnt)
				.AddAccountIdIndex(0_cnt)
				.Data(programData)
			.InstructionEnd()
			.AddSign(addressStore.VC())
			.Build();

		SendTx(solApiClient, transaction.VC());

		std::this_thread::sleep_for(std::chrono::seconds(35));
	}

	//SPEND
	{
		std::cout << "---------------------------------************************ SPEND ************************---------------------------------"_sv << std::endl;

		Sol::Core::API::RPC::ApiClient solApiClient("https://testnet.solana.com"_sv);
		Sol::Core::API::RPC::GetRecentBlockhashRsData::SP	getRecentBlockhashRs = solApiClient.getRecentBlockhash();
		const GpBytesArray									recentBlockhash = GpBase58::SDecodeToByteArray(getRecentBlockhashRs->value.blockhash, GpBase58Alphabet::NAKAMOTO);

		u_int_32 programDataVal = BitOps::H2N(u_int_32(0b01) | NumOps::SConvert<u_int_32>(100 << 2));

		GpBytesArray					programData;
		GpByteWriterStorageByteArray	programDataStorage(programData);
		GpByteWriter					programDataWriter(programDataStorage);

		programDataWriter.UInt32(programDataVal);

		std::cout << "Program data hex: " << StrOps::SFromBytesHex(programData) << std::endl;

		transaction = Sol::Core::LightWallet::TransactionBuilder::SNew()
			.MessageHeader(2_cnt, 0_cnt, 1_cnt)
			.AddAccountKey(addressStore->KeyPair().PublicBytes())
			.AddAccountKey(addressBuyerNew->KeyPair().PublicBytes())
			//.AddAccountKey(addressBuyer1->KeyPair().PublicBytes())
			.AddAccountKey(addressProgram->KeyPair().PublicBytes())
			.RecentBlockhash(recentBlockhash)
			.InstructionBegin()
				.ProgramIdIndex(2_cnt)
				.AddAccountIdIndex(1_cnt)
				.AddAccountIdIndex(0_cnt)
				.Data(programData)
			.InstructionEnd()
			.AddSign(addressStore.VC())
			.AddSign(addressBuyerNew.VC())
			.Build();

		SendTx(solApiClient, transaction.VC());

		std::this_thread::sleep_for(std::chrono::seconds(35));
	}
}

void	TestTask::SendTx
(
	Sol::Core::API::RPC::ApiClient&				aSolApiCli,
	const Sol::Core::LightWallet::Transaction&	aTx
)
{
	GpBytesArray					serializedTransactionData;
	serializedTransactionData.reserve(2048);
	GpByteWriterStorageByteArray	serializedTransactionDataStorage(serializedTransactionData);
	GpByteWriter					serializedTransactionDataWriter(serializedTransactionDataStorage);

	Sol::Core::LightWallet::Serializator::SSerialize(aTx, serializedTransactionDataWriter);

	std::string txBase64 = GpBase64::SEncodeToStr(serializedTransactionData, 0_cnt);
	std::string txBase58 = GpBase58::SEncodeToStr(serializedTransactionData, GpBase58Alphabet::NAKAMOTO);

	//std::cout << "Transaction HEX: "_sv << StrOps::SFromBytesHex(serializedTransactionData) << std::endl;
	//std::cout << "Transaction Base64: "_sv << txBase64 << std::endl;
	//std::cout << "Transaction Base58: "_sv << txBase58 << std::endl;

	aSolApiCli.sendTransaction(txBase58);
}

}//namespace Sol::Loyalty::Test

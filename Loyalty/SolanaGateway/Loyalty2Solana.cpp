#include "Loyalty2Solana.hpp"

using namespace Sol::Core;

namespace Sol::Loyalty::SolanaGateway {

Loyalty2Solana::Loyalty2Solana (std::string_view aSolanaRpcEndpoint):
iSolanaRpcEndpoint(aSolanaRpcEndpoint)
{
}

Loyalty2Solana::~Loyalty2Solana (void) noexcept
{
}

GpBytesArray	Loyalty2Solana::NewAccountPrepareTx
(
	GpRawPtrByteR aStorePublicKey,
	GpRawPtrByteR aBuyerPublicKey,
	GpRawPtrByteR aProgramPublicKey
)
{
	const GpBytesArray programData = Sol::Core::LightWallet::ProgramBuilder::SCreateAccount(89784_lamport, 4_byte, aProgramPublicKey);

	Sol::Core::LightWallet::Transaction::SP transaction = Sol::Core::LightWallet::TransactionBuilder::SNew()
		.MessageHeader(2_cnt, 0_cnt, 1_cnt)
		.AddAccountKey(aStorePublicKey)
		.AddAccountKey(aBuyerPublicKey)
		.AddAccountKey(Sol::Core::LightWallet::ProgramBuilder::SBuiltinProgramId(Sol::Core::DataModel::BuiltinProgramId::SYSTEM))
		.RecentBlockhash(RecentBlockhash())
		.InstructionBegin()
			.ProgramIdIndex(2_cnt)
			.AddAccountIdIndex(0_cnt)
			.AddAccountIdIndex(1_cnt)
			.Data(programData)
		.InstructionEnd()
		//.AddSign(addressStore.VC())
		//.AddSign(addressBuyerNew.VC())
		.Build();

	return SerializeTxNoSig(transaction.VC());
}

std::string	Loyalty2Solana::NewAccountMakeTx
(
	GpRawPtrByteR							aSerializedTransaction,
	const Sol::Core::LightWallet::Address&	aStoreAddress,
	GpRawPtrByteR							aBuyerSign
)
{
	const GpBytesArray storeSign = aStoreAddress.SignData(aSerializedTransaction);

	GpBytesArray					txData;
	GpByteWriterStorageByteArray	txDataStorage(txData);
	GpByteWriter					txDataWriter(txDataStorage);

	txDataWriter.CompactUInt16(NumOps::SConvert<u_int_16>(2));
	txDataWriter.Bytes(storeSign);
	txDataWriter.Bytes(aBuyerSign);
	txDataWriter.Bytes(aSerializedTransaction);

	return SendTx(txData);
}

std::string	Loyalty2Solana::EmitMakeTx
(
	const Sol::Core::LightWallet::Address&	aStoreAddress,
	GpRawPtrByteR							aBuyerPublicKey,
	GpRawPtrByteR							aProgramPublicKey,
	const monetary_t						aAmountEarn
)
{
	u_int_32 programDataVal = BitOps::H2N(u_int_32(0b00) | u_int_32(aAmountEarn.As<u_int_32>() << 2));

	GpBytesArray					programData;
	GpByteWriterStorageByteArray	programDataStorage(programData);
	GpByteWriter					programDataWriter(programDataStorage);

	programDataWriter.UInt32(programDataVal);

	Sol::Core::LightWallet::Transaction::SP transaction = Sol::Core::LightWallet::TransactionBuilder::SNew()
		.MessageHeader(1_cnt, 0_cnt, 1_cnt)
		.AddAccountKey(aStoreAddress.KeyPair().PublicBytes())
		.AddAccountKey(aBuyerPublicKey)
		.AddAccountKey(aProgramPublicKey)
		.RecentBlockhash(RecentBlockhash())
		.InstructionBegin()
			.ProgramIdIndex(2_cnt)
			.AddAccountIdIndex(1_cnt)
			.AddAccountIdIndex(0_cnt)
			.Data(programData)
		.InstructionEnd()
		.AddSign(aStoreAddress)
		.Build();

	return SendTx(SerializeTx(transaction.VC()));
}

GpBytesArray	Loyalty2Solana::SpendPrepareTx
(
	GpRawPtrByteR		aStorePublicKey,
	GpRawPtrByteR		aBuyerPublicKey,
	GpRawPtrByteR		aProgramPublicKey,
	const monetary_t	aAmountSpend
)
{
	u_int_32 programDataVal = BitOps::H2N(u_int_32(0b01) | u_int_32(aAmountSpend.As<u_int_32>() << 2));

	GpBytesArray					programData;
	GpByteWriterStorageByteArray	programDataStorage(programData);
	GpByteWriter					programDataWriter(programDataStorage);

	programDataWriter.UInt32(programDataVal);

	Sol::Core::LightWallet::Transaction::SP transaction = Sol::Core::LightWallet::TransactionBuilder::SNew()
		.MessageHeader(2_cnt, 0_cnt, 1_cnt)
		.AddAccountKey(aStorePublicKey)
		.AddAccountKey(aBuyerPublicKey)
		.AddAccountKey(aProgramPublicKey)
		.RecentBlockhash(RecentBlockhash())
		.InstructionBegin()
			.ProgramIdIndex(2_cnt)
			.AddAccountIdIndex(1_cnt)
			.AddAccountIdIndex(0_cnt)
			.Data(programData)
		.InstructionEnd()
		.Build();

	return SerializeTxNoSig(transaction.VC());
}

std::string	Loyalty2Solana::SpendMakeTx
(
	GpRawPtrByteR							aSerializedTransaction,
	const Sol::Core::LightWallet::Address&	aStoreAddress,
	GpRawPtrByteR							aBuyerSign
)
{
	const GpBytesArray storeSign = aStoreAddress.SignData(aSerializedTransaction);

	GpBytesArray					txData;
	GpByteWriterStorageByteArray	txDataStorage(txData);
	GpByteWriter					txDataWriter(txDataStorage);

	txDataWriter.CompactUInt16(NumOps::SConvert<u_int_16>(2));
	txDataWriter.Bytes(storeSign);
	txDataWriter.Bytes(aBuyerSign);
	txDataWriter.Bytes(aSerializedTransaction);

	return SendTx(txData);
}

GpBytesArray	Loyalty2Solana::SerializeTxNoSig (const Sol::Core::LightWallet::Transaction& aTx)
{
	GpBytesArray					serializedTransactionData;
	serializedTransactionData.reserve(2048);
	GpByteWriterStorageByteArray	serializedTransactionDataStorage(serializedTransactionData);
	GpByteWriter					serializedTransactionDataWriter(serializedTransactionDataStorage);

	Sol::Core::LightWallet::Serializator::SSerializeNoSig(aTx, serializedTransactionDataWriter);

	return serializedTransactionData;
}

GpBytesArray	Loyalty2Solana::SerializeTx (const Sol::Core::LightWallet::Transaction& aTx)
{
	GpBytesArray					serializedTransactionData;
	serializedTransactionData.reserve(2048);
	GpByteWriterStorageByteArray	serializedTransactionDataStorage(serializedTransactionData);
	GpByteWriter					serializedTransactionDataWriter(serializedTransactionDataStorage);

	Sol::Core::LightWallet::Serializator::SSerialize(aTx, serializedTransactionDataWriter);

	return serializedTransactionData;
}

std::string	Loyalty2Solana::SendTx (const GpBytesArray& aSerializedTransactionData)
{
	Sol::Core::API::RPC::ApiClient solApiClient(iSolanaRpcEndpoint);
	//std::string txBase64 = GpBase64::SEncodeToStr(serializedTransactionData, 0_cnt);
	std::string txBase58 = GpBase58::SEncodeToStr(aSerializedTransactionData, GpBase58Alphabet::NAKAMOTO);

	//std::cout << "Transaction HEX: "_sv << StrOps::SFromBytesHex(serializedTransactionData) << std::endl;
	//std::cout << "Transaction Base64: "_sv << txBase64 << std::endl;
	//std::cout << "Transaction Base58: "_sv << txBase58 << std::endl;

	return solApiClient.sendTransaction(txBase58);
}

GpBytesArray	Loyalty2Solana::RecentBlockhash (void)
{
	Sol::Core::API::RPC::ApiClient solApiClient(iSolanaRpcEndpoint);
	Sol::Core::API::RPC::GetRecentBlockhashRsData::SP	getRecentBlockhashRs	= solApiClient.getRecentBlockhash();
	const GpBytesArray									recentBlockhash			= GpBase58::SDecodeToByteArray(getRecentBlockhashRs->value.blockhash, GpBase58Alphabet::NAKAMOTO);

	return recentBlockhash;
}

}//namespace Sol::Loyalty::SolanaGateway

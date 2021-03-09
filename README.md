# Rosin Loyalty

Prototype of Loyalty system (backend server) on Solana blockchain. All written with C++.

## Core (custom implementation of Solana client light core)
Support for: RPC-JSON client, Transactions/Messages/Programs/Instructions binary format, HD wallet.

Modules:
- [ApiClient](Core/ApiClient) - Solana RPC-JSON API client (with minimal API methods needed).
- [DataModel](Core/DataModel) - Solana RPC-JSON API data model and core Messages/Programs/Instructions data model.
- [LightWalletCore](Core/LightWalletCore) - Solana light wallet (HD, tansaction binary format, signature, etc.). Used on Loyalty backend server.
- [LightWalletCoreWasm](Core/LightWalletCoreWasm) - WASM wrapper for LightWalletCore. Used on [Client app 1](https://github.com/uno-labs-solana-hackathon/customer-app), [Client app 2](https://github.com/uno-labs-solana-hackathon/customer-mobile-app). Also can be used with node.js

Depends on: 
- [Set of low level libraries](https://github.com/ITBear?tab=repositories)
- [Crypto core](https://github.com/ITBear/GpCryptoCore) - low level crypto core implementing common base cryptographic primitives for light blockchain clients.

## Loyalty backend server
Backend server implementing prototype of loyalty system.

Modules:
- [ApiClient](Loyalty/ApiClient) - API client implementetion for Loyalty backend server
- [ApiServer](Loyalty/ApiServer) - API server implementetion
- [DataModel](Loyalty/DataModel) - API/DB data model
- [SolanaGateway](Loyalty/SolanaGateway) - Gateway to Solana for using [program](https://github.com/uno-labs-solana-hackathon/loyalty-vm-contract)

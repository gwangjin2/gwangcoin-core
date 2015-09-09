gwangcoin.md


src/base58.h

 class CBitcoinAddress : public CBase58Data
{
public:
    enum
    {
        PUBKEY_ADDRESS = 125, // Suwoncoin addresses start with s

        SCRIPT_ADDRESS = 5,
        PUBKEY_ADDRESS_TEST = 111,
        SCRIPT_ADDRESS_TEST = 196,
    };

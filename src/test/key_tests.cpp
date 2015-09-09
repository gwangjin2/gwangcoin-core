#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>

#include "key.h"
#include "base58.h"
#include "uint256.h"
#include "util.h"

using namespace std;



/*
 * make from gwangcoin/contrib/pycoin

~/Projects/gwangcoin/contrib/pycoin $ ku -nSWC 1

input                          : 1
network                        : Suwoncoin mainnet
netcode                        : SWC
secret exponent                : 1
 hex                           : 1
wif                            : eRhXeqAbHtnnXvMLvArwR2wDxvq3CsbvBmbyZvexE4g5FFMGBQju
 uncompressed                  : 9UoLdfZ5be7J7Z2SMf2oK8gvgrogUACY5hvEiu2oVnh7rYK5xSM
public pair x                  : 55066263022277343669578718895168534326250603453777594175500187360389116729240
public pair y                  : 32670510020758816978083085130507043184471273380659243275938904335757337482424
 x as hex                      : 79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798
 y as hex                      : 483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8
y parity                       : even
key pair as sec                : 0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798
 uncompressed                  : 0479be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798\
                                   483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8
hash160                        : 751e76e8199196d454941c45d1b3a323f1433bd6
 uncompressed                  : 91b24bf9f5288532960ac687abb035127b1d28a5
Suwoncoin address              : sUvfdj9d7cnHNVcpHDkASXSKoAeTsKojEm
Suwoncoin address uncompressed : sXXmeff54XxS9YfnPVmxNu5PPojcrHpixP


~/Projects/gwangcoin/contrib/pycoin $ ku -nSWC 2
input                          : 2
network                        : Suwoncoin mainnet
netcode                        : SWC
secret exponent                : 2
 hex                           : 2
wif                            : eRhXeqAbHtnnXvMLvArwR2wDxvq3CsbvBmbyZvexE4g5FkG9gW1b
 uncompressed                  : 9UoLdfZ5be7J7Z2SMf2oK8gvgrogUACY5hvEiu2oVnh7rcUUCbZ
public pair x                  : 89565891926547004231252920425935692360644145829622209833684329913297188986597
public pair y                  : 12158399299693830322967808612713398636155367887041628176798871954788371653930
 x as hex                      : c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5
 y as hex                      : 1ae168fea63dc339a3c58419466ceaeef7f632653266d0e1236431a950cfe52a
y parity                       : even
key pair as sec                : 02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5
 uncompressed                  : 04c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5\
                                   1ae168fea63dc339a3c58419466ceaeef7f632653266d0e1236431a950cfe52a
hash160                        : 06afd46bcdfd22ef94ac122aa11f241244a37ecc
 uncompressed                  : d6c8e828c1eca1bba065e1b83e1dc2a36e387a42
Suwoncoin address              : sJrkmbH9318FAcZPw2DatoBUd3qvCt6D55
Suwoncoin address uncompressed : sdq5Mt131X81FgRgRj8gHihsw7fMS1MFu8

*/

static const string strSecret1C    ("eRhXeqAbHtnnXvMLvArwR2wDxvq3CsbvBmbyZvexE4g5FFMGBQju");
static const string strSecret1     ("9UoLdfZ5be7J7Z2SMf2oK8gvgrogUACY5hvEiu2oVnh7rYK5xSM");
static const string strSecret2C    ("eRhXeqAbHtnnXvMLvArwR2wDxvq3CsbvBmbyZvexE4g5FkG9gW1b");
static const string strSecret2     ("9UoLdfZ5be7J7Z2SMf2oK8gvgrogUACY5hvEiu2oVnh7rcUUCbZ");

static const CBitcoinAddress addr1C("sUvfdj9d7cnHNVcpHDkASXSKoAeTsKojEm");
static const CBitcoinAddress addr1 ("sXXmeff54XxS9YfnPVmxNu5PPojcrHpixP");

static const CBitcoinAddress addr2C("sJrkmbH9318FAcZPw2DatoBUd3qvCt6D55");
static const CBitcoinAddress addr2 ("sdq5Mt131X81FgRgRj8gHihsw7fMS1MFu8");


static const string strAddressBad("LRjyUS2uuieEPkhZNdQz8hE5YycxVEqSXA");


#ifdef KEY_TESTS_DUMPINFO
void dumpKeyInfo(uint256 privkey)
{
    CKey key;
    key.resize(32);
    memcpy(&secret[0], &privkey, 32);
    vector<unsigned char> sec;
    sec.resize(32);
    memcpy(&sec[0], &secret[0], 32);
    printf("  * secret (hex): %s\n", HexStr(sec).c_str());

    for (int nCompressed=0; nCompressed<2; nCompressed++)
    {
        bool fCompressed = nCompressed == 1;
        printf("  * %s:\n", fCompressed ? "compressed" : "uncompressed");
        CBitcoinSecret bsecret;
        bsecret.SetSecret(secret, fCompressed);
        printf("    * secret (base58): %s\n", bsecret.ToString().c_str());
        CKey key;
        key.SetSecret(secret, fCompressed);
        vector<unsigned char> vchPubKey = key.GetPubKey();
        printf("    * pubkey (hex): %s\n", HexStr(vchPubKey).c_str());
        printf("    * address (base58): %s\n", CBitcoinAddress(vchPubKey).ToString().c_str());
    }
}
#endif


BOOST_AUTO_TEST_SUITE(key_tests)

BOOST_AUTO_TEST_CASE(key_test1)
{
    CBitcoinSecret bsecret1, bsecret2, bsecret1C, bsecret2C, baddress1;
    BOOST_CHECK( bsecret1.SetString (strSecret1));
    BOOST_CHECK( bsecret2.SetString (strSecret2));
    BOOST_CHECK( bsecret1C.SetString(strSecret1C));
    BOOST_CHECK( bsecret2C.SetString(strSecret2C));
    BOOST_CHECK(!baddress1.SetString(strAddressBad));

    CKey key1  = bsecret1.GetKey();
    BOOST_CHECK(key1.IsCompressed() == false);
    CKey key2  = bsecret2.GetKey();
    BOOST_CHECK(key2.IsCompressed() == false);
    CKey key1C = bsecret1C.GetKey();
    BOOST_CHECK(key1C.IsCompressed() == true);
    CKey key2C = bsecret2C.GetKey();
    BOOST_CHECK(key1C.IsCompressed() == true);

    CPubKey pubkey1  = key1. GetPubKey();
    CPubKey pubkey2  = key2. GetPubKey();
    CPubKey pubkey1C = key1C.GetPubKey();
    CPubKey pubkey2C = key2C.GetPubKey();

    BOOST_CHECK(addr1.Get()  == CTxDestination(pubkey1.GetID()));
    BOOST_CHECK(addr2.Get()  == CTxDestination(pubkey2.GetID()));
    BOOST_CHECK(addr1C.Get() == CTxDestination(pubkey1C.GetID()));
    BOOST_CHECK(addr2C.Get() == CTxDestination(pubkey2C.GetID()));

    for (int n=0; n<16; n++)
    {
        string strMsg = strprintf("Very secret message %i: 11", n);
        uint256 hashMsg = Hash(strMsg.begin(), strMsg.end());

        // normal signatures

        vector<unsigned char> sign1, sign2, sign1C, sign2C;

        BOOST_CHECK(key1.Sign (hashMsg, sign1));
        BOOST_CHECK(key2.Sign (hashMsg, sign2));
        BOOST_CHECK(key1C.Sign(hashMsg, sign1C));
        BOOST_CHECK(key2C.Sign(hashMsg, sign2C));

        BOOST_CHECK( pubkey1.Verify(hashMsg, sign1));
        BOOST_CHECK(!pubkey1.Verify(hashMsg, sign2));
        BOOST_CHECK( pubkey1.Verify(hashMsg, sign1C));
        BOOST_CHECK(!pubkey1.Verify(hashMsg, sign2C));

        BOOST_CHECK(!pubkey2.Verify(hashMsg, sign1));
        BOOST_CHECK( pubkey2.Verify(hashMsg, sign2));
        BOOST_CHECK(!pubkey2.Verify(hashMsg, sign1C));
        BOOST_CHECK( pubkey2.Verify(hashMsg, sign2C));

        BOOST_CHECK( pubkey1C.Verify(hashMsg, sign1));
        BOOST_CHECK(!pubkey1C.Verify(hashMsg, sign2));
        BOOST_CHECK( pubkey1C.Verify(hashMsg, sign1C));
        BOOST_CHECK(!pubkey1C.Verify(hashMsg, sign2C));

        BOOST_CHECK(!pubkey2C.Verify(hashMsg, sign1));
        BOOST_CHECK( pubkey2C.Verify(hashMsg, sign2));
        BOOST_CHECK(!pubkey2C.Verify(hashMsg, sign1C));
        BOOST_CHECK( pubkey2C.Verify(hashMsg, sign2C));

        // compact signatures (with key recovery)

        vector<unsigned char> csign1, csign2, csign1C, csign2C;

        BOOST_CHECK(key1.SignCompact (hashMsg, csign1));
        BOOST_CHECK(key2.SignCompact (hashMsg, csign2));
        BOOST_CHECK(key1C.SignCompact(hashMsg, csign1C));
        BOOST_CHECK(key2C.SignCompact(hashMsg, csign2C));

        CPubKey rkey1, rkey2, rkey1C, rkey2C;

        BOOST_CHECK(rkey1.RecoverCompact (hashMsg, csign1));
        BOOST_CHECK(rkey2.RecoverCompact (hashMsg, csign2));
        BOOST_CHECK(rkey1C.RecoverCompact(hashMsg, csign1C));
        BOOST_CHECK(rkey2C.RecoverCompact(hashMsg, csign2C));

        BOOST_CHECK(rkey1  == pubkey1);
        BOOST_CHECK(rkey2  == pubkey2);
        BOOST_CHECK(rkey1C == pubkey1C);
        BOOST_CHECK(rkey2C == pubkey2C);
    }
}

BOOST_AUTO_TEST_SUITE_END()

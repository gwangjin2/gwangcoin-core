#!/usr/bin/env python

from coinkit import GwangcoinKeypair


for i in range(10):
	p = GwangcoinKeypair()
	print "private key: \t"+ p.private_key()
	print "public key: \t" + p.public_key()
	print "hash160: \t" + p.hash160()
	print "sec_exponent: \t" + p.secret_exponent()
	print "wif_pk: \t" + p.wif_pk()
	print "address: \t" + p.address()
	print ""

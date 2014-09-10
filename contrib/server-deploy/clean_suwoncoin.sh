#!/bin/bash
#
./stop_suwoncoin.sh
#
./backup_suwoncoin.sh
#
echo 'clear all coin data'
#cp .suwoncoin/suwoncoin.conf . && rm -rf .suwoncoin && mkdir .suwoncoin && cp suwoncoin.conf .suwoncoin/suwoncoin.conf
rm -rf .suwoncoin && mkdir .suwoncoin && cp suwoncoin.conf .suwoncoin/suwoncoin.conf
#

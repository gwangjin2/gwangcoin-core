#!/bin/bash
#
echo 'kill suwoncond...'
pkill -9 suwoncoind
#
#echo 'clear all coin data'
#cp .suwoncoin/suwoncoin.conf . && rm -rf .suwoncoin && mkdir .suwoncoin && cp suwoncoin.conf .suwoncoin/suwoncoin.conf
#
#echo 'restart suwoncoind...'
#./suwoncoind -daemon

ps ax |grep suwoncoind


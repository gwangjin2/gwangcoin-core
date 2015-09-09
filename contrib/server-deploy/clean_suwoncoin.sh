#!/bin/bash
#
./stop_gwangcoin.sh
#
./backup_gwangcoin.sh
#
echo 'clear all coin data'
#cp .gwangcoin/gwangcoin.conf . && rm -rf .gwangcoin && mkdir .gwangcoin && cp gwangcoin.conf .gwangcoin/gwangcoin.conf
rm -rf .gwangcoin && mkdir .gwangcoin && cp gwangcoin.conf .gwangcoin/gwangcoin.conf
#

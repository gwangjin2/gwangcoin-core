#!/bin/bash
#
echo 'kill suwoncond...'
pkill -9 gwangcoind
#
#echo 'clear all coin data'
#cp .gwangcoin/gwangcoin.conf . && rm -rf .gwangcoin && mkdir .gwangcoin && cp gwangcoin.conf .gwangcoin/gwangcoin.conf
#
#echo 'restart gwangcoind...'
#./gwangcoind -daemon

ps ax |grep gwangcoind


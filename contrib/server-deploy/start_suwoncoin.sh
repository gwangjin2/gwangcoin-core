#!/bin/bash
#
echo 'restart gwangcoind...'
./gwangcoind -daemon

ps ax |grep gwangcoind


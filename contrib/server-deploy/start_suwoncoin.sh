#!/bin/bash
#
echo 'restart suwoncoind...'
./suwoncoind -daemon

ps ax |grep suwoncoind


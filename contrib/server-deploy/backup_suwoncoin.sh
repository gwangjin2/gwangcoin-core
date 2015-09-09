#!/bin/bash
#
echo 'backup .gwangcoin'
BACKUP_DIR='gwangcoin_backup'
mkdir -p ${BACKUP_DIR}
DATE=`date +%Y%m%d-%H%m%S`
tar cvzf ${BACKUP_DIR}/gwangcoin_data_backup-${DATE}.tar.gz .gwangcoin
echo 'backup complete'


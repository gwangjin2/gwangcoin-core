#!/bin/bash
#
echo 'backup .suwoncoin'
BACKUP_DIR='suwoncoin_backup'
mkdir -p ${BACKUP_DIR}
DATE=`date +%Y%m%d-%H%m%S`
tar cvzf ${BACKUP_DIR}/suwoncoin_data_backup-${DATE}.tar.gz .suwoncoin
echo 'backup complete'


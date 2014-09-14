#! /bin/sh

check_config() {
    if [ ! -e /etc/ssh/sshd_not_to_be_run ]; then
	/usr/sbin/sshd $SSHD_OPTS -t || exit 1
    fi
}

check_status() {
	ps ax |grep suwoncoind
}


case "$1" in
  start)
	echo 'restart suwoncoind...'
	./suwoncoind -daemon
	check_status
	;;

  stop)
	echo 'kill suwoncond...'
	pkill -9 suwoncoind
	check_status
	;;

  status)
	check_status
	#ps ax |grep suwoncoind
	;;

  clean)
	echo 'clear all coin data'
	#cp .suwoncoin/suwoncoin.conf . && rm -rf .suwoncoin && mkdir .suwoncoin && cp suwoncoin.conf .suwoncoin/suwoncoin.conf
	rm -rf .suwoncoin && mkdir .suwoncoin && cp suwoncoin.conf .suwoncoin/suwoncoin.conf
	;;
	
  backup)
	echo 'backup .suwoncoin'
	BACKUP_DIR='suwoncoin_backup'
	mkdir -p ${BACKUP_DIR}
	DATE=`date +%Y%m%d-%H%m%S`
	tar cvzf ${BACKUP_DIR}/suwoncoin_data_backup-${DATE}.tar.gz .suwoncoin
	echo 'backup complete'
	;;
	
  *)
	echo "Usage: suwoncoin.sh {start|stop|clean|backup|status}" || true
	exit 1
esac

exit 0

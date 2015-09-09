#! /bin/sh

check_config() {
    if [ ! -e /etc/ssh/sshd_not_to_be_run ]; then
	/usr/sbin/sshd $SSHD_OPTS -t || exit 1
    fi
}

check_status() {
	ps ax |grep gwangcoind
}


case "$1" in
  start)
	echo 'restart gwangcoind...'
	./gwangcoind -daemon
	check_status
	;;

  stop)
	echo 'kill suwoncond...'
	pkill -9 gwangcoind
	check_status
	;;

  status)
	check_status
	#ps ax |grep gwangcoind
	;;

  clean)
	echo 'clear all coin data'
	#cp .gwangcoin/gwangcoin.conf . && rm -rf .gwangcoin && mkdir .gwangcoin && cp gwangcoin.conf .gwangcoin/gwangcoin.conf
	rm -rf .gwangcoin && mkdir .gwangcoin && cp gwangcoin.conf .gwangcoin/gwangcoin.conf
	;;
	
  backup)
	echo 'backup .gwangcoin'
	BACKUP_DIR='gwangcoin_backup'
	mkdir -p ${BACKUP_DIR}
	DATE=`date +%Y%m%d-%H%m%S`
	tar cvzf ${BACKUP_DIR}/gwangcoin_data_backup-${DATE}.tar.gz .gwangcoin
	echo 'backup complete'
	;;
	
  *)
	echo "Usage: gwangcoin.sh {start|stop|clean|backup|status}" || true
	exit 1
esac

exit 0
